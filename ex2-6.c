#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    printf("%d\n", setbits(162, 4, 2, 131)); // = 186
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    /*
    * The first thing that needs to be done is to isolate the n rightmost bit of y
    * this can be done by simply doing this operation y & ~(~0 << n) which will basically remove anything from the number
    * except for the n rightmost bits
    * for example if you have a number (131) = 1000 0011, after doing that operation you will be left with 0000 0011.
    * The second step is to move the rightmost n bits to the left so that they align with the position of p specified in the function parameter.
    * Which can be done by calculating the difference using (p + 1 - n)
    * The last step is to simply OR (|) the numbers together
    */
    return x | ((y & ~(~0 << n)) << (p + 1 - n));
}