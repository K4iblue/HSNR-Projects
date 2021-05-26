// ===================================================================
// mystack.c (Stack realisiert als Linked List)
// ===================================================================

#include <stdlib.h>
#include <stdio.h>
#include "mystack.h"

// ===================================================================
struct node {
    // Wert speichern
    float value;

    // Zeiger auf nächste Position
    struct node* next;
};

struct mystack_s {
    // Top Position
    struct node* top;

    /// Speichert einen Fehler-Code für die zuletzt ausgeführte Operation
    char error;
};

// erzeugt einen leeren Stack
mystack_t* createStack() {

    // Speicher für stack reservieren
    mystack_t* stack = malloc(sizeof(struct mystack_s));

    // Fehlerbehandlung, falls speicher reservieren nicht klappt
    if (stack == NULL) {
        printf("Could not allocate enough memory for a new stack");
        return NULL;
    }
    
    // Stack variablen initialisieren
    stack->top = NULL;
    stack->error = OK;

    return stack;
};

// prüft, ob der Stack s leer ist
char isEmpty(mystack_t* stack) {
    if (stack->top == NULL) {
        return EMPTY_STACK;
    }
    else {
        return OK;
    }
};

// legt den Wert value auf den Stack s
void push(mystack_t* stack, float value) {
   
    // Speicher für element reservieren
    struct node* element = (struct node*)malloc(sizeof(struct node));

    // Fehlerbehandlung, falls speicher reservieren nicht klappt
    if (element == NULL) {
        printf("Could not allocate enough memory for a new element");
        return;
    }

    // Element Variablen initialisieren
    element->value = value;
    element->next = stack->top;
    stack->top = element;  
};

// liefert das zuletzt eingefügte Element des Stacks s
float top(mystack_t* stack) {

    // Fehlerbehandlung, falls Stack leer ist
    if (isEmpty(stack) == EMPTY_STACK) {
        stack->error = EMPTY_STACK;
        return 1;
    }

    return stack->top->value;
};

// entfernt das zuletzt eingefügte Element vom Stack s
float pop(mystack_t* stack) {
    
    // Fehlerbehandlung, falls Stack leer ist
    if (isEmpty(stack) == EMPTY_STACK) {
        stack->error = EMPTY_STACK;
    }

    // Aktuelles Top Element zwischenspeichern, damit es später entfernt werden kann
    struct node* toPop = stack->top;
    float value = toPop->value;
    
    // Neues Top Element setzen
    stack->top = toPop->next;

    // Speicher vom alten Top Element freigeben
    free(toPop);
    return value;
};

// liefert den Inhalt der Fehlervariablen
char getError(mystack_t* stack) {
    return(EMPTY_STACK);
};

// zerstört den Stack und gibt belegten Speicherplatz frei
void destroyStack(mystack_t* stack) {

    struct node* toDestroy = stack->top;

    // Solange der Stack noch nicht leer ist
    while ((toDestroy = stack->top) != NULL) {
        // Neues Top Element setzen
        stack->top = stack->top->next;

        // Speicher vom alten Top Element freigeben und Wert ausgeben
        free(toDestroy);
    }
    return;
};
