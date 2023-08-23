#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "sqrio.h"
#include "isZero.h"
#include "eqslv.h"
#include "sqrconst.h"

/**
 *
 * @brief Debug mode, runs tests before launching program using startTests()
 *
 */

#define DEBUG

void printInfo();
void startTests();
void runTest(const int testID, const double a, const double b, const double c,
             const nSolutions ansNSol, const double ansX1, const double ansX2,
             double* const x1, double* const x2);
void printTestError(const int testID,
                    const double a, const double b, const double c,
                    const nSolutions expecNSol, const double expecX1, const double expecX2,
                    const nSolutions realNSol, double* const realX1, double* const realX2);

/**
 *
 * @brief Entry point
 *
 * Execution of the program starts here.
 *
 * @return Program exit status
 *
 */

///--------------------------------------------------------------------------------------------

int main () {

    printInfo();

    #ifdef DEBUG

        printf("Do you want to run tests? [y/n]\n");
        char ans;
        scanf(" %c", &ans);

        if (ans == 'y' or ans == 'Y') startTests();

    #endif

    double a = NAN, b = NAN, c = NAN;

    inputSquareData(&a, &b, &c);


    double x1 = NAN, x2 = NAN;
    nSolutions nRoots = ZERO;

    nRoots = solveSquare(a, b, c, &x1, &x2);

    if (nRoots == TWO) {

        fixNegativeZero(&x1);
        fixNegativeZero(&x2);

    } else if (nRoots == ONE) {

        fixNegativeZero(&x1);

    }

    printSolution(nRoots, &x1, &x2);

    return 0;
}

///--------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void printInfo() {

    printf("# Square equation solver\n"
           "# Made by: Nucc1e4r\n\n");

}

//--------------------------------------------------------------------------------------------------

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
        {-1.6, NAN}
    };

    const nSolutions nAnswers[] = {
        INF, ZERO, ONE, ONE, ONE, TWO, ZERO, TWO, TWO, ONE
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        runTest(i, tests[i][0], tests[i][1], tests[i][2], nAnswers[i], answers[i][0], answers[i][1], &tx1, &tx2);
    }

    printf("All tests ran successfully\n\n");
}

//------------------------------------------------------------------------------------------------------------------

void runTest(const int testID, const double a, const double b, const double c,
                const nSolutions ansNSol, const double ansX1, const double ansX2,
                    double* const x1, double* const x2) {

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

        printTestError(testID, a, b, c, ansNSol, ansX1, ansX2, gotNSol, x1, x2);

    } else printf("Test %d passed\n", testID);
}

//---------------------------------------------------------------------------------------------------

void printTestError(const int testID,
                    const double a, const double b, const double c,
                    const nSolutions expecNSol, const double expecX1, const double expecX2,
                    const nSolutions realNSol, double* const realX1, double* const realX2) {

    printf("Test %d failed!\n", testID);
    printf("Equation: "); printEquation(a, b, c);

    printf("Expected answer:\n\t");
    printSolution(expecNSol, &expecX1, &expecX2);

    printf("Got answer:\n\t");
    printSolution(realNSol, realX1, realX2);
}

//-------------------------------------------------------------------------------------------
