#include "exportador.h"
#include "tablero.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {

        cout << "Modo de uso: test <rutaDeSalida>" << endl;
        return 1;
    }

    BMP imagen;
    imagen.SetSize(500, 500);
    imagen.SetBitDepth(32);

    dibujarCirculo(imagen, 10, 10, 144, 0 , 2 * _PI_, "#ffa20d");

    imagen.WriteToFile(argv[1]);

    return 0;
}