#include <iostream>
#include <valarray>
#include <cmath>
#include "ivp_solver.h"

const double R = 3.5;

typedef std::valarray<double> state_t; // alias for state type

void initial_conditions(state_t & y);
void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);

int main(int argc, char **argv)
{
    int N = 1;
    state_t y(N);
    initial_conditions(y);
    integrate_euler(fderiv, y, 0.0, 10.0, 0.01, print);
    return 0;
}

void initial_conditions(state_t & y)
{
  y[0] = 0.5;
}

void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << std::endl;
}

void fderiv(const state_t & y, state_t & dydt, double t)
{
    dydt[0] = R*y[0]*(1-y[0]);
}