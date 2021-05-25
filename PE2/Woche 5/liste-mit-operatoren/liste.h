// ===================================================================
// liste.h
// ===================================================================
#ifndef _LISTE_H
#define _LISTE_H

#include <iostream>

class Liste {
    friend std::ostream& operator<<(std::ostream& os, Liste& l);
    friend std::istream& operator>>(std::istream& is, Liste& l);

private:
    int _size, _next, *_values;

    bool isFull();
    int find(int value);
    void realloc(int nsize);
    void increase();
    void decrease();

public:
    Liste(int size = 8);
    Liste(const Liste& l);
    ~Liste();

    void append(int value);
    int getValueAt(int pos);
    void erase(int value);

    int operator[](int pos);
    Liste operator+(const Liste& l);
    Liste& operator=(const Liste& l);
    bool operator==(const Liste& l);
    bool operator!=(const Liste& l);
};

#endif

