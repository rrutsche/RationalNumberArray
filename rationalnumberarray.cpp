#include "rationalnumber.h"
#include "rationalnumberarray.h"
#include <cstdlib>

struct RationalNumberArray{
    RationalNumber* data;
    int size;
    int capacity;
};

RationalNumberArray* rnaCreate(int capacity){
    RationalNumberArray* rnArray = (RationalNumberArray*) malloc(capacity * sizeof(RationalNumber));
    rnArray->capacity = capacity;
    if(!rnArray) {
        // Out of Memory!??
    }
    return rnArray;
}

void rnaDelete(RationalNumberArray* rna){
    free(rna);
}

int rnaCapacity(RationalNumberArray* rna){
    return rna->capacity;
}

int rnaSize(RationalNumberArray *rna){
    return rna->size;
}
