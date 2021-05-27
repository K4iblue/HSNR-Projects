// -------------------------------------------------------------------
// mystack.h
// -------------------------------------------------------------------

#ifndef _MYSTACK_H
#define _MYSTACK_H

// Konstanten --------------------------------------------------------
#define OK                0
#define EMPTY_STACK       3
#define ALLOC_ERROR      12


class Stack {
private:
    int _top;
    float* _values;
    char _error;

public:
    // Konstruktor
    Stack();
    // Dekonstruktor
    ~Stack();

    // Methoden
    bool isEmpty();
    void push(float value);
    float top();
    float pop();
    char getError();        
};


#endif

