#include <stdio.h>
#include <check.h>
#include "../src/roman.h"

START_TEST(test_roman_initialization)
{
    RomanBool_t  initialize_status;

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_initialization: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);
}
END_TEST

START_TEST(test_roman_valid_digits)
{
    RomanDigit_t digit;
    RomanBool_t  valid_digit;

    digit = 'M';
    valid_digit = roman_is_valid_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'D';
    valid_digit = roman_is_valid_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'C';
    valid_digit = roman_is_valid_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'L';
    valid_digit = roman_is_valid_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'X';
    valid_digit = roman_is_valid_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'V';
    valid_digit = roman_is_valid_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'I';
    valid_digit = roman_is_valid_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'R';
    valid_digit = roman_is_valid_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_FALSE, "test_roman_valid_digits: expecting valid digit %c to be ROMAN_FALSE (0), but found a value of %d\n", digit, valid_digit);
}
END_TEST

START_TEST(test_roman_valid_sequential_digits)
{
    RomanDigit_t digit;
    RomanBool_t  valid_digit;

    digit = 'M';
    valid_digit = roman_is_valid_sequential_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_FALSE, "test_roman_valid_sequential_digits: expecting valid digit %c to be ROMAN_FALSE (0), but found a value of %d\n", digit, valid_digit);
    digit = 'D';
    valid_digit = roman_is_valid_sequential_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_FALSE, "test_roman_valid_sequential_digits: expecting valid digit %c to be ROMAN_FALSE (0), but found a value of %d\n", digit, valid_digit);
    digit = 'C';
    valid_digit = roman_is_valid_sequential_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_sequential_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'L';
    valid_digit = roman_is_valid_sequential_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_FALSE, "test_roman_valid_sequential_digits: expecting valid digit %c to be ROMAN_FALSE (0), but found a value of %d\n", digit, valid_digit);
    digit = 'X';
    valid_digit = roman_is_valid_sequential_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_sequential_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'V';
    valid_digit = roman_is_valid_sequential_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_FALSE, "test_roman_valid_sequential_digits: expecting valid digit %c to be ROMAN_FALSE (0), but found a value of %d\n", digit, valid_digit);
    digit = 'I';
    valid_digit = roman_is_valid_sequential_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_TRUE, "test_roman_valid_sequential_digits: expecting valid digit %c to be ROMAN_TRUE (1), but found a value of %d\n", digit, valid_digit);
    digit = 'S';
    valid_digit = roman_is_valid_sequential_digit(digit);
    ck_assert_msg(valid_digit == ROMAN_FALSE, "test_roman_valid_sequential_digits: expecting valid digit %c to be ROMAN_FALSE (0), but found a value of %d\n", digit, valid_digit);
}
END_TEST

START_TEST(test_roman_max_sequential_digits)
{
    RomanDigit_t  digit;
    RomanCount_t  max_count;

    digit = 'M';
    max_count = roman_get_max_sequential_count(digit);
    ck_assert_msg(max_count == 1, "test_roman_max_sequential_digits: expecting valid digit %c to be (1), but found a value of %d\n", digit, max_count);
    digit = 'D';
    max_count = roman_get_max_sequential_count(digit);
    ck_assert_msg(max_count == 1, "test_roman_max_sequential_digits: expecting valid digit %c to be (1), but found a value of %d\n", digit, max_count);
    digit = 'C';
    max_count = roman_get_max_sequential_count(digit);
    ck_assert_msg(max_count == 3, "test_roman_max_sequential_digits: expecting valid digit %c to be (3), but found a value of %d\n", digit, max_count);
    digit = 'L';
    max_count = roman_get_max_sequential_count(digit);
    ck_assert_msg(max_count == 1, "test_roman_max_sequential_digits: expecting valid digit %c to be (1), but found a value of %d\n", digit, max_count);
    digit = 'X';
    max_count = roman_get_max_sequential_count(digit);
    ck_assert_msg(max_count == 3, "test_roman_max_sequential_digits: expecting valid digit %c to be (3), but found a value of %d\n", digit, max_count);
    digit = 'V';
    max_count = roman_get_max_sequential_count(digit);
    ck_assert_msg(max_count == 1, "test_roman_max_sequential_digits: expecting valid digit %c to be (1), but found a value of %d\n", digit, max_count);
    digit = 'I';
    max_count = roman_get_max_sequential_count(digit);
    ck_assert_msg(max_count == 3, "test_roman_max_sequential_digits: expecting valid digit %c to be (3), but found a value of %d\n", digit, max_count);
    digit = 'T';
    max_count = roman_get_max_sequential_count(digit);
    ck_assert_msg(max_count == 0, "test_roman_max_sequential_digits: expecting valid digit %c to be (0), but found a value of %d\n", digit, max_count);
}
END_TEST

