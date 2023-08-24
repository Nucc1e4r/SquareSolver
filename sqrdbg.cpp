#include <stdio.h>
#include <math.h>
#include "sqrio.h"
#include "eqslv.h"
#include "sqrdbg.h"
#include "sqrconst.h"

//---------------------------------------------------------------------------------------------------------------------

const TestData tests[] = {

        {.testID = 0, .coeffs = { .a = 0,  .b = 0,  .c = 0 }, .roots = { .x1 = NAN,  .x2 = NAN }, .nRoots = INF},

        {.testID = 1, .coeffs = { .a = 0,  .b = 0,  .c = 1 }, .roots = { .x1 = NAN,  .x2 = NAN }, .nRoots = ZERO},

        {.testID = 2, .coeffs = { .a = 0,  .b = 1,  .c = 0 }, .roots = { .x1 = 0,    .x2 = NAN }, .nRoots = ONE},

        {.testID = 3, .coeffs = { .a = 0,  .b = 1,  .c = 1 }, .roots = { .x1 = -1,   .x2 = NAN }, .nRoots = ONE},

        {.testID = 4, .coeffs = { .a = 1,  .b = 0,  .c = 0 }, .roots = { .x1 = 0,    .x2 = NAN }, .nRoots = ONE},

        {.testID = 5, .coeffs = { .a = 1,  .b = 1,  .c = 0 }, .roots = { .x1 = 0,    .x2 = -1  }, .nRoots = TWO},

        {.testID = 6, .coeffs = { .a = 1,  .b = 1,  .c = 1 }, .roots = { .x1 = NAN,  .x2 = NAN }, .nRoots = ZERO},

        {.testID = 7, .coeffs = { .a = 1,  .b = -6, .c = 5 }, .roots = { .x1 = 5,    .x2 = 1   }, .nRoots = TWO},

        {.testID = 8, .coeffs = { .a = 1,  .b = 5,  .c = 6 }, .roots = { .x1 = -2,   .x2 = -3  }, .nRoots = TWO},

        {.testID = 9, .coeffs = { .a = 1,  .b = 2,  .c = 1 }, .roots = { .x1 = -1,   .x2 = NAN }, .nRoots = ONE},

    };

//---------------------------------------------------------------------------------------------------------------------

void startTests() {

    double tx1 = NAN, tx2 = NAN;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {

        runTest(&tests[i], &tx1, &tx2);

    }

    printf(textFormat_cursive "All tests ran successfully\n\n" textFormat_default);
}

//------------------------------------------------------------------------------------------------------------------

void runTest(const TestData* data,
                    double* const x1, double* const x2) {

    bool err = false;

    nSolutions gotNRoots = solveSquare(data->coeffs.a, data->coeffs.b, data->coeffs.c, x1, x2);

    if (gotNRoots == data->nRoots) {

        switch (data->nRoots) {

            case TWO:

                if (not (*x1 == data->roots.x1 and *x2 == data->roots.x2)) err = true;
                break;


            case ONE:

                if (not (*x1 == data->roots.x1)) err = true;
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

        printTestError(data, gotNRoots, x1, x2);

    } else printf(textFormat_success "Test %d passed\n" textFormat_default, data->testID);
}

//---------------------------------------------------------------------------------------------------

void printTestError(const TestData* expecData,
                    const nSolutions realNSol, double* const realX1, double* const realX2) {

    printf(textFormat_error "Test %d failed!\n" textFormat_default, expecData->testID);
    printf(textFormat_cursive_underline "Equation:" textFormat_default " "); printEquation(expecData->coeffs.a, expecData->coeffs.b, expecData->coeffs.c);

    printf(textFormat_cursive_underline "Expected answer:\n\t" textFormat_default);
    printSolution(expecData->nRoots, expecData->roots.x1, expecData->roots.x2);

    printf(textFormat_cursive_underline "Got answer:\n\t" textFormat_default);
    printSolution(realNSol, *realX1, *realX2);
}

//-------------------------------------------------------------------------------------------
