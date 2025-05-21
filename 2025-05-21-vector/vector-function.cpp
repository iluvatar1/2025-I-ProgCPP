#include <vector>
#include <iostream>
#include <string>

double average(const std::vector<double> & x);

int main(int argc , char **argv)
{
    // declare the vector
    std::vector<double> data; 

    // read the size from the command line
    const int N = std::stoi(argv[1]); 

    // resize the vector
    std::cout << "Pidiendo memoria ...\n";
    data.resize(N, 0);

    // initialize the data
    std::cout << "Iniciando datos ...\n";
    for(int ii = 0; ii < N; ii++) {
        data[ii] = ii;
    }

    // compute the average
    std::cout << "Calculando promedio ...\n";
    double avg = average(data);
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << avg << "\n";

    return 0;
}

double average(const std::vector<double> & x)
{
    double suma = 0.0;
    for(int ii = 0; ii < x.size(); ii++) {
        suma = suma + x[ii];
    }
    return suma/x.size();
}