START_TEST(test_roman_compare_to_digits)
{
    RomanCompare_t  compare_value;
    RomanDigit_t    digit_a;
    RomanDigit_t    digit_b;

    digit_a = 'M';
    digit_b = 'M';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_EQUALTO, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'D';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'C';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'L';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'X';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'V';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'I';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'D';
    digit_b = 'M';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'D';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_EQUALTO, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'C';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'L';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'X';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'V';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'I';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'C';
    digit_b = 'M';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'D';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'C';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_EQUALTO, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'L';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'X';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'V';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'I';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'L';
    digit_b = 'M';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'D';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'C';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'L';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_EQUALTO, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'X';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'V';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'I';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'X';
    digit_b = 'M';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'D';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'C';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'L';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'X';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_EQUALTO, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'V';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'I';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'V';
    digit_b = 'M';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'D';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'C';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'L';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'X';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'V';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_EQUALTO, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'I';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_GREATERTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'I';
    digit_b = 'M';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'D';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'C';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'L';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'X';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'V';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_LESSTHAN, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (-1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'I';
    compare_value = roman_digit_compare_to(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_DIGIT_EQUALTO, "test_roman_compare_to_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
}
END_TEST

START_TEST(test_roman_subtraction_pair_digits)
{
    RomanBool_t     compare_value;
    RomanDigit_t    digit_a;
    RomanDigit_t    digit_b;

    digit_a = 'M';
    digit_b = 'M';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'D';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'C';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'L';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'X';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'V';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'M';
    digit_b = 'I';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'D';
    digit_b = 'M';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'D';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'C';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'L';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'X';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'V';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'D';
    digit_b = 'I';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'C';
    digit_b = 'M';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_TRUE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'D';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_TRUE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'C';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'L';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'X';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'V';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'C';
    digit_b = 'I';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'L';
    digit_b = 'M';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'D';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'C';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'L';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'X';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'V';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'L';
    digit_b = 'I';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'X';
    digit_b = 'M';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'D';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'C';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_TRUE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'L';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_TRUE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'X';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'V';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'X';
    digit_b = 'I';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'V';
    digit_b = 'M';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'D';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'C';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'L';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'X';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'V';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'V';
    digit_b = 'I';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);

    digit_a = 'I';
    digit_b = 'M';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'D';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'C';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'L';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'X';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_TRUE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'V';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_TRUE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (1), but found a value of %d\n", digit_a, digit_b, compare_value);
    digit_a = 'I';
    digit_b = 'I';
    compare_value = roman_is_valid_subtraction_pair(digit_a, digit_b);
    ck_assert_msg(compare_value == ROMAN_FALSE, "test_roman_subtraction_pair_digits: expecting digit comparison between %c and %c to be (0), but found a value of %d\n", digit_a, digit_b, compare_value);
}
END_TEST

START_TEST(test_roman_valid_numeral)
{
    char            digits[80];
    RomanBool_t     initialize_status;
    RomanNumeral_t  numeral;
    RomanBool_t     result;

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_valid_numeral: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);

    strcpy(digits, "VIII");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "viii");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "IIII");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (0), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "XXXX");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (0), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "CCCC");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (0), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "IV");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "IX");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "XL");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "XC");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "CD");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "CM");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "III");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "XXX");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);

    strcpy(digits, "CCC");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    result = roman_is_valid_numeral(&numeral);
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_valid_numeral: expecting valid numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
}
END_TEST

