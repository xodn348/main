/* Program 3.9 Testing cases */
#include <stdio.h>

int main(void)
{
    char answer = 0;

    printf("Enter Y or N: ");
    scanf("%c", &answer);

    switch(answer)
    {
        case 'y': case 'Y':
            printf("\nYou respended in the addirmative.");
            break;
        
        case 'n': case 'N':
            printf("\nYou respended in the negative.");
            break;
        
        default:
            printf("\nYou did not respond correctly...");
            break;
    }
    return 0;
}