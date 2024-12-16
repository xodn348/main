/* Program 4.6 The almost indefinite loop - computing an average */
#include <stdio.h>
#include <ctype.h> /* For tolower() function */
int main(void)
{
    char answer;
    double total = 0.0;
    double value = 0.0;
    int count = 0;

    printf("\nThis program calculatees the average of any number of values.");


    for( ;; )
    {
        printf("\nEnter a value: ");
        scanf("%lf", &value);
        total += value;
        ++count;

        /* check for more input */
        printf("Do you want to enter another value? (Y or N): ");
        scanf("%c", &answer);

        if(tolower(answer) =='n')
            break;
    }

    /* output the average to 2 decimal places */
    printf("\nThe average is %.2f\n", total/count);
    return 0;
}