START_TEST(test_roman_get_add_term)
{
    char            add_digits[80];
    int             compare_value;
    char            digits[80];
    RomanBool_t     initialize_status;
    RomanNumeral_t  numeral;
    RomanNumeral_t  numeral_to_add;
    RomanBool_t     result;

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_get_add_term: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);

    strcpy(digits, "IV");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    strcpy(add_digits, "");
    numeral_to_add.digits = add_digits;
    numeral_to_add.length = strlen(numeral_to_add.digits);
    result = roman_numeral_get_add_term(&numeral, &numeral_to_add);
    compare_value = strcmp(numeral_to_add.digits, "I");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    compare_value = strcmp(numeral.digits, "V");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_get_add_term: expecting get add term numeral for input %s to be (0), but found a value of %d for add term %s\n", numeral.digits, compare_value, numeral_to_add.digits);
    ck_assert_msg(numeral_to_add.length == 1, "test_roman_get_add_term: expecting valid numeral for input %s to be (1), but found a value of %d for add term %s\n", numeral.digits, result, numeral_to_add.digits);

    strcpy(digits, "IX");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    strcpy(add_digits, "");
    numeral_to_add.digits = add_digits;
    numeral_to_add.length = strlen(numeral_to_add.digits);
    result = roman_numeral_get_add_term(&numeral, &numeral_to_add);
    compare_value = strcmp(numeral_to_add.digits, "I");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    compare_value = strcmp(numeral.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_get_add_term: expecting get add term numeral for input %s to be (0), but found a value of %d for add term %s\n", numeral.digits, compare_value, numeral_to_add.digits);
    ck_assert_msg(numeral_to_add.length == 1, "test_roman_get_add_term: expecting valid numeral for input %s to be (1), but found a value of %d for add term %s\n", numeral.digits, result, numeral_to_add.digits);

    strcpy(digits, "XL");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    strcpy(add_digits, "");
    numeral_to_add.digits = add_digits;
    numeral_to_add.length = strlen(numeral_to_add.digits);
    result = roman_numeral_get_add_term(&numeral, &numeral_to_add);
    compare_value = strcmp(numeral_to_add.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    compare_value = strcmp(numeral.digits, "L");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_get_add_term: expecting get add term numeral for input %s to be (0), but found a value of %d for add term %s\n", numeral.digits, compare_value, numeral_to_add.digits);
    ck_assert_msg(numeral_to_add.length == 1, "test_roman_get_add_term: expecting valid numeral for input %s to be (1), but found a value of %d for add term %s\n", numeral.digits, result, numeral_to_add.digits);

    strcpy(digits, "XC");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    strcpy(add_digits, "");
    numeral_to_add.digits = add_digits;
    numeral_to_add.length = strlen(numeral_to_add.digits);
    result = roman_numeral_get_add_term(&numeral, &numeral_to_add);
    compare_value = strcmp(numeral_to_add.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    compare_value = strcmp(numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_get_add_term: expecting get add term numeral for input %s to be (0), but found a value of %d for add term %s\n", numeral.digits, compare_value, numeral_to_add.digits);
    ck_assert_msg(numeral_to_add.length == 1, "test_roman_get_add_term: expecting valid numeral for input %s to be (1), but found a value of %d for add term %s\n", numeral.digits, result, numeral_to_add.digits);

    strcpy(digits, "CD");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    strcpy(add_digits, "");
    numeral_to_add.digits = add_digits;
    numeral_to_add.length = strlen(numeral_to_add.digits);
    result = roman_numeral_get_add_term(&numeral, &numeral_to_add);
    compare_value = strcmp(numeral_to_add.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    compare_value = strcmp(numeral.digits, "D");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_get_add_term: expecting get add term numeral for input %s to be (0), but found a value of %d for add term %s\n", numeral.digits, compare_value, numeral_to_add.digits);
    ck_assert_msg(numeral_to_add.length == 1, "test_roman_get_add_term: expecting valid numeral for input %s to be (1), but found a value of %d for add term %s\n", numeral.digits, result, numeral_to_add.digits);

    strcpy(digits, "CM");
    numeral.digits = digits;
    numeral.length = strlen(numeral.digits);
    strcpy(add_digits, "");
    numeral_to_add.digits = add_digits;
    numeral_to_add.length = strlen(numeral_to_add.digits);
    result = roman_numeral_get_add_term(&numeral, &numeral_to_add);
    compare_value = strcmp(numeral_to_add.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    compare_value = strcmp(numeral.digits, "M");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_get_add_term: expecting get add term numeral for input %s to be (1), but found a value of %d\n", numeral.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_get_add_term: expecting get add term numeral for input %s to be (0), but found a value of %d for add term %s\n", numeral.digits, compare_value, numeral_to_add.digits);
    ck_assert_msg(numeral_to_add.length == 1, "test_roman_get_add_term: expecting valid numeral for input %s to be (1), but found a value of %d for add term %s\n", numeral.digits, result, numeral_to_add.digits);
}
END_TEST

START_TEST(test_roman_add_terms)
{
    RomanNumeral_t  addition_numeral;
    char            add_digits[80];
    int             compare_value;
    char            digits1[80];
    char            digits2[80];
    RomanBool_t     initialize_status;
    RomanNumeral_t  numeral1;
    RomanNumeral_t  numeral2;
    RomanBool_t     result;

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_add_terms: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);

    strcpy(digits1, "I");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "I");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "II");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "I");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "II");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "III");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "II");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "I");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "III");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "II");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "II");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "IV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "III");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "I");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "IV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "I");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "III");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "IV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "II");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "III");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "V");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "III");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "II");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "V");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "III");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "III");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "VI");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "VII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "III");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "III");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "VII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "VII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "VII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XIV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "VIII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "VII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "VII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "VIII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "V");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "V");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "V");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "V");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XV");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XXV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XV");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XXV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XXX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XXX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "XL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "L");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "L");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "LX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CXL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LXXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LXXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "LX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "LX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CL");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CCL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CL");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CCL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CCC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CCC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CD");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CD");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "CD");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "D");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "D");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "DC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "M");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "M");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "MCD");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 3, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DCCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "MD");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DCCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "MD");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "D");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "D");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "M");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "D");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "DC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "D");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "DC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "D");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "MC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "D");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "MC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 2, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "D");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "D");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add_terms(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "M");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_add_terms: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_add_terms: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);
}
END_TEST

