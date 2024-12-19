/* Program 3.2 Using if statements to decide on a discount */
#include <stdio.h>

int main(void) 
{
    const double unit_price = 3.50;
    int quantity = 0;
    printf("Enter the number that you want to buy: ");
    scanf("%d", &quantity);

    /* Test for order quantity qualifying for a discount */
    if(quantity > 10)       /* 5% discount*/
    printf("The price for %d is $%.2f\n", quantity, quantity*unit_price*0.95);
    else                    /* No discount */   
    printf("The price for %d is $%.2f\n", quantity, quantity*unit_price);
    return 0;
}