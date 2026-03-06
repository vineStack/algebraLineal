#include <iostream>
#include <vector>
#include "ioMatriz.h"

using namespace std;

void intercambioRenglones(vector<vector<double>>& m){
    int k,l;
    
    cout<<"\n Ingresa el numero de la primera fila de las dos para intercambiar: ";
    cin>>k; k-=1;
    cout<<"\n Ingresa el numero de la segunda fila de las dos para intercambiar: ";
    cin>>l; l-=1;
    
    m[k][k] = 0;
    m[k][l] = 1;
    m[l][l] = 0;
    m[l][k] = 1;
    
}

int main()
{
    int n;
    vector<vector<double>> matriz;
    
    cout<<"Inserte la dimensión \n"<<"n: ";
    cin>>n;

    matriz = mkSqMatrixI(n);

    intercambioRenglones(matriz);
    imprimirMatriz(matriz,n);
    
    return 0;
}
