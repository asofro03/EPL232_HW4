#include <stdio.h>
#include <string.h>
#include "list.h"
#include "Grayscale.h"
#include "Stegano.h"
#include "encodeText.h"
#include "StringToImage.h"

void main(int argc, char *argv[]){

    if(argc<2){
         printf("Not enough arguments\n");
        return 0;}  
    
    if(strcmp(argv[1], "-list")==0){

        if(argc<3){
         printf("Not enough arguments\n");
        return 0;}  

        int c;
        for(c=2; c<argc; c++){
            IMAGE *image = newImage(argv[c]);
            printList(image);
            printf("***************************************************************************\n");
        }     
  
    }

    if(strcmp(argv[1], "-encodeStegano")==0){

        if(argc<5){
         printf("Not enough arguments\n");
        return 0;}
        
        saveImage(encodeStegano(atoi(argv[2]), argv[3], argv[4]));
    }

    if(strcmp(argv[1], "-decodeStegano")==0){

        if(argc<4){
         printf("Not enough arguments\n");
        return 0;} 

        saveImage(decodeStegano(atoi(argv[2]), argv[3]));
    }

    if(strcmp(argv[1], "-stringToImage")==0){

        if(argc<4){
         printf("Not enough arguments\n");
        return 0;} 

        printf("Incomplete Function, canot run/n");
    }

    if(strcmp(argv[1], "-imageToString")==0){

        if(argc<3){
         printf("Not enough arguments\n");
        return 0;} 

        printf("Incomplete Function, canot run/n");
    }

    if(strcmp(argv[1], "–grayscale")==0){
       if(argc<4){
           printf("Not enough arguments\n");
        return 0;} 

           saveImage(grayscale(atoi(argv[2]), argv[3]));
       }
     
   if(strcmp(argv[1], "–encodeText")==0){
        if(argc<3){
           printf("Not enough arguments\n");
        return 0;} 

           saveImage(encodeText(atoi(argv[2]), argv[3]));

  }   

if(strcmp(argv[1], "–decodeText")==0){
        if(argc<4){
           printf("Not enough arguments\n");
        return 0;} 

           saveImage(decodeText(atoi(argv[2]), argv[3]));

  }   

}