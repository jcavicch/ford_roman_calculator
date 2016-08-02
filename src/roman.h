#ifndef ROMAN_H
#define ROMAN_H

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define ROMAN_DIGIT_INVALID       (-2)
#define ROMAN_DIGIT_LESSTHAN      (-1)
#define ROMAN_DIGIT_EQUALTO       (0)
#define ROMAN_DIGIT_GREATERTHAN   (1)

#define ROMAN_TRUE                (1)
#define ROMAN_FALSE               (0)

typedef char RomanDigit_t;
typedef int  RomanLength_t;
typedef int  RomanCompare_t;
typedef int  RomanCount_t;
typedef int  RomanBool_t;

typedef struct 
{
    RomanLength_t  length;
    RomanDigit_t  *digits;
} RomanNumeral_t;

RomanBool_t roman_initialize_library();

RomanBool_t roman_is_valid_digit(RomanDigit_t digit);

RomanBool_t roman_is_valid_sequential_digit(RomanDigit_t digit);

RomanCount_t roman_get_max_sequential_count(RomanDigit_t digit);

RomanCompare_t roman_digit_compare_to(RomanDigit_t digit_a, RomanDigit_t digit_b);

RomanBool_t roman_is_valid_subtraction_pair(RomanDigit_t digit_a, RomanDigit_t digit_b);

RomanBool_t roman_is_valid_numeral(RomanNumeral_t *numeral);

RomanBool_t roman_numeral_get_add_term(RomanNumeral_t *numeral, RomanNumeral_t *numeral_to_add);

RomanBool_t roman_numeral_add_terms(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *addition_numeral);

RomanCompare_t roman_numeral_compare_subtract_terms(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2);

RomanBool_t roman_numeral_subtract_terms(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *subtraction_numeral);

void roman_numeral_fix_term(RomanNumeral_t *numeral);

RomanBool_t roman_numeral_add(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *addition_numeral);

RomanBool_t roman_numeral_subtract(RomanNumeral_t *numeral1, RomanNumeral_t *numeral2, RomanNumeral_t *subtraction_numeral);

#endif
