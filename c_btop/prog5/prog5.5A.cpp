/* Program 5.5 Using the & operator */
#include<stdio.h>
int main(void)
{
    /* declare some integer variables */
    int a = 1L;
    int b = 2L;
    int c = 3L;

    /* declare some floating-point variables */
    float d = 4.0;
    float e = 5.0;
    float f = 6.0;

    printf("A variable of type int occupies %d bytes.", sizeof(int));
    printf("\nHere are the addresses of some variables of type int:");
    printf("\nThe address of a is: %p  The address of b is: %p", &a, &b);
    printf("\nThe address of c is: %p", &c);

    printf("\n\nA variable of type float occupies %d bytes.", sizeof(float));
    printf("\nHere are the addresses of some variables of type float:");
    printf("\nThe address of d is: %p  The address of e is: %p", &d, &e);
    printf("\nThe address of f is: %p\n", &f);

    return 0;
}

/* What you get will depend on what
operating system you’re using and what other programs are running at the time */