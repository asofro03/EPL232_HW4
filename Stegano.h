/** @file Stegano.h
 *  @brief Encodes and decodes images using other images.
 * 
 *  There are two options in this class. To encode an image or decode one. If the user wants to decode
 *  an image, then the class takes as input an integer that represents the number of bits that are going
 *  to be encoded in an image, it takes as imput a secret image that is going to be encrypted in a 
 *  cover/mask images and cover/mask image where the secret image is going to be encrypted in. The
 *  second option is to decrypt an encrypted image and get a secret image. In this case, the class takes
 *  as input an integer that represents the number of bits that are going to be decoded in the cover/mask
 *  image and the mask/cover image where the secret image is encrypted in.
 *
 *  @author AnnaMaria Sofroniou
 *  @bug No known bugs.
 */

#ifndef STEGANO_h
#define STEGANO_h

/**
 * @brief Creates a mask based on the nbBits integer.
 * 
 * @param nbBits The number of bit needed for the mask.
 * @return byte The new mask.
 */
int findMaskByte(int nbBits);

/**
 * @brief Encodes a mask image using a secret image. Bits from the secret
 * image are being inserted in the mask image creating a new image with different pixels.
 * 
 * @param nbBits The number of bits that are going to change in the pixel.
 * @param maskImage The mask/cover image.
 * @param secretImage The secret image we want to encode.
 * @return IMAGE* The new encoded image.
 */
IMAGE *encodeStegano(int nbBits, char *maskImage, char *secretImage);

/**
 * @brief Decodes a cover image and it creates the secret image.
 * 
 * @param nbBits Bits that are previously changed in the encrypted image.
 * @param encryptedImage The cover-encrypted image.
 * @return IMAGE* The decrypted secret image.
 */
IMAGE *decodeStegano(int nbBits, char *encryptedImage);

#endif