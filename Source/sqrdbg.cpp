#include <stdio.h>
#include <math.h>
#include <string.h>
#include "sqrio.h"
#include "eqslv.h"
#include "sqrdbg.h"
#include "sqrconst.h"

//-------------------------------------------------------------------------------------------------------------------------------------

void getTestFromFile(FILE* inputFile, TestData* test) {

    int nRoots = NAN;

    fscanf(inputFile, "%d %lg %lg %lg %lg %lg %d\n", &test -> testID, &test -> coeffs.a, &test -> coeffs.b, &test -> coeffs.c,
                                                                &test -> roots.x1, &test -> roots.x2, &nRoots);
    test -> nRoots = (nSolutions)nRoots;

}

//---------------------------------------------------------------------------------------------------------------------

void startTests(const TestData tests[], const int testAmount) {

    double tx1 = NAN, tx2 = NAN;

    for (int i = 0; i < testAmount; i++) {

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

//-----------------------------------------------------------------------------------------------------------------

void printTestError(const TestData* expecData,
                    const nSolutions realNSol, double* const realX1, double* const realX2) {

    printf(textFormat_error "Test %d failed!\n" textFormat_default, expecData->testID);
    printf(textFormat_cursive_underline "Equation:" textFormat_default " "); printEquation(expecData->coeffs.a,
                                                                                            expecData->coeffs.b,
                                                                                            expecData->coeffs.c);

    printf(textFormat_cursive_underline "Expected answer:\n\t" textFormat_default);
    printSolution(expecData->nRoots, expecData->roots.x1, expecData->roots.x2);

    printf(textFormat_cursive_underline "Got answer:\n\t" textFormat_default);
    printSolution(realNSol, *realX1, *realX2);
}

//------------------------------------------------------------------------------------------------------------------------

void debug(int argc, char* argv[]) {

    bool debug = false, testsFromFile = false;

    if (argc > 1) {

        int fileNamePos = NAN;

        for (int i = 1; i < argc; i++) {

            if (not strcmp("-t", argv[i])) {

                debug = true;

            }

            else if (not strcmp("-f", argv[i])) {

                testsFromFile = true;
                fileNamePos = i + 1;

            }

        }

        if (debug) {


            FILE* inpF;
            int testAmount = NAN;

            if (testsFromFile) {

                inpF = fopen(argv[fileNamePos], "r");

            }

            else {

                inpF = fopen(defaultTestFileName, "r");

            }

            fscanf(inpF, "%d", &testAmount);

            TestData tests[testAmount];

            for (int i = 0; i < testAmount; i++) {

                getTestFromFile(inpF, &tests[i]);

            }

            fclose(inpF);

            startTests(tests, testAmount);

        }

    }

}

//------------------------------------------------------------------------------------------------------------------------
