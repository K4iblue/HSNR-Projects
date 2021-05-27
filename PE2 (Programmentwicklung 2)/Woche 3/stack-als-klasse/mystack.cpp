// ===================================================================
// mystack.cpp (Stack realisiert mit dynamischen Array)
// ===================================================================

#include <stdlib.h>
#include "mystack.hpp"

Stack::Stack() {
	_top = -1;
	_error = EMPTY_STACK;
};

Stack::~Stack() {
	delete[] _values;
};

bool Stack::isEmpty() {
	if (top == NULL) {
		return true;
	}
	return false;
};

void Stack::push(float value) {

};

float Stack:: top() {

};

float Stack::pop() {

};

char Stack::getError() {

};