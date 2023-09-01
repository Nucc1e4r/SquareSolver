#include <stdio.h>
#include <math.h>
#include <string.h>
#include "sqrio.h"
#include "eqslv.h"
#include "sqrdbg.h"
#include "sqrconst.h"
#include "dblequal.h"

/**
 *
 * @brief Prints help information about using the program.
 *
 * @return nothing
 *
 */
static void printHelp();

//-------------------------------------------------------------------------------------------------------------------------------------

void getTestFromFile(FILE* inputFile, TestData* test) {

    int nRoots = 0;
                                                                    //check format
    fscanf(inputFile, "%d %lg %lg %lg %lg %lg %d\n", 
           &test->testID, &test->coeffs.a, 
           &test->coeffs.b, &test->coeffs.c,
           &test->roots.x1, &test->roots.x2, &nRoots);
    test->roots.nRoots = (nSolutions)nRoots;
}

//---------------------------------------------------------------------------------------------------------------------

void startTests(const TestData tests[], const int testAmount) { //count testAmount automatically

    double tx1 = NAN, tx2 = NAN;

    for (int i = 0; i < testAmount; i++) {
        runTest(&tests[i], &tx1, &tx2);
    }

    printf(textFormat_cursive "All tests ran successfully\n\n" textFormat_default);
}

//------------------------------------------------------------------------------------------------------------------

void runTest(const TestData* data, double* const x1, double* const x2) {

    bool err = false;

    nSolutions gotNRoots = solveSquare(data->coeffs.a, data->coeffs.b, data->coeffs.c, x1, x2);

    if (gotNRoots == data->roots.nRoots) {
        switch (data->roots.nRoots) {
            case TWO:
                if (!(doubleEqual(*x1, data->roots.x1) && doubleEqual(*x2, data->roots.x2))) {
                    err = true;
                }
                break;

            case ONE:
                if (!(doubleEqual(*x1, data->roots.x1))) {
                    err = true;
                }
                break;

            case ZERO:
            case INF:
                break;

            default:
                printf("!NUMBER OF SOLUTIONS INTERPRETATION ERROR!");
        }
    } else {
        err = true;
    }

    if (err) {
        printTestError(data, gotNRoots, x1, x2);
    } else {
        printf(textFormat_success "Test %d passed\n" textFormat_default, data->testID);
    }
}

//-----------------------------------------------------------------------------------------------------------------

void printTestError(const TestData* expecData, const nSolutions realNSol, double* const realX1, double* const realX2) {

    printf(textFormat_error "Test %d failed!\n" textFormat_default, expecData->testID);

    printf(textFormat_cursive_underline "Equation:" textFormat_default " "); 
    printEquation(expecData->coeffs.a, expecData->coeffs.b, expecData->coeffs.c);

    printf(textFormat_cursive_underline "Expected answer:\n\t" textFormat_default);
    printSolution(expecData->roots.nRoots, expecData->roots.x1, expecData->roots.x2);

    printf(textFormat_cursive_underline "Got answer:\n\t" textFormat_default);
    printSolution(realNSol, *realX1, *realX2);
}

//------------------------------------------------------------------------------------------------------------------------

bool isDebug(int argc, char* argv[]) {

    bool isDebug = false, testsFromFile = false;

    if (argc > 1) {// -l, -s

        int fileNamePos = 0;

        for (int i = 1; i < argc; i++) {
            if (!strcmp("-t", argv[i])) { 
                isDebug = true;
            }
            else if (!strcmp("-f", argv[i])) {
                testsFromFile = true;
                fileNamePos = i + 1;
            }
        }

        if (isDebug) {

            FILE* inpF = nullptr;
            int testAmount = 0;

            if (testsFromFile) {
                inpF = fopen(argv[fileNamePos], "r");//check if exists
            } else {
                inpF = fopen(defaultTestFileName, "r");
            }
            //check if file exists

            if (fscanf(inpF, "%d", &testAmount) == 1) {
                TestData tests[maxTestAmount] = {};

                for (int i = 0; i < testAmount; i++) {
                    getTestFromFile(inpF, &tests[i]);
                }

                fclose(inpF);

                startTests(tests, testAmount);
            } else {
                printf(textFormat_error "!ERROR: CANNOT READ AMOUNT OF TESTS FROM FILE!\n" textFormat_default); //?
            }
        }

    }

    return isDebug;
}

//------------------------------------------------------------------------------------------------------------------------

bool isHelp(int argc, char* argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (!strcmp("--help", argv[i])) { 

                printHelp();
                return true;
            }
        }  
    }
    return false;
}

//------------------------------------------------------------------------------------------

static void printHelp() {
    printf("Usage: main [options]\n"
            "Options:\n"
                "\t-t\t\t\tStart tests\n"
                "\t-t -f *filename*\tStart custom tests from file *filename*\n"
                "\t--help\t\t\tDisplay help\n");
}