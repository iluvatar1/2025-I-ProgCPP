#include "derivatives.h"

double forward_diff(double x, double h) {
    return (f(x + h) - f(x)) / h;
}
double central_diff(double x, double h) {
    return (f(x + h) - f(x - h)) / (2*h);
}
