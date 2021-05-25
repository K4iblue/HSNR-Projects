// *******************************************************************
// main.cpp
// *******************************************************************

#include "mandelbrot.hpp"
#include <cstdlib>
using namespace std;

// *******************************************************************
int main(int argc, char *argv[]) {
    if (argc != 6) {
        cout << "usage: " << argv[0]
             << " iter r_min i_min r_max i_max" << endl;
        return 1;
    }
    int depth = atoi(argv[1]);
    double r_min = atof(argv[2]);
    double i_min = atof(argv[3]);
    double r_max = atof(argv[4]);
    double i_max = atof(argv[5]);

    Mandelbrot mandelbrot(768, 768, depth, Complex(r_min, i_min),
                          Complex(r_max, i_max));
    // TODO
    // ...
}

