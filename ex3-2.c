#include <stdio.h>

#define MAX 100

void escape(char s[], char t[]);
void unescape(char s[], char t[])

int main()
{
    char s[MAX] = "this is a \t tab and \n a newline and a \b backspace";
    char t[MAX] = {};
    escape(s, t);
    printf("%s\n", t);
    return 0;
}

void escape(char s[], char t[])
{
    int i = 0;

    while(s[i] != '\0') {
        switch (s[i]) {
            case '\n':
                t[i] = '\\';
                t[++i] = 'n';
                break;
            case '\t':
                t[i] = '\\';
                t[++i] = 't';
                break;
            case '\b':
                t[i] = '\\';
                t[++i] = 'b';
                break;
            default:
                t[i] = s[i];
        }
        ++i;
    }
    t[i] = '\0';   
}