#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(  )
{

    int first = getchar();
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
        int c = getchar();
        while isalpha(c) {
                if (upper && ctr == 1) {
                    putchar(toupper(c));
                    }
                else if (ctr == 1) {
                    putchar(tolower(c));
                }
                else {
                    putchar(c);
                }
                ctr ++;
            
            c = getchar();
        }
        if (ctr == 1) {
            putchar(first);
        }
        else {
            putchar(tolower(first));
        }
        if (ctr > 3) {
            putchar('o');
        }
        else {
            putchar('a');
            putchar('n');
        }
        if (!isalpha(c) &&  (c != EOF)) {
                putchar(c);
            }
        first = getchar();
    }
}
