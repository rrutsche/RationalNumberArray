#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber{
    int nominator;
    int denominator;
};

#endif // RATIONALNUMBER_H

bool rnIsValid(RationalNumber n);
bool rnIsNaN(RationalNumber n);
bool rnEqual(RationalNumber m, RationalNumber n);
bool rnLessThan(RationalNumber m, RationalNumber n);
RationalNumber rnAdd(RationalNumber m, RationalNumber n);
RationalNumber rnSubtract(RationalNumber m, RationalNumber n);
RationalNumber rnMultiply(RationalNumber m, RationalNumber n);
RationalNumber rnDivide(RationalNumber m, RationalNumber n);
int gcd(int m, int n);
int kgV(int, int);
RationalNumber rnNormalize(RationalNumber n);

