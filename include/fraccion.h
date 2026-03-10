#ifndef fraccion_h
#define fraccion_h

#include <iostream>
#include <numeric>

struct Fraccion{
    long long num;
    long long den;

    Fraccion(long long n = 0, long long d = 1);
    
    //Sobrecarga de suma
    Fraccion operator+(const Fraccion& otra) const ;

    // Sobrecarga del inverso aditivo
    Fraccion operator-(const Fraccion& otra) const;

    Fraccion operator+=(const Fraccion& otra);

    // Sobrecarga de multiplicación
    Fraccion operator*(const Fraccion& otra) const;

    // Sobrecarga del inverso multiplicativo
    Fraccion operator/(const Fraccion& otra) const;

    // Sobrecarga de comparación
    bool operator==(const Fraccion& otra) const;

    bool operator!=(const Fraccion& otra) const;

    // Sobrecarga de entrada (cin)
    friend std::istream& operator>>(std::istream& is, Fraccion& f);

    // Sobrecarga de impresión
    friend std::ostream& operator<<(std::ostream& os, const Fraccion& f);

};
#endif