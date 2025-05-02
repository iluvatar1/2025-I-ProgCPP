#pragma once
#include <cmath>
#include <functional>

using fptr = std::function<double(double)>;

double forward_diff(double x, double h, fptr f);
double central_diff(double x, double h, fptr f);

using algptr = std::function<double(double, double, fptr)>;

double richardson(double x, double h, fptr f, algptr alg, int alpha);