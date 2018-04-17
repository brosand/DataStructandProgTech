#include "shrink.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define VOWELS "aeiou"
#define NUMVOWELS (5)

int main(int argc, char **argv){
  char *str = argv[1];
  char **sols;
  
  int len = strlen(str);
  sols = calloc(len, sizeof(*str));
  sols[0] = str;
  solve(str, sols, 1);
}

void solve(char *str, char **sols, int d){
    int len = strlen(str);
    char *strTmp = str;
    
    if (len == 1) {
            sols[d-1] = str;
    } else {
        char c1;
        char c2;
        /* char *str2; */
        for (int i = 0; i < len; i++){
            c1 = str[i];
            if(c1 == 0) {break;}
            c2 = str[i+1];
              
            if (legal(c1, c2)){
                /* str1 = malloc(sizeof(char) * (len - 1)); */
                /* strTmp = move */
                    
                //TODO can switch to one function cheaper
                strTmp[i] = strTmp[i+1];
                strTmp[i+1] = 0;
                fixZero(strTmp, len);
                solve(strTmp, sols, d+1);
                sols[d+1] = strTmp;
            }
            c2 = str[i+3];
            if (legal(c1, c2)){
                strTmp[i] = strTmp[i+3];
                strTmp[i+3] = 0;
                fixZero(strTmp, len);
                solve(strTmp, sols, d+1);
                sols[d+1] = strTmp;
                
            }
        }
    }
}

int legal(char c1, char c2){
    
    if ((c1 - c2) <= 5 || (c2 - c1) <= 5) {
        return 1;
    }
    for (int i = 0; i < NUMVOWELS; i++){
        if (c1 == VOWELS[i]){
            for (int k = 0; k < NUMVOWELS; k++){
                if (c2 == VOWELS[k]){
                    return 1;
                }
            }
        }
    }
    return 0;
}


void fixZero(char *str, int len){
    for (int i = 0; i < len; i++){
        if (str[i] == 0){
            for (int k = i+1; k < len; k++){
                str[k-1] = str[k];
            }
            str[len-1] = 0;
           //TODO Check this 
        }
    }
}
/* {     */
    
    
    
    
    /* char *move; */
    /* char *mov2; */
    /* while (len != 1){ */
    /*     char *next = findsols(move); */
    
    /* } */
    /* putchar(str[0]); */
    
    
    
    
    /* int move2 = 0; */
    /* while (len != 1){ */
    /*     char tmp1; */
    /*     char tmp2; */
    /*     for (int i = 0; i < len; i ++){ */
    /*         tmp1 = str[i]; */
    /*         tmp2 = str[i+1]; */
            
    /*         move = findSols(str, tmp1, tmp2, sols); */
    /*         tmp2 = str[i+3]; */
    /*         move2 = findSols(str, tmp1, tmp2, sols); */
    /*     } */
    /*     if(move == 0 || move2 == 0){ */
    /*         notImplemented(); */
    /*         //no solutions */
    /*     } */
    /*     //TODO should be an array of next possible strings? */
    /*     str = doMove(str, sols); */
    /*     len--; */
    /* } */

/* } */
/* //TODO reduce time/space by moving the for loop into findSols */
/* char **findSols(char **moves, int loc) { */
/*     char **move = moves; */
/*     char *str = moves[loc]; */
/*     char *tmpStr = str; */
/*     char tmp1; */
/*     char tmp2; */
    
/*     for (int i = 0; i < len; i ++){ */
/*             tmp1 = str[i]; */
/*             tmp2 = str[i+1]; */
            
            
/*             works = findSols((move())) */
/*             move = findSols(); */
/*             move = findSols(str, tmp1, tmp2, sols); */
/*             tmp2 = str[i+3]; */
/*             move2 = findSols(str, tmp1, tmp2, sols); */
/*         } */
    
/*     if ((first - scnd) >= -5 && (first - scnd) <= 5){ */
/*         char *out = str; */
        
/*     } else { */
/*         for (int k = 0; k < NUMVOWELS; k++){ */
/*             if (first = VOWELS[i]){ */
/*                 for (int l = 0; l < NUMVOWELS; l++){ */
/*                     if (scnd = VOWELS[l]){ */
                        
/*                         break; */
/*                             } */
/*                 } */
/*                 break; */
/*             } */
/*         } */
/*     } */
/*     if (move == 0){ */
/*         if (move2 == 0){ */
/*             return move; */
/*         } else { */
/*             return move2; */
/*         } */
/*     } else { */
/*         return move; */
/*     } */
    
    
/* } */

/* char *doMove(str, sols){ */
    
/* } */
            /* if(c1 == 0){++i; break;} */
            /* else if(c2 == 0){ */
                /* ++i;  */
                /* c2 = str[i+1]; */
                /* break;} */
