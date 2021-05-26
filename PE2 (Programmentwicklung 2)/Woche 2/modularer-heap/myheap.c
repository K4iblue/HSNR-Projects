// ===================================================================
// heap.c
// ===================================================================

#include "myheap.h"
#include <stdio.h>
#include <stdlib.h>

struct heap_s {
	// Pointer zum Heap Array
	int *values;

	// Wie viele Elemente in den Heap passen
	int capacity;

	// Wie viele Elemente sich gerade im Heap befinden
	int size;

	// Indexvariable
	int index;

	// Fehlervariable
	char error;
};

heap_t* createHeap() {
	
	// Speicher für Heap reservieren, calloc setzt den reservierten speicher auf Nullen
	heap_t* h = calloc(1, sizeof(heap_t));

	// Fehlerbehandlung
	if (h == NULL) {
		printf("Could not allocate enough memory for a new stack");
		return NULL;
	}

	// Heap Variablen initialisieren
	h->values = (int *) malloc(sizeof(int)*h->capacity);
	h->capacity = 50;
	h->size = 0;
	h->index = 0;
	h->error = EMPTY_HEAP;

	return h;
};

void destroyHeap(heap_t* h) {
	// Zuerst werden die Values freigegeben
	free(h->values);

	// Dann der restliche Heap
	free(h);
};

char insert(heap_t* h, int val) {

	// Falls der heap keine kapaziät mehr hat, muss dieser zuerst vergrößert werden,
	if (h->size == h->capacity) {
		h->capacity *= 2;
		h->values = (int*) realloc(h->values, h->capacity * sizeof(int));
	}

	// Falls heap noch leer ist
	if (h->size == 0) {
		h->values[0] = val;
		h->size++;
		h->error = OK;
		return h->error;
	}

	// Element am Ende einfügen
	h->values[h->size] = val;
	h->size++;
	h->error = OK;

	return h->error;
};

int minimum(heap_t* h) {

	// Fehlerbehandlung
	if (h->size <= 0) {
		h->error = EMPTY_HEAP;
		return -1;
	}

	return h->values[0];
};

char extractMin(heap_t* h) {

};

char getError(heap_t* h) {
	return h->error;
};

void toString(heap_t* h, char* str, int maxlen) {

};

// Um die Heap Bedingungen immer zu erfüllen brauchen wir zwei Hilfsfunktionen:
// Swap: tauscht die Position von zwei werten
// Heapify: stellt die Heap Bedingungen mithilfe der Swap Funktion wieder her

void swap(heap_t* h, int pos1, int pos2) {
	int temp = h->values[pos1];
	h->values[pos1] = h->values[pos2];
	h->values[pos2] = temp;
};

void heapify(heap_t* h, int size, int index) {

};