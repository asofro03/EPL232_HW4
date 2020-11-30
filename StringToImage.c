#include "list.h"
#include <stdio.h>
#include <string.h>
#include "StringToImage.h"

byte getBit(char *m, int n){
    if(n<0 || n> 8*strlen(m))
        return 0;
    int byteNumber = n/8;
    byte selectedByte= m[byteNumber];
    int bitNumber = 7-(n%8);
    return (selectedByte & 1<<bitNumber)>>(bitNumber-1);
}

PIXEL newPixel(byte r, byte g, byte b){
    PIXEL pixel;
    pixel.red=r;
    pixel.green=g;
    pixel.blue=b;
    return pixel;
}

IMAGE *stringToImage(char *picture, char *filename){

    FILE *countBytes;
    if((countBytes=fopen(filename, "r"))==NULL){
        printf("Cannot open file \n");
        exit(-1);}

   char c = 1, counter=0;
   while (c != EOF) {
       c=getc(countBytes);
       counter++;} 
    fclose(countBytes);

    byte **Bytes =(byte **) malloc(sizeof(byte *)*counter);
    for(c=0; c<counter; c++)
        Bytes[c]= (byte *)malloc(sizeof(byte));




















    IMAGE *image = newImage(picture);

    FILE *readData;
    if((readData=fopen(filename, "r"))==NULL){
        printf("Cannot open file \n");
        exit(-1);}

   char c = 1, size=0;
   while (c != EOF || size<image->INFOHEADER->biSize) {
       c=getc(readData);
       image->DATA[size]=c;
       size++;} 
    fclose(readData);

    int i;

    for(i=size; i<image->INFOHEADER->biSize; i++)
        image->DATA[i]=NULL;

    PIXEL **pixels = (PIXEL **)malloc(image->INFOHEADER->biHeight * sizeof(PIXEL *));
    
    for(i=0; i<image->INFOHEADER->biHeight; i++)
        pixels[i]=(PIXEL *)malloc(image->INFOHEADER->biWidth * sizeof(PIXEL));

     int r;
     i=0;
    for(r=image->INFOHEADER->biHeight-1; r>=0; r--)
        for(c=0; c<image->INFOHEADER->biHeight; c++)
            if(i+2<image->INFOHEADER->biSize){
                pixels[r][c]=newPixel(image->DATA[i], image->DATA[i+1], image->DATA[i+2]);
                i+=3;
            }
            else
                pixels[r][c]=newPixel(NULL, NULL, NULL);

    for(c=0; c<image->INFOHEADER->biHeight; c++)
        for(r=0; r<image->INFOHEADER->biHeight; r++)
            pixels[r][c]=

    


 /*   unsigned char *Data;
    Data = (unsigned char*)malloc(image->INFOHEADER->biSizeImage);

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

    for(c=0; c<size; c++)
        text[c]=getc(fp);
    text[size]='\0';
    fclose(fp);

    IMAGE *Image = newImage(image);
    Image->name =  newImageName(image);
    int dataLength = sizeof(Image->DATA)/sizeof(unsigned char); 

    int i;

    PIXEL **pixels = (PIXEL **)malloc(Image->INFOHEADER->biHeight * sizeof(PIXEL *));
    for(i=0; i<Image->INFOHEADER->biHeight; i++)
        pixels[i]=(PIXEL *)malloc(Image->INFOHEADER->biWidth * sizeof(PIXEL));

    int r;
    i=0;
    for(c=0; c<Image->INFOHEADER->biWidth; c++)
        for(r=0; r<Image->INFOHEADER->biHeight; r++){
            if(i+2<dataLength)
                pixels[r][c]= newPixel(Image->DATA[i], Image->DATA[i+1], Image->DATA[i+2]);
            else
               if(i+1<dataLength)
                    pixels[r][c]= newPixel(Image->DATA[i], Image->DATA[i+1], '0');
                else
                   if(i<dataLength)
                    pixels[r][c]= newPixel(Image->DATA[i], '0','0');
                    else
                        pixels[r][c]= newPixel('0','0','0'); 
        }
    

    for(c=0; c<Image->INFOHEADER->biWidth; c++)
        for(r=0; r<Image->INFOHEADER->biHeight; r++){
            char *string =(char *)malloc(2*sizeof(char));
            pixels[r][c] = 128 * getBit( pixels, Image->INFOHEADER->biHeight*r + c);}   */





    return image;
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
/*
void imageToString(char *picture){

    IMAGE *Image = newImage(picture);

    FILE *fp;
    fp=fopen("outputText.txt", "w");

    if(fp == NULL){
        printf("Error");   
        exit(-1);             
    }

    fwrite(Image->FILEHEADER, sizeof(Image->FILEHEADER), sizeof(Image->FILEHEADER)/(16*sizeof(byte)), fp);
    fwrite(Image->INFOHEADER, sizeof(Image->INFOHEADER), sizeof(Image->INFOHEADER)/(40*sizeof(byte)), fp);

    int i, dataLength = sizeof(Image->DATA)/sizeof(unsigned char);

    for(i=0; i<dataLength; i++)
        fprintf(fp,"%c", Image->DATA[i]);   
        
    fclose(fp);
}*/


void imageToString(char *picture){
    IMAGE *image= newImage(picture);

    int dataLength = sizeof(image->DATA)/sizeof(unsigned char);

    FILE *fp;
    fp=fopen("outputText.txt", "w");

    if(fp == NULL){
        printf("Error");   
        exit(-1);             
    }

int i;
    for(i=0; i<sizeof(image->FILEHEADER)/sizeof(byte);i++)
        fprintf(fp, "%c", image->FILEHEADER[i]);

    for(i=0; i<sizeof(image->INFOHEADER)/sizeof(byte);i++)
        fprintf(fp, "%c", image->INFOHEADER[i]);

    for(i=0; i<dataLength; i++)
        fprintf(fp, "%c", image->DATA[i]);

    fclose(fp);

}

void main(int argc, char *argv[]){

    if(argc<2){
        printf("Not enough arguments\n");
        return 0;}  

    imageToString(argv[1]);

}