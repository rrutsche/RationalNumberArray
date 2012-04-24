#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

struct RationalNumberArray;


#endif // RATIONALNUMBERARRAY_H

using namespace std;
#include "rationalnumber.h"
#include <string>

RationalNumberArray* rnaCreate(const unsigned int size);
void rnaAdd(RationalNumberArray* const rna, const RationalNumber *rn);
void rnaDelete(RationalNumberArray* rna);
int rnaCapacity(const RationalNumberArray* rna);
int rnaSize(RationalNumberArray* rna);
void rnaResize(RationalNumberArray* const rna, const unsigned int size);
void rnaSet(RationalNumberArray* const rna, const RationalNumber* rn, const unsigned int index);
RationalNumber* rnaGet(const RationalNumberArray* rna, const unsigned int index);
void rnaRemove(RationalNumberArray* rna, unsigned int beginIndex, unsigned int endIndex);
void rnaToString(const RationalNumberArray* rna);
int rnaError(RationalNumberArray* rna);
void freeRnaData(RationalNumberArray *rna);
void rnaSetErrorCallback(RationalNumberArray* rna, void (*pointer)(const RationalNumberArray* rnaErr));
void userErrorFunction(RationalNumberArray* rna);

