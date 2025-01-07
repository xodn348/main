/* Program 10.1 Exercising formatted input */
#include <stdio.h>
const size_t SIZE = 20; /* Max characters in a word */

int main(void)
{
    int value_count = 0;
    float fp1 = 0.0;
    int i = 0;
    int j = 0;
    char word1[SIZE] = " ";
    char word2[SIZE] = " ";
    int byte_count = 0;

    value_count = scanf("%f %d %d %[abcdefghijklmnopqrstuvwxyz] %*1d %s%n",
                                &fp1, &i , &j, word1, word2, &byte_count);
    printf("\nCount of bytes read = %d\n", byte_count);
    printf("\nCount of values read = %d\n", value_count);
    printf("\nfp1 = %f i = %d j = %d", fp1, i, j);
    printf("\nword1 = %s word2 = %s\n", word1, word2);
    return 0;
}
