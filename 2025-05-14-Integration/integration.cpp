#include "integration.h"

double trapezoid(double a, double b, int N, fptr fun)
{
    double Deltax = (b-a)/N;
    double suma = 0.0;
    for(int k = 1; k <= N-1; k++) {
    //for(int k = N-1; k >= 1; k--) {
        double xk = a + k*Deltax;
        suma = suma + fun(xk);
    } 
    double result = Deltax*(0.5*fun(a) + suma + 0.5*fun(b));
    return result;
}

double simpson(double a, double b, int N, fptr fun)
{
    // N must be even
	if (N % 2 != 0) {
		N++;
	}
	double Deltax = (b-a)/N;
	double suma1 = 0.0;
    for(int k = 1; k <= N/2; k++) {
		double xk = a + (2*k - 1)*Deltax;
		suma1 += fun(xk);
	}
	double suma2 = 0.0;
    for(int k = 1; k <= N/2 - 1; k++) {
		double xk = a + (2*k)*Deltax;
		suma2 += fun(xk);
	}
	double result = Deltax*(fun(a) + 4*suma1 + 2*suma2 + fun(b))/3.0;

	return result;
}

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha)
{
    double aux = std::pow(2.0, alpha);
    double val1 = alg(a, b, N, f);
    double val2 = alg(a, b, 2*N, f);
    return (aux*val2 - val1)/(aux - 1.0);
}

double gauss2(double a, double b, fptr fun)
{
    // define point coordinates
    double x0 = -1.0/std::sqrt(3.0);
    double x1 = +1.0/std::sqrt(3.0);
    
    //define weigths
    double w0 = 1.0;
    double w1 = 1.0;
    
    // compute integral
    double result = w0*fun(x0) + w1*fun(x1);
    return result;
}
