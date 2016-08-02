#include "roman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <regex.h>

#define ROMAN_REGULAR_EXPRESSION  "(^M*(C[MD]|D?C{0,3})(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})$)"

static regex_t roman_regular_expression;

#define ROMAN_DIGIT_COUNT_M_INDEX    (0)
#define ROMAN_DIGIT_COUNT_D_INDEX    (1)
#define ROMAN_DIGIT_COUNT_C_INDEX    (2)
#define ROMAN_DIGIT_COUNT_L_INDEX    (3)
#define ROMAN_DIGIT_COUNT_X_INDEX    (4)
#define ROMAN_DIGIT_COUNT_V_INDEX    (5)
#define ROMAN_DIGIT_COUNT_I_INDEX    (6)
#define ROMAN_NUMBER_OF_DIGITS       (7)

typedef struct 
{
    RomanCount_t  digit_counts[ROMAN_NUMBER_OF_DIGITS];
} RomanNumeralCounts_t;

#define ROMAN_NUMERALS_FOR_I_LENGTH      (10)

static RomanDigit_t * roman_numerals_for_i[ROMAN_NUMERALS_FOR_I_LENGTH] = 
{
    "",
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII",
    "IX"
};

#define ROMAN_NUMERALS_FOR_V_LENGTH      (3)

static RomanDigit_t * roman_numerals_for_v[ROMAN_NUMERALS_FOR_V_LENGTH] =
{
    "",
    "V",
    "X",
};

#define ROMAN_NUMERALS_FOR_X_LENGTH      (10)

static RomanDigit_t * roman_numerals_for_x[ROMAN_NUMERALS_FOR_X_LENGTH] = 
{
    "",
    "X",
    "XX",
    "XXX",
    "XL",
    "L",
    "LX",
    "LXX",
    "LXXX",
    "XC"
};

#define ROMAN_NUMERALS_FOR_L_LENGTH      (3)

static RomanDigit_t * roman_numerals_for_l[ROMAN_NUMERALS_FOR_L_LENGTH] =
{
    "",
    "L",
    "C",
};

#define ROMAN_NUMERALS_FOR_C_LENGTH      (10)

static RomanDigit_t * roman_numerals_for_c[ROMAN_NUMERALS_FOR_C_LENGTH] = 
{
    "",
    "C",
    "CC",
    "CCC",
    "CD",
    "D",
    "DC",
    "DCC",
    "DCCC",
    "CM"
};

#define ROMAN_NUMERALS_FOR_D_LENGTH      (3)

static RomanDigit_t * roman_numerals_for_d[ROMAN_NUMERALS_FOR_D_LENGTH] = 
{
    "",
    "D",
    "M",
};

#define ROMAN_NUMERALS_FOR_M_LENGTH      (2)

static RomanDigit_t * roman_numerals_for_m[ROMAN_NUMERALS_FOR_M_LENGTH] = 
{
    "",
    "M",
};

const RomanCount_t roman_number_of_previous_counts[ROMAN_NUMBER_OF_DIGITS] = 
{
    2, 2, 5, 2, 5, 2, 5
};

RomanBool_t roman_initialize_library()
{
    RomanBool_t result;
    int status;

    status = regcomp(&roman_regular_expression, ROMAN_REGULAR_EXPRESSION, REG_EXTENDED);
    if (status != 0)
    {
        printf("Error compiling regular expression %s status = %d.\n", ROMAN_REGULAR_EXPRESSION, status);
        result = ROMAN_FALSE;
    }
    else
    {
        result = ROMAN_TRUE;
    }

    return result;
}

RomanBool_t roman_is_valid_digit(RomanDigit_t digit)
{
    RomanBool_t result;

    switch (digit)
    {
        case 'I':
        case 'V':
        case 'X':
        case 'L':
        case 'C':
        case 'D':
        case 'M':
            result = ROMAN_TRUE;
            break;

        default:
            result = ROMAN_FALSE;
            break;
    }

    return result;
}

RomanBool_t roman_is_valid_sequential_digit(RomanDigit_t digit)
{
    RomanBool_t result;

    switch (digit)
    {
        case 'I':
        case 'X':
        case 'C':
            result = ROMAN_TRUE;
            break;

        case 'V':
        case 'L':
        case 'D':
        case 'M':
        default:
            result = ROMAN_FALSE;
            break;
    }

    return result;
}

RomanCompare_t roman_digit_compare_to(RomanDigit_t digit_a, RomanDigit_t digit_b)
{
    RomanCompare_t result = ROMAN_DIGIT_INVALID;

    if (digit_a == digit_b)
    {
        result = ROMAN_DIGIT_EQUALTO;
    }
    else
    {
        switch (digit_a)
        {
            case 'I':
                result = ROMAN_DIGIT_LESSTHAN;
                break;

            case 'V':
                result = (digit_b == 'I') ? ROMAN_DIGIT_GREATERTHAN : ROMAN_DIGIT_LESSTHAN;
                break;

            case 'X':
                switch (digit_b)
                {
                    case 'I':
                    case 'V':
                        result = ROMAN_DIGIT_GREATERTHAN;
                        break;

                    case 'L':
                    case 'C':
                    case 'D':
                    case 'M':
                        result = ROMAN_DIGIT_LESSTHAN;
                        break;

                    default:
                        result = ROMAN_DIGIT_EQUALTO;
                        break;
                }
                break;

            case 'L':
                switch (digit_b)
                {
                    case 'I':
                    case 'V':
                    case 'X':
                        result = ROMAN_DIGIT_GREATERTHAN;
                        break;

                    case 'C':
                    case 'D':
                    case 'M':
                        result = ROMAN_DIGIT_LESSTHAN;
                        break;

                    default:
                        result = ROMAN_DIGIT_EQUALTO;
                        break;
                }
                break;

            case 'C':
                switch (digit_b)
                {
                    case 'I':
                    case 'V':
                    case 'X':
                    case 'L':
                        result = ROMAN_DIGIT_GREATERTHAN;
                        break;

                    case 'D':
                    case 'M':
                        result = ROMAN_DIGIT_LESSTHAN;
                        break;

                    default:
                        result = ROMAN_DIGIT_EQUALTO;
                        break;
                }
                break;

            case 'D':
                switch (digit_b)
                {
                    case 'I':
                    case 'V':
                    case 'X':
                    case 'L':
                    case 'C':
                        result = ROMAN_DIGIT_GREATERTHAN;
                        break;

                    case 'M':
                        result = ROMAN_DIGIT_LESSTHAN;
                        break;

                    default:
                        result = ROMAN_DIGIT_EQUALTO;
                        break;
                }
                break;

            case 'M':
                result = ROMAN_DIGIT_GREATERTHAN;
                break;

            default:
                break;
        }
    }

    return result;
}

