// ===================================================================
// mystack.cpp (Stack realisiert mit dynamischen Array)
// ===================================================================

#include <iostream>
#include <stdlib.h>
#include "mystack.hpp"

using namespace std;

// Konstruktor
Stack::Stack() {
	// Stack initialisieren
	_top = -1;
	_error = EMPTY_STACK;

	// Speicher für 50 Floats reservieren
	_values = new float [50];	
};


// Dekonstruktor
Stack::~Stack() {
	// Stack löschen
	delete[] _values;
};


// Checkt ob Stack leer ist
bool Stack::isEmpty() {
	if (_top == -1) {
		return true;
	}
	return false;
};


// Legt den Wert (value) auf den Stack
void Stack::push(float value) {
	_top++;
	_values[_top] = value;
	_error = OK;
};


// Gibt den obersten Wert vom Stack zurück
float Stack::top() {
	if (!isEmpty()) {
		return _values[_top];
	}
	else {
		_error = EMPTY_STACK;
		// cout << "Stack is Empty!" << endl; // Debugging
		return EMPTY_STACK;
	}
};


// Entfernt den "obersten" Wert vom Stack
float Stack::pop() {
	if (!isEmpty()) {
		return _values[_top--];
	}
	else {
		_error = EMPTY_STACK;
		cout << "Stack is Empty!" << endl;
		return EMPTY_STACK;
	}
};


char Stack::getError() {
	return _error;
};