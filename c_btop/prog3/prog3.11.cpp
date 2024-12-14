/* Program 3.11 A calculator */
#include <stdio.h>

/* Step1. Getting the user input */

int main(void)
{
    double number1 = 0.0;
    double number2 = 0.0;
    char operation = 0;

    printf("\nEnter the calculation\n");
    scanf("%lf %c %lf", &number1, &operation, &number2);

/* Step2. check to make sure the input is valid */
/* Step3. perform the calculation */
/* Step4. display the output */
    switch(operation)
    {
        case '+':
            printf("= %lf\n", number1 + number2);
            break;
        
        case '-':
            printf("= %lf\n", number1 - number2);
            break;
        
        case '*':
            printf("= %lf\n", number1 * number2);
            break;
        
        case '/':
            if(number2 ==0)
                printf("\n\na Division by zero error!\n");
            else
                printf("= %lf\n", number1 / number2);
            break;
        
        case '%':
            if((long)number2 == 0)
                printf("\n\na Division be zero error!\n");            
            else
                printf("= %lf\n", (long)number1 % (long)number2);
            break;
        
        default:
            printf("\n\na Illegal operation!\n");
            break;
    }
    return 0;
}