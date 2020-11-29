/** @file Grayscale
 *  @brief turns a colored image to a grayscale one
 *  @author Antria Argyrou
 *  @bug not known 
 */

#ifndef GRAYSCALE_H
#define GRAYSCALE_H

/**
 * @brief this method turns the colors from a rainbow color to grayscale onr(black and white)
 * @param rgb 
 *  
 */
void grayscaleEffect(unsigned char *rgb);

/**
 * @brief opens a file which is the image , seperates the needed and then calls the grayscaleEffect method 
 *        to chande the colors
 * @param filename is the image
 * 
 */
void bmpGr(char *filename);

#endif