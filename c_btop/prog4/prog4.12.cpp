/* Program 4.12 Simple Simon */
#include <stdio.h> /* For input and output */
#include <ctype.h> /* For toupper() function */
#include <stdbool.h> /* For bool, true, false */
#include <stdlib.h> /* For rand() and srand() */
#include <time.h> /* For time() */

int main(void)
{
    /* Records if another game is to be played */
    char another_game = 'Y';

    /*Rest of the declarations for the program */
    bool correct = false;

    /* Number of sequences entered successfully */
    int counter = 0;

    int sequence_length = 0;
    time_t seed = 0;
    int number = 0;
    
    time_t now = 0;
    int time_taken = 0;

    /* Descrive how the game is played */
    printf("\nTo play Simple Simon, ");
    printf("\nwatch the sceen for a sequence of digits.");
    printf("\nWatch carefully, as the digits are only displayed!"
                                                "for a second!");
    printf("\nThe computer will remove them, and then prompt you");
    printf("to enter the same sequence.");
    printf("\nWhen you do, you must put spaces between the digits. \n");
    printf("\nGood Luck! \nPress Enter to play\n");
    scanf("%c", &another_game);

    /* One outer loop iteration is one game */
    do
    {
        correct = true;
        counter = 0;
        sequence_length = 2;
        time_taken = clock();

        while(correct)
        {
            /* On every third successful try, increase the sequence length */
            sequence_length += counter++%3 == 0;

            /* Set seed to be the number of seconds since Jan 1, 1970 */
            seed = time(NULL);
            now = clock();

            /* Generate a sequence of numbers and display the number */
            srand((unsigned int)seed);
            for(int i = 1; i <= sequence_length; i++)
                printf("%d", rand() %10);
            fflush(stdout);

            /* Wait for 1 second */
            for( ;clock()- now < CLOCKS_PER_SEC ;);

            /* Clear the line by moving cursor back and overwriting */
            printf("\r");
            for(int i = 1; i <= sequence_length; i++)
                printf(" ");
            printf("\r");
            fflush(stdout);

            if(counter == 1)
                printf("\nNow you enter the sequence - don't forhet"
                                                        "the spaces\n");
            else
                printf("\r");

            /* Check the input sequence of digits against the original*/
            srand((unsigned int)seed);
            for(int i = 1; i <= sequence_length; i++)
            {
                scanf("%d", &number);
                if(number != rand() %10)
                {
                    correct = false;
                    break;
                }
            }
            printf("%s\n", correct? "Correct!" : "Wrong!");
        }

        time_taken = (clock() - time_taken) / CLOCKS_PER_SEC;
        
        printf("\n\n Your score is %d", --counter * 100 / time_taken);

        fflush(stdin);

        /* Output if a new game is required */
        printf("\nDo you want to play again (y/n)? ");
        scanf("%c", &another_game);
    } while(toupper(another_game) == 'Y');
    return 0;
}