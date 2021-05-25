// *******************************************************************
// complex.h
// *******************************************************************

#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double _real, _imag;

public:
    Complex(double re = 0.0, double im = 0.0);
    double real(void) const;
    double imag(void) const;

    Complex add(const Complex &c) const;
    Complex sub(const Complex &c) const;
    Complex mul(const Complex &c) const;
    Complex div(const Complex &c) const;
    double abs(void) const;
};

#endif

