#include "tablero.h"
#include <iostream>
using namespace std;

int main() {

    Tablero<char> tt = Tablero<char>(2, 5, 6);
    cout << tt.celda(1, 1, 1) << endl;
    
    return 0;
}