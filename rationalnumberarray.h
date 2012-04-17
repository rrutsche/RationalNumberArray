#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

struct RationalNumberArray;

#endif // RATIONALNUMBERARRAY_H

#include "rationalnumber.h"

RationalNumberArray* rnaCreate(int size);
//void rnaAdd(RationalNumber* rn);
void rnaDelete(RationalNumberArray* rna);
int rnaCapacity(RationalNumberArray* rna);
int rnaSize(RationalNumberArray* rna);
/*
rnaResize();
rnaSet();
rnaGet();
rnaRemove();
*/
