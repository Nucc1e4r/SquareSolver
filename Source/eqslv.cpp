#include <math.h>
#include <assert.h>
#include "isZero.h"
#include "sqrio.h"
#include "eqslv.h"
#include "sqrconst.h"

//-----------------------------------------------------------------------------------------------------------

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

            fixNegativeZero(x1);
            fixNegativeZero(x2);

            return TWO;

        }

        else if (isZero(D)) {

            *x1 = -b / (2*a);

            fixNegativeZero(x1);

            return ONE;

        }

        else return ZERO;
    }
}

//-------------------------------------------------------------------------------------------------------------

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

        fixNegativeZero(x);

        return ONE;

    }
}

//------------------------------------------------------------------------------------------------------

void fixNegativeZero(double* const x) {

    if (isZero(*x)) *x = 0;

}

//------------------------------------------------------------------------------------------
