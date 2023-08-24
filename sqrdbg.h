#ifndef H_SQRDBG
#define H_SQRDBG

struct Coeffs {

    double a, b, c;

};

struct Roots {

    double x1, x2;

};


/**
 *
 * @brief Contains all information about one equation for test (test ID, coefficients, solutions)
 *
 */

struct TestData {

    int testID;
    Coeffs coeffs;
    Roots roots;
    nSolutions nRoots;

};


/**
 *
 * @brief Runs some default tests to check if everything works correctly.
 *
 * Can be disabled by deleting "#define DEBUG" from main file.
 *
 * @return Nothing
 *
 */

void startTests();


/**
 *
 * @brief Runs one test with given parameters.
 *
 * If test is passed, prints "Test X passed", else calls printTestError()
 *
 * @param data TestData with all information about equation
 * @param x1, x2 Pointers to variables for test results
 *
 * @return Nothing
 *
 */

void runTest(const TestData* data,
             double* const x1, double* const x2);


/**
 *
 * @brief Outputs detailed information about failed test. Uses printEquation()
 *
 * @param expecData info about equation with expected solutions
 * @param realNSol Got amount of solutions
 * @param realX1, realX2 Pointers to got answers
 *
 * @return Nothing
 *
 */

void printTestError(const TestData* expecData,
                    const nSolutions realNSol, double* const realX1, double* const realX2);


#endif
