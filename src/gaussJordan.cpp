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
    
    for (int i = 0; i < n; i++)
    {
        //primero normalizamos los pivotes
        if (A[i][i] != Fraccion(1,1))
        {
            Fraccion factorNormalizacion = Fraccion(1,1)/A[i][i]; //Esto hace 1 al pivote
            vector<vector<Fraccion>> E_escalar = filaPorEscalar(n,i,factorNormalizacion);
            A = multiplicacion(E_escalar,A,n,n,m);
            I = multiplicacion(E_escalar,I,n,n,m);
        }

        for (int j = 0; j < n; j++)
        {
            if (i != j && A[j][i] != Fraccion(0,1))
            {
                Fraccion factorEliminacion = -A[i][j];
                //Aqui se crea la matriz elemental con la cual se multiplicará por la derecha
                vector<vector<Fraccion>> E_suma = multiplofilaYSumaRenglones(n,i,j,factorEliminacion);

                A = multiplicacion(E_suma,A,n,n,m);
                I = multiplicacion(E_suma,I,n,n,n);

            }
            
        }
        
        
    }
    
    return I;

}