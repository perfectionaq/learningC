#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
	char s[100] = {0};
	itoa(-123, s);

	printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[])
{
    static int i = 0;
    int sign;

    if (n < 0) {
    	s[i++] = '-';
    	n = -n;
    }

    if (n / 10)
    	itoa(n / 10, s);

    s[i++] = n % 10 + '0';
}