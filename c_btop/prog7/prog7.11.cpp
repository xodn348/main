/* Program 7.11 A dynamic prime example */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    unsigned long *primes = NULL;
    unsigned long trial = 0;
    bool found = false;
    size_t total = 0;
    size_t count = 0;
    
    printf("How many primes would you like - you'll get at least 4? ");
    scanf("%lu", &total);
    total = total<4U ? 4U:total;
    
    /* Allocate sufficient memory to store the number of primes required */
    primes = (unsigned long *)malloc(total*sizeof(unsigned long));
    if(primes == NULL)
    {
        printf("\nNot enough memory. Hasta la Vista, baby.\n");
        return 1;
    }
    
    /* We know the first three primes*/
    /* so let's give the program a start*/
    *primes = 2UL;
    *(primes+1) = 3UL;
    *(primes+2) = 5UL;
    count = 3U;
    trial = 5UL;

    while(count < total)
    {
        trial += 2UL;

        /* Try dividing by each of the primes we have*/
        /* If any divide exactly - the number is not prime */
        for(size_t i = 0; i < count; i++)       /* Next value for checking */
            if(!(found = (trial %*(primes+i))))
                break;                          /* Exit if no remainder = not prime */

        if(found)                               /* we got one - if found is true */
            *(primes+count++) = trial;          /* Store it and increment count */
    }

    /* Display the primes 5-up */
    for(size_t i = 0; i < total; i++)
    {
        if(!(i%5U))
            printf("\n");
        printf("%12lu", *(primes+i));
    }
    printf("\n");
    return 0;
}
