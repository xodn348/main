/* Program 9.1 Pointing to functions */
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
    int (*pfun)(int, int);

    pfun = sum;
    result = pfun(a, b);
    printf("\npfun = sum             \tresult = %d", result);

    pfun = product;
    result = pfun(a, b);
    printf("\npfun = product         \tresult = %d", result);

    pfun = difference;
    result = pfun(a, b);
    printf("\npfun = difference      \tresult = %d\n", result);

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
