#include <stdio.h>
#include <math.h>

// Assigning a code to the situation with infinite amount of solutions:
    const int EQ_INF_SOL = -1;

// Declaring functions:
    bool isZero (double x);

    int solveSquare (const double a, const double b, const double c, double* x1, double* x2);
    int solveLinear (const double a, const double b, double* x);

//----------------------------------------------------------------------------------

int main () {

    printf("# Square equation solver\n"
           "# Made by: Nucc1e4r\n\n");

    printf("ax^2 + bx + c = 0\n\n");

    double a = 0, b = 0, c = 0;

    printf("Input a:\n");
    scanf("%lg", &a);

    printf("Input b:\n");
    scanf("%lg", &b);

    printf("Input c:\n");
    scanf("%lg", &c);


    double x1 = 0, x2 = 0;
    int nRoots = 0;

    nRoots = solveSquare(a, b, c, &x1, &x2);

    // Fixing negative zeros:
        if (isZero(x1)) x1 = 0;
        if (isZero(x2)) x2 = 0;

    switch (nRoots) {
        case 2:
            printf("x1 = %lg; x2 = %lg", x1, x2);
            break;
        case 1:
            printf("x = %lg", x1);
            break;
        case 0:
            printf("No real solutions");
            break;
        case EQ_INF_SOL:
            printf("x is any");
            break;
        default:
            printf("!NUMBER OF ROOTS INTERPRETATION ERROR!");
    }
    return 0;
}

//----------------------------------------------------------------------------------

bool isZero (double x) {
    double eps = 0.00000001;
    if (fabs(x) < eps) {
        return true;
    }
    return false;
}

int solveSquare (const double a, const double b, const double c, double* x1, double* x2) {
    if (isZero(a)) {
        return solveLinear(b, c, x1);
    }
    else /* if (a != 0) */ {
        double D = b*b - 4*a*c;
        double sqrtD = sqrt(D);
        if (D > 0) {
            *x1 = (-b + sqrtD) / (2*a);
            *x2 = (-b - sqrtD) / (2*a);
            return 2;
        }
        else if (isZero(D)) {
            *x1 = -b / (2*a);
            return 1;
        }
        else {
            return 0;
        }
    }
}


int solveLinear (const double a, const double b, double* x) {
    if (isZero(a)) {
        if (isZero(b)) {
            return EQ_INF_SOL;
        }
        return 0;
    }
    else /* if (a != 0) */ {
        *x = -b / a;
        return 1;
    }
}
