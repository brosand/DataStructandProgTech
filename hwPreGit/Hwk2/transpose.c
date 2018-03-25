#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>

int main(int argc, char *argv[]){
    /* puts("6"); */
    if (argc != 4 || strtol(argv[1], NULL, 10) < 1){
            /* return 1; */
        return 1;
    }
    
    long n = strtol(argv[1], NULL, 10);
    long a = strtol(argv[2], NULL, 10);
    long b = strtol(argv[3], NULL, 10);
    
    int first = getchar();
    int ctr = 0;
    
     while (first != EOF) {
        int in[n]; 
        for(int i = 0; i < n; i++) {
            if (first == EOF) {
                in[i] = '\0';
            }
            else {
                in[i] = first;
            }
            first = getchar();
            
        }
        for(int k = 0; k < n; k++) {
            
            long q = (((ctr * a + b) % n + n) % n);
            putchar(in[q]);
            ctr++;
        }
     }
    
}

