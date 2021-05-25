// ===================================================================
// liste.cpp
// ===================================================================
#include "liste.h"
using namespace std;

// ===================================================================
Liste::Liste(int size) {
    _size = size;
    _next = 0;
    _values = new int[size];
}

// ===================================================================
Liste::Liste(const Liste& l) {
    _size = l._size;
    _next = l._next;
    _values = new int[_size];

    for (int i = 0; i < _next; i++)
        _values[i] = l._values[i];
}

// ===================================================================
Liste::~Liste() {
    delete[] _values;
}

// ===================================================================
void Liste::realloc(int nsize) {
    int *tmp = new int[nsize];

    for (int i = 0; i < _next; i++)
        tmp[i] = _values[i];

    delete[] _values;
    _values = tmp;
}

// ===================================================================
void Liste::increase() {
    _size *= 2;
    realloc(_size);
}

// ===================================================================
void Liste::decrease() {
    _size /= 2;
    realloc(_size);
}

// ===================================================================
bool Liste::isFull() {
    return _next == _size;
}

// ===================================================================
int Liste::find(int val) {
    for (int pos = 0; pos < _next; pos++)
        if (_values[pos] == val)
            return pos;
    return -1;
}

// ===================================================================
int Liste::getValueAt(int pos) {
    if (pos < 0 || pos >= _next)
        throw "OutOfBoundsException";

    return _values[pos];
}

// ===================================================================
void Liste::append(int val) {
    if (isFull())
        increase();

    _values[_next] = val;
    _next += 1;
}

// ===================================================================
void Liste::erase(int val) {
    int pos = find(val);

    if (pos == -1)
        throw "ValueNotFoundException";

    for (; pos < _next -1; pos++)
        _values[pos] = _values[pos + 1];
    _next -= 1;

    if (_next < _size / 4)  // literarische Programmierung ???
        decrease();
}
