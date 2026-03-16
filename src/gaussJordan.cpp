#include <vector>
#include "../include/ioMatriz.h"
#include "../include/matrixE.h"
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

vector<vector<Fraccion>> extraerReduccion(const vector<vector<Fraccion>>& M, int n, int m) {
    vector<vector<Fraccion>> reduccion(n, vector<Fraccion>(m));

    cout<<"\n--------------->Extraccion de la reducción";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            /* code */
            reduccion[i][j] = M[i][j] ;
        }
    }
    return reduccion;
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
                continue;
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
            cout<<"\n\n\nEl pivote en la posición ("<<i+1<<","<<i+1<<") no es uno, se multiplicará\n";
            cout<<"\n--------------------------------------------------------\n";
            printMatrix(M,n,columnasM);
            cout<<"\n--------------------------------------------------------\n";
            cout<<"\nPor la matriz elemental";
            cout<<"\n--------------------------------------------------------\n";
            printMatrix(E_escalar,n,n);
            cout<<"\n--------------------------------------------------------\n";
            
            cout<<"\n\n Así se obtiene";
            M = multiplicacion(E_escalar,M,n,n,columnasM);
            cout<<"\n--------------------------------------------------------\n";
            printMatrix(M,n,columnasM);
            cout<<"\n--------------------------------------------------------\n";
        }

        for (int j = 0; j < n; j++)
        {
            if (i != j && M[j][i] != Fraccion(0,1))
            {
                Fraccion factorEliminacion = -M[j][i];
                //Aqui se crea la matriz elemental con la cual se multiplicará por la derecha
                vector<vector<Fraccion>> E_suma = multiplofilaYSumaRenglones(n,i,j,factorEliminacion);
                cout<<"\n\nSe hará 0 la entrada ("<<i+1<<","<<j+1<<") con la matriz elemental que multiplica la fila "<<i+1<<" por "<<factorEliminacion<<" y lo suma a la fila "<<j+1<<". La matriz elemental es:";
                cout<<"\n--------------------------------------------------------\n";
                printMatrix(E_suma,n,n);
                cout<<"\n--------------------------------------------------------\n";
                M = multiplicacion(E_suma,M,n,n,columnasM);
                
                cout<<" Así se obtiene"<<"\n--------------------------------------------------------\n";
                printMatrix(M,n,columnasM);
                cout<<"\n--------------------------------------------------------\n";
            }
        }
    }

    //Si la matriz no es cuadrada, devuelve la reducción por renglones de la matriz dada
    if (n != m) { cout<<"\n matriz no cuadrada\n"; return extraerReduccion(M,n,m);}
    return extraerInversa(M,n,m);

}