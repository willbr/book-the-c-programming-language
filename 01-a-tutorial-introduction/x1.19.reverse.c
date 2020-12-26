#include <stdio.h>
#include <assert.h>

#define MAXLINE (80 + 1)   /* maximum input line size */

int getline2(char line[], int maxline);
void reverse(char s[]);

int
main(void)
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = getline2(line, MAXLINE)) > 0) {
        reverse(line);
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


void
reverse(char line[])
{
    char *s, *e;
    char t;

    s = e = line;

    while (*e != '\0')
        e += 1;

    if (e > s)
        e -= 1;

    while (s < e) {
         t = *s;
        *s = *e;
        *e =  t;

        s += 1;
        e -= 1;
    }
}

