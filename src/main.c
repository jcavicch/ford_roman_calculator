#include <stdlib.h>
#include <stdio.h>
#include "roman.h"

int main(int argc, char **argv)
{
    RomanDigit_t     digits1[80];
    RomanDigit_t     digits2[80];
    RomanNumeral_t   numeral1;
    RomanNumeral_t   numeral2;
    RomanNumeral_t   numeral_result;
    RomanBool_t      result;
    RomanDigit_t     result_digits[80];
    RomanBool_t      initialize_status;

    initialize_status = roman_initialize_library();
    if (initialize_status == ROMAN_FALSE)
    {
        printf("main: roman library initialization failed.\n");
        exit(1);
    }

    if (argc != 4)
    {
        printf("main: Invalid argument count: %d.\n", argc);
        printf("main: Usage: main numeral1 [+,-] numeral2\n");
        exit(1);
    }

    numeral1.digits = digits1;
    numeral1.digits[0] = 0;
    numeral1.length = 0;
    strcpy(numeral1.digits, argv[1]);

    if (roman_is_valid_numeral(&numeral1) == ROMAN_FALSE) 
    {
        printf("main: Invalid numeral1 entered: %s.\n", numeral1.digits);
        printf("main: Usage: main numeral1 [+,-] numeral2\n");
        exit(1);
    }

    if ((strcmp(argv[2], "+") != 0) && (strcmp(argv[2], "-") != 0))
    {
        printf("main: Invalid operator entered: %s.\n", argv[2]);
        printf("main: Usage: main numeral1 [+,-] numeral2\n");
        exit(1);
    }
    
    numeral2.digits = digits2;
    numeral2.digits[0] = 0;
    numeral2.length = 0;
    strcpy(numeral2.digits, argv[3]);

    if (roman_is_valid_numeral(&numeral2) == ROMAN_FALSE) 
    {
        printf("main: Invalid numeral2 entered: %s.\n", numeral2.digits);
        printf("main: Usage: main numeral1 [+,-] numeral2\n");
        exit(1);
    }

    numeral_result.digits = result_digits;
    numeral_result.digits[0] = 0;
    numeral_result.length = 0;

    if (strcmp(argv[2], "+") == 0)
    {
        result = roman_numeral_add(&numeral1, &numeral2, &numeral_result);
        if (result == ROMAN_TRUE)
        {
            printf("main: A numeral 1 %s plus numeral2 %s equals %s\n", numeral1.digits, numeral2.digits, numeral_result.digits);
        }
        else
        {
            printf("main: Error adding numeral 1 %s to numeral 2 %s\n", numeral1.digits, numeral2.digits);
            exit(1);
        }
    }
    else if (strcmp(argv[2], "-") == 0)
    {
        result = roman_numeral_subtract(&numeral1, &numeral2, &numeral_result);
        if (result == ROMAN_TRUE)
        {
            printf("main: A numeral 1 %s minus numeral2 %s equals %s\n", numeral1.digits, numeral2.digits, numeral_result.digits);
        }
        else
        {
            printf("main: Error subtracting numeral 1 %s from numeral 2 %s\n", numeral1.digits, numeral2.digits);
            exit(1);
        }
    }
    else
    {
        printf("main: Usage: main numeral1 [+,-] numeral2\n");
        exit(1);
    }

    return 0;
}

