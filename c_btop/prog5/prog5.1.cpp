/* Program 5.1 Averaging ten numbers without storing the numbers */
#include <stdio.h>

int main(void)
{
    int number = 0;
    int count = 10;
    long sum = 0L;
    float average = 0.0f;

    /* Read the tem numbers to be averaged */
    for(int i = 0; i < count; i ++)
    {
        printf("Enter grade: ");
        scanf("%d", &number);
        sum += number;
    }

    average = (float)sum/count;

    printf("\nAverage of the tem numbers entered is: %f\n", average);
    return 0;
}