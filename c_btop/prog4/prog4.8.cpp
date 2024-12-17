/* Program 4.8 While programming and summing integers */
#include <stdio.h>
int main(void)
{
    long sum = 0L;
    int i = 1;
    int count = 0;

    /* Get the count of the number of integers to sum */
    printf("\nEnter the number of integers you want to sum: ");
    scanf("%d", &count);

    /* Sum the integers from 1 to count */
    while(i <= count)
        sum+= i++;

    printf("\nTotal of the first %d numbers is %ld\n", count, sum);
    return 0;
}