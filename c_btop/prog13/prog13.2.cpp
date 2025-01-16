/* Program 13.2 Demonstrating assertions */
#undef NDEBUG
#include <stdio.h>
#include <assert.h>

int main(void)
{
    int y = 5;
    for(int x = 0 ; x < 20 ; x++)
    {
        printf("\nx = %d y = %d", x, y);
        /* Switch on assertions */
        assert(x<y);
    }
    return 0;
}