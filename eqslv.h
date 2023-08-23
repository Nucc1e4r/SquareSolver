#ifndef H_EQSLV
#define H_EQSLV

/**
 *
 * @brief Solves a square equation (ax^2 + bx + c = 0) by computing discriminant and writing answers to memory cells.
 *
 * If equation is linear (a == 0), calls solveLinear()
 *
 * @param a coefficient a (ax^2)
 * @param b coefficient b (bx)
 * @param c coefficient c (c)
 * @param x1 Pointer to memory cell for first solution
 * @param x2 Pointer to memory cell for second solution
 *
 * @return Amount of solutions
 *
 */

nSolutions solveSquare (const double a, const double b, const double c, double* x1, double* x2);

/**
 *
 * @brief Solves a linear equation (ax + b = 0) and writes answer to memory cell.
 *
 * @param a coefficient a (ax)
 * @param b coefficient b (b)
 * @param x Pointer to memory cell for solution (receives x1 if is called from solveSquare())
 *
 * @return Amount of solutions
 *
 */

nSolutions solveLinear (const double a, const double b, double* x);

void fixNegativeZero(double* const x);

#endif
