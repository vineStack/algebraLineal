#ifndef matrixE_h
#define matrixE_h

#include <vector>
#include "ioMatriz.h"

std::vector<std::vector<double>> intercambioRenglones(int n, int x, int y);

/* 
    n:dimensión
    x: sumando 1
    y: sumando 2 y en donde se quedará la fila
*/
std::vector<std::vector<double>> sumaRenglones(int n, int x, int y);

// parámetros --->(n: dimensión, x: fila a multiplicar por escalar, k: escalar por el cual se multiplicará)
std::vector<std::vector<double>> filaPorEscalar(int n, int x, int k);

#endif