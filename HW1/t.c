#include <stdio.h>
#include <ctype.h>
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
        int len = strlen(argv[i]);
        char outputWord[] = argv[i];
        for (int j = 0; j < len; j++) {
            if (isalpha(argv[i][j])) {
                outputWord[len - 1] = argv[i][j];
                if islower(argv[i][j]) {
                     outputWord[j] = tolower(argv[i][j+1]);
                 }
                else if (isupper(argv[i][j]))  {
                     outputWord[j] = toupper(argv[i][j+1])  ; 
                 }
                
                for (int k = j+1; k < len; k++) {
                    outputWord[k] = outputWord[k+1];
                }
                break;
            }
            else
            {
                outputWord[j] = argv[i][j];
            }
        }
        outputSentence = strcat(outputSentence, " ");
        outputSentence = strcat(outputSentence, outputWord);
    }
}


