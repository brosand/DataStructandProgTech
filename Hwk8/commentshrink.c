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
  sols = calloc(len, sizeof(str));
  sols[0] = str;
  solve(str, &sols, 1);
  if(sols[len] == 0){return 0;}
  for (int i = 0; i < len; i++){
      if(sols[i] != 0){
          printf("%s\n", sols[i]);
      }
  }
}

int solve(char *str, char ***sols, int d){
    /* printf("String: %s, sols1: %s, d: %d\n", str, (*sols)[1], d); */
    
    
    int len = strlen(str);
    char *strTmp;
    /* strTmp = malloc(len * sizeof(char)); */
    /* strTmp = strncpy(strTmp, str, len); */
    if(str[1] == 0){
        /* break; */
                /* printf("setting d:%d to %s\n", d, strTmp); */
       (*sols)[d] = str; 
        return 1;
         //TODO fix this is ugly
    }
    char *strTmp2 = malloc(sizeof(char) * len);
    strncpy(strTmp2, str, len);
    
    
    
        char c1;
        char c2;
        char c3;
        for (int i = 0; i < (len - 1); i++){
            c1 = str[i];
            c2 = str[i+1];
            c3 = str[i+3];
              
            if (legal(c1, c2) == 1){
                strTmp = malloc(sizeof(str));
                strTmp = strncpy(strTmp, str, len);
                /* str1 = malloc(sizeof(char) * (len - 1)); */
                /* strTmp = move */
                    
                //TODO can switch to one function cheaper
                strTmp[i] = strTmp[i+1];
                strTmp[i+1] = 0;
                fixZero(&strTmp, len);
                /* str2 = strTmp; */
                /* printf("strTmp now is %s\n",strTmp); */
            /* } */
            /* printf("str2") */
            /* if (solve(strTmp, sols, d+1) == 1) { */
                /* if (strTmp[1] != 0){ */
                    /* str2 = strTmp; */
                    
                /* putchar('6'); */
                /* printf("setting d:%d to %s\n", d, strTmp); */
                (*sols)[d] = strTmp;
                if(
                solve(strTmp, sols, d+1) == 1)
                    {return 1;}
            }if (legal(c1,c3) == 1){
                strTmp2 = malloc(sizeof(str));
                strTmp2 = strncpy(strTmp2, str, len);
            /* c2 = str[i+3]; */
            /* if (legal(c1, c2)){ */
                strTmp2[i] = strTmp2[i+3];
                strTmp2[i+3] = 0;
                fixZero(&strTmp2, len);
                    
                /* printf("setting d:%d to %s\n", d, str2); */
                    (*sols)[d] = strTmp2;
                    if(
                    solve(strTmp2, sols, d+1)==1)
                        {return 1;}
                
                
            }
        }
    
    return 0;
}

int legal(char c1, char c2){
    if (c1 == 0 || c2 == 0){return 0;}
    if (abs(c1 - c2) <= 5 || abs(c2 - c1) <= 5) {
        /* printf("dif %d\n", (c1-c2)); */
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


void fixZero(char **str, int len){
    for (int i = 0; i < len; i++){
        if ((*str)[i] == 0){
            for (int k = i+1; k < len; k++){
                (*str)[k-1] = (*str)[k];
            }
            (*str)[len-1] = 0;
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
