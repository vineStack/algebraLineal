#include <iostream>
#include <vector>
#include "../include/fraccion.h"
using namespace std;

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
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }   
}

vector<vector<Fraccion>> readMatrix(int n, int m){
    vector<vector<Fraccion>> A(n, vector<Fraccion>(m, 0.0));
    cout<<"Ingrese la matriz por filas";
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