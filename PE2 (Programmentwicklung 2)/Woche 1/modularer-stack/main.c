// ===================================================================
// Arithmetischen Ausdruck (gegeben in UPN) bewerten
// ===================================================================

#include "mystack.h"
#include <stdio.h>  // Benötigt für Input
#include <stdlib.h>

// ===================================================================
int main(void) {
    
    // Stack erstellen
    mystack_t *stack = createStack();

    // User Input
    char input[64];
    printf("Bitte geben sie einen Term in umgekehrter polnischer notation(UNP) ein: \n");
    fgets(input, sizeof(input), stdin);
    printf("Ihre Eingabe: %s \n", input);

    // Hilfsvariable für negative zahlen
    int negative = 0;

    // Schleife über die gesamt länge des Strings
    for (int i = 0; input[i] != '\n' && i < 64; i++) {

        // Hilfsvariablen
        float temp;
        float tempPush;
        
        switch (input[i]) {
            case '+':   // Addition
                push(stack, pop(stack) + pop(stack));
                break;

            case '-':   // Subtraktion
                // Wenn nach einem minus symbol kein leerzeichen folgt, kommt eine negative zahl
                if (input[i + 1] != ' ') {
                    negative = 1;
                }
                else {
                    temp = pop(stack);
                    push(stack, pop(stack) - temp);
                }
                break;

            case '/':   // Division
                temp = pop(stack);
                push(stack, pop(stack) / temp);
                break;

            case '*':   // Multiplikation
                push(stack, pop(stack) * pop(stack));
                break;

            case ' ':   // Leerzeichen
                break;

            // Wert auf Stack ablegen
            default:
                // Char zu Float konvertieren
                tempPush = input[i] - '0';

                // Falls negative, müssen wir *(-1) machen
                if (negative) {
                    tempPush *= (-1);
                    negative = 0;
                }
                push(stack, tempPush);
                break;
        }
    }

    // Ergebnis ausgeben und Stack zerstören
    printf("Ergebnis: %f \n", top(stack));
    system("Pause");
    //destroyStack(stack);
    return 0;
}

