#include <numeric>
#include <iostream>

struct Fraccion {
    long long num;
    long long den;

    // Constructor que simplifica la fracción al crearla
    Fraccion(long long n = 0, long long d = 1) {
        if (d == 0) throw std::invalid_argument("Denominador cero");
        long long divisor = std::gcd(n, d);
        num = n / divisor;
        den = d / divisor;
        if (den < 0) { // Mantener el signo en el numerador
            num = -num;
            den = -den;
        }
    }

    // Sobrecarga de suma
    Fraccion operator+(const Fraccion& otra) const {
        return Fraccion(num * otra.den + otra.num * den, den * otra.den);
    }

    // Sobrecarga del inverso aditivo
    Fraccion operator-() {
        return Fraccion(-num,-den);
    }

    // Sobrecarga de operador de asignación de suma
    Fraccion operator+=(const Fraccion& otra) {
        long long num_nuevo = num*otra.den + otra.num*den;
        long long den_nuevo = den*otra.den;
        
        *this = Fraccion(num_nuevo,den_nuevo);

        return *this;
    }

    // Sobrecarga de multiplicación
    Fraccion operator*(const Fraccion& otra) const {
        return Fraccion(num * otra.num, den * otra.den);
    }

    // Sobrecarga del inverso multiplicativo
    Fraccion operator/(const Fraccion& otra) const{
        return Fraccion(num*otra.den, otra.num*den);
    }

    //Sobrecarga de comparación
    bool operator==(const Fraccion& otra) const{
        return(num == otra.num && den == otra.den );
    }

    // Sobrecarga de entrada (cin)
    friend std::istream& operator>>(std::istream& is, Fraccion& f) {
        std::string input;
        is >> input;
        
        size_t pos = input.find('/');
        if (pos != std::string::npos) {
            // Si encuentra una barra '/', extrae numerador y denominador
            long long n = std::stoll(input.substr(0, pos));
            long long d = std::stoll(input.substr(pos + 1));
            f = Fraccion(n, d); // Se usa el constructor para que se simplifique automáticamente
        } else {
            // Si no hay '/', se asume que es un número entero
            long long n = std::stoll(input);
            f = Fraccion(n, 1);
        }
        return is;
    }

    // Sobrecarga de impresión
    friend std::ostream& operator<<(std::ostream& os, const Fraccion& f) {
        if (f.den == 1) os << f.num;
        else os << f.num << "/" << f.den;
        return os;
    }
};