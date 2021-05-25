// *******************************************************************
// complex.cpp
// *******************************************************************

#include "complex.hpp"
#include <cmath>
using namespace std;

// *******************************************************************
Complex::Complex(double re, double im) {
    _real = re;
    _imag = im;
}

// *******************************************************************
double Complex::real(void) const {
    return _real;
}

// *******************************************************************
double Complex::imag(void) const {
    return _imag;
}

// *******************************************************************
Complex Complex::add(const Complex &c) const {
    return Complex(_real + c._real, _imag + c._imag);
}

Complex Complex::operator+(const Complex &c) const {
    return add(c);
}

// *******************************************************************
Complex Complex::sub(const Complex &c) const {
    return Complex(_real - c._real, _imag - c._imag);
}

Complex Complex::operator-(const Complex &c) const {
    return sub(c);
}

// *******************************************************************
Complex Complex::mul(const Complex &c) const {
    return Complex(_real * c._real - _imag * c._imag,
                   _real * c._imag + _imag * c._real);
}

Complex Complex::operator*(const Complex &c) const {
    return mul(c);
}

// *******************************************************************
Complex Complex::div(const Complex &c) const {
    double nenner = c._real * c._real + c._imag * c._imag;
    if (nenner == 0.0)
        throw "illegal operation";

    return Complex((_real * c._real + _imag * c._imag) / nenner,
                   (_imag * c._real - _real * c._imag) / nenner);
}

Complex Complex::operator/(const Complex &c) const {
    return div(c);
}

// *******************************************************************
double Complex::abs(void) const {
    return sqrt(_real * _real + _imag * _imag);
}

// *******************************************************************
bool Complex::operator!=(const Complex& c) const {
    double diffRe = fabs(_real - c._real);
    double diffIm = fabs(_imag - c._imag);

    return diffRe > 0.00001 || diffIm > 0.00001;
}

// *******************************************************************
bool Complex::operator==(const Complex& c) const {
    return not(*this != c);
}

// *******************************************************************
ostream& operator<<(ostream& os, Complex& c) {
    os << "(" << c._real << " + " << c._imag << " * i)";
    return os;
}

// *******************************************************************
istream& operator>>(istream& is, Complex& c) {
    is >> c._real >> c._imag;
    return is;
}

