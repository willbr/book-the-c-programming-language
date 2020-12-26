#include <stdio.h>
#include <assert.h>

#define MAXLINE (80 + 1)   /* maximum input line size */

int getline2(char line[], int maxline);
int rtrim(char line[], int len);
int is_whitespace(char c);

int
main(void)
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = getline2(line, MAXLINE)) > 0) {
        len = rtrim(line, len);
        if (line[0] == '\n')
            ;
        else
            printf("%s", line);
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


int
rtrim(char line[], int len)
{
    assert(line[len] == '\0');
    assert(line[len-1] == '\n');

    len -= 2;

    while (len >= 0 && is_whitespace(line[len]))
        len -= 1;

    line[len + 1] = '\n';
    line[len + 2] = '\0';

    return len + 2;
}


int
is_whitespace(char c)
{
    return c == ' ' || c == '\t';
}


