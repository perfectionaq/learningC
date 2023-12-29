#include <stdio.h>

#define TAPSTOP 4
#define MAXLENGTH 1000

void entab(char string[]);
int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main()
{   
    char s[MAXLENGTH] = { 0 };
    get_line(s, MAXLENGTH);
    entab(s);

    printf("%s\n", s);
    return 0;
}

void entab(char string[])
{
    char temp[MAXLENGTH] = { 0 };
    int i, j;
    int numberOfTabs;
    int numberOfSpaces;

    for (i = j = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ') {
            for (numberOfSpaces = 0; string[i] == ' '; ++i, ++numberOfSpaces)
                ;

            --i;
            numberOfTabs = numberOfSpaces / TAPSTOP;
            numberOfSpaces = numberOfSpaces % TAPSTOP;

            printf("spaces: %d tabs: %d\n", numberOfSpaces, numberOfTabs);
            while(numberOfTabs-- > 0)
                temp[j++] = '\t';
            while(numberOfSpaces-- > 0)
                temp[j++] = ' ';
            
        } else {
            temp[j++] = string[i];
        }
    }
    temp[++j] = '\0';
    copy(string, temp);
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')  
        ++i;
}