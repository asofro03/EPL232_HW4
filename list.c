#include "list.h"
#include <stdio.h>
#include <string.h>

void saveImage(IMAGE *image){
    FILE *fp=NULL;
    fp=fopen(image->name, "w");

    fwrite(image->FILEHEADER, sizeof(BITMAPFILEHEADER), 1, fp);

    fwrite(image->INFOHEADER, sizeof(BITMAPINFOHEADER), 1, fp);

    fseek(fp, image->FILEHEADER->bfOffBits, SEEK_SET);
    int i;

    for(i=0; i<image->INFOHEADER->biSizeImage; i++)
        fputc(image->DATA[i], fp);

    fclose(fp);
}

IMAGE *newImage(char *filename){

    BITMAPINFOHEADER *InfoHeader = (BITMAPINFOHEADER *)malloc(sizeof(BITMAPINFOHEADER));
    BITMAPFILEHEADER *FileHeader = (BITMAPFILEHEADER *)malloc(sizeof(BITMAPFILEHEADER));

    FILE *fp;
    fp = fopen(filename,"rb");
    if (fp == NULL){
        printf("Cannot open file\n");
        exit(-1);
    }

    fread(FileHeader, sizeof(BITMAPFILEHEADER), 1, fp);

    if (FileHeader->bfType1 !='B' || FileHeader->bfType2 !='M'){
        fclose(fp);
        printf("Not an bmp file\n");
        return NULL;
    }

    fread(InfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

    fseek(fp, FileHeader->bfOffBits, SEEK_SET);

    unsigned char *Data;
    Data = (unsigned char*)malloc(InfoHeader->biSizeImage);
    if (Data==NULL){
        free(Data);
        fclose(fp);
        printf("Cannot allocate memory for Data\n");
        exit(-1);
    }

    fread(Data, InfoHeader->biSizeImage, 1, fp);

    if(InfoHeader->biCompression!=0){
        printf("The image is compressed.\n");
    }

    fclose(fp);

    IMAGE *image = (IMAGE *) malloc(sizeof(IMAGE));
    image->DATA= Data;
    image->FILEHEADER = FileHeader;
    image->INFOHEADER = InfoHeader;
    image->name = filename; 

    return image;
}

void printList(IMAGE *image){
    printf("\nBITMAP_FILE_HEADER\n");
    printf("==================\n");
    printf("bfType: %c%c\n", image->FILEHEADER->bfType1, image->FILEHEADER->bfType2);
    printf("bfSize: %d\n", image->FILEHEADER->bfSize);
    printf("bfReserved1: %d\n", image->FILEHEADER->bfReserved1);
    printf("bfReserved2: %d\n", image->FILEHEADER->bfReserved2);
    printf("bfOffBits: %d\n", image->FILEHEADER->bfOffBits);
    printf("\n");
    printf("BITMAP_INFO_HEADER\n");
    printf("==================\n");
    printf("biSize: %d\n", image->INFOHEADER->biSize);
    printf("biWidth: %d\n", image->INFOHEADER->biWidth);
    printf("biHeight: %d\n", image->INFOHEADER->biHeight);
    printf("biPlanes: %d\n", image->INFOHEADER->biPlanes);
    printf("biBitCount: %d\n", image->INFOHEADER->biBitCount);
    printf("biCompression: %d\n", image->INFOHEADER->biCompression);
    printf("biSizeImage: %d\n", image->INFOHEADER->biSizeImage);
    printf("biXPelsPerMeter: %d\n", image->INFOHEADER->biXPelsPerMeter);
    printf("biYPelsPerMeter: %d\n", image->INFOHEADER->biYPelsPerMeter);
    printf("biClrUsed: %d\n", image->INFOHEADER->biClrUsed);
    printf("biClrImportant: %d\n\n", image->INFOHEADER->biClrImportant);
}

char *newImageName(char *name){
    char *newName = (char *)malloc((strlen(name)+ 6)*sizeof(char));
    char *new = "new-";
    strcpy(newName, new);
    strcat(newName, name);
    newName[strlen(name)+5] = '\0';
    return newName;
}
int paddBytes(BITMAPINFOHEADER *header){
    int pad = (header-> biWidth*3)%4;
    if(pad==0){
        return 0;}
    return 4-pad;
}

void cpyHeader(FILE *fpR ,FILE *fpW, int hsize){
    rewind(fpR);
    unsigned char a;
    for(int i=0; i<hsize; i++){
        fread(&a, sizeof(char),1, fpR);
        fwrite(&a, sizeof(char),1,fpW);
    }
}

/*
void main(int argc, char *argv[]){

    if(argc<1){
        printf("Not enough arguments\n");
        return 0;}  
    
    int c;
    for(c=1; c<argc; c++){
        IMAGE *image = newImage(argv[c]);
        printList(image);
       printf("***************************************************************************\n");
  }     
}   */   