START_TEST(test_roman_subtract_terms)
{
    int             compare_value;
    char            digits1[80];
    char            digits2[80];
    RomanBool_t     initialize_status;
    RomanNumeral_t  numeral1;
    RomanNumeral_t  numeral2;
    RomanBool_t     result;
    char            subtract_digits[80];
    RomanNumeral_t  subtraction_numeral;

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_subtract_terms: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);

    strcpy(digits1, "I");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "I");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "I");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "II");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "II");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "I");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "I");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "II");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "II");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "III");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "I");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "II");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 2, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "I");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "III");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "II");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "III");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "III");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "II");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "I");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "III");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "III");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "VII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "III");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "IV");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, compare_value, subtraction_numeral.digits);
    ck_assert_msg(subtraction_numeral.length == 2, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "III");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "VII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "VII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "VII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, compare_value, subtraction_numeral.digits);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "VIII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "VII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "I");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "VII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "VIII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "V");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "V");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "V");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "V");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "V");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XV");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "V");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XV");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "XX");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 2, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "XL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 2, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LXXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LXX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LXXX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "X");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "XL");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 2, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "X");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "LX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "X");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "LX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "L");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "L");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "L");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CL");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "L");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CL");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "CC");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 2, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "CD");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, compare_value, subtraction_numeral.digits);
    ck_assert_msg(subtraction_numeral.length == 2, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d for result %s\n", numeral1.digits, numeral2.digits, compare_value, subtraction_numeral.digits);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DCCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DCC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DCCC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "D");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "D");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "D");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "C");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "CD");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 2, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "C");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "D");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "DC");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "D");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "D");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "DC");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_FALSE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "D");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "D");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract_terms(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_subtract_terms: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 0, "test_roman_subtract_terms: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);
}
END_TEST

START_TEST(test_roman_numeral_add)
{
    RomanNumeral_t  addition_numeral;
    char            add_digits[80];
    int             compare_value;
    char            digits1[80];
    char            digits2[80];
    RomanBool_t     initialize_status;
    RomanNumeral_t  numeral1;
    RomanNumeral_t  numeral2;
    RomanBool_t     result;

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_numeral_add: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);

    strcpy(digits1, "LXVI");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXXIV");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "C");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_numeral_add: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_numeral_add: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 1, "test_roman_numeral_add: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "CXLVII");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "MCV");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "MCCLII");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_numeral_add: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_numeral_add: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 6, "test_roman_numeral_add: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XXXIX");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XLIV");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(add_digits, "");
    addition_numeral.digits = add_digits;
    addition_numeral.length = strlen(addition_numeral.digits);
    result = roman_numeral_add(&numeral1, &numeral2, &addition_numeral);
    compare_value = strcmp(addition_numeral.digits, "LXXXIII");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_numeral_add: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_numeral_add: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral.digits, compare_value);
    ck_assert_msg(addition_numeral.length == 7, "test_roman_numeral_add: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);
}
END_TEST

