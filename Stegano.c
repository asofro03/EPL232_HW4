#include "header.h"
#include "Stegano.h"
#include <stdio.h>
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
    
    IMAGE *Mask = newImage(maskImage);
    
    IMAGE *Secret = newImage(secretImage);

    if((Mask->INFOHEADER->biHeight!=Secret->INFOHEADER->biHeight) ||(Mask->INFOHEADER->biWidth!=Secret->INFOHEADER->biWidth)){
        printf("Error: Cover Image and Mask Image do not have the same dimensions\n");
        exit(-1);
    }

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

IMAGE *decodeStegano(int nbBits, char *encryptedImage){

    IMAGE *Encrypted = newImage(encryptedImage);
    IMAGE *encodedImage = newImage(encryptedImage);
    
    encodedImage->name=newImageName(encryptedImage);
    
    byte nByte = findMaskByte(nbBits);

    int c;
    for( c=0; c< strlen(Encrypted->DATA); c++){
        byte getLeastSignificant = Encrypted->DATA[c] & nByte;
        getLeastSignificant= getLeastSignificant<<(8-nbBits);
        encodedImage->DATA[c]= getLeastSignificant;
    }

    return encryptedImage;
}

void main(int argc, char *argv[]){

    if(argc<2){
        printf("Not enough arguments\n");
        return 0;}  

    if((strcmp(argv[1], "encode")==0))
        saveImage(encodeStegano(argv[2], argv[3], argv[4]));
    else
        saveImage(decodeStegano(argv[2], argv[3]));

}