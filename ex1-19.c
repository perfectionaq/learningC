#include <stdio.h>

#define MAX_LINE_LENGTH 1000

void copy(char to[], char from[]);
int get_line(char s[], int lim);
void reverse(char source[]);

int main()
{
    char s[MAX_LINE_LENGTH];

    while (get_line(s, MAX_LINE_LENGTH) > 0) {
        reverse(s);
        printf("%s\n", s);
    }
        
    return 0;
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

void reverse(char source[]) 
{
    int i;
    int lineLength;    
    char tempString[MAX_LINE_LENGTH];
    
    // Create a temporary copy of the original string
    copy(tempString, source);

    // find the length of the string
    lineLength = 0;
    while(tempString[lineLength] != '\n')
        ++lineLength;

    // set the source string characters from the end of the temporary
    for(i = 0; i <= lineLength; i++)
        source[i] = tempString[lineLength - i];
}