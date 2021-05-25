// *******************************************************************
// kontobewegung.h
// *******************************************************************

#ifndef _KONTOBEWEGUNG_HPP
#define _KONTOBEWEGUNG_HPP

#include "datum.hpp"

struct Kontobewegung {
    Datum tag;
    int betrag;
    std::string info;

    Kontobewegung(Datum tag, int betrag, std::string info);
};

#endif

