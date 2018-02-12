#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    /* puts("6"); */
    int n = *argv[0];
    int a = *argv[1];
    int b = *argv[2];
    
    int first = getchar();
    while (first != EOF) {
        int in[n]; 
        for(int i = 0; i < n; i++) {
            if (first == EOF) {
                in[i] = '\0';
            }
            else {
                in[i] = first;
            }
           // out[i] = in[a*i*v]
            first = getchar();
            
        }
        for(int i = 0; i < n; i++) {
            /* puts("27"); */
            int q = (a * i + b);
            printf("%d", q);
            puts("30");
            /* printf("%d", (a * i + b)); */
            printf("%d", (in[q]));
            puts("32");
            putchar(in[(a * i + b)]);
        }
    }
    
}

