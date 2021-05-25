// ===================================================================
// mystack.cpp (Stack realisiert mit dynamischen Array)
// ===================================================================

#include <stdlib.h>
#include "mystack.hpp"

// -------------------------------------------------------------------
Stack::Stack() {
    _next = 0;
    _size = 8;
    _values = new float[_size];
}

// -------------------------------------------------------------------
Stack::~Stack() {
    delete[] _values;
}

// -------------------------------------------------------------------
bool Stack::isEmpty() {
    return _next == 0;
}

// -------------------------------------------------------------------
bool Stack::isFull() {
    return _next == _size;
}

// -------------------------------------------------------------------
void Stack::increase() {
    float *t = new float[_size * 2];
    for (int i = 0; i < _size; i++)
        t[i] = _values[i];
    _size *= 2;
    delete[] _values;
    _values = t;
}

// -------------------------------------------------------------------
void Stack::push(float value) {
    if (isFull())
        increase();

    _values[_next] = value;
    _next += 1;
}

// -------------------------------------------------------------------
float Stack::top() {
    if (isEmpty()) {
        error = EMPTY_STACK;
        return 0;
    }
    error = OK;
    return _values[_next - 1];
}

// -------------------------------------------------------------------
void Stack::pop() {
    if (isEmpty()) {
        error = EMPTY_STACK;
        return;
    }
    error = OK;
    _next -= 1;
}

int Stack::getError() {
    return error;
}
