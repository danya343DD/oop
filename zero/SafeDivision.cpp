#include "SafeDivision.h"
#include "ZeroExcept.h"

using namespace std;

double SafeDivision::divide(double a, double b) {
    if (b == 0) {
        throw ZeroExcept();
    }
    return a / b;
}
