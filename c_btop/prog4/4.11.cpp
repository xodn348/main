/* Program 4.11 Reversing the digits */
#include <stdio.h>
int main(void)
{
    int number = 0;
    int rebmun = 0;
    int temp = 0;
    
    /* Get the value to be reversed */
    printf("\nEnter a positive integer : ");
    scanf("%d", &number);

    temp = number;

    /* Rverse the number stored in temp*/
    do
    {
        rebmun = rebmun * 10 + temp % 10;
        temp = temp / 10;
    } while (temp > 0);
    
    printf("\nThe number %d reversed is %d rebmun ehT\n", number, rebmun);
    return 0;
}