#include <iostream>
#include <vector>
using namespace std;

vector<vector<double>> mkSqMatrixI(int n){
    vector<vector<double>> matriz(n, vector<double>(n,0.0));
    for (int i = 0; i < n; i++)
    {
        matriz[i][i] = 1;
    }
    return matriz;
}

void imprimirMatriz(const vector<vector<double>>& m, int n){
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