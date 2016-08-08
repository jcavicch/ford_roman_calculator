/* Include Files */

#include "roman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <regex.h>

#define ROMAN_REGULAR_EXPRESSION  "(^M*(C[MD]|D?C{0,3})(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})$)"

#define ROMAN_DIGIT_COUNT_M_INDEX    (0)
#define ROMAN_DIGIT_COUNT_D_INDEX    (1)
#define ROMAN_DIGIT_COUNT_C_INDEX    (2)
#define ROMAN_DIGIT_COUNT_L_INDEX    (3)
#define ROMAN_DIGIT_COUNT_X_INDEX    (4)
#define ROMAN_DIGIT_COUNT_V_INDEX    (5)
#define ROMAN_DIGIT_COUNT_I_INDEX    (6)
#define ROMAN_NUMBER_OF_DIGITS       (7)

/* Tyepdefs */

typedef struct 
{
    RomanCount_t  digit_counts[ROMAN_NUMBER_OF_DIGITS];
} RomanNumeralCounts_t;

/* Variables */

static regex_t roman_regular_expression;

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

/*------------------------------------------------------------------------------------------------------------*/
/* roman_initialize_library()                                                                                 */
/*                                                                                                            */
/* Description: Responsible for initializing the roman numeral regular expression handling.                   */
/*                                                                                                            */
/* Inputs: None                                                                                               */
/*                                                                                                            */
/* Outputs: None                                                                                              */
/*                                                                                                            */
/* Return: None                                                                                               */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
RomanBool_t roman_initialize_library()
{
    RomanBool_t result;
    int status;

    /* Compile a regular expression denoting a valid roman numeral string. */
    status = regcomp(&roman_regular_expression, ROMAN_REGULAR_EXPRESSION, REG_EXTENDED);
    if (status != 0)
    {
        printf("Error compiling regular expression %s status = %d.\n", ROMAN_REGULAR_EXPRESSION, status);
        result = ROMAN_FALSE;
    }
    /* Compilation successful. */
    else
    {
        result = ROMAN_TRUE;
    }

    return result;
}

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_is_valid_digit(RomanDigit_t digit)                                                       */
/*                                                                                                            */
/* Description: Determines if the variable digit contains a valid roman numeral digit. Assumes a capitalized  */
/*              representation of the digit.                                                                  */
/*                                                                                                            */
/* Inputs: digit - character respresentation of the roman numeral digit.                                      */
/*                                                                                                            */
/* Outputs: None                                                                                              */
/*                                                                                                            */
/* Return: True/False indicating if a valid roman numeral character is assigned to digit.                     */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_is_valid_sequential_digit(RomanDigit_t digit)                                            */
/*                                                                                                            */
/* Description: Determines if the variable digit contains a valid sequential roman numeral digit meaning it   */
/*              can be repeated in a roman numeral string.  Assumes a capitalized representation of the       */
/*              digit.                                                                                        */
/*                                                                                                            */
/* Inputs: digit - character respresentation of the roman numeral digit.                                      */
/*                                                                                                            */
/* Outputs: None                                                                                              */
/*                                                                                                            */
/* Return: True/False indicating if a valid sequential roman numeral character is assigned to digit.          */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanCompare_t roman_digit_compare_to(RomanDigit_t digit_a, RomanDigit_t digit_b)                          */
/*                                                                                                            */
/* Description: Determines if the variable digit contains a valid sequential roman numeral digit meaning it   */
/*              can be repeated in a roman numeral string.  Assumes a capitalized representation of the       */
/*              digit.                                                                                        */
/*                                                                                                            */
/* Inputs: digit_a - character respresentation of the first roman numeral digit to compare.                   */
/*         digit_b - character respresentation of the second roman numeral digit to compare.                  */
/*                                                                                                            */
/* Outputs: None                                                                                              */
/*                                                                                                            */
/* Return: ROMAN_DIGIT_EQUALTO if the two roman numeral digits are equal.                                     */
/*         ROMAN_DIGIT_LESSTHAN if the first roman numeral digit is less than the second.                     */
/*         ROMAN_DIGIT_GREATERTHAN if the first roman numeral digit is greater than the second.               */
/*         ROMAN_DIGIT_INVALID if either the first or second roman numeral digit is invalid.                  */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanCount_t roman_get_max_sequential_count(RomanDigit_t digit)                                            */
/*                                                                                                            */
/* Description: Determines if the variable digit contains a valid sequential roman numeral digit meaning it   */
/*              can be repeated in a roman numeral string.  Assumes a capitalized representation of the       */
/*              digit.                                                                                        */
/*                                                                                                            */
/* Inputs: digit - character respresentation of the roman numeral digit.                                      */
/*                                                                                                            */
/* Outputs: None                                                                                              */
/*                                                                                                            */
/* Return: count indicating the maximum number of sequential digits can occur for the current digit.          */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_is_valid_subtraction_pair(RomanDigit_t digit_a, RomanDigit_t digit_b)                    */
/*                                                                                                            */
/* Description: Determines if the first roman numeral digit is a valid subtraction pair relative to the       */
/*              second roman numeral digit. Assumes a capitalized representation of the digit.                */
/*                                                                                                            */
/* Inputs: digit_a - character respresentation of the first roman numeral digit.                              */
/*         digit_b - character respresentation of the second roman numeral digit.                             */
/*                                                                                                            */
/* Outputs: None                                                                                              */
/*                                                                                                            */
/* Return: True/False indicating a valid subtraction roman numeral digit pair.                                */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_is_valid_numeral(RomanNumeral_t *numeral)                                                */
/*                                                                                                            */
/* Description: Determines if the first roman numeral string is valid.                                        */
/*                                                                                                            */
/* Inputs: numeral - character string respresentation of a roman numeral.                                     */
/*                                                                                                            */
/* Outputs: numeral - character string respresentation of a roman numeral. Converted to uppercase.            */
/*                                                                                                            */
/* Return: True/False indicating a valid roman numeral string.                                                */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
RomanBool_t roman_is_valid_numeral(RomanNumeral_t *numeral)
{
    RomanCompare_t compare_result;
    RomanCount_t   consecutive_digit_count = 1;
    RomanCount_t   idx;
    RomanDigit_t   previous_digit;
    int            regex_retval;
    RomanBool_t    result = ROMAN_FALSE;
    int            toupper_digit;

    /* Valid pointer check. */

    if (numeral != NULL)
    {
        /* Valid pointer check. */

        if (numeral->digits != NULL)
        {
            /* Ensure the string length member is set and valid. */

            result = ROMAN_TRUE;
            numeral->length = strlen(numeral->digits);
            /* printf("roman_is_valid_numeral: roman numeral %s has a length of %d.\n", numeral->digits, numeral->length); */

            /* Check each digit of the string. */

            for (idx = 0; idx<numeral->length; idx++)
            {
                /* printf("roman_is_valid_numeral: processing roman numeral digit %c index %d.\n", numeral->digits[idx], idx); */

                /* Convert to upper case. */

                toupper_digit = (int)numeral->digits[idx];
                toupper_digit = toupper(toupper_digit);
                numeral->digits[idx] = (char)toupper_digit;

                /* Check to see if the current digit is valid. */

                if (roman_is_valid_digit(numeral->digits[idx]) == ROMAN_TRUE)
                {
                    /* printf("roman_is_valid_numeral: valid digit for roman numeral digit %c index %d.\n", numeral->digits[idx], idx); */

                    if (idx > 0)
                    {

                        /* Compare the previous and current roman numeral digits. */

                        compare_result = roman_digit_compare_to(numeral->digits[idx], previous_digit);

                        /* Current roman numeral digit is less than the previous digit. */

                        if (compare_result == ROMAN_DIGIT_LESSTHAN)
                        {
                            consecutive_digit_count = 1;
                        }

                        /* Current roman numeral digit is greater than the previous digit. */

                        else if (compare_result == ROMAN_DIGIT_GREATERTHAN)
                        {
                            consecutive_digit_count = 1;

                            /* Check to see if the current and previous roman numeral digits form a valid subtraction pair. */

                            if (roman_is_valid_subtraction_pair(previous_digit, numeral->digits[idx]) == ROMAN_FALSE)
                            {
                                /* Invalid roman numeral digit subtraction pair. */

                                result = ROMAN_FALSE;
                                printf("roman_is_valid_numeral: invalid subtraction pair for input %s roman numeral digit %c previous %c index %d.\n", numeral->digits, numeral->digits[idx], previous_digit, idx);
                                break;
                            }
                        }

                        /* Current roman numeral digit is equal to the previous digit. */

                        else if (compare_result == ROMAN_DIGIT_EQUALTO)
                        {

                            /* Check to see if the current and previous roman numeral digits form a valid sequential pair. */

                            if (roman_is_valid_sequential_digit(numeral->digits[idx]) == ROMAN_TRUE)
                            {
                                consecutive_digit_count++;

                                /* Check to see if the valid sequential digits are within their maximum sequential count. */

                                if (roman_get_max_sequential_count(numeral->digits[idx]) < consecutive_digit_count)
                                {
                                    /* Exceeded the maximum sequential digit count. */

                                    result = ROMAN_FALSE;
                                    printf("roman_is_valid_numeral: invalid max sequential count %d for input %s roman numeral digit %c previous %c index %d.\n", consecutive_digit_count, numeral->digits, numeral->digits[idx], previous_digit, idx);
                                    break;
                                }
                            }
                            else
                            {
                                /* Invalid sequential roman numeral digit. */

                                result = ROMAN_FALSE;
                                printf("roman_is_valid_numeral: invalid sequential digit for input %s numeral digit %c previous %c index %d.\n", numeral->digits, numeral->digits[idx], previous_digit, idx);
                                break;
                            }
                        }
                        else
                        {
                            /* Invalid roman numeral digit detected. */

                            result = ROMAN_FALSE;
                            printf("roman_is_valid_numeral: invalid comparison return for input %s numeral digit %c previous %c index %d.\n", numeral->digits, numeral->digits[idx], previous_digit, idx);
                            break;
                        }
                        
                    }
                    previous_digit = numeral->digits[idx];
                }
                else
                {
                    /* Invalid roman numeral digit detected. */

                    result = ROMAN_FALSE;
                    printf("roman_is_valid_numeral: invalid digit for input %s roman numeral digit %c index %d.\n", numeral->digits, numeral->digits[idx], idx);
                    break;
                }
            }
        }
        else
        {
            /* Invalid roman numeral string pointer detected. */
            printf("roman_is_valid_numeral: invalid digits argument (NULL) pointer passed\n");
        }
    }
    else
    {
        /* Invalid roman numeral structure pointer detected. */
        printf("roman_is_valid_numeral: invalid pointer argument (NULL) pointer passed\n");
    }

    /* Valid roman numeral string so far. */
    if (result == ROMAN_TRUE)
    {
        /* printf("The string %s passed to the regular expression\n", numeral->digits); */

        /* Compare the roman numeral string against the compiled roman numeral regular expression string for validity. */

        if ((regex_retval = regexec(&roman_regular_expression, numeral->digits, 0, NULL, 0)) == 0)
        {
            /* printf("The string %s matched the regular expression\n", numeral->digits); */
        }
        else
        {
            /* Invalid roman numeral string. */

            result = ROMAN_FALSE;
            printf("The string %s did not match the regular expression\n", numeral->digits);
        } 
    }

    return result;
}

