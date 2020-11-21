#include<stdio.h>

typedef struct{
    char bfType1;   // 1 byte   // = 'B';
    char bfType2;   // 1 byte   // = 'M';
    int bfSize;     // 4 byte   //size of the file (including padding) in bytes
    short bfReserved1;  // 2 bytes  // Usually set to zero
    short bfReserved2;  // 2 bytes  // Usually set to zero
    int bfOffBits;  // 4 byte   // the offset from the beginning of the file to the bitmap data
}BITMAPFILEHEADER;

typedef struct{
    int biSize; // 4 byte   // size of the BITMAPINFOHEADER structure, in bytes
    int biWidth;    // 4 byte   // width of the image, in pixels
    int biHeight;    // 4 byte   // height of the image, in pixels
    short biPlanes; // 2 bytes  // the number of planes of the target device,usually set to zero
    short biBitCount; // 2 bytes  // the number of bits per pixel
    int biCompression;  // 4 bytes  // Specifies the type of compression,
    // usually set to zero (no compression). Need to provide an error if image is compressed.
    int biSizeImage;    // 4 bytes  // the size of the image data, in bytes.
    // If there is no compression, it is valid to set this member to zero.
    int biXPelsPerMeter;   // 4 bytes  // the horizontal pixels per meter on the designated target device, usually set to zero.
    int biYPelsPerMeter;   // 4 bytes  // the vertical pixels per meter on the designated target device, usually set to zero.
    int biClrUsed;   // 4 bytes  // the number of colors used in the bitmap, 
    // if set to zero the number of colors is calculated using the biBitCount member.
    int biClrImportant;   // 4 bytes  // the number of color that are 'important' for the bitmap,
    // if set to zero, all colors are important.
}BITMAPINFOHEADER