RomanCount_t roman_get_max_sequential_count(RomanDigit_t digit)
{
    RomanCount_t result;

    switch (digit)
    {
        case 'I':
        case 'X':
        case 'C':
            result = 3;
            break;

        case 'V':
        case 'L':
        case 'D':
        case 'M':
            result = 1;
            break;

        default:
            result = 0;
            break;
    }

    return result;
}

RomanBool_t roman_is_valid_subtraction_pair(RomanDigit_t digit_a, RomanDigit_t digit_b)
{
    RomanBool_t    result;

    switch (digit_a)
    {
        case 'I':
            result = ((digit_b == 'V') || (digit_b == 'X')) ? ROMAN_TRUE : ROMAN_FALSE;
            break;

        case 'V':
            result = ROMAN_FALSE;
            break;

        case 'X':
            result = ((digit_b == 'L') || (digit_b == 'C')) ? ROMAN_TRUE : ROMAN_FALSE;
            break;

        case 'L':
            result = ROMAN_FALSE;
            break;

        case 'C':
            result = ((digit_b == 'D') || (digit_b == 'M')) ? ROMAN_TRUE : ROMAN_FALSE;
            break;

        case 'D':
            result = ROMAN_FALSE;
            break;

        case 'M':
            result = ROMAN_FALSE;
            break;

        default:
            result = ROMAN_FALSE;
            break;
    }

    return result;
}

RomanBool_t roman_is_valid_numeral(RomanNumeral_t *numeral)
{
    RomanCompare_t compare_result;
    RomanCount_t   consecutive_digit_count = 1;
    RomanCount_t   idx;
    RomanDigit_t   previous_digit;
    int            regex_retval;
    RomanBool_t    result = ROMAN_FALSE;
    int            toupper_digit;

    if (numeral != NULL)
    {
        if (numeral->digits != NULL)
        {
            result = ROMAN_TRUE;
            numeral->length = strlen(numeral->digits);
            /* printf("roman_is_valid_numeral: roman numeral %s has a length of %d.\n", numeral->digits, numeral->length); */
            for (idx = 0; idx<numeral->length; idx++)
            {
                /* printf("roman_is_valid_numeral: processing roman numeral digit %c index %d.\n", numeral->digits[idx], idx); */
                toupper_digit = (int)numeral->digits[idx];
                toupper_digit = toupper(toupper_digit);
                numeral->digits[idx] = (char)toupper_digit;

                if (roman_is_valid_digit(numeral->digits[idx]) == ROMAN_TRUE)
                {
                    /* printf("roman_is_valid_numeral: valid digit for roman numeral digit %c index %d.\n", numeral->digits[idx], idx); */
                    if (idx > 0)
                    {
                        compare_result = roman_digit_compare_to(numeral->digits[idx], previous_digit);
                        if (compare_result == ROMAN_DIGIT_LESSTHAN)
                        {
                            consecutive_digit_count = 1;
                        }
                        else if (compare_result == ROMAN_DIGIT_GREATERTHAN)
                        {
                            consecutive_digit_count = 1;
                            if (roman_is_valid_subtraction_pair(previous_digit, numeral->digits[idx]) == ROMAN_FALSE)
                            {
                                result = ROMAN_FALSE;
                                printf("roman_is_valid_numeral: invalid subtraction pair for input %s roman numeral digit %c previous %c index %d.\n", numeral->digits, numeral->digits[idx], previous_digit, idx);
                                break;
                            }
                        }
                        else if (compare_result == ROMAN_DIGIT_EQUALTO)
                        {
                            if (roman_is_valid_sequential_digit(numeral->digits[idx]) == ROMAN_TRUE)
                            {
                                consecutive_digit_count++;
                                if (roman_get_max_sequential_count(numeral->digits[idx]) < consecutive_digit_count)
                                {
                                    result = ROMAN_FALSE;
                                    printf("roman_is_valid_numeral: invalid max sequential count %d for input %s roman numeral digit %c previous %c index %d.\n", consecutive_digit_count, numeral->digits, numeral->digits[idx], previous_digit, idx);
                                    break;
                                }
                            }
                            else
                            {
                                result = ROMAN_FALSE;
                                printf("roman_is_valid_numeral: invalid sequential digit for input %s numeral digit %c previous %c index %d.\n", numeral->digits, numeral->digits[idx], previous_digit, idx);
                                break;
                            }
                        }
                        else
                        {
                            result = ROMAN_FALSE;
                            printf("roman_is_valid_numeral: invalid comparison return for input %s numeral digit %c previous %c index %d.\n", numeral->digits, numeral->digits[idx], previous_digit, idx);
                            break;
                        }
                        
                    }
                    previous_digit = numeral->digits[idx];
                }
                else
                {
                    result = ROMAN_FALSE;
                    printf("roman_is_valid_numeral: invalid digit for input %s roman numeral digit %c index %d.\n", numeral->digits, numeral->digits[idx], idx);
                    break;
                }
            }
        }
        else
        {
            printf("roman_is_valid_numeral: invalid digits argument (NULL) pointer passed\n");
        }
    }
    else
    {
        printf("roman_is_valid_numeral: invalid pointer argument (NULL) pointer passed\n");
    }

    if (result == ROMAN_TRUE)
    {
        /* printf("The string %s passed to the regular expression\n", numeral->digits); */
        if ((regex_retval = regexec(&roman_regular_expression, numeral->digits, 0, NULL, 0)) == 0)
        {
            /* printf("The string %s matched the regular expression\n", numeral->digits); */
        }
        else
        {
            result = ROMAN_FALSE;
            printf("The string %s did not match the regular expression\n", numeral->digits);
        } 
    }

    return result;
}

