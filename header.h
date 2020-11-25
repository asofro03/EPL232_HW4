#ifndef HEADER_h
#define HEADER_h
#include <stdio.h>

typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int dword;

typedef struct{
    byte bfType1;   // 1 byte   // = 'B';
    byte bfType2;   // 1 byte   // = 'M';
    dword bfSize;     // 4 byte   //size of the file (including padding) in bytes
    word bfReserved1;  // 2 bytes  // Usually set to   // grey
    word bfReserved2;  // 2 bytes  // Usually set to zero  // grey
    dword bfOffBits;  // 4 byte   // the offset from the beginning of the file to the bitmap data // grey
}__attribute__ ((__packed__))BITMAPFILEHEADER;

typedef struct{
    dword biSize; // 4 byte   // size of the BITMAPINFOHEADER structure, in bytes
    dword biWidth;    // 4 byte   // width of the image, in pixels
    dword biHeight;    // 4 byte   // height of the image, in pixels
    word biPlanes; // 2 bytes  // the number of planes of the target device,usually set to zero    // grey
    word biBitCount; // 2 bytes  // the number of bits per pixel
    dword biCompression;  // 4 bytes  // Specifies the type of compression,
    // usually set to zero (no compression). Need to provide an error if image is compressed.
    dword biSizeImage;    // 4 bytes  // the size of the image data, in bytes.
    // If there is no compression, it is valid to set this member to zero.
    dword biXPelsPerMeter;   // 4 bytes  // the horizontal pixels per meter on the designated target device, usually set to zero. // grey
    dword biYPelsPerMeter;   // 4 bytes  // the vertical pixels per meter on the designated target device, usually set to zero.   // grey
    dword biClrUsed;   // 4 bytes  // the number of colors used in the bitmap, 
    // if set to zero the number of colors is calculated using the biBitCount member.   // grey
    dword biClrImportant;   // 4 bytes  // the number of color that are 'important' for the bitmap,
    // if set to zero, all colors are important.    // grey
}BITMAPINFOHEADER;

typedef struct{
    BITMAPFILEHEADER *FILEHEADER;
    BITMAPINFOHEADER *INFOHEADER;
    unsigned char *DATA;
    char *name;
}IMAGE;

/**
 * @brief Created a new image based on the data of the filename.
 * 
 * @param filename Data of the image.
 * @return IMAGE* New image.
 */
IMAGE *newImage (char *filename);

 /**
 * @brief Create a Image struct.
 * 
 * @param Data Data of the image.
 * @param InfoHeader Bitmap Info Header of the image.
 * @param FileHeader Bitmap File Header of the image.
 * @param nameOfImage Name of the image.
 * @return IMAGE* New image.
 */
IMAGE *createImage(unsigned char *Data, BITMAPINFOHEADER *InfoHeader, BITMAPFILEHEADER *FileHeader, char *nameOfImage);

/**
 * @brief Stores information about an image in a BITMAPINFOHEADER and BITMAPFILEHEADER.
 * 
 * @param filename  The name of the file/image.
 * @param bitmapInfoHeader  The information about the image.
 * @param bitmapFileHeader  The information about the file.
 * @return unsigned char*   The data.
 */
unsigned char *storeImage(char *filename, BITMAPINFOHEADER *bitmapInfoHeader, BITMAPFILEHEADER *bitmapFileHeader );

/**
 * @brief Prints the header list.
 * 
 * @param bitmapInfoHeader  The information about the image.  
 * @param bitmapFileHeader  The information about the file. 
 */
void printList(BITMAPINFOHEADER *bitmapInfoHeader, BITMAPFILEHEADER *bitmapFileHeader);

/**
 * @brief This function returns the name of a new image simpy by adding the word "new-"
 * in front of the already existing name.
 * 
 * @param name The already existing name of the pic.
 * @return char* New name of the pic "new-name".
 */
char *newImageName( char *name);

#endif