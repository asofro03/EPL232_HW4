#include "header.h"

IMAGE *createImage(unsigned char *Data, BITMAPINFOHEADER *InfoHeader, BITMAPFILEHEADER *FileHeader){
    IMAGE image;
    image.DATA= Data;
    image.FILEHEADER = FileHeader;
    image.INFOHEADER = InfoHeader;
}

unsigned char *storeImage(char *filename, BITMAPINFOHEADER *infoH, BITMAPFILEHEADER *fileH ){
   
    FILE *fp;
    fp = fopen(filename,"rb");
    if (fp == NULL){
        printf("Cannot open file\n");
        exit(-1);
    }

    fread(fileH, sizeof(BITMAPFILEHEADER), 1, fp);

    if (fileH->bfType1 !=0x4D && fileH->bfType2 !=0x42){
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
    printf("biClrImportant: %d\n\n", bitmapInfoHeader->biClrImportant);
}
