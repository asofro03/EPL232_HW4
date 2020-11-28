#ifndef STEGANO_h
#define STEGANO_h


/**
 * @brief Creates a mask based on the nbBits integer.
 * 
 * @param nbBits The number of bit needed for the mask.
 * @return byte The new mask.
 */
byte findMaskByte(int nbBits);

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