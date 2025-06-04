#include <iostream>
#include <vector>
#include <string>
#include "matrix_utils.h"


int main(int argc, char **argv)
{
  const int M = std::stoi(argv[1]);
  const int N = std::stoi(argv[2]);

  std::vector<double> M1(M*N, 0.0);
  std::vector<double> M2(N*(M+1), 0.0);

  fill_matrix(M1, M, N);
  print_matrix(M1, M, N);
  fill_matrix(M2, N, M+1);
  print_matrix(M2, N, M+1);

  std::vector<double> R;
  matmul(M1, M, N, M2, N, M+1, R);
  print_matrix(R, M, M+1);

  return 0;
}

