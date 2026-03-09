#ifndef gaussJordan_h
#define gaussJordan_h

#include <vector>
#include "ioMatriz.h"

std::vector<std::vector<double>> multiplicacion(const std::vector<std::vector<double>> &A, const std::vector<std::vector<double>> &B, int n, int m, int p);

std::vector<std::vector<double>> gaussJordan(std::vector<std::vector<double>> A, int n, int m);
#endif