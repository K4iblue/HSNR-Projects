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
        float wert = atof(token);

        if (wert != 0)
            s.push( wert );
        else {
            double x, y;

            y = s.top();
            s.pop();
            x = s.top();
            s.pop();

            if (strcmp(token, "+") == 0)
                s.push(x + y);
            else if (strcmp(token, "-") == 0)
                s.push(x - y);
            else if (strcmp(token, "*") == 0)
                s.push(x * y);
            else if (strcmp(token, "/") == 0)
                s.push(x / y);
            else return 1;
        }

        token = strtok(NULL, " ");
    }
    cout << "\nErgebnis: " << s.top() << endl;

    return 0;
}

