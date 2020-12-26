#include <stdio.h>
#define MAXLINE (80 + 1)   /* maximum input line size */

int getline2(char line[], int maxline);
void copy(char to[], char form[]);
int line_contains(char line[], int len, char c);

/* print longest input line */
int
main(void)
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    int c;

    while ((len = getline2(line, MAXLINE)) > 0) {
        if (len = MAXLINE && !line_contains(line, len, '\n')) {
            printf("%s", line);
            while ((c=getchar())!=EOF && c!='\n')
                putchar(c);
            putchar('\n');
        }
    }
    return 0;
}


int
getline2(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


void
copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int
line_contains(char line[], int len, char c)
{
    int i;
    for (i = 0; i < len; ++i)
        if (line[i] == c)
            return -1;
    return 0;
}

