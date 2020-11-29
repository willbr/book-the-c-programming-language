#include <stdio.h>

/* count lines in input */
int main()
{
    int c, nl, blanks, tabs;

    nl = 0;
    blanks = 0;
    tabs = 0;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;

    printf("lines:%d\n", nl);
    printf("blanks:%d\n", blanks);
    printf("tabs:%d\n", tabs);

    return 0;
}

