#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "sqrio.h"
#include "isZero.h"
#include "eqslv.h"
#include "sqrconst.h"
#include "sqrdbg.h"


/**
 *
 * @brief Debug mode, runs tests before launching program using startTests()
 *
 */

#define DEBUG


/**
 *
 * @brief Outputs basic information about the program and the creator
 *
 */

void printInfo();



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

    printSolution(nRoots, x1, x2);

    return 0;
}

///--------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void printInfo() {

    printf("# Square equation solver\n"
           "# Made by: Nucc1e4r\n\n");

}

//--------------------------------------------------------------------------------------------------

