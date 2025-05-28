#include <iostream>
#include <vector>
#include <cmath>


void deriv(const std::vector<double> & p, std::vector<double> & dp);
double eval(const std::vector<double> & p, double x);

int main(void){

    std::vector<double> data = {1,3,4.5};
    std::vector<double> ddata;
    deriv(data, ddata);
    for(auto x : ddata) { std::cout << x << " ";}
    std::cout << "\n";

    std::cout << eval(data, 3.0) << "\n";
    std::cout << eval(ddata, 3.0) << "\n";

    return 0;
}

void deriv(const std::vector<double> & p, std::vector<double> & dp)
{
    // tamaños de dp y de p
    // dp debe ser p.size() -1 
    dp.resize(p.size() - 1);

    // llenarlo
    //dp[0] = p[1]*1; // d(p[1]*x^1) = 1*p[1]*x^0
    //dp[1] = p[2]*2; // d(p[2]*x^2) = 2*p[2]*x^1
    //dp[i] = p[i+1]*(i+1);
    for (int ii = 0; ii < dp.size(); ii++) {
        dp[ii] = p[ii+1] * (ii+1);
    }
}

double eval(const std::vector<double> & p, double x)
{
    double result =  0.0;
    for (int ii = 0; ii < p.size(); ii++) {
        result += p[ii] * std::pow(x, ii);
    }
    return result;
}