#include "exportador.h"
#include "tablero.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {

        cout << "Modo de uso: test <rutaDeSalida>" << endl;
        return 1;
    }

    BMP imagen;
    imagen.SetSize(100, 100);


    dibujarRectangulo(imagen, 15, 15, 105, 300, "#ff0000", 100, true);


    imagen.WriteToFile(argv[1]);

    return 0;
}