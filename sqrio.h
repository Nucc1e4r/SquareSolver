#ifndef H_SQRIO
#define H_SQRIO

/**
 *
 * @brief Type for counting amount of equation solutions, used in solveSquare() and solveLinear()
 *
 */

enum nSolutions {   //  CamelCaseNaming structures classes enums with capital letter
                   //
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
 * @param x1 Pointer to memory cell for first solution
 * @param x2 Pointer to memory cell for second solution
 *
 * @return Nothing
 *
 */

void outputSquareSolution (nSolutions nRoots, double* x1, double* x2);

#endif
