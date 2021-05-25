// ===================================================================
// circuit.cpp
// ===================================================================
#include "complex.hpp"
#include <iostream>
#include <cmath>
using namespace std;

/* returns the impedance of a resistor */
Complex resistor(double r) {
    // TODO
}

/* returns the impedance of an inductor for a given frequency */
Complex inductor(double l, double omega) {
    // TODO
}

/* returns the impedance of a capacitor for a given frequency */
Complex capacitor(double c, double omega) {
    // TODO
}

/* returns the impedance of a serial combination (2 parts) */
Complex serial(Complex r1, Complex r2) {
    // TODO
}


/* returns the impedance of a parallel combination */
Complex parallel(Complex r1, Complex r2) {
    // TODO
}

/* computes the impedance of example circuit */
Complex circuitC() {
    double omega = 100;
    Complex r1 = resistor(20);
    Complex r2 = resistor(50);
    Complex r3 = resistor(50);
    Complex r4 = resistor(30);
    Complex l1 = inductor(0.5, omega);
    Complex l2 = inductor(1, omega);
    Complex c1 = capacitor(0.0005, omega);
    Complex c2 = capacitor(0.0001, omega);

    Complex temp1 = serial(r3, l2);
    Complex temp2 = parallel(temp1, c2);
    Complex temp3 = serial(temp2, r4);
    Complex temp4 = parallel(temp3, r2);
    Complex temp5 = parallel(c1, temp4);
    Complex temp6 = serial(l1, temp5);
    Complex result = serial(temp6, r1);

    return result;
}


int main() {
    cout << "Circuit : ";
    Complex resultC = circuitC();
    // TODO
}

