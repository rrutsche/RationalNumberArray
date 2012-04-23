#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

struct RationalNumberArray;

#endif // RATIONALNUMBERARRAY_H

using namespace std;
#include "rationalnumber.h"
#include <string>

RationalNumberArray* rnaCreate(const int size);
void rnaAdd(RationalNumberArray* const rna, const RationalNumber *rn);
void rnaDelete(RationalNumberArray* rna);
int rnaCapacity(const RationalNumberArray* rna);
int rnaSize(const RationalNumberArray* rna);
void rnaResize(RationalNumberArray* const rna, const int size);
void rnaSet(RationalNumberArray* const rna, const RationalNumber* rn, const int index);
RationalNumber* rnaGet(const RationalNumberArray* rna, const int index);
void rnaRemove(RationalNumberArray* rna, int beginIndex, int endIndex);
void rnaToString(const RationalNumberArray* rna);

