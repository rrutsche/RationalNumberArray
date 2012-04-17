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
    return rnArray;
}

void rnAdd(RationalNumberArray* rna){

}
