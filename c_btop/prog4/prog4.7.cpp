/* Program 4.7 A Guessing Game */
#include <stdio.h>
int main(void)
{
    int chosen = 15;
    int guess =0;
    int count =3;

    printf("\nThis is a guessing game.");
    printf("\nI have chosen a number between 1 and 20" 
                                    "which you must huess.\n");
    for( ; count>0; --count)
    {
    printf("\nYou have %d tr%s left.", count, count ==1? "y": "ies");
    printf("\nEnter a guess:");
    scanf("%d", &guess);

    /* check for a correct guess */
    if(guess == chosen)
    {
        printf("\nYou guessed it\n");
        return 0;
    }

    /*Check for an invalid guess */
    if(guess<1 || guess > 20)
        printf("\nI said the number is between 1 and 20.\n");
    else
        printf("\nSorry, %d is wrong.\n", guess);
    }
    printf("\nYou have had three tries and failed. The number was %d\n", chosen);
    return 0;
}