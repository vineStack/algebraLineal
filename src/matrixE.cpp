#include <vector>
#include "../include/ioMatriz.h"
using namespace std;

vector<vector<Fraccion>> intercambioRenglones(int n, int x, int y){
    vector<vector<Fraccion>> A = mkSqMatrixI(n);
    
    A[x][x] = 0;
    A[x][y] = 1;
    A[y][y] = 0;
    A[y][x] = 1;

    return A;
}

vector<vector<Fraccion>> sumaRenglones(int n, int x, int y){
    vector<vector<Fraccion>> A = mkSqMatrixI(n);
    A[x][y] = 1;
    return A;
}
// parámetros --->(n: dimensión, x: fila a multiplicar por escalar, k: escalar por el cual se multiplicará)
vector<vector<Fraccion>> filaPorEscalar(int n, int x, Fraccion k){
    vector<vector<Fraccion>> A = mkSqMatrixI(n);
    A[x][x] = k;
    return A;
}

/*
 Parámetros:
    n: dimensión
    x: fila a multiplicar por escalar
    y: fila en donde se aplicarán los cambios
    k: escalar por el cual se multiplicará x
*/
vector<vector<Fraccion>> multiplofilaYSumaRenglones(int n, int x, int y, Fraccion k){
    vector<vector<Fraccion>> A = mkSqMatrixI(n);

    A[y][x] = k;


    return A;
}