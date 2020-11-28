#include "header.h"
#include <stdio.h>
#include <string.h>
#include "StringToImage.h"

byte getBit(char *m, int n){
    int byteNumber = n/8;
    byte selectedByte= m[byteNumber];
    int bitNumber = 7-(n%8);
    byte mask = 1;
    int c;
    for(c=0; c<bitNumber; c++)
        mask<<1;
    return (selectedByte & mask)>>(bitNumber-1);
}

IMAGE stringToImage(char *image, char *filename){

    //piano to size gia na kamo malloc
    FILE *fpSize;
    if((fpSize=fopen(filename, "r"))==NULL){
        printf("Cannot open file \n");
        exit(-1);}

   int c = 1, size=0;
   while (c != EOF) {
       size++;
       c=getc(fpSize);} 
    fclose(fpSize);

    char *text=(char *)malloc((size+1)*sizeof(char));

    //diavazo pu arxeio
    FILE *fp=NULL;
    if((fp=fopen(filename, "r"))==NULL){
        printf("Cannot open file \n");
        exit(-1);}

    for( c=0; c<size; c++)
        text[c]=getc(fp);
    text[size]='\0';
    fclose(fp);

    IMAGE *Image = newImage(image);
    Image->name =  newImageName(image);
    int dataLength = sizeof(Image->DATA)/sizeof(unsigned char);

    int i;



    for(i=0; i<dataLength; i++){

    }



    for(i=0; i<dataLength ; i++)
            if(size<i)
                Image->DATA[i]='0';
            else
                Image->DATA[i]= 128 * getBit(string, height*i + j);

    ;

    
}

/*
black and white pic

each pixel == one bit of ascii
0 == black ,  1 == bright

1st bit == color of the pixel on the top left corner of the pic
2nd bit == color of the next pixel in the same column επόμενου pixel στην πρώτη στήλη
next bits you go down the column until it is completed the column
then we start all over again at the top of the next column


Η παραγόμενη εικόνα, η φωτεινότητα του pixel στη θέση (i,j) να ισούται με 128 x getBit(m, height*i + j)
όπου height είναι το ύψος της εικόνας.

int getBit(char *m, int n);

Σημειώστε ότι το μήκος του κειμένου πρέπει να είναι αρκετό ώστε να γεμίζει τις διαστάσεις της εικόνας 
και να γίνει ορατό ένα αποτέλεσμα και με γυμνό μάτι. 

Η εικόνα sampleImage.bmp χρησιμοποιείται μόνο για να αναθέσουμε στην εικόνα που δημιουργείται, 
τις ίδιες τιμές για τα BITMAP_FILE_HEADER και BITMAP_INFO_HEADER. 
Εναλλακτικά θα μπορούσαμε να αγνοήσουμε το sampleImage.bmp και να φτιάξουμε μόνοι μας τα 
BITMAP_FILE_HEADER και BITMAP_INFO_HEADER.
*/
