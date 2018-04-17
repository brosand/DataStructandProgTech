#include "shrink.h"
#include "openHash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VOWELS "aeiou"
#define NUMVOWELS (5)
#define HASHSIZE (649)

int main(int argc, char **argv){
  Table t = createTable(HASHSIZE);
  int len = strlen(argv[1]);
  
  char *str = malloc(sizeof(char) * (len+1));
  strcpy(str, argv[1]);
  
  char **sols;
  sols = calloc(len, sizeof(char*));
  
  sols[0] = str;
  
  solve(str, &sols, 1, &t);
  
  if(sols[len-1] == 0){
      for(int i = 0; i < len; i++){
          if(sols[i]!= 0){free(sols[i]);}
      }
      free(sols);
      tDelete(t);
      return 0;
  }
  
  for (int i = 0; i < len; i++){
      if(sols[i] != 0){
          printf("%s\n", sols[i]);
      }
          free(sols[i]);
  }
  
  free(sols);
  tDelete(t);
}

int solve(char *str, char ***sols, int d, Table *t){
    if (tLookup(*t, str) != NULL){
        return 0;
    } else {
        
        int len = strlen(str);
        
        char *strExtra = malloc(sizeof(char) * (len+1));
        strExtra = strcpy(strExtra, str);
        
        genInsert(*t, strExtra);
        
        if(str[1] == 0){
        return 1;
    }
    char *strTmp;
    char *strTmp2;
    char c1;
    char c2;
    char c3;
        for (int i = 0; i < (len - 1); i++){
            c1 = str[i];
            c2 = str[i+1];
            
            if (i < (len - 3)){c3 = str[i+3];}
              
            if (legal(c1, c2) == 1){
                strTmp = malloc(sizeof(char) * (len+1));
                strTmp = strcpy(strTmp, str);
                    
                strTmp[i] = strTmp[i+1];
                strTmp[i+1] = 0;
                
                fixZero(&strTmp, len);
                
                if((*sols)[d] != 0){free((*sols)[d]);} 
                
                (*sols)[d] = strTmp;
                
                if(solve(strTmp, sols, d+1, t) == 1){return 1;}
                
            } if ((i < (len - 3)) && (legal(c1,c3) == 1)){
                strTmp2 = malloc(sizeof(char) * (len+1));
                strTmp2 = strcpy(strTmp2, str);
                
                strTmp2[i] = strTmp2[i+3];
                strTmp2[i+3] = 0;
                
                fixZero(&strTmp2, len);
                    
                if((*sols)[d] != 0){free((*sols)[d]);}
                
                (*sols)[d] = strTmp2;
                
                if(solve(strTmp2, sols, d+1, t)==1) {return 1;}
                
            }
        }
    
    return 0;
    }
}
int legal(char c1, char c2){
    if (c1 == 0 || c2 == 0){return 0;}
    
    if (abs(c1 - c2) <= 5 || abs(c2 - c1) <= 5) {
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
        }
    }
}
