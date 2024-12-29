/* Program 7.12 Arrays of Pointers to Strings */
#include <stdio.h>
const size_t BUFFER_LEN = 512; /* Size of input buffer */

int main(void)
{
    char buffer[BUFFER_LEN];        // Single large buffer (512 bytes)
    char *pS[3] = {NULL};          // Array of 3 pointers to strings
    char *pbuffer = buffer;        // Pointer to start of buffer
    size_t index = 0;              // Current position in buffer

    printf("\nEntter 3 messages that total less than %u characters.", BUFFER_LEN-2);

    /* Read the strings from the keyboard */
    for(int i=0; i<3; i++)
    {
        printf("\nEnter %s messages\n", i>0 ? "another": "a");
        pS[i] = &buffer[index];

        /* Read up to the end of buffer if necessary*/
        for(; index<BUFFER_LEN ; index++)
            if((*(pbuffer+index) = getchar()) == '\n')
        {
            *(pbuffer+index++) = '\0';
            break;
        }

        /* Check for buffer capacity exceeded */
        if((index == BUFFER_LEN) && ((*(pbuffer+index-1) != '\0') || (i<2)))
        {
            printf("\nYou ran out of space in the buffer.");
            return 1;
        }
    }

    printf("\nThe strings you entered are:\n\n");
    for(int i = 0; i<3; i++)
        printf("%s\n", pS[i]);

    printf("The buffer has %d characters unused.\n", BUFFER_LEN-index);
    return 0;
}
