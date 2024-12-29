/* Program 7.13 Generalizing string input */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const size_t BUFFER_LEN = 128;  /* Length of input buffer */
const size_t NUM_P = 100;       /* maximum number of strings */

int main(void)
{
    char buffer[BUFFER_LEN];
    char *pS[NUM_P] = {NULL};
    char *pbuffer = buffer;
    int i = 0;

    printf("\nYou can enter up to %zu messages each up to %zu characters.",
                                        NUM_P, BUFFER_LEN-1);

    for(i = 0; i < NUM_P; i++)
    {
        pbuffer = buffer;  /* Reset buffer pointer for each new string */
        printf("\nEnter %s message, or press Enter to end\n",
            i > 0 ? "another" : "a");

        /* Read the string of up to BUFFER_LEN characters */
        while((pbuffer - buffer < BUFFER_LEN-1) &&
                    ((*pbuffer++ = getchar()) != '\n'));
        
        /* Check for empty line indicating end of input */
        if((pbuffer - buffer) <2)
            break;
        
        /* Check for string too long */
        if((pbuffer - buffer) == BUFFER_LEN && *(pbuffer-1)!= '\n')
        {
            printf("String too long - maximum %d characters allowed.", BUFFER_LEN);
            i--;
            continue;
        }
        *(pbuffer -1) = '\0';
        
        pS[i] = (char*)malloc(pbuffer-buffer);
        if(pS[i] == NULL)
        {
            printf("\nOut of memory - ending program.");
            return 1;
        }

        /* Copy string from buffer to new memory */
        strcpy(pS[i], buffer);
    }

    /* Output all the strings */
    printf("\nIn reverse order, the strings you entered are:\n");
    while(--i >= 0)
    {
        printf("\n%s", pS[i]);
        free(pS[i]);  // Free memory
        pS[i] = NULL;
    }
    return 0;
}
