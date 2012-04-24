#include "rationalnumber.h"
#include "rationalnumberarray.h"
#include <cstdlib>
#include <stdio.h>
#include <string.h>

/*
  Ich habe ein paar Anpassungen im struct gemacht, das malloc für die errorFunction aus der rnaCreate()
  entfernt und eine Zeile in der Callback Funktion hinzugefügt. Es kompiliert, aber ob das funktioniert,
  weiß ich nicht. Schau einfach mal rein, vielleicht ist es auch alles falsch :-)

  */

enum RNAError{
    NAN,
    OUT_OF_MEMORY,
    INVALID_INDEX,
    INVALID_RNA,
    INVALID_RN,
    NO_ERRORS
};
struct RationalNumberArray{
    RationalNumber* data;
    unsigned int size;
    unsigned int capacity;
    RNAError* error;
    void (*errorFunction)(RationalNumberArray*);
};



/*
    rnaCreate()
    Creates a RationalNumberArray and allocates its required memory.
    Returns a RationalNumberArray pointer.
*/
RationalNumberArray* rnaCreate(const unsigned int capacity){
    RationalNumberArray* rna = (RationalNumberArray*) malloc(sizeof(RationalNumberArray));
    RationalNumber* rn = (RationalNumber*) malloc(capacity * sizeof(RationalNumber));
    RNAError* err = (RNAError*) malloc(sizeof(RNAError));

    rna->error = err;
    rna->data = rn;
    if(!rna->data || !rn || !err) {
        rna->error[0] = OUT_OF_MEMORY;
    }
    rna->capacity = capacity;
    rna->size = 0;

    rna->error[0] = NO_ERRORS;
    return rna;
}

/*
    rnaDelete()
    Deletes the allocated memory of the given RationalNumberArray.
*/
void rnaDelete(RationalNumberArray* rna){
    if(!rna->data){
        rna->error[0] = INVALID_RNA;
        return;
    }
    free(rna->data);
    free(rna->error);
    free(rna);
}

/*
    rnaCapacity()
    Returns the capacity of the given RationalNumberArray
*/
int rnaCapacity(const RationalNumberArray* rna){
    if(!rna->data){
        rna->error[0] = INVALID_RNA;
        return 0;
    }
    rna->error[0] = NO_ERRORS;
    return rna->capacity;
}

/*
    rnaSize()
    Returns the size of the given RationalNumberArray
*/
int rnaSize(RationalNumberArray *rna){
    if(!rna->data){
        rna->error[0] = INVALID_RNA;
        return 0;
    }
    rna->error[0] = NO_ERRORS;
    return rna->size;
}

/*
    rnaAdd()
    Adds the RationalNumber to the next free index of the given RationalNumberArray.
    If the memory of the RationalNumberArray is not enough, it will be reallocated.
*/
void rnaAdd(RationalNumberArray* const rna, const RationalNumber *rn){

    //rnaSet(rna , rn, rna->size); ???

    if(!rn){
        rna->error[0] = INVALID_RN;
        return;
    }else if(!rna->data){
        rna->error[0] = INVALID_RNA;
        return;
    }else if(rnIsNaN(*rn)){
        rna->error[0] = NAN;
        return;
    }
    if(rna->size > rna->capacity - 1){
        realloc(rna->data, sizeof(rna->data) + 10 * sizeof(RationalNumber));
        rna->capacity = rna->capacity + 10;
    }
    rna->data[rna->size] = *rn;
    rna->size++;
    rna->error[0] = NO_ERRORS;
}

/*
    rnaResize()
    Resizes the given RationalNumberArray to the given size.
*/
void rnaResize(RationalNumberArray* const rna, const unsigned int size){
    if(!rna->data){
        rna->error[0] = INVALID_RNA;
        return;
    }
    realloc(rna->data, size * sizeof(RationalNumber));
    rna->capacity = size;
    if(rna->capacity < rna->size){
        rna->size = size;
    }
    rna->error[0] = NO_ERRORS;
}

/*
    rnaSet()
    Sets the RationalNumber to the specified index of the given RationalNumberArray.
    If the index is greater than the last element of the RationalNumberArray, the
    array will be resized.
*/
void rnaSet(RationalNumberArray* const rna, const RationalNumber* rn, const unsigned int index){

    if(!rn){
        rna->error[0] = INVALID_RN;
        return;
    }else if(!rna->data){
        rna->error[0] = INVALID_RNA;
        return;
    }else if(rnIsNaN(*rn)){
        rna->error[0] = NAN;
    }
    RationalNumber rnTemp = {0,1};
    if(index >= rna->capacity){
        int dif = 2 * index;
        realloc(rna->data, dif * sizeof(RationalNumber));
        rna->capacity = dif;
    }

    if(index >= rna->size){
        for(unsigned int i = rna->size; i<index; i++){
            rna->data[i] = rnTemp;
        }
        rna->size = index + 1;
    }
    rna->data[index] = *rn;
    rna->error[0] = NO_ERRORS;
}

/*
    rnaGet()
    Returns a RationalNumberPointer of the given RationalNumberArray at the specified index.
*/
RationalNumber* rnaGet(const RationalNumberArray* rna, const unsigned int index){
    if(!rna->data){
        rna->error[0] = INVALID_RNA;
        return 0;
    }
    if(index >= rna->size){
        rna->error[0] = INVALID_INDEX;
        return &(rna->data[index]);
    }
    rna->error[0] = NO_ERRORS;
    return &(rna->data[index]);
}

/*
    rnaRemove()

*/
void rnaRemove(RationalNumberArray *rna, const unsigned int beginIndex, const unsigned int endIndex){

    if(!rna->data){
        rna->error[0] = INVALID_RNA;
        return;
    }
    unsigned int i = beginIndex;
    unsigned int j = endIndex;
    while(j < rna->size){
        rna->data[i] = rna->data[j];
        i++;
        j++;
    }
    rna->size = i;
    rna->error[0] = NO_ERRORS;
}

int rnaError(RationalNumberArray* rna){

    printf("-------------rna error------------- %d\n",rna->error[0]);
    int i = rna->error[0];
    switch(i) {
        case 0:
            printf("ERROR: NaN\n");
            return 0;
        case 1:
            printf("ERROR: OUT_OF_MEMORY\n");
            return 1;
        case 2:
            printf("ERROR: INVALID_INDEX\n");
            return 2;
        case 3:
            printf("ERROR: INVALID_RNA\n");
            return 3;
        case 4:
            printf("ERROR: INVALID_RN\n");
            return 4;
        default:
            printf("ERROR: NO_ERRORS\n");
            return 5;
    }

}

void freeRnaData(RationalNumberArray *rna){
    free(rna->data);
    rna->data = 0;
}

void rnaSetErrorCallback(RationalNumberArray* rna, void pointer(RationalNumberArray* rnaErr)){

    rna->errorFunction = pointer;
}

void rnaToString(const RationalNumberArray* rna){
    printf("[");
    for(unsigned int i = 0; i<rna->size-1; i++){
        printf("%d/%d, ",rna->data[i].nominator, rna->data[i].denominator);
    }
    printf("%d/%d",rna->data[rna->size-1].nominator, rna->data[rna->size-1].denominator);
    printf("]\n");
}
