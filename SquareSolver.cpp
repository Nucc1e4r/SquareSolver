#include <stdio.h>
#include <math.h>
#include <assert.h>

// Creating codes for all numbers of solutions:
    enum sols {ZERO, ONE, TWO, INF};

// Declaring functions:
    bool isZero (double x);

    void inputSquareData(double* a, double* b, double* c);
    void outputSquareSolution(sols nRoots, double* x1, double* x2);

    sols solveSquare (const double a, const double b, const double c, double* x1, double* x2);
    sols solveLinear (const double a, const double b, double* x);

//----------------------------------------------------------------------------------

int main () {

    printf("# Square equation solver\n"
           "# Made by: Nucc1e4r\n\n");

    printf("ax^2 + bx + c = 0\n\n");

    double a = 0, b = 0, c = 0;

    inputSquareData(&a, &b, &c);


    double x1 = 0, x2 = 0;
    enum sols nRoots = ZERO;

    nRoots = solveSquare(a, b, c, &x1, &x2);

    // Fixing negative zeros:
        if (isZero(x1)) x1 = 0;
        if (isZero(x2)) x2 = 0;

    outputSquareSolution(nRoots, &x1, &x2);

    return 0;
}

//----------------------------------------------------------------------------------

bool isZero (double x) {

    assert(isfinite(x));

    double eps = 0.00000001;
    if (fabs(x) < eps) {
        return true;
    }
    return false;
}

void inputSquareData(double* a, double* b, double* c) {

    assert(a != b);
    assert(b != c);
    assert(a != c);

    printf("Input a:\n");
    scanf("%lg", a);

    printf("Input b:\n");
    scanf("%lg", b);

    printf("Input c:\n");
    scanf("%lg", c);
}

void outputSquareSolution(sols nRoots, double* x1, double* x2) {

    assert(x1 != x2);

    switch (nRoots) {
        case TWO:
            printf("x1 = %lg; x2 = %lg", *x1, *x2);
            break;
        case ONE:
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

sols solveSquare (const double a, const double b, const double c, double* x1, double* x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != x2);

    if (isZero(a)) {
        return solveLinear(b, c, x1);
    }
    else /* if (a != 0) */ {
        double D = b*b - 4*a*c;
        double sqrtD = sqrt(D);
        if (D > 0) {
            *x1 = (-b + sqrtD) / (2*a);
            *x2 = (-b - sqrtD) / (2*a);
            return TWO;
        }
        else if (isZero(D)) {
            *x1 = -b / (2*a);
            return ONE;
        }
        else {
            return ZERO;
        }
    }
}


sols solveLinear (const double a, const double b, double* x) {

    assert(isfinite(a));
    assert(isfinite(b));

    if (isZero(a)) {
        if (isZero(b)) {
            return INF;
        }
        return ZERO;
    }
    else /* if (a != 0) */ {
        *x = -b / a;
        return ONE;
    }
}
