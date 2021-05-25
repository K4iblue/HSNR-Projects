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

// *******************************************************************
Complex Complex::sub(const Complex &c) const {
    return Complex(_real - c._real, _imag - c._imag);
}

// *******************************************************************
Complex Complex::mul(const Complex &c) const {
    return Complex(_real * c._real - _imag * c._imag,
                   _real * c._imag + _imag * c._real);
}

// *******************************************************************
Complex Complex::div(const Complex &c) const {
    double nenner = c._real * c._real + c._imag * c._imag;

    return Complex((_real * c._real + _imag * c._imag) / nenner,
                   (_imag * c._real - _real * c._imag) / nenner);
}

// *******************************************************************
double Complex::abs(void) const {
    return sqrt(_real * _real + _imag * _imag);
}

