#include <iostream>
#include <cmath>
#include "integration.h"

double f(double x);

int main(void)
{
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    std::cout << trapezoid(0.0, 1.0, 10, f) << "\n";
    std::cout << trapezoid(0.0, 1.0, 1000, f) << "\n";
    std::cout << trapezoid(0.0, 1.0, 10000000, f) << "\n";

    std::cout << simpson(0.0, 1.0, 10, f) << "\n";

    std::cout << richardson(0.0, 1.0, 10, f, trapezoid, 2) << "\n";

    std::cout << richardson(0.0, 1.0, 10, f, simpson, 4) << "\n";

    return 0;
}

double f(double x)
{
    return std::sin(x*x);
}

