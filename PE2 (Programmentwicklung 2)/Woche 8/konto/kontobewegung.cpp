// *******************************************************************
// kontobewegung.cpp
// *******************************************************************

#include "kontobewegung.hpp"

Kontobewegung::Kontobewegung(Datum tag, int betrag, std::string info) {
    this->tag = tag;
    this->betrag = betrag;
    this->info = info;
}

