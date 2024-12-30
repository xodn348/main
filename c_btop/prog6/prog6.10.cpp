/* Program 6.10 Analyzing text */
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>


#define TEXTLEN 10000 /* Maximum length of text */
#define BUFFERSIZE 100 /* Input buffer size */
#define MAXWORDS 500
#define WORDLEN 15

int main(void)
{
    char text[TEXTLEN+1];
    char buffer[BUFFERSIZE];
    char endstr[] = "*\n";

    const char space = ' ';
    const char quote = '\'';

    char words[MAXWORDS][WORDLEN+1];
    int nword[MAXWORDS];
    char word[WORDLEN+1];
    int wordlen = 0;
    int wordcount = 0;

    printf("Enter text on an arbitrary numer of lines.");
    printf("\nEnter a line containing just an asterisk to end input:\n\n");

    /* Read an arbitrary number of lines of text */
    while(true)
    {
        if(!strcmp(fgets(buffer, BUFFERSIZE, stdin), endstr))
            break;
        
        if(strlen(text)+strlen(buffer)+1 > TEXTLEN)
        {
            printf("Maximum capacity for text rxceeded. Teminating program.");
            return 1;
        }
        strcat(text, buffer);
    }

    /* Replace everthing except alpha and single quote characters by spaces */
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == quote || isalnum(text[i]))
            continue;
        text[i] = space;
    }

    /* Find unique words and store in words array */
    int index = 0;
    while(true)
    {
        /* Ignore any leading spaces before a word*/
        while(text[index] == space)
            ++index;

        /* If we are at the end of text, we are done */
        if(text[index] == '\0')
            break;
        
        /* Extract a word */
        wordlen = 0;
        while(text[index] == quote || isalpha(text[index]))
        {
            /* Check if word is too long*/
            if(wordlen == WORDLEN)
            {
                printf("Maximum word length exceeded. Terminating program.");
                return 1;
            }
            word[wordlen++] = tolower(text[index++]);
        }
        word[wordlen++] = '\0';

        /* Check for word already stored */
        bool isnew = true;
        for(int i = 0; i < wordcount; i++)
            if(strcmp(word, words[i]) == 0)
            {
                ++nword[i];
                isnew = false;
                break;
            }
        if(isnew)
        {
            /* Check if we have space for another word*/
            if(wordcount >= MAXWORDS)
            {
                printf("\n MAXIMUM word count exceeded. Terminating program.");
                return 1;
            }

            strcpy(words[wordcount], word);
            nword[wordcount++] = 1;
        }
    }
    /* Output the words and frequencies */
    for(int i = 0; i<wordcount; i++)
    {
        if(!(i%3))
            printf("\n");
        printf(" %-15s%5d", words[i], nword[i]);
    }

    return 0;
}