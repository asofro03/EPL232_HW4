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
        int c;
        for(c=2; c<argc; c++){
            IMAGE *image = newImage(argv[c]);
            printList(image);
            printf("***************************************************************************\n");
  }     
        
    }


}