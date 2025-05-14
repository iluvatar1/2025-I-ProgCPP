#pragma once
#include <functional>
#include <cmath>

// using fptr = double(double);
using fptr = std::function<double(double)>;

// trapezoid(0.0, 1.0, 10, fun)
double trapezoid(double a, double b, int N, fptr fun);

double simpson(double a, double b, int N, fptr fun);

using algptr = std::function<double(double, double, int, fptr)>;

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha);

double gauss2(double a, double b, fptr fun);
double gauss3(double a, double b, fptr fun);
