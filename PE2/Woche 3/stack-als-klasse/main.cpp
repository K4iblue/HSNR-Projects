//********************************************************************
//  main.cpp ::: Auswerten arithmetischer Ausdruecke in UPN
//     (12 + 9) * 7 - 3 * 21 + 18 / 2 ==
//          12  9 + 7 * 3  21 * - 18  2 / +  ==  93
//
//  !!! Ohne Fehlerbehandlung !!!
//********************************************************************

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "mystack.hpp"
using namespace std;

// -------------------------------------------------------------------
int main(void) {
    char ausdruck[] = "20 1 2 + 3 * -";
    char *token;
    Stack s;

    // TODO

    token = strtok(ausdruck, " ");
    while (token != NULL) {
        float wert = atof(token);

        token = strtok(NULL, " ");
    }

    return 0;
}

