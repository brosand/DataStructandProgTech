#include <stdio.h>
#include <stdlib.h>

const char *keyConvert(unsigned int x, unsigned int y, unsigned int z) {
    /* char *xx; */
    /* char *yy; */
    /* char *zz; */
    /* xx = malloc(10); */
    /* yy = malloc(10); */
    /* zz = malloc(10); */
    char * out;
    out = malloc(31);
    sprintf(out,"%010u", x);
    sprintf(&out[10],"%010u", y);
    sprintf(&out[20],"%010u", z);
    return out;
    /* atol(output, a, 10); */
    /* return a; */
    /* return atol() */
} 
unsigned int
    hash(const char *str)
    {
        unsigned int hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash % 300;
    }


int main() {
    unsigned int t = -1;
    const char *key = keyConvert(101123,10230,156500);
    unsigned int hashed = hash(key);
    
    printf("%u", hashed);
}
