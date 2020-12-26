#include <stdio.h>

#define MAXLEN 200
#define HIST_WIDTH 40

int
is_whitespace(char c)
{
    switch (c) {
        case ' ':
        case '\n':
        case '\t':
            return 1;
        default:
            return 0;
    }
}


int
is_word_char(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    else if (c >= 'A' && c <= 'Z')
        return 1;
    else if (c == '_')
        return 1;
    else
        return 0;
}

void
render_hist(char *buf, int freq, int max_freq)
{
    int i, j;

    i = ((float)freq / (float)max_freq) * HIST_WIDTH;

    for (j = 0; j < i; j++)
        buf[j] = '#';

    buf[j] = '\0';
}


int
main()
{
    int c, pc;
    int word_length;
    int max_length_found;
    int max_freq;
    int wordhist[MAXLEN];
    int i;
    char histbuff[HIST_WIDTH + 1];

    word_length = max_length_found = max_freq = 0;

    for (i = 0; i < MAXLEN; i++)
        wordhist[i] = 0;

    while ((c = getchar()) != EOF) {
        if (is_word_char(c)) {
            /*putchar(c);*/
            word_length += 1;
        } else if (is_word_char(pc)) {
            /*putchar('\n');*/
            /*printf("%d\n", word_length);*/
            wordhist[word_length] += 1;
            if (word_length > max_length_found)
                max_length_found = word_length;
            word_length = 0;
       }
       pc = c;
    }

    /*printf("mlf: %d\n", max_length_found);*/

    for (i = 0; i <= max_length_found; i++)
        if (wordhist[i] > max_freq)
            max_freq = wordhist[i];

    /*printf("%d\n", max_freq);*/

    printf(" l,  c, hist\n");
    printf("============\n");

    for (i = 0; i <= max_length_found; i++) {
        if (wordhist[i] > 0) {
            render_hist(histbuff, wordhist[i], max_freq);
            printf("%2d, %2d, %s\n", i, wordhist[i], histbuff);
        }
    }
}

