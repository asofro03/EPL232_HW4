#include "header.h"

IMAGE stringToImage(char *image, char *filename){

    FILE *fpSize=NULL;
    if((fpSize=fopen(filename, "r"))==NULL){
        printf("Cannot open file \n");
        exit(-1);}

   int c = 1, size=0;
   while (c != EOF) {
       size++;
       c=getc(fpSize);} 
    fclose(fpSize);

    char *text=(char *)malloc((size+1)*sizeof(char));

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
    
    int r, c;
    for(c=0; c<Image->INFOHEADER->biWidth; c++)
        for( r=0; r<Image->INFOHEADER->biHeight; r++)
            if(size<r*c)
                Image->DATA

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
