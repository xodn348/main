/* Program 8.8 A function to increase your salary that doesn't work */
#include <stdio.h>

long *IncomePlus(long* pPay); /* Prototype for increase function */

int main(void)
{
    long your_pay = 30000L;
    long *pold_pay = &your_pay;
    long *pnew_pay = NULL;

    pnew_pay = IncomePlus(pold_pay);
    printf("\nOld pay = $%ld New pay = $%ld\n", *pold_pay, *pnew_pay);

    return 0;
}

/* Definition of function to increment pay */
long *IncomePlus(long *pPay)
{
    long pay = 0;
    
    pay = *pPay + 10000;
    return &pay;
}
