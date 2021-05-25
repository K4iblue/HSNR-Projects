#ifndef COMPLEX_NUMBER_COMPLEX_H
#define COMPLEX_NUMBER_COMPLEX_H

typedef struct complex_s complex_t;

complex_t *getComplex(double re, double im);
complex_t *addComplex(complex_t *a, complex_t *b);
complex_t *subComplex(complex_t *a, complex_t *b);
complex_t *mulComplex(complex_t *a, complex_t *b);
complex_t *divComplex(complex_t *a, complex_t *b);
void printComplex(complex_t *a);
void cleanComplex(complex_t *a);

#endif //COMPLEX_NUMBER_COMPLEX_H
