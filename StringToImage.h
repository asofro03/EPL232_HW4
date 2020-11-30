/** @file StringToImage.h
 *  @brief Creates images from strings.
 * 
 *  @bug Incompleted.
 */

#ifndef STRINGTOIMAGE_h
#define STRINGTOIMAGE_h
#include "list.h"

typedef struct{
    byte red;
    byte green;
    byte blue;
}PIXEL;

/**
 * @brief Creates a pixel by using 3 bytes from data.
 * 
 * @param r Red byte.
 * @param g Green byte.
 * @param b Blue byte.
 * @return PIXEL 
 */
PIXEL newPixel(byte r, byte g, byte b);

/**
 * @brief Creates an image from a text.
 * 
 * @param picture The image prototype for the new image.
 * @param filename The filename that the text is in.
 * @return IMAGE* An image from text.
 */
IMAGE *stringToImage(char *picture, char *filename);

/**
 * @brief Creates text from an image.
 * 
 * @param picture The picture the text is going to be created from.
 */
void imageToString(char *picture);

/**
 * @brief creates an array with integers and then 'suffles' it
 * @param N
 * @param systemkey
 */
int *createPermutationFunction(int N, unsigned int systemkey);
#endif