#ifndef ioMatriz_h
#define ioMatriz_h

#include <iostream>
#include <vector>

std::vector<std::vector<double>> mkSqMatrixZero(int n);

/*
  -Encargada de crear la matriz identidad de orden n
*/
std::vector<std::vector<double>> mkSqMatrixI(int n);

/*
  -Imprime la matriz
*/
void printMatrix(const std::vector<std::vector<double>>& A, int n, int m);

/*
  -Leer valores por consola para una matriz
*/
std::vector<std::vector<double>> readMatrix(int n, int m);

#endif