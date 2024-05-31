#include <stdio.h>

void itob(int n, char s[], unsigned b);
void reverse(char s[]);

int main()
{
    char s[100] = {};

    itob(123, s, 16); // 7B
    printf("%s\n", s);
    itob(123, s, 8); // 173
    printf("%s\n", s);
    itob(123456, s, 20); // F8CG
    printf("%s\n", s); 
    
    return 0;
}

void itob(int n, char s[], unsigned b)
{
    int i = 0;
    int temp = 0;

    do {
        temp = n % b;
        // Turn any numbers above 9 into letters.
        if (temp > 9) 
            s[i++] = (temp + 'A') - 10;
        else
            s[i++] = temp + '0';
    } while ((n /= b) > 0);

    s[i] = '\0';

    reverse(s);
}


void reverse(char s[]) {

    int i;
    int string_length = 0;

    for (i = 0; s[i] != '\0'; i++)
        string_length++;

    // copy source string into a temp variable
    char temp[string_length];
    for (i = 0; i < string_length; i++)
        temp[i] = s[i];

    for (i = 0; i < string_length; i++)
        s[i] = temp[string_length - 1 - i];

}