/* Program 8.4 The change that doesn't */
#include <stdio.h>

int change(int *pnumber); /* Function prototype */

int main(void)
{
    int number = 10;
    int *pnumber = &number;
    int result = 0;

    result = change(pnumber);
    printf("\nIn main, result = %d\tnumber = %d", result, number);
    return 0;
}

/* Definition of the function change () */
int change(int *pnumber)
{
    *pnumber *= 2;
    printf("\nIn function change, *pnumber = %d\n", *pnumber);
    return *pnumber;
}
