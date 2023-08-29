#include <math.h>
#include <assert.h>
#include "isZero.h"
#include "sqrconst.h"

bool isZero (double x) {

    assert(isfinite(x));

    if (fabs(x) < eps) {
        return true;
    }
    return false;
}
