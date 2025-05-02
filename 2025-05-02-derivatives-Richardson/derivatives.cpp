#include "derivatives.h"

double forward_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x)) / h;
}
double central_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x - h)) / (2*h);
}

double richardson(double x, double h, fptr f, algptr alg, int alpha)
{
    double aux = std::pow(2.0, alpha);
    double val1 = alg(x, h, f);
    double val2 = alg(x, h/2.0, f);
    return (aux*val2 - val1)/(aux - 1.0);
}