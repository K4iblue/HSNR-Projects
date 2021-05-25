// ===================================================================
// test.cpp
// ===================================================================
#include <iostream>
#include <sstream>
using namespace std;

#include "liste.h"
const bool OK = true;

// Black-Box Test: append ============================================
bool test01(void) {
    Liste l(4);

    l.append(1);
    if (l.getValueAt(0) != 1)
        return !OK;

    try {       // Kein weiterer Wert vorhanden?
        l.getValueAt(1);
    } catch (const char *e) {
        return OK;
    }
    return !OK;
}

// Black-Box Test: erase =============================================
bool test02(void) {
    Liste l(4);

    l.append(1);
    try {       // Wird der Wert gefunden?
        l.erase(1);   // ... und entfernt?
    } catch (const char *e) {
        return !OK;
    }
    try {       // Wert wirklich entfernt?
        l.getValueAt(0);
    } catch (const char *e) {
        return OK;
    }
    return !OK;
}

// White-Box Test: increase ==========================================
bool test03(void) {
    Liste l(4);

    for (int i = 0; i < 50; i++)
        l.append(i);

    for (int i = 0; i < 50; i++)
        if (l.getValueAt(i) != i)
            return !OK;
    return OK;
}



// ===================================================================
int main(void) {
    if (OK == test01())
        cout << "test01 passed\n";
    else cout << "!!! test01 failed !!!\n";

    if (OK == test02())
        cout << "test02 passed\n";
    else cout << "!!! test02 failed !!!\n";

    if (OK == test03())
        cout << "test03 passed\n";
    else cout << "!!! test03 failed !!!\n";

    // TODO: mehr Tests

}

