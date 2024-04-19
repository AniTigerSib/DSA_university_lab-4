#ifndef SEARCH_H
#define SEARCH_H

#include <cstring>

char* KMP(char* txt, char* pat);
void ComputeLPS(char* pat, int M, char* lps);

#endif