#include "header.h"

IMAGE *newImage(char *filename){

    BITMAPINFOHEADER *InfoHeader;
    BITMAPFILEHEADER *FileHeader;

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
    printf("BITMAP_FILE_HEADER\n");
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

/*
IMAGE *newImage (char *filename){
    BITMAPINFOHEADER *InfoHeader;
    BITMAPFILEHEADER *FileHeader;
    unsigned char *Data= storeImage(filename, InfoHeader, FileHeader);
    IMAGE *image = createImage(Data, InfoHeader, FileHeader, filename);
    return image;
}

IMAGE *createImage(unsigned char *Data, BITMAPINFOHEADER *InfoHeader, BITMAPFILEHEADER *FileHeader, char *filename){
    IMAGE image;
    image.DATA= Data;
    image.FILEHEADER = FileHeader;
    image.INFOHEADER = InfoHeader;
    image.name = filename;
}

unsigned char *storeImage(char *filename, BITMAPINFOHEADER *infoH, BITMAPFILEHEADER *fileH ){
   
   printf("%s\n", filename);

    FILE *fp;
    fp = fopen(filename,"rb");
    if (fp == NULL){
        printf("Cannot open file\n");
        exit(-1);
    }

    fread(fileH, sizeof(BITMAPFILEHEADER), 1, fp);

    if (fileH->bfType1 !=0x'B' || fileH->bfType2 !='M'){
        printf("%c\n",fileH->bfType1);
        fclose(fp);
        printf("Not an bmp file\n");
        return NULL;
    }

    fread(infoH, sizeof(BITMAPINFOHEADER), 1, fp);

    if((infoH->biWidth*3)%4==0)
        fileH->bfOffBits= 4-(infoH->biWidth*3)%4;
    else
        fileH->bfOffBits= 0;

    unsigned char *data;
    data = (unsigned char*)malloc(infoH->biSizeImage);
    if (data!=NULL){
        free(data);
        fclose(fp);
        printf("Cannot allocate memory for Data\n");
        exit(-1);
    }

    fread(data, infoH->biSizeImage, 1, fp);

    if(infoH->biCompression!=0){
        printf("The image is compressed.\n");
    }

    fclose(fp);
    return data;
}   

void printList(BITMAPINFOHEADER *bitmapInfoHeader, BITMAPFILEHEADER *bitmapFileHeader){
    printf("BITMAP_FILE_HEADER\n");
    printf("==================\n");
    printf("bfType: %c%c\n", bitmapFileHeader->bfType1, bitmapFileHeader->bfType2);
    printf("bfSize: %d\n", bitmapFileHeader->bfSize);
    printf("bfReserved1: %d\n", bitmapFileHeader->bfReserved1);
    printf("bfReserved2: %d\n", bitmapFileHeader->bfReserved2);
    printf("bfOffBits: %d\n", bitmapFileHeader->bfOffBits);
    printf("\n");
    printf("BITMAP_INFO_HEADER\n");
    printf("==================\n");
    printf("biSize: %d\n", bitmapInfoHeader->biSize);
    printf("biWidth: %d\n", bitmapInfoHeader->biWidth);
    printf("biHeight: %d\n", bitmapInfoHeader->biHeight);
    printf("biPlanes: %d\n", bitmapInfoHeader->biPlanes);
    printf("biBitCount: %d\n", bitmapInfoHeader->biBitCount);
    printf("biCompression: %d\n", bitmapInfoHeader->biCompression);
    printf("biSizeImage: %d\n", bitmapInfoHeader->biSizeImage);
    printf("biXPelsPerMeter: %d\n", bitmapInfoHeader->biXPelsPerMeter);
    printf("biYPelsPerMeter: %d\n", bitmapInfoHeader->biYPelsPerMeter);
    printf("biClrUsed: %d\n", bitmapInfoHeader->biClrUsed);
    printf("biClrImportant: %d\n", bitmapInfoHeader->biClrImportant);
}   */

char *newImageName( char *name){
    char *newName = (char *)malloc((strlen(name)+ 5)*sizeof(char));
    char *new = "-new";
    strcat(newName, new);
    strcat(newName, name);
    newName[strlen(name)+4] = '\0';
    return newName;
}

void main(int argc, char *argv[]){

    if(argc<1){
        printf("Not enough arguments\n");
        return 0;}  

    int c;
    for(c=1; c<argc; c++){
        printList(newImage(argv[c]));
        printf("***************************************************************************\n");
  }
}
