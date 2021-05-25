// *******************************************************************
// test.cpp
// *******************************************************************

#include <iostream>
#include "konto.hpp"
#include "sparkonto.hpp"
#include "girokonto.hpp"
using namespace std;

const bool OK = true;

// *******************************************************************
bool test01() {
    Datum d1(1, 1, 2021);
    Konto k("Huber", "4711", "0815", 123, d1);

    if (k.kontostand() != 123)
        return !OK;

    Datum d2(30, 1, 2021);
    k.hebeAb(123, d2);

    if (k.kontostand() != 0)
        return !OK;

    Datum d3(1, 3, 2021);
    k.hebeAb(123, d3);

    if (k.kontostand() != -123)
        return !OK;

    Datum d4(1, 4, 2021);
    k.zahleEin(123, d4);

    if (k.kontostand() != 0)
        return !OK;

    Datum d5(1, 9, 2021);
    if (k.kontoauszug(d5) !=
            "Kontoauszug fuer Kontonummer 4711 (Huber) am 1.9.2021\n"
            "30.1.2021: Barauszahlung -123\n"
            "1.3.2021: Barauszahlung -123\n"
            "1.4.2021: Bareinzahlung 123\n")
        return !OK;
    return OK;
}

/*
// *******************************************************************
bool test02() {
    Datum d1(1, 1, 2021);
    Sparkonto sk("Meyer", "1234", "7654", 100, 0.1, d1);

    if (sk.kontostand() != 100)
        return !OK;

    Datum d2(30, 1, 2021);
    try {
        sk.hebeAb(123, d2);
        return !OK;
    } catch (const char *e) {}

    if (sk.kontostand() != 100)
        return !OK;

    Datum d3(1, 3, 2021);
    sk.zahleEin(100, d3);

    if (sk.kontostand() != 200)
        return !OK;

    Datum d4(1, 4, 2021);
    sk.zinsgutschrift(d4);
    if (sk.kontostand() != 202)
        return !OK;

    Datum d5(1, 9, 2021);
    if (sk.kontoauszug(d5) !=
            "Kontoauszug fuer Kontonummer 1234 (Meyer) am 1.9.2021\n"
            "1.3.2021: Bareinzahlung 100\n")
        return !OK;
    return OK;
}

// *******************************************************************
bool test03() {
    Datum d1(1, 1, 2021);
    Girokonto gk("Fischer", "2324", "1987", 100, 200, 0.2, d1);

    if (gk.kontostand() != 100)
        return !OK;
    if (gk.getDispo() != 200)
        return !OK;

    Datum d2(30, 1, 2021);
    try {
        gk.hebeAb(200, d2);
    } catch (const char *e) {
        return !OK;
    }
    if (gk.kontostand() != -100)
        return !OK;

    try {
        gk.hebeAb(200, d2);
        return !OK;
    } catch (const char *e) {}
    if (gk.kontostand() != -100)
        return !OK;

    Datum d3(1, 3, 2021);
    gk.zahleEin(300, d3);
    if (gk.kontostand() != 200)
        return !OK;

    Datum d4(1, 4, 2021);
    gk.zinsgutschrift(d4);
    if (gk.kontostand() != 199)
        return !OK;

    Datum d5(1, 9, 2021);
    if (gk.kontoauszug(d5) !=
            "Kontoauszug fuer Kontonummer 2324 (Fischer) am 1.9.2021\n"
            "30.1.2021: Barauszahlung -200\n"
            "1.3.2021: Bareinzahlung 300\n")
        return !OK;
    return OK;
}

// *******************************************************************
bool test04() {
    Datum d1(1, 1, 2021);
    Girokonto gk1("Fischer", "2324", "1987", 100, 200, 0.2, d1);

    Datum d2(5, 9, 2020);
    Girokonto gk2("Meier", "1516", "1983", 300, 200, 0.3, d2);

    Datum d3(31, 1, 2021);
    gk1.ueberweise(-100, d3, "Rechnungsnummer 4711");
    gk2.ueberweise(+100, d3, "Rechnungsnummer 4711");

    if (gk1.kontostand() != 0 || gk2.kontostand() != 400)
        return !OK;

    Datum d4(1, 3, 2021);
    try {
        // Die Bank stellt sicher, dass beide Kontobewegungen stattfinden,
        // oder keine von beiden. Ist das Konto, von dem abgebucht wird,
        // nicht gedeckt, wird direkt in die Fehlerbehandlung verzweigt.
        gk1.ueberweise(-300, d3, "Rechnungsnummer 4711");
        gk2.ueberweise(+300, d3, "Rechnungsnummer 4711");
        return !OK;
    } catch (const char *e) {}

    if (gk1.kontostand() != 0 || gk2.kontostand() != 400)
        return !OK;
    return OK;
}
*/

// *******************************************************************
int main(void) {
    if (test01() == OK)   // Konto
        cout << "test01 war erfolgreich\n";
    else cout << "!!! test01 ist fehlgeschlagen !!!\n";

    /*
    if (test02() == OK)   // Spar-Konto
        cout << "test02 war erfolgreich\n";
    else cout << "!!! test02 ist fehlgeschlagen !!!\n";

    if (test03() == OK)   // Giro-Konto
        cout << "test03 war erfolgreich\n";
    else cout << "!!! test03 ist fehlgeschlagen !!!\n";

    if (test04() == OK)   // Giro-Konto: ueberweisen
        cout << "test04 war erfolgreich\n";
    else cout << "!!! test04 ist fehlgeschlagen !!!\n";
     */

    return 0;
}

