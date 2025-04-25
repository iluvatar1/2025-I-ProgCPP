#include <iostream>
#include <cmath>
#include <string>

// declaration
bool isprime(long n);
void test(void);

int main(int argc, char **argv){

    // ./a.out -> argc = 1, argv = ["./a.out"]
    // ./a.out 10 -> argc = 2, argv = ["./a.out", "10"]
    // ./a.out 10 0.55 -> argc = 3, argv = ["./a.out", "10", "0.55"]
    // ./a.out 300 400 -> argc = 3, argv = ["./a.out", "300", "400"]

    int vmin = std::stoi(argv[1]);
    int vmax = std::stoi(argv[2]);

    for(int ii = vmin; ii <= vmax-4; ++ii) {
        if (isprime(ii) == true and isprime(ii+4) == true) {
            std::cout << "(" << ii << ", " << ii+4 << ") ";
        }
    }
    std::cout << "\n";

    return 0;
}

// implementation
bool isprime(long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }

    // suppose it is prime
    bool flag = true; 

    if (n == 2) {
        return true;
    }

    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }

    return flag;
}

void test(void){
    //std::cout << 1 << ": " << isprime(1) << "\n";
    std::cout << 2 << ": " << isprime(2) << "\n";
    std::cout << 15 << ": " << isprime(15) << "\n";
    std::cout << 10000000019 << ": " << isprime(10000000019) << "\n";
    std::cout << 1000000007 << ": " << isprime(1000000007) << "\n";
}
