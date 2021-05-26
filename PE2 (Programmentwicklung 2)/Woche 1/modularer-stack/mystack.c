// ===================================================================
// mystack.c (Stack realisiert mit dynamischen Array)
// ===================================================================

#include <stdlib.h>
#include "mystack.h"

// ===================================================================
struct mystack_s {
    // Top Position
    int* top;

    // Zeiger auf nächste Position
    int* next;

    // Wert speichern
    float value;

    /// Speichert einen Fehler-Code für die zuletzt ausgeführte Operation
    char error; // 'E' = Empty
};

// erzeugt einen leeren Stack
mystack_t* createStack() {

};

// prüft, ob der Stack s leer ist
char isEmpty(mystack_t* stack) {

};

// legt den Wert value auf den Stack s
void push(mystack_t* stack, float value) {

};

// liefert das zuletzt eingefügte Element des Stacks s
float top(mystack_t* stack) {

    // Fehlerbehandlung
    if (isEmpty(stack) == '-1') {
        stack->error = 'E';
        return 1;
    }
};

// entfernt das zuletzt eingefügte Element vom Stack s
void pop(mystack_t* stack) {
    
    // Fehlerbehandlung
    if (isEmpty(stack) == '-1') {
        stack->error = 'E';
        return 1;
    }
};

// liefert den Inhalt der Fehlervariablen
char getError(mystack_t* stack) {

};

// zerstört den Stack und gibt belegten Speicherplatz frei
void destroyStack(mystack_t* stack) {

};
