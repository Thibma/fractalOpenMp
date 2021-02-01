#ifndef FRACTALMODEL_HPP
#define FRACTALMODEL_HPP

#include <omp.h>
#include <ostream>

#include "fractal.hpp"
#include "complex.hpp"
#include "EasyBMP/EasyBMP.h"

class FractalModel {

private:
    double m_xmin, m_xmax, m_ymin, m_ymax;
    unsigned int m_width, m_height;
    Fractal *fractal;
    BMP *image;

public:
    FractalModel();
    ~FractalModel();
    BMP *getImage();

    void setMinMax(double xmin, double xmax, double ymin, double ymax);
    void setFractal(Fractal *fractal);
    void setSize(unsigned int width, unsigned int height);

    Complex getPosFromFractal(int x, int y);

    void calculate();
};

#endif