#if 0
/*------------------------------------------------------------------------------------------------------------*/
/* void roman_numeral_fix_term(RomanNumeral_t *numeral)                                                       */
/*                                                                                                            */
/* Description: Normalizes or fixes the roman numeral string post addition or subtraction. NOT USED.          */
/*                                                                                                            */
/* Inputs: numeral - character string respresentation of a roman numeral.                                     */
/*                                                                                                            */
/* Outputs: numeral - character string respresentation of a roman numeral. Converted to uppercase.            */
/*                                                                                                            */
/* Return: None.                                                                                              */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
void roman_numeral_fix_term(RomanNumeral_t *numeral)
{
    RomanCount_t           idx;
    RomanNumeralCounts_t   numeral_counts;

    /* Valid pointer check. */

    if (numeral != NULL)
    {
        /* Valid pointer check. */

        if (numeral->digits != NULL)
        {

            /* Check for a valid roman numeral string. */

            if (roman_is_valid_numeral(numeral) == ROMAN_FALSE)
            {

                /* Initialize the roman numeral digit counts. */

                memset(&numeral_counts, 0, sizeof(RomanNumeralCounts_t));

                /* Process each digit of the string. */

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

                /* Process each digit and output the corresponding string via a lookup table. */

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
#endif

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_numeral_get_add_term(RomanNumeral_t *numeral, RomanNumeral_t *numeral_to_add)            */
/*                                                                                                            */
/* Description: Determines if the first roman numeral string is valid.                                        */
/*                                                                                                            */
/* Inputs: numeral - character string respresentation of a roman numeral.                                     */
/*                                                                                                            */
/* Outputs: numeral_to_add - character string respresentation of the roman numeral add term. Converted to     */
/*                           uppercase.                                                                       */
/*                                                                                                            */
/* Return: True/False indicating a valid roman numeral add term string.                                       */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
RomanBool_t roman_numeral_get_add_term(RomanNumeral_t *numeral, RomanNumeral_t *numeral_to_add)
{
    RomanCompare_t compare_result;
    RomanCount_t   consecutive_digit_count = 1;
    RomanCount_t   idx;
    RomanDigit_t   previous_digit;
    int            remaining_length;
    RomanBool_t    result = ROMAN_FALSE;

    /* Valid pointer check. */

    if ((numeral != NULL) && (numeral_to_add != NULL))
    {
        /* Valid pointer check. */

        if ((numeral->digits != NULL) && (numeral_to_add->digits != NULL))
        {
            /* Ensure the output roman numeral string is initially set to the empty string. */

            numeral_to_add->length = 0;
            numeral_to_add->digits[0] = 0;

            result = ROMAN_TRUE;

            /* Ensure the string length member is set and valid. */

            numeral->length = strlen(numeral->digits);

            /* Process each digit of the string. */

            for (idx = 0; idx<numeral->length; idx++)
            {
                /* Convert to upper case. */

                numeral->digits[idx] = (char)toupper((int)numeral->digits[idx]);

                /* Check for a valid roman numeral string. */

                if (roman_is_valid_digit(numeral->digits[idx]) == ROMAN_TRUE)
                {
                    if (idx > 0)
                    {

                        /* Compare the previous and current roman numeral digits. */

                        compare_result = roman_digit_compare_to(numeral->digits[idx], previous_digit);

                        /* Current roman numeral digit is less than the previous digit. */

                        if (compare_result == ROMAN_DIGIT_LESSTHAN)
                        {
                            consecutive_digit_count = 1;
                        }

                        /* Current roman numeral digit is greater than the previous digit. */

                        else if (compare_result == ROMAN_DIGIT_GREATERTHAN)
                        {
                            consecutive_digit_count = 1;

                            /* Check to see if the current and previous roman numeral digits form a valid subtraction pair. */

                            if (roman_is_valid_subtraction_pair(previous_digit, numeral->digits[idx]) == ROMAN_FALSE)
                            {
                                /* Invalid roman numeral digit subtraction pair. */

                                result = ROMAN_FALSE;
                                printf("roman_numeral_get_add_term: invalid subtraction pair roman numeral digit %c previous %c index %d.\n", numeral->digits[idx], previous_digit, idx);
                                break;
                            }
                            else
                            {
                                /* Copy the subtraction digit to the add term string. */

                                numeral_to_add->digits[numeral_to_add->length] = previous_digit;
                                numeral_to_add->length++;
                                numeral_to_add->digits[numeral_to_add->length] = 0;
                                remaining_length = numeral->length - idx;
                                memcpy(&numeral->digits[idx-1], &numeral->digits[idx], remaining_length);
                                numeral->length--;
                                numeral->digits[numeral->length] = 0;
                            }
                        }

                        /* Current roman numeral digit is equal to the previous digit. */

                        else if (compare_result == ROMAN_DIGIT_EQUALTO)
                        {

                            /* Check to see if the current and previous roman numeral digits form a valid sequential pair. */

                            if (roman_is_valid_sequential_digit(numeral->digits[idx]) == ROMAN_TRUE)
                            {
                                consecutive_digit_count++;

                                /* Check to see if the valid sequential digits are within their maximum sequential count. */

                                if (roman_get_max_sequential_count(numeral->digits[idx]) < consecutive_digit_count)
                                {
                                    /* Exceeded the maximum sequential digit count. */

                                    result = ROMAN_FALSE;
                                    printf("roman_numeral_get_add_term: invalid max sequential count roman numeral digit %c previous %c index %d.\n", numeral->digits[idx], previous_digit, idx);
                                    break;
                                }
                            }
                            else
                            {
                                /* Invalid sequential roman numeral digit. */

                                result = ROMAN_FALSE;
                                printf("roman_numeral_get_add_term: invalid sequential roman numeral digit %c previous %c index %d.\n", numeral->digits[idx], previous_digit, idx);
                                break;
                            }
                        }
                        else
                        {
                            /* Invalid roman numeral digit detected. */

                            result = ROMAN_FALSE;
                            printf("roman_numeral_get_add_term: invalid comparison return numeral digit %c previous %c index %d.\n", numeral->digits[idx], previous_digit, idx);
                            break;
                        }
                        
                    }
                    previous_digit = numeral->digits[idx];
                }
                else
                {
                    /* Invalid roman numeral digit detected. */

                    result = ROMAN_FALSE;
                    printf("roman_numeral_get_add_term: invalid digit for roman numeral digit %c index %d.\n", numeral->digits[idx], idx);
                    break;
                }
            }
        }
    }

    if (result == ROMAN_TRUE)
    {
        /* Check to ensure the add term string length is greater than zero. */

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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_numeral_add_terms(RomanNumeral_t *numeral1, romanNumeral_t *numeral2,                    */
/*                                     RomanNumeral_t *addition_numeral)                                      */
/*                                                                                                            */
/* Description: Performs addition of the two roman numeral strings.                                           */
/*                                                                                                            */
/* Inputs: numeral1 - character string respresentation of the first roman numeral.                            */
/*         numeral2 - character string respresentation of the second roman numeral.                           */
/*                                                                                                            */
/* Outputs: addition_numeral - character string respresentation of the roman numeral add result.              */
/*                                                                                                            */
/* Return: True/False indicating a valid roman numeral add result string.                                     */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
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

    /* Valid pointer check. */

    if ((numeral1 != NULL) && (numeral2 != NULL))
    {
        /* Valid pointer check. */

        if ((numeral1->digits != NULL) && (numeral2->digits != NULL))
        {

            /* Check for valid roman numeral strings. */

            /* if ((roman_is_valid_numeral(numeral1) == ROMAN_TRUE) && (roman_is_valid_numeral(numeral2) == ROMAN_TRUE)) */
            /* { */

                /* Initialize the roman numeral digit counts. */

                memset(&numeral_result_counts, 0, sizeof(RomanNumeralCounts_t));

                result = ROMAN_TRUE;

                /* Initialize the roman numeral digit counts. */

                memset(&numeral1_counts, 0, sizeof(RomanNumeralCounts_t));

                /* Process each digit of the string. */

                for (idx = 0; idx<numeral1->length; idx++)
                {

                    /* Check to see if the current and previous roman numeral digits form a valid subtraction pair. */

                    valid_subtract_pair = roman_is_valid_subtraction_pair(previous_digit, numeral1->digits[idx]);

                    /* Update the first roman numeral digit counts. */

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

                /* Initialize the roman numeral digit counts. */

                memset(&numeral2_counts, 0, sizeof(RomanNumeralCounts_t));

                /* Process each digit of the string. */

                for (idx = 0; idx<numeral2->length; idx++)
                {

                    /* Check to see if the current and previous roman numeral digits form a valid subtraction pair. */

                    valid_subtract_pair = roman_is_valid_subtraction_pair(previous_digit, numeral2->digits[idx]);

                    /* Update the second roman numeral digit counts. */

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

                /* Process each roman numeral digit count. */

                for (idx = (ROMAN_NUMBER_OF_DIGITS-1); idx >= 0; idx--)
                {
                    /* printf("roman_numeral_add_terms: numeral1_counts.digit_counts[%d]=%d\n", idx, numeral1_counts.digit_counts[idx]); */
                    /* printf("roman_numeral_add_terms: numeral2_counts.digit_counts[%d]=%d\n", idx, numeral2_counts.digit_counts[idx]); */
                    numeral_result_counts.digit_counts[idx] = numeral_result_counts.digit_counts[idx] + numeral1_counts.digit_counts[idx] + numeral2_counts.digit_counts[idx];

                    /* Check to see if we have exceeded the maximum allowable count for this digit. */

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

                /* Ensure the addition roman numeral string is set initially to the empty string. */

                addition_numeral->digits[0] = 0;
                addition_numeral->length = 0;

                /* Process each digit and output the corresponding string via a lookup table. */

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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_numeral_compare_subtract_terms(RomanNumeral_t *numeral1, romanNumeral_t *numeral2)       */
/*                                                                                                            */
/* Description: Performs comparison of the two roman numeral subtraction strings.                             */
/*                                                                                                            */
/* Inputs: numeral1 - character string respresentation of the first roman numeral.                            */
/*         numeral2 - character string respresentation of the second roman numeral.                           */
/*                                                                                                            */
/* Outputs: None.                                                                                             */
/*                                                                                                            */
/* Return: ROMAN_DIGIT_EQUALTO if the two roman numeral strings are equal.                                    */
/*         ROMAN_DIGIT_LESSTHAN if the first roman numeral string is less than the second.                    */
/*         ROMAN_DIGIT_GREATERTHAN if the first roman numeral string is greater than the second.              */
/*         ROMAN_DIGIT_INVALID if either the first or second roman numeral string is invalid.                 */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
RomanCompare_t roman_numeral_compare_subtract_terms(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2)
{
    RomanCount_t           extra_counts;
    RomanCount_t           idx;
    RomanNumeralCounts_t   numeral1_counts;
    RomanNumeralCounts_t   numeral2_counts;
    RomanDigit_t           previous_digit = ' ';
    RomanCompare_t         result = ROMAN_DIGIT_INVALID;
    RomanBool_t            valid_subtract_pair;

    /* Valid pointer check. */

    if ((numeral1 != NULL) && (numeral2 != NULL))
    {
        /* Valid pointer check. */

        if ((numeral1->digits != NULL) && (numeral2->digits != NULL))
        {

            /* Check for valid roman numeral strings. */

            if ((roman_is_valid_numeral(numeral1) == ROMAN_TRUE) && (roman_is_valid_numeral(numeral2) == ROMAN_TRUE))
            {

                /* Initialize the roman numeral digit counts. */

                memset(&numeral1_counts, 0, sizeof(RomanNumeralCounts_t));

                /* Process each digit of the string. */

                for (idx = 0; idx<numeral1->length; idx++)
                {

                    /* Check to see if the current and previous roman numeral digits form a valid subtraction pair. */

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

                /* Initialize the roman numeral digit counts. */

                memset(&numeral2_counts, 0, sizeof(RomanNumeralCounts_t));

                /* Process each digit of the string. */

                for (idx = 0; idx<numeral2->length; idx++)
                {

                    /* Check to see if the current and previous roman numeral digits form a valid subtraction pair. */

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

                /* Normalize the first roman numeral counts. */

                for (idx = (ROMAN_NUMBER_OF_DIGITS-1); idx >= 0; idx--)
                {
                    /* Check to see if we have exceeded the maximum allowable count for this digit. */

                    if (numeral1_counts.digit_counts[idx] >= roman_number_of_previous_counts[idx])
                    {
                        if (idx > 0)
                        {
                            extra_counts = numeral1_counts.digit_counts[idx] / roman_number_of_previous_counts[idx];
                            numeral1_counts.digit_counts[(idx-1)] = numeral1_counts.digit_counts[(idx-1)] + extra_counts;
                            /* printf("roman_numeral_compare_subtract_terms: numeral1_counts.digit_counts[%d]=%d\n", (idx-1), numeral1_counts.digit_counts[(idx-1)]); */
                        }
                        numeral1_counts.digit_counts[idx] = numeral1_counts.digit_counts[idx] % roman_number_of_previous_counts[idx];
                    }
                    /* printf("roman_numeral_compare_subtract_terms: numeral1_counts.digit_counts[%d]=%d\n", idx, numeral1_counts.digit_counts[idx]); */
                }

                /* Normalize the second roman numeral counts. */

                for (idx = (ROMAN_NUMBER_OF_DIGITS-1); idx >= 0; idx--)
                {
                    /* Check to see if we have exceeded the maximum allowable count for this digit. */

                    if (numeral2_counts.digit_counts[idx] >= roman_number_of_previous_counts[idx])
                    {
                        if (idx > 0)
                        {
                            extra_counts = numeral2_counts.digit_counts[idx] / roman_number_of_previous_counts[idx];
                            numeral2_counts.digit_counts[(idx-1)] = numeral2_counts.digit_counts[(idx-1)] + extra_counts;
                            /* printf("roman_numeral_compare_subtract_terms: numeral2_counts.digit_counts[%d]=%d\n", (idx-1), numeral2_counts.digit_counts[(idx-1)]); */
                        }
                        numeral2_counts.digit_counts[idx] = numeral2_counts.digit_counts[idx] % roman_number_of_previous_counts[idx];
                    }
                    /* printf("roman_numeral_compare_subtract_terms: numeral2_counts.digit_counts[%d]=%d\n", idx, numeral2_counts.digit_counts[idx]); */
                }

                /* Perform a comparison of digit counts starting with the MS digit. */

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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_numeral_subtract_terms(RomanNumeral_t *numeral1, romanNumeral_t *numeral2,               */
/*                                          RomanNumeral_t *subtraction_numeral)                              */
/*                                                                                                            */
/* Description: Performs subtraction of the two roman numeral strings.                                        */
/*                                                                                                            */
/* Inputs: numeral1 - character string respresentation of the first roman numeral.                            */
/*         numeral2 - character string respresentation of the second roman numeral.                           */
/*                                                                                                            */
/* Outputs: subtraction_numeral - character string respresentation of the roman numeral subtract result.      */
/*                                                                                                            */
/* Return: True/False indicating a valid roman numeral subtract result string.                                */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
RomanBool_t roman_numeral_subtract_terms(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *subtraction_numeral)
{
    RomanCompare_t         compare_result;
    RomanCount_t           extra_counts;
    RomanCount_t           idx;
    RomanCount_t           idx2;
    RomanCount_t           idx3;
    RomanNumeralCounts_t   numeral1_counts;
    RomanNumeralCounts_t   numeral2_counts;
    RomanNumeralCounts_t   numeral_result_counts;
    RomanDigit_t           previous_digit = ' ';
    RomanBool_t            result = ROMAN_FALSE;
    RomanBool_t            valid_subtract_pair;

    /* Valid pointer check. */

    if ((numeral1 != NULL) && (numeral2 != NULL) && (subtraction_numeral != NULL))
    {
        /* Valid pointer check. */

        if ((numeral1->digits != NULL) && (numeral2->digits != NULL) && (subtraction_numeral->digits != NULL))
        {

            /* Check for valid roman numeral strings. */

            /* if ((roman_is_valid_numeral(numeral1) == ROMAN_TRUE) && (roman_is_valid_numeral(numeral2) == ROMAN_TRUE)) */
            /* { */

                /* Initialize the roman numeral digit counts. */

                memset(&numeral_result_counts, 0, sizeof(RomanNumeralCounts_t));

                /* Perform a comparison of the two subtract terms to ensure the first is greater than or equal to the second. */

                compare_result = roman_numeral_compare_subtract_terms(numeral1, numeral2);
                if ((compare_result == ROMAN_DIGIT_GREATERTHAN) || (compare_result == ROMAN_DIGIT_EQUALTO))
                {
                    result = ROMAN_TRUE;

                    /* Initialize the roman numeral digit counts. */

                    memset(&numeral1_counts, 0, sizeof(RomanNumeralCounts_t));

                    /* Process each digit of the string. */

                    for (idx = 0; idx<numeral1->length; idx++)
                    {

                        /* Check to see if the current and previous roman numeral digits form a valid subtraction pair. */

                        valid_subtract_pair = roman_is_valid_subtraction_pair(previous_digit, numeral1->digits[idx]);

                        /* Update the digit counts for the first roman numeral. */

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

                    /* Initialize the roman numeral digit counts. */

                    memset(&numeral2_counts, 0, sizeof(RomanNumeralCounts_t));

                    /* Process each digit of the string. */

                    for (idx = 0; idx<numeral2->length; idx++)
                    {
                        /* Check to see if the current and previous roman numeral digits form a valid subtraction pair. */

                        valid_subtract_pair = roman_is_valid_subtraction_pair(previous_digit, numeral2->digits[idx]);

                        /* Update the digit counts for the second roman numeral. */

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

                    /* Normalize the first roman numeral counts. */

                    for (idx = (ROMAN_NUMBER_OF_DIGITS-1); idx >= 0; idx--)
                    {
                        /* Check to see if we have exceeded the maximum allowable count for this digit. */

                        if (numeral1_counts.digit_counts[idx] >= roman_number_of_previous_counts[idx])
                        {
                            if (idx > 0)
                            {
                                extra_counts = numeral1_counts.digit_counts[idx] / roman_number_of_previous_counts[idx];
                                numeral1_counts.digit_counts[(idx-1)] = numeral1_counts.digit_counts[(idx-1)] + extra_counts;
                                /* printf("roman_numeral_subtract_terms: numeral1_counts.digit_counts[%d]=%d\n", (idx-1), numeral1_counts.digit_counts[(idx-1)]); */
                            }
                            numeral1_counts.digit_counts[idx] = numeral1_counts.digit_counts[idx] % roman_number_of_previous_counts[idx];
                        }
                        /* printf("roman_numeral_subtract_terms: numeral1_counts.digit_counts[%d]=%d\n", idx, numeral1_counts.digit_counts[idx]); */
                    }

                    /* Normalize the second roman numeral counts. */

                    for (idx = (ROMAN_NUMBER_OF_DIGITS-1); idx >= 0; idx--)
                    {
                        /* Check to see if we have exceeded the maximum allowable count for this digit. */

                        if (numeral2_counts.digit_counts[idx] >= roman_number_of_previous_counts[idx])
                        {
                            if (idx > 0)
                            {
                                extra_counts = numeral2_counts.digit_counts[idx] / roman_number_of_previous_counts[idx];
                                numeral2_counts.digit_counts[(idx-1)] = numeral2_counts.digit_counts[(idx-1)] + extra_counts;
                                /* printf("roman_numeral_subtract_terms: numeral2_counts.digit_counts[%d]=%d\n", (idx-1), numeral2_counts.digit_counts[(idx-1)]); */
                            }
                            numeral2_counts.digit_counts[idx] = numeral2_counts.digit_counts[idx] % roman_number_of_previous_counts[idx];
                        }
                        /* printf("roman_numeral_subtract_terms: numeral2_counts.digit_counts[%d]=%d\n", idx, numeral2_counts.digit_counts[idx]); */
                    }

                    /* Process each roman numeral digit count. */

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

                    /* Ensure the subtraction roman numeral string is set initially to the empty string. */

                    subtraction_numeral->digits[0] = 0;
                    subtraction_numeral->length = 0;

                    /* Process each digit and output the corresponding string via a lookup table. */

                    for (idx = 0; idx < ROMAN_NUMBER_OF_DIGITS; idx++)
                    {
                        /* printf("roman_numeral_subtract_terms: numeral_result_counts.digit_counts[%d]=%d\n", idx, numeral_result_counts.digit_counts[idx]); */
                        if (numeral_result_counts.digit_counts[idx] >= 0)
                        {
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

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_numeral_add(RomanNumeral_t *numeral1, romanNumeral_t *numeral2,                          */
/*                               RomanNumeral_t *addition_numeral)                                            */
/*                                                                                                            */
/* Description: Performs addition of the two roman numeral strings.                                           */
/*                                                                                                            */
/* Inputs: numeral1 - character string respresentation of the first roman numeral.                            */
/*         numeral2 - character string respresentation of the second roman numeral.                           */
/*                                                                                                            */
/* Outputs: addition_numeral - character string respresentation of the roman numeral add result.              */
/*                                                                                                            */
/* Return: True/False indicating a valid roman numeral add result string.                                     */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
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

    /* Valid pointer check. */

    if ((numeral1 != NULL) && (numeral2 != NULL) && (addition_numeral != NULL))
    {
        /* Valid pointer check. */

        if ((numeral1->digits != NULL) && (numeral2->digits != NULL) && (addition_numeral->digits != NULL))
        {

            /* Ensure the addition roman numeral string is set initially to the empty string. */

            addition_numeral->digits[0] = 0;
            addition_numeral->length = 0;

            /* Check for valid roman numeral strings. */

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
#if 0
                numeral_result2.digits = result_digits2;
                numeral_result2.digits[0] = 0;
                numeral_result2.length = 0;
#endif

                /* Perform the addition of the two roman numeral terms. */

                add_term_result = roman_numeral_add_terms(numeral1, numeral2, &numeral_result1);
                if (add_term_result == ROMAN_TRUE)
                {
                    /* printf("roman_numeral_add:1 A numeral 1 %s plus numeral 2 %s equals = %s.\n", numeral1->digits, numeral2->digits, numeral_result1.digits); */
                }
                else
                {
                    /* Invalid addition result detected. */

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

                /* Store the addition result to the output parameter. */

                strcpy(addition_numeral->digits, numeral_result1.digits);
                addition_numeral->length = numeral_result1.length;
            }
        }
    }

    if (result == ROMAN_TRUE)
    {
        if (addition_numeral->length >= 0)
        {
            /* printf("roman_numeral_add: A numeral 1 term %s plus numeral 2 term %s equals %s.\n", numeral1->digits, numeral2->digits, addition_numeral->digits); */
        }
        else
        {
            result = ROMAN_FALSE;
            addition_numeral->digits[0] = 0;
            addition_numeral->length = 0;
        } 
    }

    return result;
}

/*------------------------------------------------------------------------------------------------------------*/
/* RomanBool_t roman_numeral_subtract(RomanNumeral_t *numeral1, romanNumeral_t *numeral2,                     */
/*                                    RomanNumeral_t *subtraction_numeral)                                    */
/*                                                                                                            */
/* Description: Performs subtraction of the two roman numeral strings.                                        */
/*                                                                                                            */
/* Inputs: numeral1 - character string respresentation of the first roman numeral.                            */
/*         numeral2 - character string respresentation of the second roman numeral.                           */
/*                                                                                                            */
/* Outputs: subtraction_numeral - character string respresentation of the roman numeral subtract result.      */
/*                                                                                                            */
/* Return: True/False indicating a valid roman numeral subtract result string.                                */
/*                                                                                                            */
/*------------------------------------------------------------------------------------------------------------*/
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

    /* Valid pointer check. */

    if ((numeral1 != NULL) && (numeral2 != NULL) && (subtraction_numeral != NULL))
    {
        /* Valid pointer check. */

        if ((numeral1->digits != NULL) && (numeral2->digits != NULL) && (subtraction_numeral->digits != NULL))
        {

            /* Ensure the subtraction roman numeral string is set initially to the empty string. */

            subtraction_numeral->digits[0] = 0;
            subtraction_numeral->length = 0;

            /* Check for valid roman numeral strings. */

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
#if 0
                numeral_result2.digits = result_digits2;
                numeral_result2.digits[0] = 0;
                numeral_result2.length = 0;
#endif

                /* Perform the subtraction of the two roman numeral terms. */

                add_term_result = roman_numeral_subtract_terms(numeral1, numeral2, &numeral_result1);
                if (add_term_result == ROMAN_TRUE)
                {
                    /* printf("roman_numeral_subtract:1 A numeral 1 %s minus numeral 2 %s equals = %s.\n", numeral1->digits, numeral2->digits, numeral_result1.digits); */
 
#if 0
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
#endif
 
#if 0
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
#endif

                    /* Store the addition result to the output parameter. */

                    strcpy(subtraction_numeral->digits, numeral_result1.digits);
                    subtraction_numeral->length = numeral_result1.length;
                }
                else
                {
                    /* Invalid subtraction result detected. */

                    result = ROMAN_FALSE;
                    /* printf("roman_numeral_subtract:4 Error subtracting numeral 1 %s minus numeral 2 %s.\n", numeral1->digits, numeral2->digits); */
                }
            }
        }
    }

    if (result == ROMAN_TRUE)
    {
        if (subtraction_numeral->length >= 0)
        {
            /* printf("roman_numeral_subtract: A numeral 1 term %s minus numeral 2 term %s equals %s.\n", numeral1->digits, numeral2->digits, subtraction_numeral->digits); */
        }
        else
        {
            result = ROMAN_FALSE;
            subtraction_numeral->digits[0] = 0;
            subtraction_numeral->length = 0;
        } 
    }

    return result;
}

