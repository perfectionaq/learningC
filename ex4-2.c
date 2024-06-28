#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int getlinee(char line[], int max);

int main()
{
	double sum, atof(char []);
	char line[MAXLINE];
	int getlinee(char line[], int max);

	sum = 0;
	while (getlinee(line, MAXLINE) > 0)
		printf("\t%.6f\n", atof(line));

	return 0;
}

double atof(char s[])
{
	double val, power, snpower, snsign;
	int i, k, sign, snval;

	for(i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1; 
	if((s[i] == '+' || s[i] == '-'))
		i++;

	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if(s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	if(s[i] == 'e' || s[i] == 'E')
		i++;

	snsign = (s[i] == '-') ? -1 : 1;
	if((s[i] == '+' || s[i] == '-'))
		i++;

	for(snpower = 1.0; isdigit(s[i]); i++) {		
		snval = 10.0 * snval + (s[i] - '0');
	}

	for(k = 0; k < snval; k++)
		if(snsign > 0)
			snpower *= 10;
		else
			snpower /= 10;

	return (sign * val / power) * snpower;
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