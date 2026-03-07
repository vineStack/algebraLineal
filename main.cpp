#include <iostream>
#include <vector>
#include "../include/ioMatriz.h"
#include "../include/matrixE.h"
#include "../include/gaussJordan.h"

using namespace std;

int main()
{
    int n,m,x,y;
    vector<vector<double>> A,B,C;
    
    cout<<"Inserte la dimensión \n"<<"n: ";
    cin>>n;

    A = mkSqMatrixI(n);
    cout<<"\n Ingresa el numero de la primera fila de las dos para intercambiar: ";
    cin>>x; x-=1;
    cout<<"\n Ingresa el numero de la segunda fila de las dos para intercambiar: ";
    cin>>y; y-=1;

    cout<<"\n Matriz intercambio de renglones";
    printMatrix(intercambioRenglones(n,x,y),n,n);

    cout<<"\n Matriz suma de renglones";
    printMatrix(sumaRenglones(n,x,y),n,n);

    cout<<"\n Matriz suma de un renglon por el multiplo de otro";
    printMatrix(multiplofilaYSumaRenglones(n,x,y,4),n, n);

    cout<<"\n ingrese la dimensión de la matriz. Filas: ";
    cin>>n;
    cout<<"\t Columnas: ";
    cin>>m;
    
    A = readMatrix(n,m);
    printMatrix(A,n,m);
    
    B = readMatrix(n,m);
    printMatrix(B,n,m);

    C = multiplicacion(A,B,n,m,m);
    printMatrix(C,n,m);
    
    return 0;
}
