#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include "complex.hpp"

class Fractal {
public:
    Fractal();

    // On fait hériter cette classe au cas ou on veut créer plusieurs modèles (ex : Mandelbrot)
    virtual int dot(Complex zc) = 0;

protected:
    int max;
};

#endif