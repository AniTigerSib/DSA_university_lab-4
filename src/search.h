#ifndef SEARCH_H
#define SEARCH_H

#include <cstring>

char* KMP(char* pat, char* txt);
void ComputeLPS(char* pat, int M, char* lps);

#endif