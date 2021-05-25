#include <stdexcept>
#include "mystack.hpp"

// -------------------------------------------------------------------
Stack::Stack() {
    _next = 0;
    _size = 8;
    _values = new double[_size];
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
    double *t = new double[_size * 2];
    for (int i = 0; i < _size; i++)
        t[i] = _values[i];
    _size *= 2;
    delete[] _values;
    _values = t;
}

// -------------------------------------------------------------------
void Stack::push(double value) {
    if (isFull())
        increase();

    _values[_next] = value;
    _next += 1;
}

// -------------------------------------------------------------------
double Stack::top() {
    if (isEmpty())
        throw std::runtime_error("empty stack exception");
    return _values[_next - 1];
}

// -------------------------------------------------------------------
void Stack::pop() {
    if (isEmpty())
        throw std::runtime_error("empty stack exception");
    _next -= 1;
}

