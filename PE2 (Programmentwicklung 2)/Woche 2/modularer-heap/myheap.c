// ===================================================================
// Minheap
// heap.c
// ===================================================================



#include <stdio.h>
#include <stdlib.h>
#include "myheap.h"

void swap(heap_t* h, int pos1, int pos2);
void heapify(heap_t* h, int size, int index);

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
	h->values = (int*)malloc(sizeof(int) * h->capacity);
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
		h->values = (int*)realloc(h->values, h->capacity * sizeof(int));
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

	// Falls Heap leer ist, Fehlerbehandlung
	if (h->size <= 0) {
		h->error = EMPTY_HEAP;
		return -1;
	}

	// Root Element ist immer das kleinste Element
	return h->values[0];
};

char extractMin(heap_t* h) {
	// Falls Heap leer ist, Fehlerbehandlung
	if (h->size <= 0) {
		h->error = EMPTY_HEAP;
		return -1;
	}

	// Wenn der Heap nur einen Wert hat
	if (h->size == 1) {
		h->size--;
		return h->values[0];
	}

	// kleinsten Wert speichern
	int root = h->values[0];
	h->values[0] = h->values[h->size-1];
	h->size--;
	heapify(h, h->size, 0);

	return root;
};

char getError(heap_t* h) {
	return h->error;
};

void toString(heap_t* h, char* str, int maxlen) {
	//char* string = (char*)malloc(sizeof(maxlen*2));

	for (int i = 0; i < h->size; i++) {
		char tmp[2];

		if (i > 0) {
			str[maxlen] = ',';
			str[maxlen + 1] = ' ';
			str[maxlen + 2] = '\0';
		}
		sprintf(tmp, "%d", h->values[i]);
	}

	//return string;
};

// Um die Heap Bedingungen immer zu erfüllen brauchen wir zwei Hilfsfunktionen:
// Swap: tauscht die Position von zwei werten
// Heapify: stellt die Heap Bedingungen mithilfe der Swap Funktion wieder her

void swap(heap_t* h, int pos1, int pos2) {
	int temp = h->values[pos1];
	h->values[pos1] = h->values[pos2];
	h->values[pos2] = temp;
};

// Great resource: https://www.geeksforgeeks.org/binary-heap/
void heapify(heap_t* h, int size, int index) {

	// Root Element
	int smallest = index;	
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;

	// leftChild ist kleiner als smallest
	if (leftChild < size && h->values[leftChild] > h->values[smallest]) {
		smallest = leftChild;
	}

	// rightChild ist kleiner als smallest
	if (rightChild < size && h->values[rightChild] > h->values[smallest]) {
		smallest = rightChild;
	}

	// Position der Werte wechseln und funktion erneut aufrufen
	if (smallest != index) {
		swap(h, index, smallest);
		heapify(h, size, smallest);
	}
};