#include "rational.hpp"
#include <stdexcept>

// Konstruktor
Rational::Rational(int z, int n) {
    if (0 == n)
        throw std::runtime_error("division by zero");

    _zaehler = z;
    _nenner = n;
    kuerzen();
}

void Rational::kehrwert() {
    if (0 == _zaehler)
        throw std::runtime_error("division by zero");

    int t = _zaehler;
    _zaehler = _nenner;
    _nenner = t;
}

void Rational::kuerzen() {
    int a = _zaehler;
    int b = _nenner;

    while (b != 0) {
        int h = a % b;
        a = b;
        b = h;
    }

    _zaehler /= a;
    _nenner /= a;
}

Rational Rational::add(Rational x) {
    Rational r;
    r._zaehler = _zaehler * x._nenner + _nenner * x._zaehler;
    r._nenner = _nenner * x._nenner;
    r.kuerzen();
    return r;
}

Rational Rational::sub(Rational x) {
    return add(-x);
}

Rational Rational::mul(Rational x) {
    return Rational(_zaehler * x._zaehler, _nenner * x._nenner);
}

Rational Rational::div(Rational x) {
    x.kehrwert();
    return mul(x);
}

int Rational::getZaehler() const {
    return _zaehler;
}

int Rational::getNenner() const {
    return _nenner;
}

Rational Rational::operator-() { // Vorzeichen
    return Rational(-_zaehler, _nenner);
}

Rational Rational::operator+(const Rational& x){
    return add(x);
}

Rational Rational::operator-(const Rational& x){
    return sub(x);
}

Rational Rational::operator*(const Rational& x){
    return mul(x);
}

Rational Rational::operator/(const Rational& x){
    return div(x);
}

bool Rational::operator<(const Rational& x) {
    return _zaehler * x._nenner < _nenner * x._zaehler;
}

bool Rational::operator>(const Rational& x) {
    return _zaehler * x._nenner > _nenner * x._zaehler;
}

bool Rational::operator==(const Rational& x) {
    return _zaehler * x._nenner == _nenner * x._zaehler;
}

bool Rational::operator!=(const Rational& x) {
    return _zaehler * x._nenner != _nenner * x._zaehler;
}

