#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

struct RationalNumberArray;

#endif // RATIONALNUMBERARRAY_H

#include "rationalnumber.h"

RationalNumberArray* rnaCreate(int size);
void rnaAdd(RationalNumberArray* rna, RationalNumber* rn);
void rnaDelete(RationalNumberArray* rna);
int rnaCapacity(RationalNumberArray* rna);
int rnaSize(RationalNumberArray* rna);
void rnaResize(RationalNumberArray* rna, int size);
void rnaSet(RationalNumberArray* rna, RationalNumber* rn, int index);
RationalNumber* rnaGet(RationalNumberArray* rna, int index);
/*

rnaRemove();
*/
