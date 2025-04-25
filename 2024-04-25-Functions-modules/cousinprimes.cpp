#include <iostream>
#include <cmath>

#include "prime_utils.h"

int main(void){

    for(int ii = 300; ii <= 400-4; ++ii) {
        if (isprime(ii) == true and isprime(ii+4) == true) {
            std::cout << "(" << ii << ", " << ii+4 << ") ";
        }
    }
    std::cout << "\n";

    return 0;
}

