// detab program
#include <stdio.h>

/* What is required (as far as I understand) in this question is a behavior similar to a text editor
// For example: assume that the tabstop (number of spaces inserted when you press the tap button)
* is 4. if you are at position 0 in the text (beginning to write or at the beginning of a line)
* then you will jump 4 spaces (because the tapstop is 4).
* however if you are at position 2 and you press tap you will still jump to position 4 and add only 2 spaces.
* basically we will need to add a number of spaces equal to the amount of remaining spaces to reach the next tapstop position
* The next tapstop position can be calculated by (currentPosition % tapstop)
* e.g. tap stop is 4 and currentPosition is 2 then 2 % 4 = 2 (this is the amount of spaces needed to be added)
* another example if the taptop is 4 and the position is 11 then 11 % 4 = 3
*/

#define TAPSTOP 4
#define MAXLENGTH 1000

void detab(char string[]);
int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    char s[MAXLENGTH];
    get_line(s, MAXLENGTH);
    detab(s);
    printf("%s\n", s);
    return 0;
}

/* I opted to replace the tabs in the input as opposed to simply outputing a new string */
void detab(char string[])
{   
    // Length here isn't accurate
    // assuming a string of MAXLENGTH \t characters
    // we would need at least MAXLENGTH * TABSTOP
    // but it will do for my purposes :D
    char temp[MAXLENGTH] = {0};

    // i is to track the loop over the input string
    // j is to track the current position in the temp array
    // they are not always equal because replacing a \t with multiple spaces
    // changes the original input string. thus the i variable will not be pointing to the correct position
    // basically, replacing the tabs in place (in the same string) requires shifting
    // which is not being done here.
    int i, j;
    int remainingSpacesToNextTapStop = TAPSTOP;

    for (i = 0, j = i; string[i] != '\n'; ++i) {
        if (string[i] == '\t') {

            // i + 1 is required to accomodate for 0 indexing
            // e.g. assume a string "h\tworld"
            // at "h" i = 0
            // but 0 % 4 = 4 which is wrong
            // because there's already 1 character and 3 more to the TAPSTOP
            remainingSpacesToNextTapStop = TAPSTOP - ((i + 1) % TAPSTOP);
            for (;j < (i + remainingSpacesToNextTapStop); ++j)
                temp[j] = ' ';
            
        } else {
            temp[j] = string[i];
            ++j;
        }
    }
    
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