#ifndef STEGANO_h
#define STEGANO_h
#include "header.h"

typedef struct{
    byte red;
    byte green;
    byte blue;
}PIXEL;

IMAGE stringToImage(char *image, char *filename);
#endif