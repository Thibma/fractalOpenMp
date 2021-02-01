#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex {
public:
    Complex(double reel, double img);
    Complex();
    Complex sqr();
    double sqrModulus();
    friend Complex operator +(const Complex &c1, const Complex &c2);

private:
    double m_reel;
    double m_img;
};

#endif