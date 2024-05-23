#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    printf("%u\n", bitcount(8)); // the result is 1
    return 0;
}


int bitcount(unsigned x)
{
    int count;

    for(count = 0; x != 0; count++)
        x &= (x - 1);
    return count;
}