#include "rationalnumber.h"
#include <iostream>
#include <stdio.h>

using namespace std;

bool rnIsValid(RationalNumber n){
    if (n.denominator == 0){
        return false;
    }
    return true;
}

bool rnIsNaN(RationalNumber n){
    if (n.denominator == 0){
        return true;
    }
    return false;
}

bool rnEqual(RationalNumber m, RationalNumber n){

    if(rnIsNaN(m) || rnIsNaN(n)){
        return false;
    }
    printf("\nrnEqual\n");
    printf("%d/%d equal %d/%d \n",m.nominator,m.denominator,n.nominator,n.denominator);
    n = rnNormalize(n);
    m = rnNormalize(m);

    printf("normalized: %d/%d equal %d/%d \n",m.nominator,m.denominator,n.nominator,n.denominator);
    int mNominator = m.nominator * n.denominator;
    int nNominator = n.nominator * m.denominator;
    if(mNominator == nNominator){
        return true;
    }

    return false;
}

bool rnLessThan(RationalNumber m, RationalNumber n){
    if(rnIsValid(m) && rnIsValid(n)){
        printf("\nrnLessThan\n");
        printf("%d/%d lessthan %d/%d \n",m.nominator,m.denominator,n.nominator,n.denominator);
        n = rnNormalize(n);
        m = rnNormalize(m);
        if(m.denominator * n.denominator < 0){
            if(m.nominator * n.denominator > n.nominator * m.denominator){
                return true;
            }
        }else{
            if(m.nominator * n.denominator < n.nominator * m.denominator){
                return true;
            }
        }

    }
    return false;
}

RationalNumber rnAdd(RationalNumber m, RationalNumber n){

    if(rnIsNaN(m)){
        return m;
    }else if(rnIsNaN(n)){
        return n;
    }
    printf("\nrnAdd\n");

    m = rnNormalize(m);
    n = rnNormalize(n);
    printf("add: ");
    printf("%d/%d + ", m.nominator, m.denominator);
    printf("%d/%d = ", n.nominator, n.denominator);

    m.nominator *= n.denominator;
    n.nominator *= m.denominator;
    m.denominator *= n.denominator;


    RationalNumber result;
    result.nominator = m.nominator + n.nominator;
    result.denominator = m.denominator;

    result = rnNormalize(result);
    printf("\nrnAdd Result: %d/%d", result.nominator, result.denominator);
    return result;

}

RationalNumber rnSubtract(RationalNumber m, RationalNumber n){

    if(rnIsNaN(m)){
        return m;
    }else if(rnIsNaN(n)){
        return n;
    }

    m = rnNormalize(m);
    n = rnNormalize(n);

    m.nominator *= n.denominator;
    n.nominator *= m.denominator;
    m.denominator *= n.denominator;    

    RationalNumber result;
    result.nominator = m.nominator - n.nominator;
    result.denominator = m.denominator;

    return rnNormalize(result);
}

RationalNumber rnMultiply(RationalNumber m, RationalNumber n){

    if(rnIsNaN(m)){
        return m;
    }else if(rnIsNaN(n)){
        return n;
    }

    m = rnNormalize(m);
    n = rnNormalize(n);

    RationalNumber result;
    result.nominator = m.nominator * n.nominator;
    result.denominator = m.denominator * n.denominator;

    return rnNormalize(result);
}

RationalNumber rnDivide(RationalNumber m, RationalNumber n){

    printf("divide: ");
    printf("%d/%d / %d/%d ", m.nominator, m.denominator, n.nominator, n.denominator);
    if(rnIsNaN(m)){
        return m;
    }else if(rnIsNaN(n)){
        return n;
    }



    m = rnNormalize(m);
    n = rnNormalize(n);

    RationalNumber result;
    result.nominator = m.nominator * n.denominator;
    result.denominator = m.denominator * n.nominator;

    return rnNormalize(result);
}

int gcd(int m, int n){
    if(n == 0){
        return m;
    }else{
        return gcd(n, m%n);
    }
}

int kgV(int m, int n){
    int divisor = gcd(m, n);
    int result = (m * n) / divisor;
    return result;
}


RationalNumber rnNormalize(RationalNumber n){
    int divisor = gcd(n.nominator, n.denominator);
    RationalNumber result;
    result.nominator = n.nominator / divisor;
    result.denominator = n.denominator / divisor;
    return result;
}
