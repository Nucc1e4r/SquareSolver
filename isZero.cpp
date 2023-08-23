#include <math.h>
#include <assert.h>
#include "isZero.h"
#include "sqrconst.h"

/**
 *
 * @brief Checks if double value is equal to 0
 *
 * @param x Value
 *
 * @return true if x is 0, false otherwise
 *
 */

bool isZero (double x) {

    assert(isfinite(x));

    if (fabs(x) < eps) {
        return true;
    }
    return false;
}