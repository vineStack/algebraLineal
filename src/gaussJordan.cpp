#include <vector>
#include "ioMatriz.h"
#include "matrixE.h"
using namespace std;

// Función auxiliar para extraer la parte derecha (la inversa) de la matriz aumentada
vector<vector<Fraccion>> extraerInversa(const vector<vector<Fraccion>>& M, int n, int m) {
    vector<vector<Fraccion>> inversa(n, vector<Fraccion>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inversa[i][j] = M[i][m + j];
        }
    }
    return inversa;
}

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
    vector<vector<Fraccion>> M = concatenarMatrices(A,I);
    int columnasM = n+m;

    for (int i = 0; i < n; i++)
    {

        // 2. MANEJO DE CEROS: Intercambio de filas (Pivoteo parcial)
        if (M[i][i] == Fraccion(0, 1)) {
            int filaSwap = -1;
            for (int k = i + 1; k < n; k++) {
                if (M[k][i] != Fraccion(0, 1)) {
                    filaSwap = k;
                    break;
                }
            }

            if (filaSwap == -1) {
                throw runtime_error("La matriz no tiene inversa (es singular).");
            }

            // Aplicar matriz elemental de intercambio a la matriz aumentada completa
            vector<vector<Fraccion>> E_swap = intercambioRenglones(n, i, filaSwap);
            M = multiplicacion(E_swap, M, n, n, columnasM);
        }

        //Ahora normalizamos los pivotes
        if (M[i][i] != Fraccion(1,1))
        {
            Fraccion factorNormalizacion = Fraccion(1,1)/M[i][i]; //Esto hace 1 al pivote
            vector<vector<Fraccion>> E_escalar = filaPorEscalar(n,i,factorNormalizacion);
            M = multiplicacion(E_escalar,M,n,n,columnasM);
        }

        for (int j = 0; j < n; j++)
        {
            if (i != j && M[j][i] != Fraccion(0,1))
            {
                Fraccion factorEliminacion = -M[j][i];
                //Aqui se crea la matriz elemental con la cual se multiplicará por la derecha
                vector<vector<Fraccion>> E_suma = multiplofilaYSumaRenglones(n,i,j,factorEliminacion);

                M = multiplicacion(E_suma,M,n,n,columnasM);
                cout<<"\n--------------------------------------------------------\n";
                printMatrix(M,n,columnasM);
                cout<<"\n--------------------------------------------------------\n";
            }
        }
    }
    
    return extraerInversa(M,n,m);

}