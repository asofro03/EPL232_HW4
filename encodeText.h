/** @file encodeText
 *  @brief 2 methodes that we need in other classes
 *  @author Antria Argyrou
 *  @bug not known bugs 
 */



#ifndef ENCODETEXT_H
#define ENCODETEXT_H

/**
 * @brief creates an array with integers and then 'suffles' it
 * @param N
 * @param systemkey
 */
int *createPermutationFunction(int N, unsigned int systemkey);


/**
 * @brief calculates the Un
 * @param m
 * @param n
 */ 
byte getBit(char *m, int n);

#endif