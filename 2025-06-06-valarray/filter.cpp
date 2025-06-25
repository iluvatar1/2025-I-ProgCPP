#include <string>
#include <iostream>
#include <valarray>
#include <iomanip>
#include <numeric>

void print(std::string msg, const std::valarray<double>& v)
{
    std::cout << msg << " ";
    for (auto n: v) { std::cout << " " << n; }
    std::cout << '\n';
}

int main()
{
    const int N = 1000;
    std::valarray<double> x(N);

    // init with N points in between [0, 2pi)
    // fill with 0 1 2 3 ... N-1
    // multiply by (xmax-xmin)/N
    std::iota(std::begin(x), std::end(x), 0.0);
    print("iota applied: ", x);
    x = x*(2.0*M_PI/N); 
    print("multiplied: ", x);

    std::valarray<double> y = std::sin(x);
    print("sin: ", y);

    std::valarray<double> filtered = x[std::abs(std::sin(x)) < 0.5];
    print("filter: ", filtered);

    return 0;
}