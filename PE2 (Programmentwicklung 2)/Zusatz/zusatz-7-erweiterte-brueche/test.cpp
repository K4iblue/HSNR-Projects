#include <iostream>
#include "rational.hpp"
#include "extrational.hpp"
using namespace std;

const bool OK = true;

// -------------------------------------------------------------------
bool test01() {
    Rational a(1, 2);
    Rational b(2, 3);
    Rational c = a + b;

    if (c != Rational(7, 6))
        return not OK;
    return OK;
}

// -------------------------------------------------------------------
bool test02() {
    Rational a(1, 2);
    Rational b(2, 3);
    Rational c = a - b;

    if (c != Rational(-1, 6))
        return not OK;
    return OK;
}

// -------------------------------------------------------------------
bool test03() {
    Rational a(1, 2);
    Rational b(2, 3);
    Rational c = a * b;

    if (c != Rational(1, 3))
        return not OK;
    return OK;
}

// -------------------------------------------------------------------
bool test04() {
    Rational a(1, 2);
    Rational b(2, 3);
    Rational c = a / b;

    if (c != Rational(3, 4))
        return not OK;
    return OK;
}



// -------------------------------------------------------------------
int main(void) {
    if (OK == test01())
        cout << "test01 passed" << endl;
    else cout << "!!! test01 failed !!!" << endl;

    if (OK == test02())
        cout << "test02 passed" << endl;
    else cout << "!!! test02 failed !!!" << endl;

    if (OK == test03())
        cout << "test03 passed" << endl;
    else cout << "!!! test03 failed !!!" << endl;

    if (OK == test04())
        cout << "test04 passed" << endl;
    else cout << "!!! test04 failed !!!" << endl;

} 
