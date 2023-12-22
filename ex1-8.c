#include <stdio.h>

int main()
{
    int c, spcn;

    spcn = 0;
    while((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++spcn;
    printf("%d\n", spcn);
    
    return 0;
}