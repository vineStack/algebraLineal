#include <iostream>
#include <vector>
using namespace std;

vector<vector<double>> mkSqMatrixZero(int n){
    vector<vector<double>> A(n, vector<double>(n,0.0));
    return A;
}

vector<vector<double>> mkSqMatrixI(int n){
    vector<vector<double>> A = mkSqMatrixZero(n);
    for (int i = 0; i < n; i++)
    {
        A[i][i] = 1;
    }
    return A;
}

void imprimirMatriz(const vector<vector<double>>& m, int n){
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }   
}

//void modificaFila(std::vector<std::vector<double>>& m, int n);