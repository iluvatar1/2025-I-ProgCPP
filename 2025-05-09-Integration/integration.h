#pragma once
#include <functional>

// using fptr = double(double);
using fptr = std::function<double(double)>;

// trapezoid(0.0, 1.0, 10, fun)
double trapezoid(double a, double b, int N, fptr fun);

double simpson(double a, double b, int N, fptr fun);