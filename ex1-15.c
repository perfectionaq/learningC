#include <stdio.h>

float ftoc(float fahr);

int main()
{
    float hundredF = 100.0;

    printf("%.2fF is %.2fC\n", hundredF, ftoc(hundredF));

    return 0;
}

float ftoc(float fahr)
{
    return 5 * (fahr - 32) / 9;
}