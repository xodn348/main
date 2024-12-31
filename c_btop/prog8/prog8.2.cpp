/* Program 8.2 More scope in this one */
#include <stdio.h>
int main(void)
{
    int count = 0;
    do
    {
        int count = 0;
        ++count;
        printf("\ncount = %d", count);
    } while (++count <= 8);

    /* Inner count is dead, this is outer */
    printf("\ncount = %d\n", count);
    return 0;
}
