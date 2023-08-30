#ifndef H_SQRDBG
#define H_SQRDBG

#define defaultTestAmount 10
#define defaultTestFileName "Tests/defaultTests.txt"

struct Coeffs {
    double a, b, c;
};

struct Roots {
    double x1, x2;
    nSolutions nRoots;
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
};


/**
 *
 * @brief Runs given tests to check if program works correctly
 *
 * @param tests Array of given tests
 * @param testAmount Amount of given tests
 *
 * @return Nothing
 *
 */

void startTests(const TestData tests[], const int testAmount);


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


/**
 *
 * @brief Reads one test line from file
 *
 * @param inputFile file to read test from. Should be opened before calling the function.
 * @param test Pointer to memory cell to write test data to.
 *
 * @return Nothing
 *
 */

void getTestFromFile(FILE* inputFile, TestData* test);


/**
 *
 * @brief Starts debug mode if -t was in launch flags. Reads tests from file "defaultTestFileName". Can read tests from another file with "-f *filename*" in launch flags
 *
 * @param argc, argv amount and array of launch flags
 *
 * @return true if debug was started, false otherwise
 *
 */

bool isDebug(int argc, char* argv[]);


/**
 *
 * @brief Uses printHelp() if --help was in launch flags
 *
 * @param argc, argv amount and array of launch flags
 *
 * @return true if help was shown, false otherwise
 *
 */

bool isHelp(int argc, char* argv[]);


/**
 *
 * @brief Prints help information about using the program.
 *
 * @return nothing
 *
 */

void printHelp();

#endif
