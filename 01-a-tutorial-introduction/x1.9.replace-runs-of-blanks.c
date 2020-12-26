#include <stdio.h>

int
main()
{
    int c, pc;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && pc == ' ')
            ;
        else
            putchar(c);
        pc = c;
    }
}

