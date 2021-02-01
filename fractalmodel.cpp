#include "fractalmodel.hpp"

// Modèle de fractale par défaut
FractalModel::FractalModel() {
    this->m_xmin = 0;
    this->m_xmax = 0;
    this->m_ymin = 0;
    this->m_ymax = 0;

    this->m_width = 2000;
    this->m_height = 2000;

    image = new BMP();
}

// Desctruction de l'allocation
FractalModel::~FractalModel() {
    delete image;
}

// Récupération de l'image pour l'export en BMP
BMP *FractalModel::getImage() {
    return this->image;
}

// Permet de choisir le plan
void FractalModel::setMinMax(double xmin, double xmax, double ymin, double ymax) {
    this->m_xmin = xmin;
    this->m_xmax = xmax;
    this->m_ymin = ymin;
    this->m_ymax = ymax;
}

// Permet d'associer la fractal au modèle
void FractalModel::setFractal(Fractal *fractal) {
    this->fractal = fractal;
}

// Permet de choisir la taille de l'image
void FractalModel::setSize(unsigned int width, unsigned int height) {
    this->m_width = width;
    this->m_height = height;
}

// Permet de convertir un point sur un plan en complexe pour une fractale
Complex FractalModel::getPosFromFractal(int x, int y) {
    double newX = this->m_xmin + (x * (this->m_xmax - this->m_xmin) / this->m_width);
    double newY = this->m_ymin + (y * (this->m_ymax - this->m_ymin) / this->m_height);
    return Complex(newX, newY);
}

// Permet de calculer une fractale (EFFECTUÉ DANS PLUSIEURS THREADS)
void FractalModel::calculate() {

    image->SetSize(this->m_width, this->m_height);
    image->SetBitDepth(24);
    int colorValue;
    RGBApixel color;
    #pragma omp parallel shared(m_height, m_width, fractal) private(colorValue, color)
    {
        #pragma omp for
        {
            for (int y = 0; y < this->m_height; y++) {
                for (int x = 0; x < this->m_width; x++) {
                    colorValue = this->fractal->dot(this->getPosFromFractal(x, y));
                    color = image->GetPixel(x, y);
                    color.Red = colorValue;
                    color.Blue = colorValue;
                    color.Green = colorValue;
                    color.Alpha = 0;
                    image->SetPixel(x, y, color);
                }
            }
        }
    }
    
}