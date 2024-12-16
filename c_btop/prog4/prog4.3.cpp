/* Program 4.3 Sum the integers from 1 to a user-specified number */
#include <stdio.h>
int main(void)
{
    long sum = 0L;
    int count = 0;

    /* Read the numver of integers to be summed */
    printf("\nEnter the number of integers you want to sum: ");
    scanf("%d", &count);

    /* Sum integers from 1 to count */
    for(int i = 1; i <= count; i++)
        sum += i;

    /* Display the sum */
    printf("\nTotal of the first %d numbers is %ld\n", count, sum);
    return 0;
}