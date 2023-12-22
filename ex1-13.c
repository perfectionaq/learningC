#include <stdio.h>


// Note: this exercise is about arrays but I didnt notice till I wrote the solution :D
// Note: this only prints the histogram without the words (for alignment purposes)
// if you want to print the words before each line in the histogram uncomment the putchar line
int main() 
{   
    int c, i, currentWordLength;
    
    currentWordLength = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (currentWordLength > 0) {
                for(i = 0; i < currentWordLength; ++i)
                    putchar('=');
            }
            putchar('\n');
            currentWordLength = 0;
        } else {
            // putchar(c);
            ++currentWordLength;
        }
    }

    return 0;
}