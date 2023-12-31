#ifndef H_EQSLV
#define H_EQSLV


/**
 *
 * @brief Solves a square equation (ax^2 + bx + c = 0) by computing discriminant and writing answers to memory cells.
 *
 * If equation is linear (a == 0), calls solveLinear()
 *
 * @param a, b, c coefficients
 * @param x1, x2 Pointers to memory cells for solutions
 *
 * @return Amount of solutions
 *
 */

nSolutions solveSquare (const double a, const double b, const double c, double* x1, double* x2);


/**
 *
 * @brief Solves a linear equation (ax + b = 0) and writes answer to memory cell.
 *
 * @param a, b coefficients
 * @param x Pointer to memory cell for solution (receives x1 if is called from solveSquare())
 *
 * @return Amount of solutions
 *
 */

nSolutions solveLinear (const double a, const double b, double* x);

#endif
