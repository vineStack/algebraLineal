#ifndef ioMatriz_h
#define ioMatriz_h

#include <iostream>
#include <vector>
#include "fraccion.h"

/*
Concatena horizontalmente la matriz A y la matriz B. Crea la matriz aumentada
    &A -> vector<vector<Fraccion>>
    &B -> vector<vector<Fraccion>>
*/
std::vector<std::vector<Fraccion>> concatenarMatrices(const std::vector<std::vector<Fraccion>>& A, const std::vector<std::vector<Fraccion>>& B);

std::vector<std::vector<Fraccion>> mkSqMatrixZero(int n);

/*
  -Encargada de crear la matriz identidad de orden n
*/
std::vector<std::vector<Fraccion>> mkSqMatrixI(int n);

/*
  -Imprime la matriz
*/
void printMatrix(const std::vector<std::vector<Fraccion>>& A, int n, int m);

/*
  -Leer valores por consola para una matriz
*/
std::vector<std::vector<Fraccion>> readMatrix(int n, int m);

#endif