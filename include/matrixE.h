#ifndef matrixE_h
#define matrixE_h

#include <vector>
#include "ioMatriz.h"

std::vector<std::vector<Fraccion>> intercambioRenglones(int n, int x, int y);

/* 
    n:dimensión
    x: sumando 1
    y: sumando 2 y en donde se quedará la fila
*/
std::vector<std::vector<Fraccion>> sumaRenglones(int n, int x, int y);

// parámetros --->(n: dimensión, x: fila a multiplicar por escalar, k: escalar por el cual se multiplicará)
std::vector<std::vector<Fraccion>> filaPorEscalar(int n, int x, int k);

std::vector<std::vector<Fraccion>> multiplofilaYSumaRenglones(int n, int x, int y, int k);

#endif