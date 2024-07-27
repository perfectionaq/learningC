#include <stdio.h>

unsigned int strend(char *s, char *t);

int main()
{
	char p[50] = "hello, world";
	char t[50] = "world";

	printf("%s\n", strend(p, t) ? "found" : "not found");
	return 0;
}

unsigned int strend(char *s, char *t)
{
	while (*s) {
		while (*s == *t) {
			t++;
			s++;

			if (*s == '\0' && *t == '\0')
				return 1;
		}
			
		s++;
	}

	return 0;
}