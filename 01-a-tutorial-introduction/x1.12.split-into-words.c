#include <stdio.h>

int
is_split_char(char c)
{
    switch (c) {
        case '\n':
        case ' ':
        case ',':
            return 1;
        default:
            return 0;
    }
}

int
main()
{
    int c, pc;

    while ((c = getchar()) != EOF) {
        if (is_split_char(c))
            c = '\n';

        if (c == '\n' && pc == '\n')
            ;
        else
            putchar(c);

        pc = c;
    }
}

