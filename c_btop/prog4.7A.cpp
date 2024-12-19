/* Program 4.7 A Guessing Game */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(void)
{
    int chosen = 0;
    int guess =0;
    int count =3;
    int limit = 20;

    srand(time(NULL));
    chosen = 1+ rand()%limit;

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

    /* Check for an invalid guess */
    if(guess<1 || guess > 20)
        printf("\nI said the number is between 1 and 20.\n");
    else
        printf("\nSorry, %d is wrong.\n", guess);
    }
    
    printf("\nYou have had three tries and failed. The number was %ld\n", chosen);
    return 0;
}