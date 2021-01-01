#include <stdio.h>

int main()
{
    int ch;
    printf("Press a key: ");
    ch = getchar();
    putchar(ch);
    printf(" = %d\n", ch);
    ch = getchar();
    putchar(ch);
    printf(" = %d\n", ch);
}
