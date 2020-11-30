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

    IMAGE *image = newImage(picture);

   unsigned char *Data;
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
            pixels[r][c] = 128 * getBit( pixels, Image->INFOHEADER->biHeight*r + c);}   

    return image;
}   

int *createPermutationFunction(int N, unsigned int systemkey){
    int *perm= malloc(sizeof(int)*N);
    for (int i=0; i<N; i++){
        perm[i]=i+1;
    }
    srand(systemkey);
    for(int i=0;i<N;i++){
        int k=rand() % N;
        int j=rand()%N;
        int temp=perm[k];
        perm[k]=perm[j];
        perm[j]=temp;
    }
    return perm;

}

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