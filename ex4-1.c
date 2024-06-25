#include <stdio.h>
#define MAXLINE 1000

int getlinee(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found = 0;
	int index;

	while (getlinee(line, MAXLINE) > 0)
			if((index = strindex(line, pattern)) >= 0) {
				printf("%s | at index %d\n", line, index);				
			}
	return 0;
}

int getlinee(char line[], int max)
{
	int c, i;

	i = 0;
	while(--max > 0 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;

	if(c == '\n')
		line[i++] = c;

	line[i] = '\0';

	return i;
}

/* This is the same method that's in the book */
/* The only thing we need to change is not to return from the method and stop the outer for loop after we found the first match */
/* Instead we store the the for index that the match was found at and we keep the loop going until the entire line has been tested */
int strindex(char s[], char t[])
{
	int i, j, k;
	int index = -1;

	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			index = i;
	}

	return index >= 0 ? index : -1;
}