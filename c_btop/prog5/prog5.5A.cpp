/* Program 5.5 Using the & operator */
#include<stdio.h>

int main (void)
{
int data[5];

for(int i = 0 ; i<5 ; i++)
    {
        data[i] = 12*(i+1);
        printf("\ndata[%d] Address: %p Contents: %d", i, &data[i], data[i]);
    }
    return 0;
}   