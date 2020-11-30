#ifndef STRINGTOIMAGE_h
#define STRINGTOIMAGE_h
#include "list.h"

typedef struct{
    byte red;
    byte green;
    byte blue;
}PIXEL;

IMAGE stringToImage(char *image, char *filename);

/**
 * @brief creates an array with integers and then 'suffles' it
 * @param N
 * @param systemkey
 */
int *createPermutationFunction(int N, unsigned int systemkey);
#endif