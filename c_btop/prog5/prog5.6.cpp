/* Program 5.6 Know your hat size - if you dare... */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    /* The size array stores hat sizes from 6 1/2 to 7 7/8 */
    /* Each row defines one character of a size value so */
    /* a size is selected by using the same index for each*/
    /* the three rows. e.g. Index 2 selects 6 3/4. */
    char size[3][12] = { /* Hat sizes as characters */
        {'6', '6', '6', '6', '7', '7', '7', '7', '7', '7', '7', '7'},
        {'1', '5', '3', '7', ' ', '1', '1', '3', '1', '5', '3', '7'},
        {'2', '8', '4', '8', ' ', '8', '4', '8', '2', '8', '4', '8'}
    };    

    int headsize[12] = 
    {164, 166, 169, 172, 175, 178, 181, 184, 188, 191, 194, 197};

    float cranium = 0.0;
    int your_head = 0;
    int i = 0;
    bool hat_found = false;

    /* Get the circumference of the head */
    printf("\nEnter the circumference of your head above your eyebrows" 
    "in inches as a decimal value: ");
    scanf("%f", &cranium);

    /* Covert to whole eights of an inch*/
    your_head = (int)(8.0 * cranium);

    /* Search for a hat size */
    for(i = 1; i < 12; i++)
    {
        /* Find head size in the headsize array */
        if(your_head > headsize[i-1] && your_head <= headsize[i])
        {
            hat_found = true;
            break;
        }
        if(your_head == headsize[0])
        {
            i = 0;
            hat_found = true;
            break;
        }
    }

    if(hat_found)
        printf("\nYour hat size is %c %c%c%c\n", size[0][i], size[1][i], 
               (size[1][i] == ' ') ? ' ' : '/', size[2][i]);
    else
    {
        if(your_head < headsize[0])
            printf("\nYou are the proverbial pinhead. No hat for" "you I'm afraid.\n");
        else
            printf("\nYou, in technical parlance, are a hathead." 
                   "no hat for you, I'm afraid.\n");
    }

    return 0;
}