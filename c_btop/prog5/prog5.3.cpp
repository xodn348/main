/* Program 5.3 Averaging ten numbers - storing the numbers the easy way */
#include <stdio.h>
int main(void)
{
    int numbers[10];
    int count = 10;
    long sum = 0L;
    float average = 0.0f;

    printf("\nEnter the 10 numbers:\n");

    /* Read the ten numbers to be averaged */
    for(int i = 0; i < count; i++)
    {
        printf("%2d >> ", i+1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }
    average = (float)sum/count;

    printf("\nAverage of the ten numbers entered is: %f\n", average);
    return 0;
}