/* Program 4.10 Sums of integers with a while loop nested in a for loop */
#include <stdio.h>
int main(void)
{
    long sum = 1L;
    int j = 1;
    int count = 0;

    /* Prompt for, and read the input count */
    printf("\nEnter the number of integers you want to sum:");
    scanf("%d", &count);

    for(int i = 1; i <= count; i++)
    {
        sum = 1L;
        j=1;
        printf("\n1");

        /* Calculate sum of integers from 1 to i*/
        while(j < i)
        {
            sum += ++j;
            printf("+%d", j);
        }
        printf("= %ld\n", sum);
    }
    return 0;
}
