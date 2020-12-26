#include <stdio.h>
#include <stdlib.h>

void debug_line(char*, size_t);
void entab_line(char*, size_t);

enum {
    tab_width = 8
};



int
main(void)
{
    int whitespace;
    char *line;
    size_t buffer_size;
    size_t read;
    int i;
    int x;
    int delta;
    char c;

    puts("hi");

    while ((read = getline(&line, &buffer_size, stdin)) != -1){
        /*debug_line(line, read);*/
        entab_line(line, read);
        /*puts("");*/
    }

    free(line);

    return 0;
}

void
debug_line(char *line, size_t read)
{
    int whitespace;
    int x;
    int i;
    int delta;
    char c;

    whitespace = 0;
    x = 0;

    for (i = 0; i < read; i += 1) {
        c = line[i];
        if (c == '\t') {
            x += tab_width;
            delta = tab_width - (x % tab_width);
            /*printf("{%d, %d}", x, delta);*/
            while (delta) {
                putchar('t');
                delta -= 1;
            }
        } else if (c == ' ') {
            x += 1;
            putchar('.');
        } else  {
            x += 1;
            putchar(c);
        }
    }
}


void
entab_line(char *line, size_t read)
{
    int whitespace;
    int x;
    int i;
    int delta;
    char c;

    whitespace = 0;
    x = 0;
    /*printf("%s", line);*/
    for (i = 0; i < read; i += 1) {
        c = line[i];
        if (c == '\t') {
            delta = tab_width - (x % tab_width);
            x += delta;
            whitespace += delta;
        } else if (c == ' ') {
            x += 1;
            whitespace += 1;
        } else  {
            while (whitespace >= tab_width) {
                /*printf("{%d,tab}", whitespace);*/
                putchar('\t');
                whitespace -= tab_width;
            }
            while (whitespace) {
                putchar(' ');
                whitespace -= 1;
            }
            x += 1;
            putchar(c);
        }
    }
}

