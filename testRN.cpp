/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>

#include "rationalnumber.h"
#include "rationalnumberarray.h"


int main()
{

    printf("Performing unit tests for RationalNumber...");
    fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );
    assert( rnIsNaN(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( rnIsNaN(t4) );

    printf("Performing unit tests for RationalNumberArray...");
     /* Part 2 - RationalNumberArray type */
        printf("\n");

        RationalNumber *rn1 = &n1;
        RationalNumber *rn2 = &n2;
        RationalNumber *rn3 = &n3;
        RationalNumber *rn4 = &n4;

        RationalNumberArray *rna = rnaCreate(10);

        rnaAdd(rna, rn4);
        rnaSet(rna,rn1,1);
        rnaSet(rna,rn2,3);
        rnaSet(rna,rn3,6);
        rnaSet(rna,rn4,8);
        rnaToString(rna);

        assert(rnEqual(n1,*rnaGet(rna,0)));
        assert(rnEqual(n2,*rnaGet(rna,3)));
        assert(rnEqual(n3,*rnaGet(rna,6)));
        assert(rnEqual(n3,*rnaGet(rna,8)));


        rnaRemove(rna,0,3);
        rnaToString(rna);
        assert(!rnEqual(n1,*rnaGet(rna,0)));
        assert(!rnEqual(n2,*rnaGet(rna,3)));

        assert(10 == rnaSize(rna));

        rnaSet(rna, rn1, 14);
        assert(15 == rnaSize(rna));
        assert(15 < rnaCapacity(rna));

        rnaAdd(rna, rn2);
        assert(rnEqual(n2,*rnaGet(rna,rnaSize(rna)-1)));

/*
    RationalNumberArray* rna = rnaCreate(5);

    printf("capacity of rna: %d \n", rnaCapacity(rna));

    printf("-------rnaAdd()--------\n");
    rnaAdd(rna,&n1);
    rnaAdd(rna,&n2);
    rnaAdd(rna,&n3);
    printf("size of rna: %d \n", rnaSize(rna));
    printf("capacity of rna: %d \n", rnaCapacity(rna));
    rnaToString(rna);

    printf("-------rnaSet()--------\n");
    rnaSet(rna, &n2, 9);
    printf("size of rna: %d \n", rnaSize(rna));
    printf("capacity of rna: %d \n", rnaCapacity(rna));
    rnaToString(rna);

    printf("-------rnaGet()---------\n");
    int index = 9;
    RationalNumber* rnp = rnaGet(rna, index);
    printf("RationalNumber on index %d: %d/%d\n", index, rnp->nominator, rnp->denominator);

    printf("-------rnaResize()---------\n");
    int resizeTo = 20;
    rnaResize(rna, resizeTo);
    printf("rna resized to %d\n", resizeTo);
    printf("size of rna: %d \n", rnaSize(rna));
    printf("capacity of rna: %d \n", rnaCapacity(rna));
    rnaToString(rna);

    resizeTo = 2;
    rnaResize(rna, resizeTo);
    printf("rna resized to %d\n", resizeTo);
    printf("size of rna: %d \n", rnaSize(rna));
    printf("capacity of rna: %d \n", rnaCapacity(rna));
    rnaToString(rna);

    printf("-------rnaAdd()--------\n");
    rnaAdd(rna,&n3);
    rnaAdd(rna,&n4);
    printf("size of rna: %d \n", rnaSize(rna));
    printf("capacity of rna: %d \n", rnaCapacity(rna));
    rnaToString(rna);

    printf("------rnaRemove()-------\n");
    rnaRemove(rna, 1, 2);
    printf("size of rna: %d \n", rnaSize(rna));
    printf("capacity of rna: %d \n", rnaCapacity(rna));
    rnaToString(rna);
*/
    printf(" successful!\n");

    return 0;
}

