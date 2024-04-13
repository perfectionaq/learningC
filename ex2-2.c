#include <stdio.h>

int get_line(char s[], int lim);

int main() 
{
    char string[1000];   
    get_line(string, 1000);

    printf("%send\n", string);
    return 0;
}

// Basically separate each condition in the for loop into its own condition
int get_line(char s[], int lim)
{
    int c, i;
    int continueLoop = 1;

    i = 0;
    while(continueLoop) {
        c = getchar();
        if (i >= lim - 1)
            continueLoop = 0;
        else if (c == '\n')
            continueLoop = 0;
        else if (c == EOF)
            continueLoop = 0;
        else
            s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}