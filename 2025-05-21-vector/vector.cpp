#include <vector>
#include <iostream>
#include <string>

int main(int argc , char **argv)
{
    // declare the vector
    std::vector<double> data; 

    // read the size from the command line
    const int N = std::stoi(argv[1]); 

    // resize the vector
    data.resize(N, 0);

    // initialize the data
    for(int ii = 0; ii < N; ii++) {
        data[ii] = ii;
    }

    // compute the average
    double suma = 0.0;
    for(int ii = 0; ii < N; ii++) {
        suma = suma + data[ii];
    }
    std::cout << suma/N << "\n";

    return 0;
}