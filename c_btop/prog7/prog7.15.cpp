/* Program 7.15 An improved calculator */
#include <stdio.h> /* Standard input/output */
#include <string.h> /* For string functions */
#include <ctype.h> /* For character functions */
#include <stdlib.h> /* For malloc() and free() */
#include <math.h> /* For math functions */

#define BUFFER_LEN 256 /* Length of input buffer */

int main(void)
{
    char input[BUFFER_LEN]; 
    char number_string[30]; /* Buffer for number string */
    char op = 0;

    unsigned int index = 0; /* Index of the current character in input */
    unsigned int to = 0; /* To index for copying input to itself*/
    size_t input_length = 0; /* Length of the string in input */
    unsigned int number_length = 0;
    double result = 0.0;
    double number = 0.0;

    printf("\nTo use this calculator, enter any expression with"
                            " or without spaces");
    printf("\nAn expression may include the operators:");
    printf("\n         +, -, *, /, %%, or ^(raise to a power).");
    printf("\nUse = at the beginning of a line to operate on ");
    printf("\nthe result of the previous calculation.");
    printf("\nUse quit by itself to stop the calculator.\n\n");

    /* The main calculator loop*/
    while(strcmp(fgets(input, BUFFER_LEN, stdin), "quit\n") != 0)
    {
        input_length = strlen(input);
        input[--input_length] = '\0';

        
        /* Remove all spaces from the input by copying the string to itself */
        /* including the string terminating character */
        for(to = 0, index = 0; index <= input_length; index++)
        if(*(input+index) != ' ')
            *(input+to++) = *(input+index);

        input_length = strlen(input);
        index = 0;

        if(input[index] == '=')
            index++;
        else
        {   /* Check for sign and copy it*/
            number_length = 0;
            if(input[index] =='+' || input[index] == '-')
            *(number_string+number_length++) = *(input+index++);

            /* Copy all following digits*/
            for( ; isdigit(*(input+index)) ; index++)
            *(number_string+number_length++) = *(input+index);

            /* Copy any fractional part*/
            if(*(input+index)=='.')
            {/* Yes so copy the decimal point and the following digits */
                *(number_string+number_length++) = *(input+index++);
                // Get fraction digits
                for( ; isdigit(*(input+index)); index++)
                    *(number_string+number_length++) = *(input+index);                   
            }
            *(number_string+number_length) = '\0';

            /* If we have a left operand, the length of number_string */
            /* will be > 0. In this case convert to a double so we     */
            /* can use it in the calculation */
            if(number_length>0)
                result = atof(number_string);
        }

        /* Now look for 'op number' combinattions */ 
        for(;index < input_length;)
        {
            op = *(input+index++);
            /* Copy the next operand and store it in number */
            number_length = 0;

            /* Check for sign and copy it */
            if(input[index] =='+' || input[index] =='-')
            *(number_string+number_length++) = *(input+ index++);

            /* Copy all following digits */
            for( ; isdigit(*(input+index)) ; index++)
                *(number_string+number_length++) = *(input+index);

            /* Copy any fractional part */
            if(*(input+index)=='.')
            {   /* Yes so copy the decimal point and the following digits */
                /* Copy the decimal point and the following digits       */
                *(number_string+number_length++) = *(input+index++);
                for( ; isdigit(*(input+index)); index++)
                    *(number_string+number_length++) = *(input+index);
            }
            *(number_string+number_length) = '\0';

            /* Conver to a double so we can use it in the calculation */
            number = atof(number_string);

            /* excute operation, as 'result op = number*/
            switch(op)
            {
                case '+' :
                    result += number;
                    break;
                case '-' :
                    result -= number;
                    break;  
                case '*' :
                    result *= number;
                    break;
                case '/' :
                    if(number == 0)
                        printf("\n\n\aDivision bt zero error!\n");
                    else
                        result /= number;
                    break;
                case '%' :
                    if((long)number == 0)
                        printf("\n\n\aDivision by zero error!\n");
                    else
                        result = (double)((long)result % (long)number);
                    break;
                case '^' :
                    result = pow(result, number);
                    break;
                default :
                    printf("\n\n\aIllegal operation!\n");
                    break;
            }
        }
        printf("= %f\n", result);
    }
    return 0;
}
