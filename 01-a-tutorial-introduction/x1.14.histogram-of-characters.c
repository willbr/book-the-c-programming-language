#include <stdio.h>

#define LETTERS_IN_ALPHABET 26
#define HIST_WIDTH 40

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
    int c;
    int i;
    int max_freq;
    int cfreq[LETTERS_IN_ALPHABET];
    char histbuff[HIST_WIDTH + 1];

    max_freq = 0;

    for (i = 0; i < LETTERS_IN_ALPHABET; i++)
        cfreq[i] = 0;

    while ((c = getchar()) != EOF) {
        if ('A' <= c && c <= 'Z')
            c = c - 'A' + 'a';

        if ('a' <= c && c <= 'z')
            cfreq[c - 'a'] += 1;
    }

    for (i = 0; i < LETTERS_IN_ALPHABET; i++)
        if (cfreq[i] > max_freq)
            max_freq = cfreq[i];

    printf("l,  c, hist\n"
           "===========\n");

    for (i = 0; i < LETTERS_IN_ALPHABET; i++) {
        render_hist((char*)&histbuff, cfreq[i], max_freq);
        printf("%c, %2d, %s\n", i + 'a', cfreq[i], histbuff);
    }
}

