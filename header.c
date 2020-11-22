#include "header.h"

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

    fclose(fp);
    return data;
}
