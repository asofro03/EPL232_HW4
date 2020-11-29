#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/**
 * @brief this method turns the colors from a rainbow color to grayscale onr(black and white)
 * @param rgb 
 *  
 */
void grayscaleEffect(unsigned char *rgb){
	float value = 0.299*rgb[0] + 0.587*rgb[1] + 0.114*rgb[2];
	int grayscale = round(value);
	rgb[0] = grayscale;
	rgb[1] = grayscale;
	rgb[2] = grayscale;
}



void BmpEffects(char *filename){
	FILE *fp = fopen(filename, "rb");

	FILE *newfp = fopen("replace.tmp", "wb"); 
	BITMAPFILEHEADER *fileheader =newImage(fp);
	BITMAPINFOHEADER *infoheader = newImage(fp);
	
	int padding = paddingBytes(infoheader);
	int Headerbytes = fileheader->biBitCount;
	int Databytes = fileheader->biSizeImage - Headerbytes;
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