

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <encodeText.h>


int *createPermutationFunction(int N, unsigned int systemkey){
    int *perm= malloc(sizeof(int)*N);
    for (int i=0; i<N; i++){
        perm[i]=i+1;
    }
    srand(systemkey);
    for(int i=0;i<N;i++){
        int k=rand() % N;
        int j=rand()%N;
        int temp=perm[k];
        perm[k]=perm[j];
        perm[j]=temp;
    }
    return perm;

}


byte getBit(char *m, int n){
    if(n<0 || n> 8*strlen(m))
        return 0;
    int byteNumber = n/8;
    byte selectedByte= m[byteNumber];
    int bitNumber = 7-(n%8);
    return (selectedByte & 1<<bitNumber)>>(bitNumber-1);
}