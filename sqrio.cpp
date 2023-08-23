#include <stdio.h>
#include <assert.h>
#include "isZero.h"
#include "sqrio.h"

void inputSquareData(double* const a, double* const b, double* const c) { // const ptr

    assert(a != NULL);
    assert(b != nullptr);
    assert(c != 0);

    assert(a != b);
    assert(b != c);
    assert(a != c);

    printf("Input a, b, c:\n");
    scanf("%lg %lg %lg", a, b, c);            // TODO: proceed input correctness

}

void outputSquareSolution(nSolutions nRoots, double* x1, double* x2) {

    assert(x1 != 0);
    assert(x2 != 0);

    assert(x1 != x2);

    switch (nRoots) {
        case TWO:

            // Fixing negative zeros:
            if (isZero(*x1)) *x1 = 0;
            if (isZero(*x2)) *x2 = 0;

            printf("x1 = %lg; x2 = %lg", *x1, *x2);
            break;


        case ONE:

            // Fixing negative zeros:
            if (isZero(*x1)) *x1 = 0;

            printf("x = %lg", *x1);
            break;


        case ZERO:

            printf("No real solutions");
            break;


        case INF:

            printf("x is any");
            break;


        default:
            printf("!NUMBER OF ROOTS INTERPRETATION ERROR!");
    }
}