void roman_numeral_fix_term(RomanNumeral_t *numeral)
{
    RomanCount_t           idx;
    RomanNumeralCounts_t   numeral_counts;

    if (numeral != NULL)
    {
        if (numeral->digits != NULL)
        {
            if (roman_is_valid_numeral(numeral) == ROMAN_FALSE)
            {
                memset(&numeral_counts, 0, sizeof(RomanNumeralCounts_t));
                for (idx = 0; idx<numeral->length; idx++)
                {
                    switch (numeral->digits[idx])
                    {
                        case 'I':
                            numeral_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX]++;
                            break;

                        case 'V':
                            numeral_counts.digit_counts[ROMAN_DIGIT_COUNT_V_INDEX]++;
                            break;

                        case 'X':
                            numeral_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX]++;
                            break;
 
                        case 'L':
                            numeral_counts.digit_counts[ROMAN_DIGIT_COUNT_L_INDEX]++;
                            break;

                        case 'C':
                            numeral_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX]++;
                            break;

                        case 'D':
                            numeral_counts.digit_counts[ROMAN_DIGIT_COUNT_D_INDEX]++;
                            break;

                        case 'M':
                            numeral_counts.digit_counts[ROMAN_DIGIT_COUNT_M_INDEX]++;
                            break;

                        default:
                            break;
                    }
                }

                numeral->digits[0] = 0;
                numeral->length = 0;

                for (idx = (ROMAN_NUMBER_OF_DIGITS-1); idx >= 0; idx--)
                {
                    switch (idx)
                    {
                        case ROMAN_DIGIT_COUNT_I_INDEX:
                            if ((numeral_counts.digit_counts[idx] > 0) && (numeral_counts.digit_counts[idx-1] > 0))
                            {
                                numeral_counts.digit_counts[idx] = numeral_counts.digit_counts[idx] + roman_number_of_previous_counts[idx];
                                numeral_counts.digit_counts[idx-1] = 0;
                            }
                            strcat(numeral->digits, roman_numerals_for_i[numeral_counts.digit_counts[idx]]);
                            numeral->length = strlen(numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_V_INDEX:
                            strcat(numeral->digits, roman_numerals_for_v[numeral_counts.digit_counts[idx]]);
                            numeral->length = strlen(numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_X_INDEX:
                            if ((numeral_counts.digit_counts[idx] > 0) && (numeral_counts.digit_counts[idx-1] > 0))
                            {
                                numeral_counts.digit_counts[idx] = numeral_counts.digit_counts[idx] + roman_number_of_previous_counts[idx];
                                numeral_counts.digit_counts[idx-1] = 0;
                            }
                            strcat(numeral->digits, roman_numerals_for_x[numeral_counts.digit_counts[idx]]);
                            numeral->length = strlen(numeral->digits);
                            break;
 
                        case ROMAN_DIGIT_COUNT_L_INDEX:
                            strcat(numeral->digits, roman_numerals_for_l[numeral_counts.digit_counts[idx]]);
                            numeral->length = strlen(numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_C_INDEX:
                            if ((numeral_counts.digit_counts[idx] > 0) && (numeral_counts.digit_counts[idx-1] > 0))
                            {
                                numeral_counts.digit_counts[idx] = numeral_counts.digit_counts[idx] + roman_number_of_previous_counts[idx];
                                numeral_counts.digit_counts[idx-1] = 0;
                            }
                            strcat(numeral->digits, roman_numerals_for_c[numeral_counts.digit_counts[idx]]);
                            numeral->length = strlen(numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_D_INDEX:
                            strcat(numeral->digits, roman_numerals_for_d[numeral_counts.digit_counts[idx]]);
                            numeral->length = strlen(numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_M_INDEX:
                            strcat(numeral->digits, roman_numerals_for_m[numeral_counts.digit_counts[idx]]);
                            numeral->length = strlen(numeral->digits);
                            break;

                        default:
                            break;
                    }
                }
            }
        }
    }
}

RomanBool_t roman_numeral_get_add_term(RomanNumeral_t *numeral, RomanNumeral_t *numeral_to_add)
{
    RomanCompare_t compare_result;
    RomanCount_t   consecutive_digit_count = 1;
    RomanCount_t   idx;
    RomanDigit_t   previous_digit;
    int            remaining_length;
    RomanBool_t    result = ROMAN_FALSE;

    if ((numeral != NULL) && (numeral_to_add != NULL))
    {
        if ((numeral->digits != NULL) && (numeral_to_add->digits != NULL))
        {
            numeral_to_add->length = 0;
            numeral_to_add->digits[0] = 0;

            result = ROMAN_TRUE;

            numeral->length = strlen(numeral->digits);
            for (idx = 0; idx<numeral->length; idx++)
            {
                numeral->digits[idx] = (char)toupper((int)numeral->digits[idx]);
                if (roman_is_valid_digit(numeral->digits[idx]) == ROMAN_TRUE)
                {
                    if (idx > 0)
                    {
                        compare_result = roman_digit_compare_to(numeral->digits[idx], previous_digit);
                        if (compare_result == ROMAN_DIGIT_LESSTHAN)
                        {
                            consecutive_digit_count = 1;
                        }
                        else if (compare_result == ROMAN_DIGIT_GREATERTHAN)
                        {
                            consecutive_digit_count = 1;
                            if (roman_is_valid_subtraction_pair(previous_digit, numeral->digits[idx]) == ROMAN_FALSE)
                            {
                                result = ROMAN_FALSE;
                                printf("roman_numeral_get_add_term: invalid subtraction pair roman numeral digit %c previous %c index %d.\n", numeral->digits[idx], previous_digit, idx);
                                break;
                            }
                            else
                            {
                                numeral_to_add->digits[numeral_to_add->length] = previous_digit;
                                numeral_to_add->length++;
                                numeral_to_add->digits[numeral_to_add->length] = 0;
                                remaining_length = numeral->length - idx;
                                memcpy(&numeral->digits[idx-1], &numeral->digits[idx], remaining_length);
                                numeral->length--;
                                numeral->digits[numeral->length] = 0;
                            }
                        }
                        else if (compare_result == ROMAN_DIGIT_EQUALTO)
                        {
                            if (roman_is_valid_sequential_digit(numeral->digits[idx]) == ROMAN_TRUE)
                            {
                                consecutive_digit_count++;
                                if (roman_get_max_sequential_count(numeral->digits[idx]) < consecutive_digit_count)
                                {
                                    result = ROMAN_FALSE;
                                    printf("roman_numeral_get_add_term: invalid max sequential count roman numeral digit %c previous %c index %d.\n", numeral->digits[idx], previous_digit, idx);
                                    break;
                                }
                            }
                            else
                            {
                                result = ROMAN_FALSE;
                                printf("roman_numeral_get_add_term: invalid sequential roman numeral digit %c previous %c index %d.\n", numeral->digits[idx], previous_digit, idx);
                                break;
                            }
                        }
                        else
                        {
                            result = ROMAN_FALSE;
                            printf("roman_numeral_get_add_term: invalid comparison return numeral digit %c previous %c index %d.\n", numeral->digits[idx], previous_digit, idx);
                            break;
                        }
                        
                    }
                    previous_digit = numeral->digits[idx];
                }
                else
                {
                    result = ROMAN_FALSE;
                    printf("roman_numeral_get_add_term: invalid digit for roman numeral digit %c index %d.\n", numeral->digits[idx], idx);
                    break;
                }
            }
        }
    }

    if (result == ROMAN_TRUE)
    {
        if (numeral_to_add->length > 0)
        {
            /* printf("A numeral add term %s was generated with length = %d.\n", numeral_to_add->digits, numeral_to_add->length); */
        }
        else
        {
            result = ROMAN_FALSE;
        } 
    }

    return result;
}

RomanBool_t roman_numeral_add_terms(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *addition_numeral)
{
    RomanDigit_t           digit;
    RomanCount_t           extra_counts;
    RomanCount_t           idx;
    RomanNumeralCounts_t   numeral1_counts;
    RomanNumeralCounts_t   numeral2_counts;
    RomanNumeralCounts_t   numeral_result_counts;
    RomanDigit_t           previous_digit = ' ';
    RomanBool_t            result;
    RomanBool_t            valid_subtract_pair;

    if ((numeral1 != NULL) && (numeral2 != NULL))
    {
        if ((numeral1->digits != NULL) && (numeral2->digits != NULL))
        {
            /* if ((roman_is_valid_numeral(numeral1) == ROMAN_TRUE) && (roman_is_valid_numeral(numeral2) == ROMAN_TRUE)) */
            /* { */
                memset(&numeral_result_counts, 0, sizeof(RomanNumeralCounts_t));

                result = ROMAN_TRUE;

                memset(&numeral1_counts, 0, sizeof(RomanNumeralCounts_t));
                for (idx = 0; idx<numeral1->length; idx++)
                {
                    valid_subtract_pair = roman_is_valid_subtraction_pair(previous_digit, numeral1->digits[idx]);
                    switch (numeral1->digits[idx])
                    {
                        case 'I':
                            numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX]++;
                            break;

                        case 'V':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_V_INDEX]++;
                            }
                            else
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX] += 3;
                            }
                            break;

                        case 'X':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX]++;
                            }
                            else
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX] += 8;
                            }
                            break;
 
                        case 'L':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_L_INDEX]++;
                            }
                            else
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX] += 3;
                            }
                            break;

                        case 'C':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX]++;
                            }
                            else
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX] += 8;
                            }
                            break;

                        case 'D':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_D_INDEX]++;
                            }
                            else
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX] += 3;
                            }
                            break;

                        case 'M':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_M_INDEX]++;
                            }
                            else
                            {
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX] += 8;
                            }
                            break;

                        default:
                            break;
                    }
                    previous_digit = numeral1->digits[idx];
                }

                previous_digit = ' ';
                memset(&numeral2_counts, 0, sizeof(RomanNumeralCounts_t));
                for (idx = 0; idx<numeral2->length; idx++)
                {
                    valid_subtract_pair = roman_is_valid_subtraction_pair(previous_digit, numeral2->digits[idx]);
                    switch (numeral2->digits[idx])
                    {
                        case 'I':
                            numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX]++;
                            break;

                        case 'V':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_V_INDEX]++;
                            }
                            else
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX] += 3;
                            }
                            break;

                        case 'X':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX]++;
                            }
                            else
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX] += 8;
                            }
                            break;
 
                        case 'L':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_L_INDEX]++;
                            }
                            else
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX] += 3;
                            }
                            break;

                        case 'C':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX]++;
                            }
                            else
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX] += 8;
                            }
                            break;

                        case 'D':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_D_INDEX]++;
                            }
                            else
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX] += 3;
                            }
                            break;

                        case 'M':
                            if (valid_subtract_pair == ROMAN_FALSE)
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_M_INDEX]++;
                            }
                            else
                            {
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX] += 8;
                            }
                            break;

                        default:
                            break;
                    } 
                    previous_digit = numeral2->digits[idx];
                }

                for (idx = (ROMAN_NUMBER_OF_DIGITS-1); idx >= 0; idx--)
                {
                    /* printf("roman_numeral_add_terms: numeral1_counts.digit_counts[%d]=%d\n", idx, numeral1_counts.digit_counts[idx]); */
                    /* printf("roman_numeral_add_terms: numeral2_counts.digit_counts[%d]=%d\n", idx, numeral2_counts.digit_counts[idx]); */
                    numeral_result_counts.digit_counts[idx] = numeral_result_counts.digit_counts[idx] + numeral1_counts.digit_counts[idx] + numeral2_counts.digit_counts[idx];
                    if (numeral_result_counts.digit_counts[idx] >= roman_number_of_previous_counts[idx])
                    {
                        if (idx > 0)
                        {
                            extra_counts = numeral_result_counts.digit_counts[idx] / roman_number_of_previous_counts[idx];
                            numeral_result_counts.digit_counts[(idx-1)] = numeral_result_counts.digit_counts[(idx-1)] + extra_counts;
                            /* printf("roman_numeral_add_terms: numeral_result_counts.digit_counts[%d]=%d\n", (idx-1), numeral_result_counts.digit_counts[(idx-1)]); */
                        }
                        numeral_result_counts.digit_counts[idx] = numeral_result_counts.digit_counts[idx] % roman_number_of_previous_counts[idx];
                    }
                    /* printf("roman_numeral_add_terms: numeral_result_counts.digit_counts[%d]=%d\n", idx, numeral_result_counts.digit_counts[idx]); */
                }

                addition_numeral->digits[0] = 0;
                addition_numeral->length = 0;
                for (idx = 0; idx < ROMAN_NUMBER_OF_DIGITS; idx++)
                {
                    /* printf("roman_numeral_add_terms: numeral_result_counts.digit_counts[%d]=%d\n", idx, numeral_result_counts.digit_counts[idx]); */
                    switch (idx)
                    {
                        case ROMAN_DIGIT_COUNT_I_INDEX:
                            strcat(addition_numeral->digits, roman_numerals_for_i[numeral_result_counts.digit_counts[idx]]);
                            addition_numeral->length = strlen(addition_numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_V_INDEX:
                            if ((numeral_result_counts.digit_counts[idx] > 0) && (numeral_result_counts.digit_counts[idx+1] > 0))
                            {
                                numeral_result_counts.digit_counts[idx+1] = numeral_result_counts.digit_counts[idx+1] + roman_number_of_previous_counts[idx+1];
                                numeral_result_counts.digit_counts[idx] = 0;
                            }
                            strcat(addition_numeral->digits, roman_numerals_for_v[numeral_result_counts.digit_counts[idx]]);
                            addition_numeral->length = strlen(addition_numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_X_INDEX:
                            strcat(addition_numeral->digits, roman_numerals_for_x[numeral_result_counts.digit_counts[idx]]);
                            addition_numeral->length = strlen(addition_numeral->digits);
                            break;
 
                        case ROMAN_DIGIT_COUNT_L_INDEX:
                            if ((numeral_result_counts.digit_counts[idx] > 0) && (numeral_result_counts.digit_counts[idx+1] > 0))
                            {
                                numeral_result_counts.digit_counts[idx+1] = numeral_result_counts.digit_counts[idx+1] + roman_number_of_previous_counts[idx+1];
                                numeral_result_counts.digit_counts[idx] = 0;
                            }
                            strcat(addition_numeral->digits, roman_numerals_for_l[numeral_result_counts.digit_counts[idx]]);
                            addition_numeral->length = strlen(addition_numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_C_INDEX:
                            strcat(addition_numeral->digits, roman_numerals_for_c[numeral_result_counts.digit_counts[idx]]);
                            addition_numeral->length = strlen(addition_numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_D_INDEX:
                            if ((numeral_result_counts.digit_counts[idx] > 0) && (numeral_result_counts.digit_counts[idx+1] > 0))
                            {
                                numeral_result_counts.digit_counts[idx+1] = numeral_result_counts.digit_counts[idx+1] + roman_number_of_previous_counts[idx+1];
                                numeral_result_counts.digit_counts[idx] = 0;
                            }
                            strcat(addition_numeral->digits, roman_numerals_for_d[numeral_result_counts.digit_counts[idx]]);
                            addition_numeral->length = strlen(addition_numeral->digits);
                            break;

                        case ROMAN_DIGIT_COUNT_M_INDEX:
                            strcat(addition_numeral->digits, roman_numerals_for_m[numeral_result_counts.digit_counts[idx]]);
                            addition_numeral->length = strlen(addition_numeral->digits);
                            break;

                        default:
                            result = ROMAN_FALSE;
                            break;
                    }
                    /* printf("roman_numeral_add_terms: numeral_result_counts.digit_counts[%d]=%d\n", idx, numeral_result_counts.digit_counts[idx]); */
                }
            /* } */
        }
    }

    if (result == ROMAN_TRUE)
    {
        /* printf("roman_numeral_add_terms: A numeral %s plus numeral %s equals %s.\n", numeral1->digits, numeral2->digits, addition_numeral->digits); */
    }
    else
    {
        addition_numeral->digits[0] = 0;
        addition_numeral->length = 0;
    } 

    return result;
}

RomanCompare_t roman_numeral_compare_subtract_terms(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2)
{
    RomanCount_t           idx;
    RomanNumeralCounts_t   numeral1_counts;
    RomanNumeralCounts_t   numeral2_counts;
    RomanCompare_t         result = ROMAN_DIGIT_INVALID;

    if ((numeral1 != NULL) && (numeral2 != NULL))
    {
        if ((numeral1->digits != NULL) && (numeral2->digits != NULL))
        {
            if ((roman_is_valid_numeral(numeral1) == ROMAN_TRUE) && (roman_is_valid_numeral(numeral2) == ROMAN_TRUE))
            {
                memset(&numeral1_counts, 0, sizeof(RomanNumeralCounts_t));
                for (idx = 0; idx<numeral1->length; idx++)
                {
                    switch (numeral1->digits[idx])
                    {
                        case 'I':
                            numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX]++;
                            break;

                        case 'V':
                            numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_V_INDEX]++;
                            break;

                        case 'X':
                            numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX]++;
                            break;
 
                        case 'L':
                            numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_L_INDEX]++;
                            break;

                        case 'C':
                            numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX]++;
                            break;

                        case 'D':
                            numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_D_INDEX]++;
                            break;

                        case 'M':
                            numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_M_INDEX]++;
                            break;

                        default:
                            break;
                    }
                }

                memset(&numeral2_counts, 0, sizeof(RomanNumeralCounts_t));
                for (idx = 0; idx<numeral2->length; idx++)
                {
                    switch (numeral2->digits[idx])
                    {
                        case 'I':
                            numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX]++;
                            break;

                        case 'V':
                            numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_V_INDEX]++;
                            break;

                        case 'X':
                            numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX]++;
                            break;
 
                        case 'L':
                            numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_L_INDEX]++;
                            break;

                        case 'C':
                            numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX]++;
                            break;

                        case 'D':
                            numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_D_INDEX]++;
                            break;

                        case 'M':
                            numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_M_INDEX]++;
                            break;

                        default:
                            break;
                    }
                }

                result = ROMAN_DIGIT_EQUALTO;
                /* Check to ensure the first operand is larger than the second operand. */
                for (idx = 0; idx < ROMAN_NUMBER_OF_DIGITS; idx++)
                {
                    if (numeral1_counts.digit_counts[idx] == numeral2_counts.digit_counts[idx])
                    {
                    }
                    else if (numeral1_counts.digit_counts[idx] > numeral2_counts.digit_counts[idx])
                    {
                        result = ROMAN_DIGIT_GREATERTHAN;
                        break;
                    }
                    else
                    {
                        result = ROMAN_DIGIT_LESSTHAN;
                        break;
                    }
                }
            }
        }
    }

    return result;
}

