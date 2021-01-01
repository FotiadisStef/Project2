#include <stdio.h>

int main()
{
    int ch;
    ch = getchar();
    while (ch != EOF)
    {
        putchar(ch);
        printf(" %d\n", ch);
        ch = getchar();
    }
}