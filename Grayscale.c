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

void pinkscaleEffect(unsigned char *rgb){
	float value = 0.255*rgb[0] + 0.192*rgb[1] + 0.203*rgb[2];
	int pinkscale = round(value);
	rgb[0] = pinkscale;
	rgb[1] = pinkscale;
	rgb[2] = pinkscale;
}

void bmpGr(char *filename){
	
	FILE *newfp = fopen("replace.tmp", "wb"); 
	BITMAPFILEHEADER *fileheader =newImageName(filename);
	BITMAPINFOHEADER *infoheader = newImageName(filename);
	
	int padding = paddBytes(infoheader);
	int Headerbytes = fileheader->bfOffBits;
	int Databytes = fileheader->bfSize - Headerbytes;
	int widthbytes = infoheader->biWidth*3 ;

	cpyHeader(filename,newfp,Headerbytes);

	unsigned char rgb[3];
	int skip=0;
	int index=0;
	int count=0;
	int ef=1;
	for(int i = 0; i<Databytes; i++){
		count++;
		if(i == widthbytes-1 && padding !=0){
			skip = 1;
			index = i; 
			
		}else if(i == index+padding) skip=0;
		fread(rgb, sizeof(char), 3, filename);
		if(!skip){
			if(ef == 1)grayscaleEffect(rgb);
			else if(ef == 2)pinkscaleEffect(rgb);
		}
		fwrite(rgb, sizeof(char), 3, newfp);
	}
	printf("padding :%d, counter: %d\n", padding, count);
	fclose(filename);
	fclose(newfp);
	rename("replace.tmp", filename);
	free(fileheader);
	free(infoheader);


}