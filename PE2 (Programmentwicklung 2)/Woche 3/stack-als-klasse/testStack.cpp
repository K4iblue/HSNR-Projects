#include <iostream>
#include "mystack.hpp"
using namespace std;

//********************************************************************
bool test01() {
    Stack s;

    if (s.isEmpty())
        return true;
    return false;
}

//********************************************************************
bool test02() {
    Stack s;

    s.push(42);
    if (s.isEmpty())
        return false;
    return true;
}

//********************************************************************
bool test03() {
    Stack s;

    s.push(42);
    s.pop();
    if (s.isEmpty())
        return true;
    return false;
}

//********************************************************************
bool test04() {
    Stack s;
    float erg;

    s.push(42.25);
    erg = s.top();
    if (erg == 42.25)
        return true;
    return false;
}

//********************************************************************
bool test05() {
    Stack s;
    bool res = true;
    int val;

    for (int i = 1; i < 30; i++)
        s.push(i);

    for (int i = 29; i > 0 && res; i--) {
        val = s.top();
        if (val != i)
            res = false;
        s.pop();
    }

    return res;
}

//********************************************************************
bool test06() {
    Stack s;
    bool res = false;

    s.top();
    if( s.getError() == EMPTY_STACK )
        res = true;

    return res;
}

//********************************************************************
bool test07() {
    Stack s;
    bool res = false;

    s.pop();
    if( s.getError() == EMPTY_STACK ) {
        res = true;
    }

    return res;
}

//********************************************************************
int Testmain(void) {
    bool ok = true;

    if (ok) {
        if (true == (ok = test01()))
            cout << "Test01 passed\n";
        else cout << "!!! Test01 failed !!!\n";
    }

    if (ok) {
        if (true == (ok = test02()))
            cout << "Test02 passed\n";
        else cout << "!!! Test02 failed !!!\n";
    }

    if (ok) {
        if (true == (ok = test03()))
            cout << "Test03 passed\n";
        else cout << "!!! Test03 failed !!!\n";
    }

    if (ok) {
        if (true == (ok = test04()))
            cout << "Test04 passed\n";
        else cout << "!!! Test04 failed !!!\n";
    }

    if (ok) {
        if (true == (ok = test05()))
            cout << "Test05 passed\n";
        else cout << "!!! Test05 failed !!!\n";
    }

    if (ok) {
        if (true == (ok = test06()))
            cout << "Test06 passed\n";
        else cout << "!!! Test06 failed !!!\n";
    }

    if (ok) {
        if (true == (ok = test07()))
            cout << "Test07 passed\n";
        else cout << "!!! Test07 failed !!!\n";
    }

    if (ok)
        cout << "\nTest passed\n";
    else cout << "\n!!! Test failed !!!\n";

    system("Pause");

    return 0;
}

