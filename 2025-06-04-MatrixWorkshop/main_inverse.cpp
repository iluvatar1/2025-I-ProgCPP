#include <iostream>
#include <vector>
#include <string>
#include "matrix_utils.h"


int main(int argc, char **argv)
{
  // const int M = std::stoi(argv[1]);
  int M = 2;

  std::vector<double> M1(M*M, 0.0);
  std::vector<double> M2(M*M, 0.0);
  M1[0*M + 0] = -1;
  M1[0*M + 1] = 1.5;
  M1[1*M + 0] = 1;
  M1[1*M + 1] = -1;

  M2[0*M + 0] = 1.99;
  M2[0*M + 1] = 3;
  M2[1*M + 0] = 2;
  M2[1*M + 1] = 2;

  print_matrix(M1, M, M);
  print_matrix(M2, M, M);

  std::cout << check_inverse(M1, M2, M, 0.1) << "\n";
  std::cout << check_inverse(M2, M1, M, 0.1) << "\n";
  

  return 0;
}

