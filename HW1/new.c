#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(  ) {

    char first = getchar();
    while (first != EOF) {
        int upper = 0;
        if (isupper(first)) {
                upper = 1;
            }
        if (!isalpha(first)) {
            putchar(first);
            first = getchar();
            continue;
        }
        int ctr = 1;
        char c = getchar();
        while isalpha(c) {
                if (upper && ctr == 1) {
                    putchar(toupper(c));
                    }
                else {
                    putchar(c);
                }
                ctr ++;
            
            c = getchar();
        }
        if (ctr > 3) {
            putchar(tolower(first));
            putchar('o');
        }
        else {
            putchar(first);
            putchar('a');
            putchar('n');
        }
        if (!isalpha(c)) {
                putchar(c);
            }
        first = getchar();
    }
}
