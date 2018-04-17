#ifndef __SHRINK_H_
#define __SHRINK_H_
#include "openHash.h"

int solve(char *str, char ***sols, int d, Table *t);

int legal(char c1, char c2);

void fixZero(char **str, int len);

#endif // __SHRINK_H_
