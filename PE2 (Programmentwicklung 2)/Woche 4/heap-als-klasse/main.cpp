// -------------------------------------------------------------------
// main.cpp   Zeiten der einzelnen Operationen messen
// -------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "myheap.hpp"
using namespace std;

const int Min = 1 << 15;
const int Max = 1 << 26;

int main(void) {
    cout << setw(20) << "increasing" << setw(20) << "decreasing"
         << setw(20) << "random" << endl;
    cout << setw(10) << "insert" << setw(10) << "extract"
         << setw(10) << "insert" << setw(10) << "extract"
         << setw(10) << "insert" << setw(10) << "extract" << endl;

    for (int n = Min; n <= Max; n *= 2) {
        Heap h(n);
        clock_t tic, toc, diff;

        // -----------------------------------------------------------
        tic = clock();
        for (int i = 0; i < n; i++)
            h.insert(i);
        toc = clock();
        diff = (toc - tic) * 1000;
        cout << setw(7) << diff / CLOCKS_PER_SEC << " ms" << flush;

        tic = clock();
        for (int i = 0; i < n; i++)
            h.extractMin();
        toc = clock();
        diff = (toc - tic) * 1000;
        cout << setw(7) << diff / CLOCKS_PER_SEC << " ms" << flush;

        // -----------------------------------------------------------
        tic = clock();
        for (int i = 0; i < n; i++)
            h.insert(n - i);
        toc = clock();
        diff = (toc - tic) * 1000;
        cout << setw(7) << diff / CLOCKS_PER_SEC << " ms" << flush;

        tic = clock();
        for (int i = 0; i < n; i++)
            h.extractMin();
        toc = clock();
        diff = (toc - tic) * 1000;
        cout << setw(7) << diff / CLOCKS_PER_SEC << " ms" << flush;

        // -----------------------------------------------------------
        tic = clock();
        for (int i = 0; i < n; i++)
            h.insert(rand());
        toc = clock();
        diff = (toc - tic) * 1000;
        cout << setw(7) << diff / CLOCKS_PER_SEC << " ms" << flush;

        tic = clock();
        for (int i = 0; i < n; i++)
            h.extractMin();
        toc = clock();
        diff = (toc - tic) * 1000;
        cout << setw(7) << diff / CLOCKS_PER_SEC << " ms" << endl;
    }
}

