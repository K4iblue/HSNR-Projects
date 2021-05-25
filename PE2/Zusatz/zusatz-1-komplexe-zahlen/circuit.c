#include "complex.h"

#include <stdio.h>

/* returns the impedance of a resistor */
complex_t *resistor( double r ) {
    return getComplex(r, 0);
}

/* returns the impedance of an inductor for a given frequency */
complex_t *inductor( double l, double omega ) {
    return getComplex(0, omega * l);
}

/* returns the impedance of a capacitor for a given frequency */
complex_t *capacitor( double c, double omega ) {
    return divComplex( getComplex(1,0) ,getComplex(0, omega * c));
}

/* returns the impedance of a serial combination (2 parts) */
complex_t *serial( complex_t* r1, complex_t* r2 ) {
    return addComplex(r1, r2);
}


/* returns the impedance of a parallel combination */
complex_t *parallel( complex_t* r1, complex_t* r2 ) {
    complex_t *p1 = mulComplex(r1, r2);
    complex_t *p2 = addComplex(r1, r2);
    complex_t *result = divComplex(p1 , p2);
    cleanComplex( p1 );
    cleanComplex( p2 );
    return result;
}


/* computes the impedance of example circuit */
complex_t *circuitC() {
    double omega = 100;
    complex_t* r1 = resistor(20);
    complex_t* r2 = resistor(50);
    complex_t* r3 = resistor(50);
    complex_t* r4 = resistor(30);
    complex_t* l1 = inductor(0.5, omega);
    complex_t* l2 = inductor(1, omega);
    complex_t* c1 = capacitor(0.0005, omega);
    complex_t* c2 = capacitor(0.0001, omega);

    complex_t* temp1 = serial( r3, l2 );
    complex_t* temp2 = parallel( temp1, c2 );
    complex_t* temp3 = serial( temp2, r4 );
    complex_t* temp4 = parallel( temp3, r2 );
    complex_t* temp5 = parallel( c1, temp4 );
    complex_t* temp6 = serial( l1, temp5 );
    complex_t* result = serial( temp6, r1 );

    cleanComplex(r1); cleanComplex(r2); cleanComplex(r3); cleanComplex(r4);
    cleanComplex(l1); cleanComplex(l2);
    cleanComplex(c1); cleanComplex(c2);
    cleanComplex(temp1); cleanComplex(temp2); cleanComplex(temp3);
    cleanComplex(temp4); cleanComplex(temp5); cleanComplex(temp6);

    return result;
}


int main() {
    printf("Circuit : ");
    complex_t *resultC = circuitC();
    printComplex(resultC);
    cleanComplex(resultC);

    return 0;
}
