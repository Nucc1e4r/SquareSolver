#include <math.h>
#include <assert.h>
#include "dblequal.h"
#include "sqrio.h"
#include "eqslv.h"
#include "sqrconst.h"

/**
 *
 * @brief Sets value of x to 0 if x == -0
 *
 * @param x Pointer to memory cell for x
 *
 * @return Nothing
 *
 */

static void fixNegativeZero(double* const x);

//-----------------------------------------------------------------------------------------------------------

nSolutions solveSquare (const double a, const double b, const double c, double* x1, double* x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    if (doubleEqual(a, 0)) {
        return solveLinear(b, c, x1);
    }

    double D = b*b - 4*a*c;

    if (doubleEqual(D, 0)) {

        *x1 = -b / (2*a);
        fixNegativeZero(x1);
        return ONE;

    } else if (D > eps) {
        
        double sqrtD = sqrt(D);
        *x1 = (-b + sqrtD) / (2*a);
        *x2 = (-b - sqrtD) / (2*a);

        fixNegativeZero(x1);
        fixNegativeZero(x2);

        return TWO;
    }
    return ZERO;
}

//-------------------------------------------------------------------------------------------------------------

nSolutions solveLinear (const double a, const double b, double* x) {

    assert(x != 0);

    assert(isfinite(a));
    assert(isfinite(b));

    if (doubleEqual(a, 0)) {

        if (doubleEqual(b, 0)) {
            return INF;
        }

        return ZERO;

    } else /* if (a != 0) */ {

        *x = -b / a;
        fixNegativeZero(x);
        return ONE;
    }
}

//------------------------------------------------------------------------------------------------------

static void fixNegativeZero(double* const x) {

    if (doubleEqual(*x, 0)) *x = 0;

}

//------------------------------------------------------------------------------------------------
