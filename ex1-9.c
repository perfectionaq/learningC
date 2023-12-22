#include <stdio.h>

int main()
{
    // character input
    int c;

    while ((c = getchar()) != EOF) {
        // if the character is not a space print the character
        if (c != ' ') {
            putchar(c);
        } else {
            // otherwise: print the character (we'll always print the first space)
            putchar(c);

            // skip all subsequent spaces;
            while((c = getchar()) == ' ')
                ;
            // print the last character read from input
            // this character will be a non-blank character since we're now out of the loop
            // if we don't print the character, then every character after a single or a sequence of blanks would not be printed
            // the check is needed to handle the case where the last sequence of spaces is right before the EOF
            if (c != EOF)
                putchar(c);
        }
    }
    return 0;
}