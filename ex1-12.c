#include <stdio.h>

int main() 
{
    int c;

    while((c = getchar()) != EOF) {
        // if the current character isn't a blank space or end of line we print the character as is
        if (c != ' ' && c != '\t' && c != '\n') {
            putchar(c);
        } else {
            // otherwise we print a newline character since a blank character indicates the end of a word
            // we first need to skip any additional subsequent blank characters if any
            // then we print the newline character
            // and the last character which broke the loop
            while((c = getchar()) == ' ' || c == '\t' || c == '\n')
                ;
            putchar('\n');
            putchar(c);
        }
    }
    return 0;
}