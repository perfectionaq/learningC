#include <stdio.h>

#define MAX_NUMBER_OF_WORDS 1000

int main()
{
    int c, i;
    int currentWordIndex, currentLineIndex, wordLengths[MAX_NUMBER_OF_WORDS];
    int maxWordLength;

    currentLineIndex = currentWordIndex = 0;
    maxWordLength = 0;

    for(i = 0; i < MAX_NUMBER_OF_WORDS; ++i)
        wordLengths[i] = 0;
    
    while((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') {
            if (wordLengths[currentWordIndex] > maxWordLength) {
                maxWordLength = wordLengths[currentWordIndex];
            }
        ++currentWordIndex;
        } else {
            ++wordLengths[currentWordIndex];
        }
    
    for (i = 0; i < maxWordLength; ++i) {
        for(int j = 0; j < MAX_NUMBER_OF_WORDS; ++j) {
            int currentWordLength = wordLengths[j];
            if (currentWordLength > 0 && currentWordLength > i) {
                putchar('#');
            } else {
                putchar('-');
            }
            putchar('\t');
        }
        putchar('\n');
    }

    return 0;
}