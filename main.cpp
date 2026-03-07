#include <iostream>
#include <vector>
#include "../include/ioMatriz.h"
#include "../include/matrixE.h"

using namespace std;

int main()
{
    int n,x,y;
    vector<vector<double>> A;
    
    cout<<"Inserte la dimensión \n"<<"n: ";
    cin>>n;

    A = mkSqMatrixI(n);
    cout<<"\n Ingresa el numero de la primera fila de las dos para intercambiar: ";
    cin>>x; x-=1;
    cout<<"\n Ingresa el numero de la segunda fila de las dos para intercambiar: ";
    cin>>y; y-=1;

    intercambioRenglones(n,x,y);
    imprimirMatriz(A,n);
    
    cout<<"\n Matriz intercambio de renglones";
    imprimirMatriz(intercambioRenglones(n,0,n-1),n);

    cout<<"\n Matriz suma de renglones";
    imprimirMatriz(sumaRenglones(n,x,y),n);

    return 0;
}
