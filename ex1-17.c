#include <stdio.h>

#define LINE_LENGTH_THRESHOLD 80
#define MAX_LINE_LENGTH 1000

int getlinee(char line[], int maxline);

int main()
{
    char currentLine[MAX_LINE_LENGTH];
    int c, lineLength;

    while((lineLength = getlinee(currentLine, MAX_LINE_LENGTH)) > 0) {
        if (lineLength > LINE_LENGTH_THRESHOLD) 
            printf("%s\n", currentLine);
    }

    return 0;
}

int getlinee(char s[], int lim)
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