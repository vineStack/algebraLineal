#include <vector>
#include "ioMatriz.h"
#include "matrixE.h"
using namespace std;

vector<vector<double>> multiplicacion(const vector<vector<double>> &A, const vector<vector<double>> &B, int n, int m, int p)
{
    vector<vector<double>> C(n, vector<double>(p,0.0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    return C;
}

vector<vector<double>> gaussJordan(vector<vector<double>> A, int n, int m){
    
    vector<vector<double>> I = mkSqMatrixI(n);

    for (int i = 0; i < n; i++) //Este ciclo va sobre las columnas
    {
        for (int j = 0; j < n; j++) //Este ciclo va sobre las filas
        {
            if (i==j && A[i][j]==1) continue;
            if (i==j && A[i][j]!=1) A = multiplicacion(filaPorEscalar(n,i,1/A[i][j]),A,n,n,m);
            else{
                A = multiplicacion(multiplofilaYSumaRenglones(n,i,j, -A[i][j]),A,n,n,m);
                printMatrix(A,n,m);
                I = multiplicacion(multiplofilaYSumaRenglones(n,i,j, -A[i][j]),I,n,n,m);
                printMatrix(I,n,n);
            }            
        }
        
    }
    
    return I;

}