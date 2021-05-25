#ifndef _STACK_H
#define _STACK_H

class Stack {
protected:
    double *_values;
    int _size, _next;

    bool isFull();
    void increase();

public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(double value);
    double top();
    void pop();
};

#endif

