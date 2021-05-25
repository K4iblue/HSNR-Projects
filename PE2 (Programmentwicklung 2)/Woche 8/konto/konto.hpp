// *******************************************************************
// konto.h
// *******************************************************************

#ifndef _KONTO_HPP
#define _KONTO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "kontobewegung.hpp"

class Konto {
private:
    std::string inhaber, nr, pin;
    Datum letzteAenderung;
    int stand;
    std::vector<Kontobewegung> bewegungen;

public:
    Konto(std::string inhaber, std::string nr, std::string pin,
          int betrag, Datum d);
    ~Konto();
    void zahleEin(int betrag, Datum d,
                          std::string info = "Bareinzahlung");
    void hebeAb(int betrag, Datum d,
                        std::string info = "Barauszahlung");
    int kontostand();
    std::string kontoauszug(Datum d);
};

#endif

