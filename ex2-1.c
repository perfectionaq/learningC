#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    /* Unsigned types have a minimum value of 0 by definition */

    printf("SIGNED CHAR MAX: %d\n", CHAR_MAX);
    printf("SIGNED CHAR MIN: %d\n", CHAR_MIN);
    printf("UNSIGNED CHAR MAX: %d\n", UCHAR_MAX);

    printf("SINGED INT MAX: %d\n", INT_MAX);
    printf("SIGNED INT MIN: %d\n", INT_MIN);
    printf("UNSIGNED INT MAX: %d\n", UINT_MAX);

    printf("SIGNED SHORT MAX: %d\n", SHRT_MAX);
    printf("SIGNED SHORT MIN: %d\n", SHRT_MIN);
    printf("UNSIGNED SHORT MAX: %d\n", USHRT_MAX);

    printf("SIGNED LONG MAX: %ld\n", LONG_MAX);
    printf("SIGNED LONG MIN: %ld\n", LONG_MIN);
    printf("UNSIGNED LONG MAX: %ld\n", ULONG_MAX);

    printf("FLOAT MAX: %.2f\n", FLT_MAX);
    printf("FLOAT MIN: %e\n", FLT_MIN);
    
    printf("DOUBLE MAX: %.2f\n", DBL_MAX);
    printf("DOUBLE MIN: %e\n", DBL_MIN);
    return 0;
}