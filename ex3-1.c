#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int numbers[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int x = 4;

    printf("%d\n", binsearch(x, numbers, 10)); // result is 2 (index 2)
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low < high) {
        mid = ((low + high) / 2) + 1;
        if (x < v[mid])
            high = mid - 1;            
        else
            low = mid;
    }

    if (x == v[low])
        return low;

    return -1;
}