START_TEST(test_roman_numeral_subtract)
{
    int             compare_value;
    char            digits1[80];
    char            digits2[80];
    RomanBool_t     initialize_status;
    RomanNumeral_t  numeral1;
    RomanNumeral_t  numeral2;
    RomanBool_t     result;
    RomanNumeral_t  subtraction_numeral;
    char            subtract_digits[80];

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_numeral_subtract: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);

    strcpy(digits1, "LXVI");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXXIV");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "XXXII");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_numeral_subtract: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_numeral_subtract: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 5, "test_roman_numeral_subtract: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "MCV");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "CXLVII");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "CMLVIII");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_numeral_subtract: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_numeral_subtract: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 7, "test_roman_numeral_subtract: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);

    strcpy(digits1, "XLIV");
    numeral1.digits = digits1;
    numeral1.length = strlen(numeral1.digits);
    strcpy(digits2, "XXXIX");
    numeral2.digits = digits2;
    numeral2.length = strlen(numeral2.digits);
    strcpy(subtract_digits, "");
    subtraction_numeral.digits = subtract_digits;
    subtraction_numeral.length = strlen(subtraction_numeral.digits);
    result = roman_numeral_subtract(&numeral1, &numeral2, &subtraction_numeral);
    compare_value = strcmp(subtraction_numeral.digits, "V");
    ck_assert_msg(result == ROMAN_TRUE, "test_roman_numeral_subtract: expecting subtract terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
    ck_assert_msg(compare_value == 0, "test_roman_numeral_subtract: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral.digits, compare_value);
    ck_assert_msg(subtraction_numeral.length == 1, "test_roman_numeral_subtract: expecting valid subtraction numeral result for inputs %s and %s to be (1), but found a value of 0\n", numeral1.digits, numeral2.digits);
}
END_TEST

void convert_to_roman(RomanCount_t val, RomanNumeral_t *numeral) 
{
    const char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const int   size[] = { 0,   1,    2,     3,    2,   1,    2,     3,      4,    2};

    int idx = 0;

    while (val >= 1000) 
    {
        numeral->digits[idx] = 'M';
        idx++;
        numeral->digits[idx] = 0;
        val -= 1000;
    }

    strcat (numeral->digits, huns[val/100]); 
    idx += size[val/100]; 
    val = val % 100;

    strcat (numeral->digits, tens[val/10]);  
    idx += size[val/10];  
    val = val % 10;

    strcat (numeral->digits, ones[val]);
    idx += size[val];

    numeral->digits[idx] = 0;
}

int roman_digit_value(RomanDigit_t c)
{

    int value=0;

    switch(c)
    {
         case 'I': value = 1; break;

         case 'V': value = 5; break;

         case 'X': value = 10; break;

         case 'L': value = 50; break;

         case 'C': value = 100; break;

         case 'D': value = 500; break;

         case 'M': value = 1000; break;

         case '\0': value = 0; break;

         default: value = -1;  
    }

    return value;
}

void roman_convert_to_integer(RomanNumeral_t *numeral, RomanCount_t *value)
{
    RomanCount_t i = 0;

    *value = 0;

    while (numeral->digits[i] > 0)
    {

         if (roman_digit_value(numeral->digits[i]) < 0)
         {
             printf("Invalid roman digit : %c", numeral->digits[i]);
             *value = 0;
         }

         if ((strlen(numeral->digits) - i) > 2)
         {

             if (roman_digit_value(numeral->digits[i]) < roman_digit_value(numeral->digits[i+2]))
             {

                 printf("Invalid roman number");
                 *value = 0;
             }
         }

         if (roman_digit_value(numeral->digits[i]) >= roman_digit_value(numeral->digits[i+1]))
         {
             *value = *value + roman_digit_value(numeral->digits[i]);
         }
         else
         {
             *value = *value + (roman_digit_value(numeral->digits[i+1]) - roman_digit_value(numeral->digits[i]));
             i++;
         }
         i++;
    }
}

START_TEST(test_roman_numeral_add_all)
{
    RomanNumeral_t  addition_numeral1;
    RomanNumeral_t  addition_numeral2;
    RomanCount_t    addition_result1;
    RomanCount_t    addition_result2;
    char            add_digits1[80];
    char            add_digits2[80];
    int             compare_value;
    char            digits1[80];
    char            digits2[80];
    RomanBool_t     initialize_status;
    RomanNumeral_t  numeral1;
    RomanNumeral_t  numeral2;
    RomanBool_t     result;
    RomanCount_t    value1;
    RomanCount_t    value2;

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_numeral_add_all: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);

#if 0

    for (value1 = 0; value1 < 2000; value1++)
    {
        strcpy(digits1, "");
        numeral1.digits = digits1;
        numeral1.length = strlen(numeral1.digits);
        convert_to_roman(value1, &numeral1);
        printf("Roman numeral string for value 1 %d is %s\n", value1, numeral1.digits);
    }
    exit(0);
#endif

    for (value1 = 0; value1 < 1000; value1++)
    {
        strcpy(digits1, "");
        numeral1.digits = digits1;
        numeral1.length = strlen(numeral1.digits);
        convert_to_roman(value1, &numeral1);
        /* printf("Roman numeral string for value 1 %d is %s\n", value1, numeral1.digits); */

        for (value2 = 0; value2 < 1000; value2++)
        {
            addition_result2 = value1 + value2;
            strcpy(add_digits2, "");
            addition_numeral2.digits = add_digits2;
            addition_numeral2.length = strlen(addition_numeral2.digits);
            convert_to_roman(addition_result2, &addition_numeral2);
            addition_numeral2.length = strlen(addition_numeral2.digits);
            /* printf("Roman numeral string for value add 2 %d is %s\n", addition_result2, addition_numeral2.digits); */

            strcpy(digits2, "");
            numeral2.digits = digits2;
            numeral2.length = strlen(numeral2.digits);
            convert_to_roman(value2, &numeral2);
            /* printf("Roman numeral string for value 2 %d is %s\n", value2, numeral2.digits); */

            strcpy(add_digits1, "");
            addition_numeral1.digits = add_digits1;
            addition_numeral1.length = strlen(addition_numeral1.digits);
            result = roman_numeral_add(&numeral1, &numeral2, &addition_numeral1);
            ck_assert_msg(result == ROMAN_TRUE, "test_roman_numeral_add_all: expecting add terms numeral for inputs %s and %s to be (1), but found a value of %d\n", numeral1.digits, numeral2.digits, result);
            roman_convert_to_integer(&addition_numeral1, &addition_result1);
            /* printf("Roman numeral string for value add 1 %d is %s\n", addition_result1, addition_numeral1.digits); */
            compare_value = strcmp(addition_numeral1.digits, addition_numeral2.digits);
            ck_assert_msg(compare_value == 0, "test_roman_numeral_add_all: expecting add terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, addition_numeral1.digits, compare_value);
            ck_assert_msg(addition_numeral1.length == addition_numeral2.length, "test_roman_numeral_add_all: expecting valid addition numeral result for inputs %s and %s to be (1), but found a value of 0\n", addition_numeral1.length, addition_numeral2.length);
        }
    }
}
END_TEST

START_TEST(test_roman_numeral_subtract_all)
{
    RomanBool_t     compare_result;
    int             compare_value;
    char            digits1[80];
    char            digits2[80];
    RomanBool_t     initialize_status;
    RomanNumeral_t  numeral1;
    RomanNumeral_t  numeral2;
    RomanBool_t     result;
    RomanNumeral_t  subtraction_numeral1;
    RomanNumeral_t  subtraction_numeral2;
    RomanCount_t    subtraction_result1;
    RomanCount_t    subtraction_result2;
    char            subtract_digits1[80];
    char            subtract_digits2[80];
    RomanCount_t    value1;
    RomanCount_t    value2;

    initialize_status = roman_initialize_library();
    ck_assert_msg(initialize_status == ROMAN_TRUE, "test_roman_numeral_subtract_all: expecting initialization status to be ROMAN_TRUE (1), but found a value of %d\n", initialize_status);

#if 0

    for (value1 = 0; value1 < 2000; value1++)
    {
        strcpy(digits1, "");
        numeral1.digits = digits1;
        numeral1.length = strlen(numeral1.digits);
        convert_to_roman(value1, &numeral1);
        printf("Roman numeral string for value 1 %d is %s\n", value1, numeral1.digits);
    }
    exit(0);
#endif

    for (value1 = 0; value1 < 2000; value1++)
    {
        strcpy(digits1, "");
        numeral1.digits = digits1;
        numeral1.length = strlen(numeral1.digits);
        convert_to_roman(value1, &numeral1);
        numeral1.length = strlen(numeral1.digits);
        /* printf("Roman numeral string for value 1 %d is %s\n", value1, numeral1.digits); */

        for (value2 = 0; value2 < 2000; value2++)
        {
            strcpy(subtract_digits2, "");
            subtraction_numeral2.digits = subtract_digits2;
            subtraction_numeral2.length = strlen(subtraction_numeral2.digits);

            if (value1 >= value2)
            {
                subtraction_result2 = value1 - value2;
                compare_result = ROMAN_TRUE;
                convert_to_roman(subtraction_result2, &subtraction_numeral2);
                subtraction_numeral2.length = strlen(subtraction_numeral2.digits);
                /* printf("Roman numeral string for value add 2 %d is %s\n", subtraction_result2, subtraction_numeral2.digits); */
            }
            else
            {
                subtraction_result2 = 0;
                compare_result = ROMAN_FALSE;
            }

            strcpy(digits2, "");
            numeral2.digits = digits2;
            numeral2.length = strlen(numeral2.digits);
            convert_to_roman(value2, &numeral2);
            numeral2.length = strlen(numeral2.digits);
            /* printf("Roman numeral string for value 2 %d is %s\n", value2, numeral2.digits); */

            strcpy(subtract_digits1, "");
            subtraction_numeral1.digits = subtract_digits1;
            subtraction_numeral1.length = strlen(subtraction_numeral1.digits);

            result = roman_numeral_subtract(&numeral1, &numeral2, &subtraction_numeral1);
            subtraction_numeral1.length = strlen(subtraction_numeral1.digits);
            ck_assert_msg(result == compare_result, "test_roman_numeral_subtract_all: expecting subtract terms numeral for inputs %s and %s to be (1), but found values of %d and %d\n", numeral1.digits, numeral2.digits, result, compare_result);
            roman_convert_to_integer(&subtraction_numeral1, &subtraction_result1);
            compare_value = strcmp(subtraction_numeral1.digits, subtraction_numeral2.digits);
            ck_assert_msg(compare_value == 0, "test_roman_numeral_subtract_all: expecting subtract terms numeral for inputs %s and %s to be %s (0), but found a value of %d\n", numeral1.digits, numeral2.digits, subtraction_numeral1.digits, compare_value);
            ck_assert_msg(subtraction_numeral1.length == subtraction_numeral2.length, "test_roman_numeral_subtract_all: expecting valid addition numeral result for inputs %s and %s to be (1), but found values %d and %d of 0\n", numeral1.digits, numeral2.digits, subtraction_numeral1.length, subtraction_numeral2.length);
        }
    }
}
END_TEST

Suite * roman_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_set_timeout(tc_core, 720);

    tcase_add_test(tc_core, test_roman_initialization);
    tcase_add_test(tc_core, test_roman_valid_digits);
    tcase_add_test(tc_core, test_roman_valid_sequential_digits);
    tcase_add_test(tc_core, test_roman_max_sequential_digits);
    tcase_add_test(tc_core, test_roman_compare_to_digits);
    tcase_add_test(tc_core, test_roman_valid_numeral);
    tcase_add_test(tc_core, test_roman_get_add_term);
    tcase_add_test(tc_core, test_roman_add_terms);
    tcase_add_test(tc_core, test_roman_subtract_terms);
    tcase_add_test(tc_core, test_roman_numeral_add);
    tcase_add_test(tc_core, test_roman_numeral_subtract);
    tcase_add_test(tc_core, test_roman_numeral_add_all);
    tcase_add_test(tc_core, test_roman_numeral_subtract_all);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(int argc, char **argv)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

