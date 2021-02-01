#include "complex.hpp"

// Création d'un nombre complexe à l'aide du réel et de l'image
Complex::Complex(double reel, double img) {
    this->m_reel = reel;
    this->m_img = img;
}

// Création d'un complexe par défault
Complex::Complex() {
    this->m_reel = 0;
    this->m_img = 0;
}

// Calcul d'un complexe au carré
Complex Complex::sqr() {
    double r = this->m_reel * this->m_reel - this->m_img * this->m_img;
    double i = 2 * this->m_reel * this->m_img;
    return Complex(r, i);
}

// Calcul du modulos d'un complexe
double Complex::sqrModulus() {
    return this->m_reel * this->m_reel + this->m_img * this->m_img;
}

// Permet de faire une opération + entre deux objets Complex
Complex operator +(const Complex &c1, const Complex &c2) {
    return Complex(c1.m_reel + c2.m_reel, c1.m_img + c2.m_img);
}