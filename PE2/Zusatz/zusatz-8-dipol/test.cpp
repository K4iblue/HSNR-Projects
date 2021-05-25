// *******************************************************************
// test.cpp
// *******************************************************************

#include <iostream>
#include "dipol.hpp"
using namespace std;

bool ok = true;

// *******************************************************************
bool test01() {
    Resistor r1(200);
    Resistor r2(200);

    Parallel p;
    p.append(&r1);
    p.append(&r2);

    if (p.impedance() != complex<double>(100, 0))
        return not ok;

    Serial s;
    s.append(&r1);
    s.append(&r2);

    if (s.impedance() != complex<double>(400, 0))
        return not ok;

    return ok;
}

// *******************************************************************
bool test02() {
    Resistor r1(100);
    Resistor r2(200);
    Inductor l(0.1, 1000);

    Serial s;
    s.append(&r1);
    s.append(&l);

    Parallel p;
    p.append(&s);
    p.append(&r2);

    if (p.impedance() != complex<double>(80, 40))
        return not ok;

    return ok;
}

// *******************************************************************
bool test03() {
    Resistor r(100);
    Inductor l(0.2, 1000);
    Capacitor c(2e-6, 1000);

    Serial s;
    s.append(&r);
    s.append(&l);

    Parallel p;
    p.append(&s);
    p.append(&c);

    if (p.impedance() != complex<double>(250, 250))
        return not ok;

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
}