RomanBool_t roman_numeral_subtract_terms(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *subtraction_numeral)
{
    RomanCompare_t         compare_result;
    RomanCount_t           idx;
    RomanCount_t           idx2;
    RomanCount_t           idx3;
    RomanNumeralCounts_t   numeral1_counts;
    RomanNumeralCounts_t   numeral2_counts;
    RomanNumeralCounts_t   numeral_result_counts;
    RomanDigit_t           previous_digit = ' ';
    RomanBool_t            result = ROMAN_FALSE;
    RomanBool_t            valid_subtract_pair;

    if ((numeral1 != NULL) && (numeral2 != NULL) && (subtraction_numeral != NULL))
    {
        if ((numeral1->digits != NULL) && (numeral2->digits != NULL) && (subtraction_numeral->digits != NULL))
        {
            /* if ((roman_is_valid_numeral(numeral1) == ROMAN_TRUE) && (roman_is_valid_numeral(numeral2) == ROMAN_TRUE)) */
            /* { */
                memset(&numeral_result_counts, 0, sizeof(RomanNumeralCounts_t));
                compare_result = roman_numeral_compare_subtract_terms(numeral1, numeral2);
                if ((compare_result == ROMAN_DIGIT_GREATERTHAN) || (compare_result == ROMAN_DIGIT_EQUALTO))
                {
                    result = ROMAN_TRUE;
                    memset(&numeral1_counts, 0, sizeof(RomanNumeralCounts_t));
                    for (idx = 0; idx<numeral1->length; idx++)
                    {
                        valid_subtract_pair = roman_is_valid_subtraction_pair(previous_digit, numeral1->digits[idx]);
                        switch (numeral1->digits[idx])
                        {
                            case 'I':
                                numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX]++;
                                break;

                            case 'V':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_V_INDEX]++;
                                }
                                else
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX] += 3;
                                }
                                break;

                            case 'X':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX]++;
                                }
                                else
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX] += 8;
                                }
                                break;
 
                            case 'L':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_L_INDEX]++;
                                }
                                else
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX] += 3;
                                }
                                break;

                            case 'C':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX]++;
                                }
                                else
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX] += 8;
                                }
                                break;

                            case 'D':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_D_INDEX]++;
                                }
                                else
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX] += 3;
                                }
                                break;

                            case 'M':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_M_INDEX]++;
                                }
                                else
                                {
                                    numeral1_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX] += 8;
                                }
                                break;

                            default:
                                result = ROMAN_FALSE;
                                break;
                        }
                        previous_digit = numeral1->digits[idx];
                    }

                    previous_digit = ' ';
                    memset(&numeral2_counts, 0, sizeof(RomanNumeralCounts_t));
                    for (idx = 0; idx<numeral2->length; idx++)
                    {
                        valid_subtract_pair = roman_is_valid_subtraction_pair(previous_digit, numeral2->digits[idx]);
                        switch (numeral2->digits[idx])
                        {
                            case 'I':
                                numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX]++;
                                break;

                            case 'V':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_V_INDEX]++;
                                }
                                else
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX] += 3;
                                }
                                break;

                            case 'X':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX]++;
                                }
                                else
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_I_INDEX] += 8;
                                }
                                break;
 
                            case 'L':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_L_INDEX]++;
                                }
                                else
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX] += 3;
                                }
                                break;

                            case 'C':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX]++;
                                }
                                else
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_X_INDEX] += 8;
                                }
                                break;

                            case 'D':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_D_INDEX]++;
                                }
                                else
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX] += 3;
                                }
                                break;

                            case 'M':
                                if (valid_subtract_pair == ROMAN_FALSE)
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_M_INDEX]++;
                                }
                                else
                                {
                                    numeral2_counts.digit_counts[ROMAN_DIGIT_COUNT_C_INDEX] += 8;
                                }
                                break;

                            default:
                                result = ROMAN_FALSE;
                                break;
                        }
                        previous_digit = numeral2->digits[idx];
                    }

                    for (idx = (ROMAN_NUMBER_OF_DIGITS-1); idx >= 0; idx--)
                    {
                        /* printf("roman_numeral_subtract_terms: numeral1_counts.digit_counts[%d]=%d\n", idx, numeral1_counts.digit_counts[idx]); */
                        /* printf("roman_numeral_subtract_terms: numeral2_counts.digit_counts[%d]=%d\n", idx, numeral2_counts.digit_counts[idx]); */
                        if (numeral1_counts.digit_counts[idx] < numeral2_counts.digit_counts[idx])
                        {
                            for (idx2 = (idx-1); idx2 >= 0; idx2--)
                            {
                                if (numeral1_counts.digit_counts[idx2] > 0)
                                {
                                    numeral1_counts.digit_counts[idx2] = numeral1_counts.digit_counts[idx2] - 1;
                                    /* printf("roman_numeral_subtract_terms: numeral1_counts.digit_counts[%d]=%d\n", idx2, numeral1_counts.digit_counts[idx2]); */
                                    for (idx3 = (idx2+1); idx3 <= idx; idx3++)
                                    {
                                        if (idx3 != idx)
                                        {
                                            numeral1_counts.digit_counts[idx3] += (roman_number_of_previous_counts[idx3]-1);
                                        }
                                        else
                                        {
                                            numeral1_counts.digit_counts[idx3] += (roman_number_of_previous_counts[idx3]);
                                        }
                                        /* printf("roman_numeral_subtract_terms: numeral1_counts.digit_counts[%d]=%d\n", idx3, numeral1_counts.digit_counts[idx3]); */
                                    }
                                    break;
                                }
                            }
                        }
                        numeral_result_counts.digit_counts[idx] = numeral1_counts.digit_counts[idx] - numeral2_counts.digit_counts[idx];
                        /* printf("roman_numeral_subtract_terms: numeral_result_counts.digit_counts[%d]=%d\n", idx, numeral_result_counts.digit_counts[idx]); */
                    }

                    subtraction_numeral->digits[0] = 0;
                    subtraction_numeral->length = 0;

                    for (idx = 0; idx < ROMAN_NUMBER_OF_DIGITS; idx++)
                    {
                        /* printf("roman_numeral_subtract_terms: numeral_result_counts.digit_counts[%d]=%d\n", idx, numeral_result_counts.digit_counts[idx]); */
                        switch (idx)
                        {
                            case ROMAN_DIGIT_COUNT_I_INDEX:
                                strcat(subtraction_numeral->digits, roman_numerals_for_i[numeral_result_counts.digit_counts[idx]]);
                                subtraction_numeral->length = strlen(subtraction_numeral->digits);
                                break;

                            case ROMAN_DIGIT_COUNT_V_INDEX:
                                if ((numeral_result_counts.digit_counts[idx] > 0) && (numeral_result_counts.digit_counts[idx+1] > 0))
                                {
                                    numeral_result_counts.digit_counts[idx+1] = numeral_result_counts.digit_counts[idx+1] + roman_number_of_previous_counts[idx+1];
                                    numeral_result_counts.digit_counts[idx] = 0;
                                }
                                strcat(subtraction_numeral->digits, roman_numerals_for_v[numeral_result_counts.digit_counts[idx]]);
                                subtraction_numeral->length = strlen(subtraction_numeral->digits);
                                break;

                            case ROMAN_DIGIT_COUNT_X_INDEX:
                                strcat(subtraction_numeral->digits, roman_numerals_for_x[numeral_result_counts.digit_counts[idx]]);
                                subtraction_numeral->length = strlen(subtraction_numeral->digits);
                                break;
 
                            case ROMAN_DIGIT_COUNT_L_INDEX:
                                if ((numeral_result_counts.digit_counts[idx] > 0) && (numeral_result_counts.digit_counts[idx+1] > 0))
                                {
                                    numeral_result_counts.digit_counts[idx+1] = numeral_result_counts.digit_counts[idx+1] + roman_number_of_previous_counts[idx+1];
                                    numeral_result_counts.digit_counts[idx] = 0;
                                }
                                strcat(subtraction_numeral->digits, roman_numerals_for_l[numeral_result_counts.digit_counts[idx]]);
                                subtraction_numeral->length = strlen(subtraction_numeral->digits);
                                break;

                            case ROMAN_DIGIT_COUNT_C_INDEX:
                                strcat(subtraction_numeral->digits, roman_numerals_for_c[numeral_result_counts.digit_counts[idx]]);
                                subtraction_numeral->length = strlen(subtraction_numeral->digits);
                                break;

                            case ROMAN_DIGIT_COUNT_D_INDEX:
                                if ((numeral_result_counts.digit_counts[idx] > 0) && (numeral_result_counts.digit_counts[idx+1] > 0))
                                {
                                    numeral_result_counts.digit_counts[idx+1] = numeral_result_counts.digit_counts[idx+1] + roman_number_of_previous_counts[idx+1];
                                    numeral_result_counts.digit_counts[idx] = 0;
                                }
                                strcat(subtraction_numeral->digits, roman_numerals_for_d[numeral_result_counts.digit_counts[idx]]);
                                subtraction_numeral->length = strlen(subtraction_numeral->digits);
                                break;

                            case ROMAN_DIGIT_COUNT_M_INDEX:
                                strcat(subtraction_numeral->digits, roman_numerals_for_m[numeral_result_counts.digit_counts[idx]]);
                                subtraction_numeral->length = strlen(subtraction_numeral->digits);
                                break;

                            default:
                                result = ROMAN_FALSE;
                                break;
                        }
                        /* printf("roman_numeral_subtract_terms: numeral_result_counts.digit_counts[%d]=%d\n", idx, numeral_result_counts.digit_counts[idx]); */
                    }
                }
            /* } */
        }
    }


    if (result == ROMAN_TRUE)
    {
        /* printf("roman_numeral_subtract_terms: A numeral %s minus numeral %s equals %s.\n", numeral1->digits, numeral2->digits, subtraction_numeral->digits); */
    }
    else
    {
        subtraction_numeral->digits[0] = 0;
        subtraction_numeral->length = 0;
    } 

    return result;
}

