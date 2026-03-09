#include <vector>
#include "../include/ioMatriz.h"
using namespace std;

vector<vector<double>> intercambioRenglones(int n, int x, int y){
    vector<vector<double>> A = mkSqMatrixI(n);
    
    A[x][x] = 0;
    A[x][y] = 1;
    A[y][y] = 0;
    A[y][x] = 1;

    return A;
}

vector<vector<double>> sumaRenglones(int n, int x, int y){
    vector<vector<double>> A = mkSqMatrixI(n);
    A[x][y] = 1;
    return A;
}
// parámetros --->(n: dimensión, x: fila a multiplicar por escalar, k: escalar por el cual se multiplicará)
vector<vector<double>> filaPorEscalar(int n, int x, int k){
    vector<vector<double>> A = mkSqMatrixI(n);
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
vector<vector<double>> multiplofilaYSumaRenglones(int n, int x, int y, int k){
    vector<vector<double>> A = mkSqMatrixI(n);

    A[y][x] = k;


    return A;
}