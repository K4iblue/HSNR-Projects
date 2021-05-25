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
        float *_values;
        int _size, _next;
        char error;

        bool isFull();
        void increase();

        public:
        Stack();
        ~Stack();
        bool isEmpty();
        void push(float value);
        float top();
        void pop();
        int getError();
};


#endif

