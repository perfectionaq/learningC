#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char s[6] = "hello";
    printf("%d\n", any(s, "oe"));
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;

    for(i = 0; s1[i] != '\0'; i++) {
        /* keep looping until a match is found */
        for(j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++)
            ;
        /* if the comparison string reached its end (\0) it means there is no match and we can add the character to the string */
        if (s2[j] != '\0') 
            return i;
    }

    return -1;
}