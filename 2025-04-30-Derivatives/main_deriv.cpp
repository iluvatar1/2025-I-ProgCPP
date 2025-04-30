#include <iostream>
#include "derivatives.h"

//double f(double x);

int main(int argc, char **argv) {
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    double x = 1.2345;
    double h = 1.0e-19;

    double forward_result = forward_diff(x, h);
    double central_result = central_diff(x, h);

    std::cout << "Forward Difference: " << forward_result << std::endl;
    std::cout << "Central Difference: " << central_result << std::endl;
    std::cout << "Exact Difference  : " << 2*x*std::cos(x*x) << std::endl;

    return 0;
}

double f(double x)
{
   return std::sin(x*x); // 2xcos(x^2) 
}
