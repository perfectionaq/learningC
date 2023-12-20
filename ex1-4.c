#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 100;
    step = 2;

    celsius = lower;

    while (celsius <= upper) {
        fahr = celsius * (9.0 / 5.0) + 32;
        printf("%3.0f\t%6.2f\n", celsius, fahr);
        celsius = celsius + step;
    }
    
    return 0;
}