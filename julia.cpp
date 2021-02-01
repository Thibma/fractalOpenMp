#include "julia.hpp"

// Fractale de Julia avec une graine C par défaut 
Julia::Julia() {
    Complex c(-0.0849, 0.8721);
    this->m_c = c;
}

// Fractale de Julia avec une graine C personnalisée
Julia::Julia(Complex c) {
    this->m_c = c;
}

// Calcul d'un point de la fractale de Julia
int Julia::dot(Complex zc) {
    Complex z = zc;
    for (int i = 1; i < this->max; i++) {
        z = z.sqr() + this->m_c;
        if (z.sqrModulus() >= 2) {
            return i;
        }
    }
    return 0;
}