RomanBool_t roman_numeral_add(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *addition_numeral)
{
    RomanBool_t    add_term_result;
    RomanDigit_t   blank_digits[80];
    RomanCount_t   consecutive_digit_count = 1;
    RomanDigit_t   digits1[80];
    RomanDigit_t   digits2[80];
    RomanBool_t    get_subtract_term_result1 = ROMAN_FALSE;
    RomanBool_t    get_subtract_term_result2 = ROMAN_FALSE;
    RomanNumeral_t numeral_blank;
    RomanNumeral_t numeral_to_subtract1;
    RomanNumeral_t numeral_to_subtract2;
    RomanNumeral_t numeral_result1;
    RomanNumeral_t numeral_result2;
    RomanBool_t    result;
    RomanDigit_t   result_digits1[80];
    RomanDigit_t   result_digits2[80];
    RomanBool_t    subtract_term_result;


    if ((numeral1 != NULL) && (numeral2 != NULL) && (addition_numeral != NULL))
    {
        if ((numeral1->digits != NULL) && (numeral2->digits != NULL) && (addition_numeral->digits != NULL))
        {
            addition_numeral->digits[0] = 0;
            addition_numeral->length = 0;

            if ((roman_is_valid_numeral(numeral1) == ROMAN_TRUE) && (roman_is_valid_numeral(numeral2) == ROMAN_TRUE))
            {
                result = ROMAN_TRUE;

#if 0
                numeral_to_subtract1.digits = digits1;
                numeral_to_subtract1.digits[0] = 0;
                numeral_to_subtract1.length = 0;
                printf("roman_numeral_add: Checking for numeral subtract term 1 for input %s with length = %d.\n", numeral1->digits, numeral1->length);
                get_subtract_term_result1 = roman_numeral_get_add_term(numeral1, &numeral_to_subtract1);
                if (get_subtract_term_result1 == ROMAN_TRUE)
                {
                    printf("roman_numeral_add: A numeral subtract term 1 %s was generated with length = %d.\n", numeral_to_subtract1.digits, numeral_to_subtract1.length);
#if 0
                    roman_numeral_fix_term(numeral1);
                    printf("roman_numeral_add: A numeral 1 %s was fixed with length = %d.\n", numeral1->digits, numeral1->length);
#endif
                }
#endif

#if 0
                numeral_to_subtract2.digits = digits2;
                numeral_to_subtract2.digits[0] = 0;
                numeral_to_subtract2.length = 0;
                printf("roman_numeral_add: Checking for numeral subtract term 2 for input %s with length = %d.\n", numeral2->digits, numeral2->length);
                get_subtract_term_result2 = roman_numeral_get_add_term(numeral2, &numeral_to_subtract2);
                if (get_subtract_term_result2 == ROMAN_TRUE)
                {
                    printf("roman_numeral_add: A numeral subtract term 2 %s was generated with length = %d.\n", numeral_to_subtract2.digits, numeral_to_subtract2.length);
#if 0
                    roman_numeral_fix_term(numeral2);
                    printf("roman_numeral_add: A numeral 2 %s was fixed with length = %d.\n", numeral2->digits, numeral2->length);
#endif
                }

#endif
                numeral_result1.digits = result_digits1;
                numeral_result1.digits[0] = 0;
                numeral_result1.length = 0;
                numeral_result2.digits = result_digits2;
                numeral_result2.digits[0] = 0;
                numeral_result2.length = 0;

                add_term_result = roman_numeral_add_terms(numeral1, numeral2, &numeral_result1);
                if (add_term_result == ROMAN_TRUE)
                {
                    /* printf("roman_numeral_add:1 A numeral 1 %s plus numeral 2 %s equals = %s.\n", numeral1->digits, numeral2->digits, numeral_result1.digits); */
                }
                else
                {
                    result = ROMAN_FALSE;
                    printf("roman_numeral_add:1 Error adding numeral 1 %s plus numeral 2 %s.\n", numeral1->digits, numeral2->digits);
                }
 
#if 0
                if (get_subtract_term_result1 == ROMAN_TRUE)
                {
                    strcpy(numeral_result2.digits, numeral_result1.digits);
                    numeral_result2.length = numeral_result1.length;
                    subtract_term_result = roman_numeral_subtract(&numeral_result2, &numeral_to_subtract1, &numeral_result1);
                    if (subtract_term_result == ROMAN_TRUE)
                    {
                        printf("roman_numeral_add:3 A numeral 1 %s minus numeral 2 %s equals = %s.\n", numeral_result2.digits, numeral_to_subtract1.digits, numeral_result1.digits);
                    }
                    else
                    {
                        result = ROMAN_FALSE;
                        printf("roman_numeral_add:3 Error subtracting numeral 1 %s minus numeral 2 %s.\n", numeral_result2.digits, numeral_to_subtract1.digits);
                    }
                } 
#endif
 
#if 0
                if (get_subtract_term_result2 == ROMAN_TRUE)
                {
                    strcpy(numeral_result2.digits, numeral_result1.digits);
                    numeral_result2.length = numeral_result1.length;
                    subtract_term_result = roman_numeral_subtract(&numeral_result2, &numeral_to_subtract2, &numeral_result1);
                    if (subtract_term_result == ROMAN_TRUE)
                    {
                        printf("roman_numeral_add:4 A numeral 1 %s minus numeral 2 %s equals = %s.\n", numeral_result2.digits, numeral_to_subtract2.digits, numeral_result1.digits);
                    }
                    else
                    {
                        result = ROMAN_FALSE;
                        printf("roman_numeral_add:4 Error adding numeral 1 %s plus numeral 2 %s.\n", numeral_result2.digits, numeral_to_subtract2.digits);
                    }
                } 
#endif

                strcpy(addition_numeral->digits, numeral_result1.digits);
                addition_numeral->length = numeral_result1.length;
            }
        }
    }

    if (result == ROMAN_TRUE)
    {
        if (addition_numeral->length > 0)
        {
            printf("roman_numeral_add: A numeral 1 term %s plus numeral 2 term %s equals %s.\n", numeral1->digits, numeral2->digits, addition_numeral->digits);
        }
        else
        {
            result = ROMAN_FALSE;
        } 
    }

    return result;
}

