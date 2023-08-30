#include <math.h>
#include <assert.h>
#include "dblequal.h"
#include "sqrconst.h"

bool doubleEqual (double x, double y) {

    assert(isfinite(x));
    assert(isfinite(y));

    if (fabs(x - y) < eps) {
        return true;
    }
    return false;
}
