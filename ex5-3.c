#include <stdio.h>

void ptrstrcat(char *s, char *t);

int main() 
{

	char p[50]= "hello";
	char t[20] = ", world";

	ptrstrcat(p, t);

	printf("%s\n", p);
	return 0;
}

void ptrstrcat(char *s, char *t)
{
	while(*s)
		s++;

	while(*s++ = *t++)
		;
}

