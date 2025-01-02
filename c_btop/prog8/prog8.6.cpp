/* Program 8.6 The functional approach to string sorting*/
#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For malloc, free
#include <stdbool.h>    // For bool type
#include <string.h>     // For string functions like strcmp

// Function prototypes
bool str_in(char **);                  // Read a string from input
void str_sort(char *p[], size_t n);    // Sort array of strings
void swap(void **p1, void **p2);       // Swap two pointers
void str_out(char *p[], size_t n);     // Output sorted strings

const size_t BUFFER_LEN = 256;         // Maximum length of input string
const size_t NUM_P = 50;               // Maximum number of strings

int main(void)
{
    char *pS[NUM_P];                   // Array of pointers to strings
    size_t count = 0;                  // Count of strings read

    // Print instructions for user
    printf("\nEnter successive lines, pressing Enter at the end of"
                            " each line.\nJust press Enter to end.\n");

    // Read strings until array full or empty line entered
    for(count = 0; count < NUM_P; count++)
        if(!str_in(&pS[count]))        // Read string, break if empty
            break;

    str_sort(pS, count);               // Sort the strings
    str_out(pS, count);                // Output and free memory
    return 0;
}

bool str_in(char **pString)
{
    char buffer[BUFFER_LEN];           // Temporary buffer for input

    // Read a line from stdin
    if(fgets(buffer, BUFFER_LEN, stdin) == NULL)
    {
        printf("\nError reading string.\n");
        exit(1);
    }

    // Remove newline if present
    size_t len = strlen(buffer);       // Get string length
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';          // Replace newline with null
        len--;                         // Adjust length
    }

    // Check for empty or whitespace-only input
    if(len == 0 || buffer[0] == '\0' || buffer[0] == '\n')
        return false;                  // Return false for empty input

    // Check if string is only whitespace
    bool only_spaces = true;
    for(size_t i = 0; i < len; i++) {
        if(buffer[i] != ' ' && buffer[i] != '\t') {
            only_spaces = false;        // Found non-whitespace
            break;
        }
    }
    if(only_spaces)
        return false;                  // Return false if only whitespace

    // Allocate memory for the string
    *pString = (char*)malloc(len + 1); // +1 for null terminator
    if(*pString == NULL)               // Check if allocation failed
    {
        printf("\nOut of memory.");
        exit(1);
    }

    strcpy(*pString, buffer);          // Copy string to allocated memory
    return true;                       // Return success
}

void str_sort(char *p[], size_t n)
{
    bool sorted = false;               // Flag for sort completion
    while(!sorted)                     // Continue until no swaps needed
    {
        sorted = true;                 // Assume sorted
        for(size_t i = 0; i < n-1 ; i++)
            if(strcmp(p[i], p[i+1]) > 0)  // Compare adjacent strings
            {
                sorted = false;           // Mark as not sorted
                swap((void**)&p[i], (void**)&p[i+1]);  // Swap pointers
            }
    }
}

void swap(void **p1, void **p2)
{
    void *pt = *p1;                    // Store first pointer
    *p1 = *p2;                         // Copy second to first
    *p2 = pt;                         // Copy stored to second
}

void str_out(char *p[], size_t n)
{
    printf("\nYour input sorted in order is:\n\n");
    for(size_t i = 0 ; i < n ; i++)
    {
        printf("%s\n", p[i]);          // Print each string
        free(p[i]);                    // Free string memory
        p[i] = NULL;                   // Clear pointer
    }
    return;
}
