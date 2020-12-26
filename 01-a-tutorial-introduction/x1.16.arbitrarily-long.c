#include <stdio.h>
#define MAXLINE 20   /* maximum input line size */

int getline2(char line[], int maxline);
void copy(char to[], char form[]);

/* print longest input line */
int
main(void)
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    int c;

    max = 0;
    while ((len = getline2(line, MAXLINE)) > 0) {
        if (len > 1 && line[len-1] != '\n') {
            while ((c=getchar())!=EOF && c!='\n')
                ;
            printf("%s...\n", line);
        } else {
            printf("%s", line);
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

