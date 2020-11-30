/** @file list.h
 *  @brief Creates IMAGES structs and prints a list of image's information.
 * 
 *  This class takes as input one or more files, where we read images in the newImage function.
 *  Also in the newImage function, the information about each image is saved in an IMAGE struct.
 *  The information about each image is printed in printList function.
 *
 *  @author AnnaMaria Sofroniou
 *  @bug No known bugs.
 */

#ifndef LIST_h
#define LIST_h
#include <stdio.h>
#include <string.h>

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
}__attribute__((__packed__))BITMAPFILEHEADER;  //

typedef unsigned char luminance;
typedef luminance pixel1[1];   

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
    
}__attribute__((__packed__))BITMAPINFOHEADER;  //

typedef struct{
    BITMAPFILEHEADER *FILEHEADER;
    BITMAPINFOHEADER *INFOHEADER;
    unsigned char *DATA;
    char *name;
}__attribute__((__packed__))IMAGE; //

/**
 * @brief Saves an image as a file.
 * 
 * @param image The image that we are going to save.
 */
void saveImage(IMAGE *image);

/**
 * @brief Created a new image based on the data of the filename. Creates a Image struct where stores
 * information about the image in a BITMAPINFOHEADER, BITMAPFILEHEADER and data.
 * 
 * @param filename Name of the image.
 * @return IMAGE* New image struct filled with the image's information.
 */
IMAGE *newImage (char *filename);

/**
 * @brief Prints the header list.
 * 
 * @param image The image that the header information is stored.
 */
void printList(IMAGE *image);

/**
 * @brief This function returns the name of a new image simpy by adding the word "new-"
 * in front of the already existing name.
 * 
 * @param name The already existing name of the pic.
 * @return char* New name of the pic "new-name".
 */
char *newImageName( char *name);

/**
 * @brief finds the padding
 * 
 * @param header
 * @return 0 there isnt a padding or the padding number 
 */
int paddBytes(BITMAPINFOHEADER *header);

void cpyHeader(FILE *fpR ,FILE *fpW, int hsize);

/**
 * @brief Driver function of the class. The main function takes as input one or more images
 * and it prints a list for each image of their information.
 * 
 * @param argc The number of files.
 * @param argv The name of the files.
 */
void main(int argc, char *argv[]);

#endif