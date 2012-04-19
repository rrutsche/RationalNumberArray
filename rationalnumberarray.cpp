#include "rationalnumber.h"
#include "rationalnumberarray.h"
#include <cstdlib>
#include <stdio.h>

struct RationalNumberArray{
    RationalNumber* data;
    int size;
    int capacity;
};

RationalNumberArray* rnaCreate(int capacity){
    RationalNumberArray* rna = (RationalNumberArray*) malloc(sizeof(RationalNumberArray));
    RationalNumber* rn = (RationalNumber*) malloc(capacity * sizeof(RationalNumber));
    if(!rna) {
        // Out of Memory!??
    }else if(!rn){
        // Out of Memory!!!
    }
    rna->capacity = capacity;
    rna->size = 0;
    rna->data = rn;
    return rna;
}

void rnaDelete(RationalNumberArray* rna){
    free(rna->data);
    free(rna);
}

int rnaCapacity(RationalNumberArray* rna){
    return rna->capacity;
}

int rnaSize(RationalNumberArray *rna){
    return rna->size;
}

void rnaAdd(RationalNumberArray* rna, RationalNumber *rn){

    if(rna->size > rna->capacity - 1){
        realloc(rna->data, sizeof(rna->data) + 10 * sizeof(RationalNumber));
        rna->capacity = rna->capacity + 10;
    }
    rna->data[rna->size] = *rn;
    rna->size++;
}

void rnaResize(RationalNumberArray* rna, int size){
    realloc(rna->data, size * sizeof(RationalNumber));
    rna->capacity = size * sizeof(RationalNumber);
    if(rna->capacity < rna->size){
        rna->size = rna->capacity;
    }
}

void rnaSet(RationalNumberArray* rna, RationalNumber* rn, int index){
    if(index >= rna->capacity){

        realloc(rna->data, (index + 1) * sizeof(RationalNumber));
        RationalNumber rnTemp = {0,1};
        int i = rna->capacity;
        for(i; i<index; i++){
            rna->data[i] = rnTemp;
        }
        rna->capacity = index + 1;
        rna->size = index;
    }
    rna->data[index] = *rn;
}

RationalNumber* rnaGet(RationalNumberArray* rna, int index){
    return &(rna->data[index]);
}
