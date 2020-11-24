#include "header.h"
#include "Stegano.h"
#include <string.h>

IMAGE *encodeStegano(int nbBits, char *maskImage, char *secretImage){

   /* BITMAPINFOHEADER *maskInfoHeader;
    BITMAPFILEHEADER *maskFileHeader;
    unsigned char *maskData= storeImage(maskImage, maskInfoHeader, maskFileHeader);
    IMAGE *Mask = createImage(maskData, maskInfoHeader, maskFileHeader, maskImage); */
    IMAGE *Mask = newImage(maskImage);

    /*BITMAPINFOHEADER *secretInfoHeader;
    BITMAPFILEHEADER *secretFileHeader;
    unsigned char *secretData= storeImage(secretImage, secretInfoHeader, secretFileHeader);
    IMAGE *Secret = createImage(secretData, secretInfoHeader, secretFileHeader, secretImage);   */
    IMAGE *Secret = newImage(secretImage);

    if((Mask->INFOHEADER->biHeight!=Secret->INFOHEADER->biHeight) ||(Mask->INFOHEADER->biWidth!=Secret->INFOHEADER->biWidth)){
        printf("Error: Cover Image and Mask Image do not have the same dimensions\n");
        exit(-1);
    }

  
  /*  BITMAPINFOHEADER *newImageInfoHeader;
    BITMAPFILEHEADER *newImageFileHeader;
    unsigned char *newImageData= storeImage(maskImage, newImageInfoHeader, newImageFileHeader);
    IMAGE *newImage = createImage(newImageData, newImageInfoHeader, newImageFileHeader, newName);   */
    IMAGE *encodedImage = newImage(maskImage);
    encodedImage->name=newImageName(maskImage);

    int c;

    byte nByte = 1;
    for(c=1; c<nbBits; c++){
        nByte= nByte<<1;
        nByte = nByte|1;
    }

    for( c=0; c< sizeof(Mask->DATA)/sizeof(unsigned char); c++){
        byte getLeastSignificant = Mask->DATA[c] & nByte;
        getLeastSignificant= getLeastSignificant<<(8-nbBits);
        encodedImage->DATA[c]= Secret->DATA[0]|getLeastSignificant;
    }

    return encodedImage;
}