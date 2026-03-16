#ifndef gaussJordan_h
#define gaussJordan_h

#include <vector>
#include "ioMatriz.h"

/*
    &M -> Referencia a la matriz aumentada
    n = m, caso matriz cuadrada y ademas existe inversa
*/
std::vector<std::vector<Fraccion>> extraerInversa(const std::vector<std::vector<Fraccion>>& M, int n, int m);

/*
    &M -> Referencia a la matriz aumentada
    n -> filas
    m -> columnas
    Devuelve la reducción por columnas de la matriz aumentada cuando la matriz no tiene inversa y/o no es cuadrada
*/
std::vector<std::vector<Fraccion>> extraerReduccion(const std::vector<std::vector<Fraccion>>& M, int n, int m);

/*
    &A -> Referencia a factor izquierdo
    &B -> Referencia a factor derecho
    n: filas &A
    m: columnas &A, filas &B
    p: columnas &B
*/
std::vector<std::vector<Fraccion>> multiplicacion(const std::vector<std::vector<Fraccion>> &A, const std::vector<std::vector<Fraccion>> &B, int n, int m, int p);

std::vector<std::vector<Fraccion>> gaussJordan(std::vector<std::vector<Fraccion>> A, int n, int m);
#endif