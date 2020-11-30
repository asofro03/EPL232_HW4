#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <Grayscale.h>
 
void grayscaleEffect(unsigned char *rgb){
	float value = 0.299*rgb[0] + 0.587*rgb[1] + 0.114*rgb[2];
	int grayscale = round(value);
	rgb[0] =(unsigned char) grayscale;
	rgb[1] =(unsigned char) grayscale;
	rgb[2] =(unsigned char) grayscale;
}

void pinkscaleEffect(unsigned char *rgb){
	float value = 0.255*rgb[0] + 0.192*rgb[1] + 0.203*rgb[2];
	int pinkscale = round(value);
	rgb[0] = pinkscale;
	rgb[1] = pinkscale;
	rgb[2] = pinkscale;
}


void bmpGr(char *filename,int effect){
	
	IMAGE *image= newImage(filename);
	int padding = paddBytes(image->INFOHEADER);
	int Headerbytes = (image->FILEHEADER)->bfOffBits;
	int Databytes = (image->FILEHEADER)->bfSize - Headerbytes;
	int widthbytes = (image->INFOHEADER)->biWidth*3 ;

	
	int skip=0;
	int index=0;
	
	int ef=1;

		int j;
		for(j=0; j<image->INFOHEADER->biSizeImage;j+=3){
			unsigned char *a=(unsigned char *)malloc(sizeof(unsigned char *)*3);
			a[0]=image->DATA[j];
			a[1]=image->DATA[j+1];
			a[2]=image->DATA[j+2];

			if(!skip){
			if(ef == 1){
				grayscaleEffect(a);
				image->DATA[j]=a[0];
				image->DATA[j+1]=a[1];
				image->DATA[j+2]=a[2];


			}
			else if(ef == 2){
				pinkscaleEffect(a);
				image->DATA[j]=a[0];
				image->DATA[j+1]=a[1];
				image->DATA[j+2]=a[2];
				}
			}
		}
	
	saveimage(image);
	free(image);
	}
