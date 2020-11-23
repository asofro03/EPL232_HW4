#ifndef HEADER_h
#define HEADER_h
#include <stdio.h>

/**
 * @brief Encodes a secret image using a mask image. Bits from the secret
 * image are being inserted in the mask image creating a new image with different pixels.
 * 
 * @param nbBits The number of bits that are going to change in the pixel.
 * @param maskImage The mask/cover image.
 * @param secretImage The secret image we want to encode.
 * @return IMAGE* The new encoded image.
 */
IMAGE *encodeStegano(int nbBits, char *maskImage, char *secretImage);

#endif