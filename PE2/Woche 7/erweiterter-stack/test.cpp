#include <iostream>
#include "mystack.hpp"
#include "extstack.hpp"
using namespace std;

const bool OK = true;

//********************************************************************
bool test01() {
    Stack s;

    if (s.isEmpty())
        return OK;
    return not OK;
}

//********************************************************************
bool test02() {
    Stack s;

    s.push(4.25);
    if (s.isEmpty())
        return not OK;
    return OK;
}

//********************************************************************
bool test03() {
    Stack s;

    s.push(4.25);
    s.pop();
    if (s.isEmpty())
        return OK;
    return not OK;
}

//********************************************************************
bool test04() {
    Stack s;
    double erg;

    s.push(42.25);
    erg = s.top();
    if (erg == 42.25)
        return OK;
    return not OK;
}

//********************************************************************
bool test05() {
    Stack s;
    bool res = OK;
    double val;

    for (int i = 1; i < 30; i++)
        s.push(i);

    for (int i = 29; i > 0 && res; i--) {
        val = s.top();
        if (val != i)
            res = not OK;
        s.pop();
    }

    return res;
}

//********************************************************************
bool test06() {
    Stack s;
    bool res = not OK;

    try {
        s.top();
    } catch (runtime_error& e) {
        res = OK;
    }

    return res;
}

//********************************************************************
bool test07() {
    Stack s;
    bool res = not OK;

    try {
        s.pop();
    } catch (runtime_error& e) {
        res = OK;
    }

    return res;
}

//********************************************************************
int main(void) {
    if (OK == test01())
        cout << "Test01 passed\n";
    else cout << "!!! Test01 failed !!!\n";

    if (OK == test02())
        cout << "Test02 passed\n";
    else cout << "!!! Test02 failed !!!\n";

    if (OK == test03())
        cout << "Test03 passed\n";
    else cout << "!!! Test03 failed !!!\n";

    if (OK == test04())
        cout << "Test04 passed\n";
    else cout << "!!! Test04 failed !!!\n";

    if (OK == test05())
        cout << "Test05 passed\n";
    else cout << "!!! Test05 failed !!!\n";

    if (OK == test06())
        cout << "Test06 passed\n";
    else cout << "!!! Test06 failed !!!\n";

    if (OK == test07())
        cout << "Test07 passed\n";
    else cout << "!!! Test07 failed !!!\n";

}

