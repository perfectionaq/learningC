#include <stdio.h>

int invert(unsigned x, int p, int n);

int main()
{
    unsigned char x = 156;
    printf("%u\n", y);
    return 0;
}

int invert(unsigned x, int p, int n)
{
    return x ^ ~(~0 << n) << (p + 1 - n);
}
