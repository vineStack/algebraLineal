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
void imprimirMatriz(const std::vector<std::vector<double>>& m, int n);

/*
  -Modifica las filas de una matriz
*/
void modificaFila(std::vector<std::vector<double>>& m, int n);

#endif