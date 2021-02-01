#ifndef JULIA_HPP
#define JULIA_HPP

#include "fractal.hpp"

class Julia : public Fractal {
private:
    Complex m_c;

public:
    Julia();
    Julia(Complex c);
    int dot(Complex zc);
};

#endif