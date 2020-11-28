#ifndef STRINGTOIMAGE_h
#define STRINGTOIMAGE_h
#include "list.h"

typedef struct{
    byte red;
    byte green;
    byte blue;
}PIXEL;

IMAGE stringToImage(char *image, char *filename);
#endif