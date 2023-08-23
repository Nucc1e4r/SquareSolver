#include <math.h>
#include <assert.h>
#include "isZero.h"
#include "sqrio.h"
#include "eqslv.h"

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

nSolutions solveSquare (const double a, const double b, const double c, double* x1, double* x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != 0);
    assert(x2 != 0);
    assert(x1 != x2);

    if (isZero(a)) {
        return solveLinear(b, c, x1);
    }
    else /* if (a != 0) */ {
        double D = b*b - 4*a*c;
        double sqrtD = sqrt(D);
        if (D > 0) {
            *x1 = (-b + sqrtD) / (2*a);
            *x2 = (-b - sqrtD) / (2*a);
            return TWO;
        }
        else if (isZero(D)) {
            *x1 = -b / (2*a);
            return ONE;
        }
        else {
            return ZERO;
        }
    }
}

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

nSolutions solveLinear (const double a, const double b, double* x) {

    assert(x != 0);

    assert(isfinite(a));
    assert(isfinite(b));

    if (isZero(a)) {
        if (isZero(b)) {
            return INF;
        }
        return ZERO;
    }
    else /* if (a != 0) */ {
        *x = -b / a;
        return ONE;
    }
}
