#include <iostream>
#include <cmath>
#include <string>

#include "prime_utils.h"

long largest_prime_factor(long n);
 
int main(int argc, char **argv){

    // ./a.out 10 -> argc = 2, argv = ["./a.out", "10"]

    long N = std::stol(argv[1]);

    std::cout << largest_prime_factor(N) << "\n";

    return 0;
}

long largest_prime_factor(long n)
{
    // barrer por los divisores, y si es primo, imprimir
}
