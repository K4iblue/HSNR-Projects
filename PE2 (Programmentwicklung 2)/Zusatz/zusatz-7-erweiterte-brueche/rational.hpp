#ifndef _RATIONAL_H
#define _RATIONAL_H

#include <iostream>

class Rational {
friend std::ostream& operator<<(std::ostream& os, const Rational& x) {
    os << x._zaehler << "/" << x._nenner;
    return os;
}

protected:
    int _zaehler, _nenner;

    Rational add(Rational x); // Addition
    Rational sub(Rational x); // Subtraktion
    Rational mul(Rational x); // Multiplikation
    Rational div(Rational x); // Division
    void kehrwert();
    void kuerzen();

public:
    Rational(int z = 1, int n = 1);
    Rational operator-(); // Vorzeichen
    Rational operator+(const Rational& x);
    Rational operator-(const Rational& x);
    Rational operator*(const Rational& x);
    Rational operator/(const Rational& x);

    bool operator<(const Rational& x);
    bool operator>(const Rational& x);
    bool operator==(const Rational& x);
    bool operator!=(const Rational& x);

    int getZaehler() const;
    int getNenner() const;
};

#endif

