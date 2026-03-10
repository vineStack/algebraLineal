#include <iostream>
#include <vector>
#include "../include/fraccion.h"
#include "../include/ioMatriz.h"
#include "../include/matrixE.h"
#include "../include/gaussJordan.h"

using namespace std;

int main()
{
    int n,m;
    vector<vector<Fraccion>> A,B;

    cout<<"\n ingrese la dimensión de la matriz. \n Filas: ";
    cin>>n;
    cout<<"\n Columnas: ";
    cin>>m;
    
    A = readMatrix(n,m);
    printMatrix(A,n,m);
    
    B = gaussJordan(A,n,m);

    cout<<"\nEn teoría, la matriz inversa";
    printMatrix(B,n,n);
    


    return 0;

}
