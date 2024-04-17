/* htoi */

#include <stdio.h>

int htoi(char s[]);

int main()
{
    printf("%d\n", htoi("0xff")); // 255
    printf("%d\n", htoi("123")); // 291
    printf("%d\n", htoi("0x0F")); // 15
    return 0;
}

int htoi(char s[])
{
    int i;
    int acc;

    acc = i = 0;
    /* check if the string starts with either 0x or 0X and skip it */
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
        i += 2;
    
    for (i; s[i] != '\0'; ++i)
        if (s[i] >= '0' && s[i] <= '9')
            acc = acc * 16 + s[i] - '0';
        else if ((s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'))
            acc = acc * 16 + ((s[i] - '0') % 16 - 1 + 10);
        else 
            acc = acc;

    return acc;
}