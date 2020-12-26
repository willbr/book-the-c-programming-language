#include <stdio.h>

int
main(void)
{
    int i;
    int s;
    char c;

    i = 0;

    while ((c = getchar()) != EOF) {
        s = 8 - (i % 8);

        if (c == '\t')
            while (s--)
                putchar(' ');
        else if (c == '\n')
            puts("");
        else
            putchar(c);

        i = c == '\n' ? 0 : i + 1;
    }
    return 0;
}

