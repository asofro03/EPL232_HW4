#include "list.h" 
#include "Stegano.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 gcc Stegano.c list.c -o runSis
 ./runSis encode 4 IMG_6865.bmp IMG_6875.bmp    image says no<3
 ./runSis decode 4 new-IMG_6865.bmp             the save image says no<3
 */

IMAGE *encodeStegano(int nbBits, char *maskImage, char *secretImage){
    
    IMAGE *Mask = newImage(maskImage);
    
    IMAGE *Secret = newImage(secretImage);

    if((Mask->INFOHEADER->biHeight!=Secret->INFOHEADER->biHeight) ||(Mask->INFOHEADER->biWidth!=Secret->INFOHEADER->biWidth)){
        printf("Error: Cover Image and Mask Image do not have the same dimensions\n");
        exit(-1);
    }

    IMAGE *encodedImage = newImage(maskImage);
    encodedImage->name=newImageName(maskImage);

   for( c=0; c< Mask->INFOHEADER->biSizeImage; c++){
        int getMostSignificant = Secret->DATA[c] >> (8-nbBits);
        getMostSignificant=getMostSignificant%(int)pow(2, nbBits);
        Mask->DATA[c]=Mask->DATA[c]>>nbBits;
        Mask->DATA[c]=Mask->DATA[c]<<nbBits;
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

   // if((strcmp(argv[1], "encode")==0))
       saveImage(encodeStegano(atoi(argv[1]), argv[2], argv[3]));
  //  else

 // int number = (int)(argv[1]-'0');
//    IMAGE *image = decodeStegano( atoi(argv[1]), argv[2]);
 //   saveImage(image);
       // saveImage(decodeStegano( atoi(argv[1]), argv[2]));
}