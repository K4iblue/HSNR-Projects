#ifndef _LLIST_H
#define _LLIST_H

// incomplete data type  or  forward declaration
typedef struct llist_s llist_t;

// public interface
llist_t *create(void);
void append(llist_t *l, int val);
int getValueAt (llist_t *l, int pos);
void erase(llist_t *l, int val);
void toScreen(llist_t * l);
char getError(llist_t * l);
void destroy(llist_t * l);

// errors
#define OUT_OF_BOUNDS 1
#define NOT_FOUND 2

#endif

