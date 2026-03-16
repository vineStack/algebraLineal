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

    cout<<"\n ingrese la dimensión de la matriz.\n Filas: ";
    cin>>n;
    cout<<"\n Columnas: ";
    cin>>m;
    
    A = readMatrix(n,m);
    printMatrix(A,n,m);
    B = gaussJordan(A,n,m);
    try
    {
        cout<<"\n\nPor lo tanto, la matriz inversa es:";
        printMatrix(B,n,n);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout<<"\n\nLa reducción por renglones es:\n";
        printMatrix(B,n,m);
    }
    
    

    


    return 0;

}
