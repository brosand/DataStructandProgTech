#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    if (argc < 1) {
            return 1;
        }
    puts(argv[1]);
    int c = argv[1][0];
    if (isalpha(c)) {
        puts("hi");
    }
    puts("end");
    char outputSentence[] = "";
    
    for (int i = 0; i < argc; i++) {
        printf("string %d: %s", (i,argv[i]));
        /* puts("18"); */
        /* int len = strlen(argv[i]); */
        /* /\* outW = char[len]; *\/ */
        /* puts("20"); */
        /* char outW[len+1]; */
        /* for (int j = 0; j < len; j++) { */
        /*     if (isalpha(argv[i][j])) { */
        /*         printf("%s\n", outW); */
        /*         printf("%c\n", outW[0]); */
        /*         printf("%d\n", len); */
        /*         puts("27"); */
        /*         outW[len - 1] = argv[i][j]; */
        /*         printf("%c\n", outW[len - 1]); */
        /*         if islower(argv[i][j]) { */
        /*              puts("32"); */
        /*              outW[j] = tolower(argv[i][j+1]); */
        /*          } */
        /*         else if (isupper(argv[i][j]))  { */
        /*              puts("36"); */
        /*              outW[j] = toupper(argv[i][j+1])  ;  */
        /*          } */
                
        /*         for (int k = j+1; k < len; k++) { */
        /*             outW[k] = outW[k+1]; */
        /*         } */
        /*         break; */
        /*     } */
        /*     else */
        /*     { */
        /*         outW[j] = argv[i][j]; */
        /*     } */
        /* } */
        /* strcat(outputSentence, " "); */
        /* strcat(outputSentence, outW); */
    }
}


