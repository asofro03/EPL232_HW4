#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

 
void grayscaleEffect(unsigned char *rgb){
	float value = 0.299*rgb[0] + 0.587*rgb[1] + 0.114*rgb[2];
	int grayscale = round(value);
	rgb[0] = grayscale;
	rgb[1] = grayscale;
	rgb[2] = grayscale;
}

void bmpGr(char *filename){
	FILE *fp = fopen(filename, "rb");

	FILE *newfp = fopen("replace.tmp", "wb"); 
	BITMAPFILEHEADER *fileheader =newImage(fp);
	BITMAPINFOHEADER *infoheader = newImage(fp);
	
	int padding = paddingBytes(infoheader);
	int Headerbytes = fileheader->bfOffBits;
	int Databytes = fileheader->bfSize - Headerbytes;
	int widthbytes = infoheader->biWidth*3 ;

	copyHeader(fp,newfp,Headerbytes);

	unsigned char rgb[3];
	int skip=0;
	int index=0;
	int count=0;
	for(int i = 0; i<Databytes; i++){
		count++;
		if(i == widthbytes-1 && padding !=0){
			skip = 1;
			index = i; 
		}else if(i == index+padding) skip=0;
		fread(rgb, sizeof(char), 3, fp);
		if(skip==1){
			grayscaleEffect(rgb);
		}
		fwrite(rgb, sizeof(char), 3, newfp);
	}
	printf("padding :%d, counter: %d\n", padding, count);
	fclose(fp);
	fclose(newfp);
	remove(filename);
	rename("replace.tmp", filename);
	free(fileheader);
	free(infoheader);


}