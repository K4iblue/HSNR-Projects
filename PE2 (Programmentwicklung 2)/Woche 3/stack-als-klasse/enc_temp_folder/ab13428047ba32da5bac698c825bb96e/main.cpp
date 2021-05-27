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

    token = strtok(ausdruck, " ");
    while (token != NULL) {
        printf("%s \n", token);

        // Falls der Token ein Operator ist
        if (token == "+" || "-" || "*" || "/") {
            cout << "Klappt" << endl;
        }
        float wert = atof(token);

        token = strtok(NULL, " ");
    }


    system("Pause");
    return 0;
}
