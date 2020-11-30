/** @file Grayscale
 *  @brief turns a colored image to a grayscale one
 *  @author Antria Argyrou
 *  @bug does not compile  
 */

#ifndef GRAYSCALE_H
#define GRAYSCALE_H

/**
 * @brief this method turns the colors from a rainbow color to grayscale onr(black and white)
 * @param rgb array
 *  
 */
void grayscaleEffect(unsigned char *rgb);

/**
 * @brief thats an extra method that changes the image to a pinkscale
 * @param rgb array
 * 
 */ 
void pinkscaleEffect(unsigned char *rgb);

/**
 * @brief this method is where actually the change happends it takes the 
 *		 image and change the rgb 3 by 3 by calling the grayscale effect method 
 *        
 * @param filename is the image
 * @param effect the 1 is for the homework and the 2 is the extra method
 * 
 */

void bmpGr(char *filename, int effect);

#endif