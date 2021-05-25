// *******************************************************************
// test.cpp
// *******************************************************************

#include <iostream>
#include "complex.hpp"
using namespace std;

bool ok = true;

// *******************************************************************
bool test01() {
    Complex a(2, 3);
    Complex b(3, 4);
    Complex c = a.add(b);

    if (c.real() != 5.0 || c.imag() != 7.0)
        return !ok;
    return ok;
}

// *******************************************************************
bool test02() {
    Complex a(2, 3);
    Complex b(3, 5);
    Complex c = a.sub(b);

    if (c.real() != -1.0 || c.imag() != -2.0)
        return !ok;
    return ok;
}

// *******************************************************************
bool test03() {
    Complex a(2, 3);
    Complex b(3, 5);
    Complex c = a.mul(b);

    if (c.real() != -9.0 || c.imag() != 19.0)
        return !ok;
    return ok;
}

// *******************************************************************
bool test04() {
    Complex a(2, 3);
    Complex b(3, 5);
    Complex c = a.div(b);

    if (c.real() != 21.0/34.0 || c.imag() != -1.0/34.0)
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

    return 0;
}

