#include <iostream>
#include <cmath>

#include "prime_utils.h"

// declaration
void test(void);

int main(void){

    for(int ii = 2; ii <= 150; ++ii) {
        if (isprime(ii) == true) {
            std::cout << ii << "\n";    
        }
    }

    return 0;
}


void test(void){
    //std::cout << 1 << ": " << isprime(1) << "\n";
    std::cout << 2 << ": " << isprime(2) << "\n";
    std::cout << 15 << ": " << isprime(15) << "\n";
    std::cout << 10000000019 << ": " << isprime(10000000019) << "\n";
    std::cout << 1000000007 << ": " << isprime(1000000007) << "\n";
}
