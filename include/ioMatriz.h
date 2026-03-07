#ifndef ioMatriz_h
#define ioMatriz_h

#include <iostream>
#include <vector>

/*
  -Encargada de crear la matriz identidad de orden n
*/
std::vector<std::vector<double>> mkSqMatrixI(int n);

/*
  -Imprime la matriz
*/
void printMatrix(const std::vector<std::vector<double>>& m, int n);

/*
  -Modifica las filas de una matriz
*/
std::vector<std::vector<double>> readMatrix(int n, int m);

#endif