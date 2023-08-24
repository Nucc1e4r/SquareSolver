#ifndef H_SQRIO
#define H_SQRIO


/**
 *
 * @brief Type for counting amount of equation solutions, used in solveSquare() and solveLinear()
 *
 */

enum nSolutions {

/** No solutions */
    ZERO = 0,

/** One solution */
    ONE = 1,

/** Two solutions */
    TWO = 2,

/** Any real number is a solution */
    INF = -1

};


/**
 *
 * @brief Inputs values a, b, c from keyboard (for ax^2 + bx + c = 0)
 *
 * @param a Pointer to memory cell for variable a
 * @param b Pointer to memory cell for variable b
 * @param c Pointer to memory cell for variable c
 *
 * @return Nothing
 *
 */

void inputSquareData (double* a, double* b, double* c);


/**
 *
 * @brief Outputs final solution(s) to the equation
 *
 * @param nRoots Number of solutions received from solveSquare()
 * @param x1 First solution
 * @param x2 Second solution
 *
 * @return Nothing
 *
 */

void printSolution(const nSolutions nRoots, const double x1, const double x2);


/**
 *
 * @brief Outputs the equation ("c = 0" if a == b == 0, "bx + c = 0" if a == 0, "ax^2 + bx + c = 0" otherwise)
 *
 * @param a, b, c Coefficients
 *
 * @return Nothing
 *
 */

void printEquation(const double a, const double b, const double c);

#endif
