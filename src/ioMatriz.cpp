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

void printMatrix(const vector<vector<double>>& A, int n, int m){
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

vector<vector<double>> readMatrix(int n, int m){
    vector<vector<double>> A(n, vector<double>(m, 0.0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>A[i][j];
        }
    }
    return A;
}

//void modificaFila(std::vector<std::vector<double>>& m, int n);