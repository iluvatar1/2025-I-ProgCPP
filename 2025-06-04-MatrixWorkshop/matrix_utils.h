#pragma once

#include <iostream>
#include <vector>
#include <cmath>

void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & indata, int m, int n,
                      std::vector<double> & outdata);
void matmul(const std::vector<double> & A, int mA, int nA, 
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C);


bool check_inverse(const std::vector<double> & A,  
                   const std::vector<double> & B, 
                   int m, 
                   double eps);