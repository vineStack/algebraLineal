#include <iostream>
#include <vector>
#include "../include/fraccion.h"
using namespace std;

/*
    Crea la matriz aumentada
    &A -> vector<vector<Fraccion>>
    &B -> vector<vector<Fraccion>>
*/
vector<vector<Fraccion>> concatenarMatrices(const vector<vector<Fraccion>>& A, const vector<vector<Fraccion>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();

    // Creamos una matriz con n filas y (m + p) columnas
    vector<vector<Fraccion>> aumentada(n, vector<Fraccion>(m + p));

    for (int i = 0; i < n; i++) {
        // Copiamos la parte de A
        for (int j = 0; j < m; j++) {
            aumentada[i][j] = A[i][j];
        }
        // Copiamos la parte de B justo después de m
        for (int j = 0; j < p; j++) {
            aumentada[i][m + j] = B[i][j];
        }
    }

    return aumentada;
}

/*
    Matriz cero de orden nxn
*/
vector<vector<Fraccion>> mkSqMatrixZero(int n){
    vector<vector<Fraccion>> A(n, vector<Fraccion>(n,0.0));
    return A;
}

vector<vector<Fraccion>> mkSqMatrixI(int n){
    vector<vector<Fraccion>> A = mkSqMatrixZero(n);
    for (int i = 0; i < n; i++)
    {
        A[i][i] = 1;
    }
    return A;
}

void printMatrix(const vector<vector<Fraccion>>& A, int n, int m){
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }   
}

vector<vector<Fraccion>> readMatrix(int n, int m){
    vector<vector<Fraccion>> A(n, vector<Fraccion>(m, 0.0));
    cout<<"\nIngrese la matriz por filas\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>A[i][j];
        }
    }
    return A;
}

//void modificaFila(std::vector<std::vector<Fraccion>>& m, int n);