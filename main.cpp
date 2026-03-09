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

    cout<<"\n ingrese la dimensión de la matriz. \n Filas: ";
    cin>>n;
    cout<<"\n Columnas: ";
    cin>>m;
    
    A = readMatrix(n,m);
    printMatrix(A,n,m);
    
    cout<<"\Disque aplicando Gauss Jordan";
    C = gaussJordan(A,n,m);

    cout<<"En teoría, la matriz inversa";
    printMatrix(C,n,n);
    

    
    return 0;

}
