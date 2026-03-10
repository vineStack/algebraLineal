#ifndef gaussJordan_h
#define gaussJordan_h

#include <vector>
#include "ioMatriz.h"

std::vector<std::vector<Fraccion>> multiplicacion(const std::vector<std::vector<Fraccion>> &A, const std::vector<std::vector<Fraccion>> &B, int n, int m, int p);

std::vector<std::vector<Fraccion>> gaussJordan(std::vector<std::vector<Fraccion>> A, int n, int m);
#endif