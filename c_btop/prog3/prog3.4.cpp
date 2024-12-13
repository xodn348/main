/* Program 3.4 Converting uppercase to lowercase */
#include <stdio.h>
int main(void)
{
    char letter = 0;
    
    printf("Enter an uppercase letter:");
    scanf("%c", &letter);

    /* Check whether the input is uppercase */
    if(letter >= 'A')
        {
            if(letter <= 'Z')
            {
                letter = letter - 'A'+ 'a';
                printf("You entered an uppercase %c\n", letter);
            }
            else
                letter = letter - 'a' + 'A';
                printf("Try using the shift key Bud! I want a capital letter.\n");
                printf("It's gonna be %c\n", letter);    
        }
    else
        printf("You didn't enter an uppercase letter\n");
    return 0;
}