#include "list.h" 
#include "Stegano.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
gcc Stegano.c list.c -o run -lm
encode:     ./run 4 IMG_6865.bmp IMG_6875.bmp
decode:     ./run decode 4 new-IMG_6865.bmp
*/

int findMaskByte(int nbBits){
    int nByte = 1;

    int c;
    for(c=1; c<nbBits; c++){
        nByte= nByte<<1;
        nByte = nByte|1;
    }
    return nByte;
}

IMAGE *encodeStegano(int nbBits, char *maskImage, char *secretImage){
    
    IMAGE *Mask = newImage(maskImage);
    
    IMAGE *Secret = newImage(secretImage);

    if((Mask->INFOHEADER->biHeight!=Secret->INFOHEADER->biHeight) ||(Mask->INFOHEADER->biWidth!=Secret->INFOHEADER->biWidth)){
        printf("Error: Cover Image and Mask Image do not have the same dimensions\n");
        exit(-1);
    }

    IMAGE *encodedImage = newImage(maskImage);
    encodedImage->name=newImageName(maskImage);

    int c;
   for( c=0; c< Mask->INFOHEADER->biSizeImage; c++){
        int getMostSignificant = Secret->DATA[c] >> (8-nbBits);
        getMostSignificant=getMostSignificant & findMaskByte(nbBits);
        Mask->DATA[c]=Mask->DATA[c]>>nbBits;
        Mask->DATA[c]=Mask->DATA[c]<<nbBits;
        encodedImage->DATA[c]= Mask->DATA[c]|getMostSignificant;
    }  

    return encodedImage;
}

IMAGE *decodeStegano(int nbBits, char *encryptedImage){

    IMAGE *encrypted = newImage(encryptedImage);

    IMAGE *decodedImage = newImage(encryptedImage);

    decodedImage->name=newImageName(encryptedImage);

     int c;
   for( c=0; c< encrypted->INFOHEADER->biSizeImage; c++){
        int getLeastSignificant = encrypted->DATA[c] << (8-nbBits);
        int mask = findMaskByte(nbBits);
        mask = mask<<(8-nbBits);
        decodedImage->DATA[c]= getLeastSignificant & mask;
    }  

    return decodedImage;
}

/*
void main(int argc, char *argv[]){

    if(argc<2){
        printf("Not enough arguments\n");
        return 0;}  

    saveImage(encodeStegano(atoi(argv[1]), argv[2], argv[3]));
   // saveImage(decodeStegano(atoi(argv[1]), argv[2]));
}  */