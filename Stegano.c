#include "header.h"
#include "Stegano.h"
#include <string.h>

byte findMaskByte(int nbBits){
    byte nByte = 1;
    int c;
    for(c=1; c<nbBits; c++){
        nByte= nByte<<1;
        nByte = nByte|1;
    }
    return nByte;
}

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

    byte nByte = findMaskByte(nbBits);
    nByte = nByte<<(8-nbBits);

    int c;
    for( c=0; c< strlen(Mask->DATA); c++){
        byte getMostSignificant = Secret->DATA[c] & nByte;
        getMostSignificant= getMostSignificant>>(8-nbBits);
        encodedImage->DATA[c]= Mask->DATA[c]|getMostSignificant;
    }

    return encodedImage;
}