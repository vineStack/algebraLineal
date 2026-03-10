#include <vector>
#include "ioMatriz.h"
#include "matrixE.h"
using namespace std;

vector<vector<Fraccion>> multiplicacion(const vector<vector<Fraccion>> &A, const vector<vector<Fraccion>> &B, int n, int m, int p)
{
    vector<vector<Fraccion>> C(n, vector<Fraccion>(p,0));
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

vector<vector<Fraccion>> gaussJordan(vector<vector<Fraccion>> A, int n, int m){
    
    vector<vector<Fraccion>> I = mkSqMatrixI(n);
    vector<vector<Fraccion>> E_escalar;
    //primero normalizamos los pivotes
    for (int i = 0; i < n; i++)
    {
        if (A[i][i] == Fraccion(1,1))
        {
            A = multiplicacion(filaPorEscalar(n,i,Fraccion(1,1)/A[i][i]),A,n,n,m); //Normalización del pivote
            I = multiplicacion(filaPorEscalar(n,i,Fraccion(1,1)/A[i][i]),A,n,n,m);
        }
        
    }
    

    for (int i = 0; i < n; i++) //Este ciclo va sobre las columnas
    {
        for (int j = 0; j < n; j++) //Este ciclo va sobre las filas
        {   
            if (i==j && A[i][j]==1) continue;
            
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