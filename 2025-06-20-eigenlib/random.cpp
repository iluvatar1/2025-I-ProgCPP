#include <iostream>
#include <eigen3/Eigen/Dense>
#include <string>

int main(int argc, char* argv[])
{
    // Check if the user provided matrix size
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <seed> <matrix_size>" << std::endl;
        return 1;
    }

    // Get matrix size N from command line argument
    const int N = std::stoi(argv[2]);
    srand(std::stoi(argv[1]));

    // Initialize Eigen matrix and vector with random values
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(N, N);  // NxN matrix with random values
    Eigen::VectorXd b = Eigen::VectorXd::Random(N);     // N-length vector with random values

    //std::cout << "Matrix A (" << N << "x" << N << "):\n" << A << std::endl;
    //std::cout << "Vector b (" << N << "):\n" << b << std::endl;

    // Solve the system Ax = b using Householder QR decomposition
    //Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
    Eigen::VectorXd x = A.partialPivLu().solve(b);

    //std::cout << "The solution vector x is:\n" << x << std::endl;
    
    // Output the residual norm (A * x - b)
    std::cout << "Residual norm: " << (A * x - b).norm() << std::endl;

    return 0;
}
