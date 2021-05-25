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


