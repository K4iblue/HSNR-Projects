// *******************************************************************
// complex.h
// *******************************************************************

#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>

class Complex {
    friend std::ostream& operator<<(std::ostream& os, Complex& c);
    friend std::istream& operator>>(std::istream& os, Complex& c);

private:
    double _real, _imag;

    Complex add(const Complex &c) const;
    Complex sub(const Complex &c) const;
    Complex mul(const Complex &c) const;
    Complex div(const Complex &c) const;

public:
    Complex(double re = 0.0, double im = 0.0);
    double real(void) const;
    double imag(void) const;

    Complex operator+(const Complex &c) const;
    Complex operator-(const Complex &c) const;
    Complex operator*(const Complex &c) const;
    Complex operator/(const Complex &c) const;
    double abs(void) const;

    bool operator==(const Complex &c) const;
    bool operator!=(const Complex &c) const;
};

#endif