RomanBool_t roman_numeral_subtract(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *subtraction_numeral)
{
    RomanBool_t    add_term_result;
    RomanCount_t   consecutive_digit_count = 1;
    RomanDigit_t   digits1[80];
    RomanDigit_t   digits2[80];
    RomanBool_t    get_add_term_result1 = ROMAN_FALSE;
    RomanBool_t    get_add_term_result2 = ROMAN_FALSE;
    RomanNumeral_t numeral_to_add1;
    RomanNumeral_t numeral_to_add2;
    RomanNumeral_t numeral_result1;
    RomanNumeral_t numeral_result2;
    RomanBool_t    result;
    RomanDigit_t   result_digits1[80];
    RomanDigit_t   result_digits2[80];
    RomanBool_t    subtract_term_result;

    if ((numeral1 != NULL) && (numeral2 != NULL) && (subtraction_numeral != NULL))
    {
        if ((numeral1->digits != NULL) && (numeral2->digits != NULL) && (subtraction_numeral->digits != NULL))
        {
            subtraction_numeral->digits[0] = 0;
            subtraction_numeral->length = 0;

            if ((roman_is_valid_numeral(numeral1) == ROMAN_TRUE) && (roman_is_valid_numeral(numeral2) == ROMAN_TRUE))
            {
                result = ROMAN_TRUE;

#if 0
                numeral_to_add1.digits = digits1;
                numeral_to_add1.digits[0] = 0;
                numeral_to_add1.length = 0;
                get_add_term_result1 = roman_numeral_get_add_term(numeral1, &numeral_to_add1);
                if (get_add_term_result1 == ROMAN_TRUE)
                {
                    printf("roman_numeral_subtract: A numeral add term 1 %s was generated with length = %d.\n", numeral_to_add1.digits, numeral_to_add1.length);
#if 0
                    roman_numeral_fix_term(numeral1);
                    printf("roman_numeral_subtract: A numeral 1 %s was fixed with length = %d.\n", numeral1->digits, numeral1->length);
#endif
                }
#endif

#if 0
                numeral_to_add2.digits = digits2;
                numeral_to_add2.digits[0] = 0;
                numeral_to_add2.length = 0;
                get_add_term_result2 = roman_numeral_get_add_term(numeral2, &numeral_to_add2);
                if (get_add_term_result2 == ROMAN_TRUE)
                {
                    printf("roman_numeral_subtract: A numeral add term 2 %s was generated with length = %d.\n", numeral_to_add2.digits, numeral_to_add2.length);
#if 0
                    roman_numeral_fix_term(numeral2);
                    printf("roman_numeral_subtract: A numeral 2 %s was fixed with length = %d.\n", numeral2->digits, numeral2->length);
#endif
                }

#endif
                numeral_result1.digits = result_digits1;
                numeral_result1.digits[0] = 0;
                numeral_result1.length = 0;
                numeral_result2.digits = result_digits2;
                numeral_result2.digits[0] = 0;
                numeral_result2.length = 0;

                add_term_result = roman_numeral_subtract_terms(numeral1, numeral2, &numeral_result1);
                if (add_term_result == ROMAN_TRUE)
                {
                    /* printf("roman_numeral_subtract:1 A numeral 1 %s minus numeral 2 %s equals = %s.\n", numeral1->digits, numeral2->digits, numeral_result1.digits); */
 
                    if (get_add_term_result1 == ROMAN_TRUE)
                    {
                        strcpy(numeral_result2.digits, numeral_result1.digits);
                        numeral_result2.length = numeral_result1.length;
                        add_term_result = roman_numeral_subtract(&numeral_result2, &numeral_to_add1, &numeral_result1);
                        if (add_term_result == ROMAN_TRUE)
                        {
                            printf("roman_numeral_subtract:2 A numeral 1 %s plus numeral 2 %s equals = %s.\n", numeral_result2.digits, numeral_to_add1.digits, numeral_result1.digits);
                        }
                        else
                        {
                            result = ROMAN_FALSE;
                            printf("roman_numeral_subtract:2 Error adding numeral 1 %s plus numeral 2 %s.\n", numeral_result2.digits, numeral_to_add1.digits);
                        }
                    } 
 
                    if (get_add_term_result2 == ROMAN_TRUE)
                    {
                        strcpy(numeral_result2.digits, numeral_result1.digits);
                        numeral_result2.length = numeral_result1.length;
                        subtract_term_result = roman_numeral_add(&numeral_result2, &numeral_to_add2, &numeral_result1);
                        if (subtract_term_result == ROMAN_TRUE)
                        {
                            printf("roman_numeral_subtract:2 A numeral 1 %s plus numeral 2 %s equals = %s.\n", numeral_result2.digits, numeral_to_add2.digits, numeral_result1.digits);
                        }
                        else
                        {
                            result = ROMAN_FALSE;
                            printf("roman_numeral_subtract:2 Error adding numeral 1 %s plus numeral 2 %s.\n", numeral_result2.digits, numeral_to_add2.digits);
                        }
                    } 

                    strcpy(subtraction_numeral->digits, numeral_result1.digits);
                    subtraction_numeral->length = numeral_result1.length;
                }
                else
                {
                    result = ROMAN_FALSE;
                    printf("roman_numeral_subtract:4 Error subtracting numeral 1 %s minus numeral 2 %s.\n", numeral1->digits, numeral2->digits);
                }
            }
        }
    }

    if (result == ROMAN_TRUE)
    {
        if (subtraction_numeral->length >= 0)
        {
            printf("roman_numeral_subtract: A numeral 1 term %s minus numeral 2 term %s equals %s.\n", numeral1->digits, numeral2->digits, subtraction_numeral->digits);
        }
        else
        {
            result = ROMAN_FALSE;
        } 
    }

    return result;
}

