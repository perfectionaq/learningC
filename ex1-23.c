/* removes comment lines from input string */
#include <stdio.h>

#define MAXLENGTH 10000

int get_line(char s[], int lim);
void copy(char to[], char from[]);
void removeComments(char s[]);

int main()
{   
    int i, c;
    char s[MAXLENGTH] = { 0 };
    
    for (i = 0; ((c = getchar()) != EOF) && i < MAXLENGTH; ++i)
        s[i] = c;
    s[++i] = '\0';

    removeComments(s);

    return 0;
}

/**
 * There are multiple ways that comments can exist in C code
 * One way is to be a one line comment on a separate line
 * 
 * e.g. "// comment line"
 * 
 * Another way is to be a multi line comment like this commment :D
 * Lasly is can be part of a code line
 * 
 * e.g. "printf("%s\n", stringOfStrings) // prints the string of strings!"
 * 
 * OH! I also forgot it can exist in the middle of a code line (but please dont do this. its sacrilege)
 * 
 * e.g. "void removeComments( / * sacrilege comment * / char string[])"
 * 
 * You can test his program on itself!
*/

void removeComments(char string[])
{
    int i;

    for (i = 0; string[i] != '\0'; ++i) {
        /* here we check for a // comment 
        * if we find a // comment that means its a one line comment regardless of where it occurs
        * this means we need to ignore all characters until the end of line '\n'
        * at the end we manually put the '\n' character after the loop has stopped.
        */
        if (string[i] == '/' && string[i + 1] == '/') {
            while(string[i++] != '\n')
                ;
            --i;
            putchar('\n');
        } else if (string[i] == '/' && string[i + 1] == '*') {
            /**
             * This is to handle multi line comments or comments within "/ * * /"
             * we first skip the first two characters indicating the start of a comment
             * after checking for the beginning of a comment
             * we check if we're still within the comment 
             * by checking if no * / appeared yet
             * the only time when the while condition is false is if the last two characters in the comment are * /
             * we increment i to skip the / character
            */
            i += 2;

            while(string[i] != '*' || string[i + 1] != '/')
                ++i;
            ++i;
        } else {
            putchar(string[i]);
        }
    }
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