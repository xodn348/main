/* Program 9.2 Arrays of Pointers to functions */

#include <stdio.h>

/* Function prototypes */
int sum(int, int);
int product(int, int);
int difference(int, int);

int main(void)
{
    int a = 10;
    int b = 5;
    int result = 0;
    int (*pfun[3])(int, int);

    /* Initialize pointers to functions */
    pfun[0] = sum;
    pfun[1] = product;
    pfun[2] = difference;

    /* Execute each function pointed to */
    for(int i = 0 ; i < 3; i++)
    {
        result = pfun[i](a, b);
        printf("\nresult = %d", result);
    }

    /* Call all three functions through pointers in an expression*/
    result = pfun[1](pfun[0](a, b), pfun[2](a, b));
    printf("\n\nThe product of the sum and the difference = %d\n", result);
    
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}

int product(int x, int y)
{
    return x * y;
}

int difference(int x, int y)
{
    return x - y;
}
