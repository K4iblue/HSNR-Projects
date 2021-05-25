// *******************************************************************
// test.cpp
// *******************************************************************

#include <iostream>
#include <sstream>
#include "complex.hpp"
using namespace std;

bool ok = true;

// *******************************************************************
bool test01() {
    Complex a(2, 3);
    Complex b(3, 4);
    Complex c = a + b;

    if (c.real() != 5.0 || c.imag() != 7.0)
        return !ok;

    Complex d(5.0, 7.0);
    if (c != d)
        return !ok;

    return ok;
}

// *******************************************************************
bool test02() {
    Complex a(2, 3);
    Complex b(3, 5);
    Complex c = a - b;

    if (c.real() != -1.0 || c.imag() != -2.0)
        return !ok;

    Complex d(-1.0, -2.0);
    if (c != d)
        return !ok;

    return ok;
}

// *******************************************************************
bool test03() {
    Complex a(2, 3);
    Complex b(3, 5);
    Complex c = a * b;

    if (c.real() != -9.0 || c.imag() != 19.0)
        return !ok;

    Complex d(-9.0, 19.0);
    if (c != d)
        return !ok;

    return ok;
}

// *******************************************************************
bool test04() {
    Complex a(2, 3);
    Complex b(3, 5);
    Complex c = a / b;

    if (c.real() != 21.0/34.0 || c.imag() != -1.0/34.0)
        return !ok;

    Complex d(21.0/34.0, -1.0/34.0);
    if (c != d)
        return !ok;

    return ok;
}

// *******************************************************************
bool test05() {
    Complex c;
    istringstream is("2.5 3.25");

    is >> c;
    if (c != Complex(2.5, 3.25))
        return !ok;

    ostringstream os;
    os << c;
    if (os.str() != "(2.5 + 3.25 * i)")
        return !ok;

    return ok;
}

// *******************************************************************
int main(void) {
    if (test01())
        cout << "test01() war erfolgreich\n";
    else cout << "!!! test01() ist fehlgeschlagen!!!\n";

    if (test02())
        cout << "test02() war erfolgreich\n";
    else cout << "!!! test02() ist fehlgeschlagen!!!\n";

    if (test03())
        cout << "test03() war erfolgreich\n";
    else cout << "!!! test03() ist fehlgeschlagen!!!\n";

    if (test04())
        cout << "test04() war erfolgreich\n";
    else cout << "!!! test04() ist fehlgeschlagen!!!\n";

    if (test05())
        cout << "test05() war erfolgreich\n";
    else cout << "!!! test05() ist fehlgeschlagen!!!\n";
}

