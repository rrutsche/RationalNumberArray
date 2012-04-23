#include "rationalnumber.h"
#include "rationalnumberarray.h"
#include <cstdlib>
#include <stdio.h>
#include <string.h>

enum RNAError{
    NAN,
    OUT_OF_MEMORY,
    INVALID_INDEX,
    INVALID_RNA
};
struct RationalNumberArray{
    RationalNumber* data;
    int size;
    int capacity;
    RNAError* error;
};



/*
    rnaCreate()
    Creates a RationalNumberArray and allocates its required memory.
    Returns a RationalNumberArray pointer.
*/
RationalNumberArray* rnaCreate(const int capacity){
    RationalNumberArray* rna = (RationalNumberArray*) malloc(sizeof(RationalNumberArray));
    RationalNumber* rn = (RationalNumber*) malloc(capacity * sizeof(RationalNumber));
    RNAError* err = (RNAError*) malloc(sizeof(RNAError));
    rna->error = err;
    if(!rna || !rn || !err) {
        rna->error[0] = OUT_OF_MEMORY;
    }
    rna->capacity = capacity;
    rna->size = 0;
    rna->data = rn;
    return rna;
}

/*
    rnaDelete()
    Deletes the allocated memory of the given RationalNumberArray.
*/
void rnaDelete(RationalNumberArray* rna){
    if(!rna){
        rna->error[0] = INVALID_RNA;
    }
    free(rna->data);
    free(rna);
}

/*
    rnaCapacity()
    Returns the capacity of the given RationalNumberArray
*/
int rnaCapacity(const RationalNumberArray* rna){
    if(!rna){
        rna->error[0] = INVALID_RNA;
    }
    return rna->capacity;
}

/*
    rnaSize()
    Returns the size of the given RationalNumberArray
*/
int rnaSize(RationalNumberArray *rna){
    if(!rna){
        rna->error[0] = INVALID_RNA;
    }
    return rna->size;
}

/*
    rnaAdd()
    Adds the RationalNumber to the next free index of the given RationalNumberArray.
    If the memory of the RationalNumberArray is not enough, it will be reallocated.
*/
void rnaAdd(RationalNumberArray* const rna, const RationalNumber *rn){

    if(rnIsNaN(*rn)){
        rna->error[0] = NAN;
    }else if(!rna){
        rna->error[0] = INVALID_RNA;
    }
    if(rna->size > rna->capacity - 1){
        realloc(rna->data, sizeof(rna->data) + 10 * sizeof(RationalNumber));
        rna->capacity = rna->capacity + 10;
    }
    rna->data[rna->size] = *rn;
    rna->size++;
}

/*
    rnaResize()
    Resizes the given RationalNumberArray to the given size.
*/
void rnaResize(RationalNumberArray* const rna, const int size){
    realloc(rna->data, size * sizeof(RationalNumber));
    rna->capacity = size;
    if(rna->capacity < rna->size){
        rna->size = size;
    }
}

/*
    rnaSet()
    Sets the RationalNumber to the specified index of the given RationalNumberArray.
    If the index is greater than the last element of the RationalNumberArray, the
    array will be resized.
*/
void rnaSet(RationalNumberArray* const rna, const RationalNumber* rn, const int index){

    RationalNumber rnTemp = {0,1};
    if(index >= rna->capacity){
        int dif = 2 * index;
        realloc(rna->data, dif * sizeof(RationalNumber));
        rna->capacity = dif;
    }

    if(index >= rna->size){
        int i = rna->size;
        for(i; i<index; i++){
            rna->data[i] = rnTemp;
        }
        rna->size = index + 1;
    }
    rna->data[index] = *rn;
}

/*
    rnaGet()
    Returns a RationalNumberPointer of the given RationalNumberArray at the specified index.
*/
RationalNumber* rnaGet(const RationalNumberArray* rna, const int index){
    return &(rna->data[index]);
}

/*
    rnaRemove()

*/
void rnaRemove(RationalNumberArray *rna, const int beginIndex, const int endIndex){

    int i = beginIndex;
    int j = endIndex;
    while(j < rna->size){
        rna->data[i] = rna->data[j];
        i++;
        j++;
    }
    rna->size = i;
}

void rnaToString(const RationalNumberArray* rna){
    printf("[");
    for(int i = 0; i<rna->size-1; i++){
        printf("%d/%d, ",rna->data[i].nominator, rna->data[i].denominator);
    }
    printf("%d/%d",rna->data[rna->size-1].nominator, rna->data[rna->size-1].denominator);
    printf("]\n");
}
