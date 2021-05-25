// ===================================================================
// heap.h
// ===================================================================

#ifndef _HEAP_H
#define _HEAP_H


// Konstanten --------------------------------------------------------
#define OK                0
#define DUPLICATE_VALUE   1
#define EMPTY_HEAP        2


// Vorwärtsdeklaration (unvollständiger Datentyp) --------------------
typedef struct heap_s heap_t;


// Schnittstelle -----------------------------------------------------
heap_t *createHeap();
void destroyHeap(heap_t *h);

char insert(heap_t *h, int val);
int minimum(heap_t *h);
char extractMin(heap_t *h);
char getError(heap_t *h);
void toString(heap_t *h, char *str, int maxlen);

#endif

