#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s[6] = "hello";
    squeeze(s, "ol");

    printf("%s\n", s);
    return 0; 
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    i = j = k = 0;

    for(i; s1[i] != '\0'; i++) {

        /* keep looping until a match is found */
        for(k = 0; s2[k] != '\0' && s1[i] != s2[k]; k++)
            ;
        
        /* if the comparison string reached its end (\0) it means there is no match and we can add the character to the string */
        if (s2[k] == '\0') 
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
}