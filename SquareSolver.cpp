#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "sqrio.h"
#include "isZero.h"
#include "eqslv.h"

/**
 *
 * @brief Debug mode, runs tests before launching program using startTests()
 *
 */

#define DEBUG

void startTests();
void runTest(const double a, const double b, const double c, const nSolutions ansNSol, const double ansX1, const double ansX2, double* const x1, double* const x2, const int testID);

/**
 *
 * @brief Entry point
 *
 * Execution of the program starts here.
 *
 * @return Program exit status
 *
 */

//----------------------------------------------------------------------------------

int main () {

    #ifdef DEBUG
        startTests();
    #endif

    printf("# Square equation solver\n"
           "# Made by: Nucc1e4r\n\n");

    printf("ax^2 + bx + c = 0\n\n");

    double a = NAN, b = NAN, c = NAN;

    inputSquareData(&a, &b, &c);


    double x1 = NAN, x2 = NAN;
    nSolutions nRoots = ZERO;

    nRoots = solveSquare(a, b, c, &x1, &x2);


    outputSquareSolution(nRoots, &x1, &x2);

    return 0;
}

//----------------------------------------------------------------------------------

/**
 *
 * @brief Runs some default tests to check if everything works correctly.
 *
 * Can be disabled by deleting "#define DEBUG" from main file.
 *
 * @return Nothing if everything is fine, Error if program works incorrectly.
 *
 */

void startTests() {

    double tx1 = NAN, tx2 = NAN;

    const double tests[][3] = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1},
        {1, -6, 5},
        {1, 5, 6},
        {1, 2, 1}
    };

    const double answers[][2] = {
        {NAN, NAN},
        {NAN, NAN},
        {0, NAN},
        {-1, NAN},
        {0, NAN},
        {0, -1},
        {NAN, NAN},
        {5, 1},
        {-2, -3},
        {-1, NAN}
    };

    const nSolutions nAnswers[] = {
        INF, ZERO, ONE, ONE, ONE, TWO, ZERO, TWO, TWO, ONE
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        runTest(tests[i][0], tests[i][1], tests[i][2], nAnswers[i], answers[i][0], answers[i][1], &tx1, &tx2, i);
    }

    printf("All tests ran successfully\n\n");
}

void runTest(const double a, const double b, const double c,
                const nSolutions ansNSol, const double ansX1, const double ansX2,
                    double* const x1, double* const x2, const int testID) {

    bool err = false;

    nSolutions gotNSol = solveSquare(a, b, c, x1, x2);

    if (gotNSol == ansNSol) {
        switch (ansNSol) {
            case TWO:
                if (not (*x1 == ansX1 and *x2 == ansX2)) err = true;
                break;
            case ONE:
                if (not (*x1 == ansX1)) err = true;
                break;
            case ZERO:
                break;
            case INF:
                break;
            default:
                printf("!NUMBER OF SOLUTIONS INTERPRETATION ERROR!");
        }
    } else err = true;

    if (err) {
        printf("Test %d failed!\n", testID);
        printf("Equation: ");
        if (isZero(a)) {
            if (isZero(b)) printf("%lg = 0\n", c);
            else if (b == 1) printf("x + %lg = 0\n", c);
            else printf("%lgx + %lg = 0\n", b, c);
        } else if (a == 1) {
            if (isZero(b)) printf("x^2 + %lg = 0\n", c);
            else if (b == 1) printf("x^2 + x + %lg = 0\n", c);
            else printf("x^2 + %lgx + %lg = 0\n", b, c);
        } else {
            if (isZero(b)) printf("%lgx^2 + x^2 + %lg = 0\n", a, c);
            else if (b == 1) printf("%lgx^2 + x + %lg = 0\n", a, c);
            else printf("%lgx^2 + %lgx + %lg = 0\n", a, b, c);
        }
        printf("Expected answer:\n");
        switch (ansNSol) {
            case TWO:
                printf("\ttwo roots: x1 = %lg, x2 = %lg\n", ansX1, ansX2);
                break;
            case ONE:
                printf("\tone root: x = %lg\n", ansX1);
                break;
            case ZERO:
                printf("\tno real solutions\n");
                break;
            case INF:
                printf("\tinfinite amount of solutions\n");
                break;
            default:
                printf("!NUMBER OF SOLUTIONS INTERPRETATION ERROR!");
        }
        printf("Got answer:\n");
        switch (gotNSol) {
            case TWO:
                printf("\ttwo roots: x1 = %lg, x2 = %lg\n", *x1, *x2);
                break;
            case ONE:
                printf("\tone root: x = %lg\n", *x1);
                break;
            case ZERO:
                printf("\tno real solutions\n");
                break;
            case INF:
                printf("\tinfinite amount of solutions\n");
                break;
            default:
                printf("!NUMBER OF SOLUTIONS INTERPRETATION ERROR!");
        }

    } else printf("Test %d passed\n", testID);
}

