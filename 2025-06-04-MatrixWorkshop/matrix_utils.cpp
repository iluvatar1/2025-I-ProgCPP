#include "matrix_utils.h"

void fill_matrix(std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = ii*n+jj; // A_(i, j) = i*n + j = id
    }
  }
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
  // TODO
   for (int ii = 0; ii < m; ++ii) {
     for (int jj = 0; jj < n; ++jj) {
       dataout[jj*m + ii] = datain[ii*n + jj];
     }
   }
}

void matmul(const std::vector<double> & A, int mA, int nA, 
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C)
{
  if (nA != mB) {
    std::cerr << "ERROR: nA == mB\n";
    return; 
  }
  // resize result matrix
  int mC = mA;
  int nC = nB;
  C.resize(mC*nC, 0.0);

  // llenar C
  for (int ii = 0; ii < mC; ii++){
    for (int jj = 0; jj < nC; jj++) {
      C[ii*nC + jj] = 0.0;
      for (int kk = 0; kk < nA; kk++) {
        C[ii*nC + jj] += A[ii*nA + kk]*B[kk*nB + jj];
      }
    }   
  }
}

bool check_inverse(const std::vector<double> & A,  
                   const std::vector<double> & B, 
                   int m, 
                   double eps) {

  // multiply matrices
  std::vector<double> r;
  matmul(A, m, m, B, m, m, r);

  // matriz resta?
  for (int ii = 0; ii < m; ii++){
    for (int jj = 0; jj < m; jj++) {
      int identidad = 0.0;
      if (ii == jj) identidad = 1.0;
      r[ii*m + jj] = r[ii*m + jj] - identidad;
    }
  }

  // verify elements: early exit
  for (int ii = 0; ii < m; ii++){
    for (int jj = 0; jj < m; jj++) {
      if (std::fabs(r[ii*m + jj]) > eps) {
        return false;
      } 
    }
  }
  return true;
}