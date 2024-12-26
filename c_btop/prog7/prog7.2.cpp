/* Program 7.2 What's the pointer */
#include <stdio.h>

int main(void)
{
    long num1 = 0L;
    long num2 = 0L;
    long *pnum = NULL;

    pnum = &num1;
    *pnum = 2;
    ++num2;
    printf("\nPointer details:"
           "\n- Address where pointer is stored (address of pnum): %p"
           "\n- size of pointer: %d bytes"
           "\n- Value stored in pointer (address of num1): %p"
           "\n- Value pointed to (*pnum): %ld", 
           &pnum, sizeof(pnum), pnum, *pnum);
    num2 += *pnum;

    pnum = &num2;
    ++*pnum;
    printf("\n\nPointer details:"
           "\n- Address where pointer is stored (address of pnum): %p"
           "\n- size of pointer: %d bytes"
           "\n- Value stored in pointer (address of num2): %p"
           "\n- Value pointed to (*pnum): %ld", 
           &pnum, sizeof(pnum), pnum, *pnum);

    printf("\n\nnum1 = %ld num2 = %ld *pnum = %ld *pnum + num2 = %ld\n",
                                        num1, num2, *pnum, *pnum + num2);
    return 0;
}