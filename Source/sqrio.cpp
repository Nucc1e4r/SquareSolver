#include <stdio.h>
#include <assert.h>
#include "dblequal.h"
#include "sqrio.h"
#include "sqrconst.h"

void inputSquareData(double* const a, double* const b, double* const c) {

    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);

    assert(a != b);
    assert(b != c);
    assert(a != c);

    printf(textFormat_bold "ax^2 + bx + c = 0\n" textFormat_default);
    printf("Input a, b, c:\n");

    int nCorrect = scanf("%lg %lg %lg", a, b, c);

    if (nCorrect < params) {
        printf("Something is wrong with your input, only %d of %d coefficients were read correctly. please try again\n\n", nCorrect, params);
        fflush(stdin);
        inputSquareData(a, b, c);
    }
}


void printSolution(const nSolutions nRoots, const double x1, const double x2) {
    switch (nRoots) {
        case TWO:
            printf("two roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;

        case ONE:
            printf("one root: x = %lg\n",x1);
            break;

        case ZERO:
            printf("no real solutions\n");
            break;

        case INF:
            printf("infinite amount of solutions\n");
            break;

        default:
            printf("!NUMBER OF SOLUTIONS INTERPRETATION ERROR!");
    }
}



void printEquation(const double a, const double b, const double c) { // TODO: ask
    if (doubleEqual(a, 0)) {

        if      (doubleEqual(b, 0))    printf("%lg = 0\n", c);
        else if (doubleEqual(b, 1))    printf("x + %lg = 0\n", c);
        else                           printf("%lgx + %lg = 0\n", b, c);

    } else if (doubleEqual(a, 1)) {
        if      (doubleEqual(b, 0))          printf("x^2 + %lg = 0\n", c);
        else if (doubleEqual(b, 1))       printf("x^2 + x + %lg = 0\n", c);
        else                            printf("x^2 + %lgx + %lg = 0\n", b, c);

    } else {

        if (doubleEqual(b, 0))          printf("%lgx^2 + x^2 + %lg = 0\n", a, c);
        else if (doubleEqual(b, 1))       printf("%lgx^2 + x + %lg = 0\n", a, c);
        else                            printf("%lgx^2 + %lgx + %lg = 0\n", a, b, c);
    }
}
