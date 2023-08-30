#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "sqrio.h"
#include "dblequal.h"
#include "eqslv.h"
#include "sqrconst.h"
#include "sqrdbg.h"


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

int main (int argc, char* argv[]) {

    printInfo();

    if (isHelp(argc, argv))
        return 0;

    if (isDebug(argc, argv)) 
        return 0;

    double a = NAN, b = NAN, c = NAN;

    inputSquareData(&a, &b, &c);

    double x1 = NAN, x2 = NAN;
    nSolutions nRoots = ZERO;

    nRoots = solveSquare(a, b, c, &x1, &x2);

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

