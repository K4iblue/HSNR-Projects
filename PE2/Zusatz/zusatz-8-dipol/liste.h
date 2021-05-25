#ifndef _LISTE_H
#define _LISTE_H

// -------------------------------------------------------------------
template <typename T>
class Liste {
private:
    int _size;
    int _next;
    T *_values;

    bool isFull();
    int find(T value);
    void increase();
    void decrease();

public:
    Liste(int size = 8);
    Liste(const Liste& l);
    ~Liste();
    void append(T value);
    void erase(T value);
    T getValueAt(int pos);
    int size();

    T operator[](int pos);
    Liste& operator=(const Liste& l);
};

// -------------------------------------------------------------------
template <typename T>
Liste<T>::Liste(int size) : _size(size), _next(0), _values(new T[size]) {
}

// -------------------------------------------------------------------
template <typename T>
Liste<T>::Liste(const Liste& l) {
    _size = l._size;
    _next = l._next;
    _values = new T[_size];

    for (int i = 0; i < _next; i++)
        _values[i] = l._values[i];
}

// -------------------------------------------------------------------
template <typename T>
Liste<T>::~Liste() {
    delete[] _values;
}

// -------------------------------------------------------------------
template <typename T>
void Liste<T>::increase() {
    T *tmp = new T[_size * 2];

    for (int i = 0; i < _size; i++)
        tmp[i] = _values[i];

    delete[] _values;
    _values = tmp;
    _size *= 2;
}

// -------------------------------------------------------------------
template <typename T>
void Liste<T>::decrease() {
    _size /= 2;
    T *tmp = new T[_size];

    for (int i = 0; i < _size; i++)
        tmp[i] = _values[i];

    delete[] _values;
    _values = tmp;
}

// -------------------------------------------------------------------
template <typename T>
bool Liste<T>::isFull() {
    return _next == _size;
}

// -------------------------------------------------------------------
template <typename T>
int Liste<T>::find(T val) {
    int pos;

    for (pos = 0; pos < _next; pos++)
        if (_values[pos] == val)
            return pos;
    return -1;
}

// -------------------------------------------------------------------
template <typename T>
T Liste<T>::getValueAt(int pos) {
    if (pos < 0 || pos >= _next)
        throw "OutOfBoundsException";

    return _values[pos];
}

// -------------------------------------------------------------------
template <typename T>
void Liste<T>::append(T val) {
    if (isFull())
        increase();

    _values[_next] = val;
    _next += 1;
}

// -------------------------------------------------------------------
template <typename T>
void Liste<T>::erase(T val) {
    int pos = find(val);

    if (pos == -1)
        throw "ValueNotFoundException";

    for (; pos < _next -1; pos++)
        _values[pos] = _values[pos + 1];
    _next -= 1;

    if (_next < _size / 4)
        decrease();
}

// -------------------------------------------------------------------
template <typename T>
int Liste<T>::size() {
    return _next;
}

// -------------------------------------------------------------------
template <typename T>
T Liste<T>::operator[](int pos) {
    return getValueAt(pos);
}

// -------------------------------------------------------------------
template <typename T>
Liste<T>& Liste<T>::operator=(const Liste<T>& l) {
    if (this != &l) {
        delete[] _values;

        _size = l._size;
        _next = l._next;
        _values = new T[_size];

        for (int i = 0; i < _next; i++)
            _values[i] = l._values[i];
    }
    return *this;
}

#endif

