/* Program 3.2 Using if statements to decide on a discount */
#include <stdio.h>

int main(void) 
{
    const long unit_price = 350L; /* Unit price in cents */
    int quantity = 0;
    printf("Enter the number that you want to buy:"); /* Prompt message */
    scanf(" %d", &quantity); /* Read the input */
    long discount = 0L; /* Discount allowed */
    
    if(quantity>10)
    discount = 5L; /* 5% discount */
    
    long total_price = quantity*unit_price*(100-discount)/100;
    long dollars = total_price/100;
    long cents = total_price%100;
    
    printf("\nThe price for %d is $%ld.%ld\n", quantity, dollars,cents);    
    
    return 0;
}