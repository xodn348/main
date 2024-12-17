/* Program 4.9 Sums of integers step-by-step */
#include <stdio.h>

int main(void)
{
    long sum = 0L;
    int count = 0;

    /* Prompt for, and read the input count */
    printf("\nEnter the number of integers you want to sum : ");
    scanf("%d", &count);

    for(int i= 1; i <= count; i++)
    {
        sum = 0L;

        /* Calculate sum of integer from 1 to i*/
        for(int j = 1; j <= i; j++)
            sum += j;

        printf("\n%d\t%ld", i, sum);
    }
    return 0;
}