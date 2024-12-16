/* Program 4.4 Summing integers - compact version */
#include <stdio.h>
int main(void)
{
    long sum = 0L;
    int count = 0;

    /* Read the number of integers to be summed */
    printf("\nEnter the number of integers you want to sum: ");
    scanf(" %d", &count);

    /* Sum integers from 1 to count */
    for(int i = 1; i <= count; sum += i++);
    
    /* Display the sum */
    printf("\nTotal of the first %d numbers is %ld\n", count, sum);
    return 0;
}