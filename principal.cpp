#include "exportador.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {

        cout << "Modo de uso: <nombreDeEjecutable> <rutaDeSalida>\n"
             << "Ej:\tSi se compila esto a un archivo 'principal.o' y\n"
             << "'cubo.bmp' la ruta de salida, se pone:\n\n"
             << "principal.o cubo.bmp\n\nEn la llamada al main." << endl;
        return 1;
    }

    /*
        -=-=-=    <=-=>     >-=-<     <=-=>      DESCRIPCIÓN      <=-=>     >-=-<     <=-=>       =-=-=-
        Este es un modelo de prueba, que trata de dibujar el cubo que hice para graficar las diagonales
        de un cubo en todas sus posibles direcciones. ¡Siéntanse libre de jugar con los parámetros y ver
        qué sale!
        -=-=-=    <=-=>     >-=-<     <=-=>   <<-=-=-> <-=-=->>   <=-=>     >-=-<     <=-=>       =-=-=-
    */

    // Dimensiones (pueden cambiarla a gusto)
    double ancho = 1300;
    double alto = 1100;

    // Acomodamos coordenadas para que no quede feo. El ancho optimamente debe ser mayor al alto.
    if (alto > ancho) {

        double temp = ancho;
        ancho = alto;
        alto = temp;
    }

    // Definimos todos los puntos vértice a utilizar en cálculos
    double x0, x1, x2, x3, y0, y1, y2, y3, y4, y5, y6, y7, h;
    x0 = ancho / 13; x1 = ancho / 2.6; x2 = ancho / 1.625; x3 = ancho / (1300.0 / 1200.0);
    y0 = alto / 11; y1 = alto / (1100.0 / 150.0); y2 = alto / 5.5; y3 = alto / 4.4;
    h = (ancho + alto) / 3.2;
    y4 = y0 + h; y5 = y1 + h; y6 = y2 + h; y7 = y3 + h;

    // Defino el radio exterior de los pivotes y el radio interior
    double r1, r2;
    r1 = 15; r2 = 10;

    if ( r2 > r1) {

        double rTemp = r1;
        r1 = r2;
        r2 = rTemp;
    }

    // Defino también los colores para más cmodidad
    const char* azulOscuro = "#113a57"; const char* bordo = "#780000"; const char* rojo = "#ff0000";
    const char* naranja = "#ff9900"; const char* naranjito = "#ffd000"; const char* amarillo = "#ffff00";
    const char* verde = "#00ff00"; const char* blanco = "#ffffff"; const char * fondo = "#dddddd";

    // Declaramos el objeto BMP y sus dimensiones.
    cout << "\nGenerando Imagen de Prueba... ";

    BMP imagen;

    cout << "Listo!\n"
         << "Cambiando el tamaño a (" << ancho << " x " << alto << ") px... ";

    imagen.SetSize(ancho, alto);

    cout << "Listo!\n" << endl;

    // Primero pinto el fondo
    RGBApixel pixTemp = HexToRGB(fondo);
    for (int j = 0; j < alto; j++) {

        for (int i = 0; i < ancho; i++) {

            cambiarColor(imagen, i, j, pixTemp.Red, pixTemp.Green, pixTemp.Blue);
        }
    }

    cout << "Dibujando Líneas Externas... ";
    // Dibujo Cara Superior
    DrawAALine(imagen, x0, y1, x2, y0, HexToRGB(azulOscuro));
    DrawAALine(imagen, x0, y1, x1, y3, HexToRGB(azulOscuro));
    DrawAALine(imagen, x2, y0, x3, y2, HexToRGB(azulOscuro));
    DrawAALine(imagen, x1, y3, x3, y2, HexToRGB(azulOscuro));
    // Dibujo Cara Inferior
    DrawAALine(imagen, x0, y5, x2, y4, HexToRGB(azulOscuro));
    DrawAALine(imagen, x0, y5, x1, y7, HexToRGB(azulOscuro));
    DrawAALine(imagen, x2, y4, x3, y6, HexToRGB(azulOscuro));
    DrawAALine(imagen, x1, y7, x3, y6, HexToRGB(azulOscuro));
    // Dibujo Pilares
    DrawAALine(imagen, x0, y1, x0, y5, HexToRGB(azulOscuro));
    DrawAALine(imagen, x1, y3, x1, y7, HexToRGB(azulOscuro));
    DrawAALine(imagen, x2, y0, x2, y4, HexToRGB(azulOscuro));
    DrawAALine(imagen, x3, y2, x3, y6, HexToRGB(azulOscuro));

    cout << "Listo!\nDibujando Diagonales que pasan por el centro... ";
    // Se sigue los esquemas de los archivos imagen 'CuboCoordenadas.png' y 'Cubo.png'

    // Dibujo diagonales bordo
    DrawAALine(imagen, (x1 + x2) / 2, (y3 + y0) / 2, (x1 + x2) / 2, (y7 + y4) / 2, HexToRGB(bordo));
    DrawAALine(imagen, (x0 + x2) / 2, (y5 + y0) / 2, (x1 + x3) / 2, (y7 + y2) / 2, HexToRGB(bordo));
    DrawAALine(imagen, (x0 + x1) / 2, (y5 + y3) / 2, (x2 + x3) / 2, (y4 + y2) / 2, HexToRGB(bordo));
    // Dibujo diagonales rojas
    DrawAALine(imagen, x1, (y3 + y7) / 2, x2, (y0 + y4) / 2, HexToRGB(rojo));
    DrawAALine(imagen, x0, (y1 + y5) / 2, x3, (y2 + y6) / 2, HexToRGB(rojo));
    // Dibujo diagonales naranjas
    DrawAALine(imagen, x1, y7, x2, y0, HexToRGB(naranja));
    DrawAALine(imagen, x1, y3, x2, y4, HexToRGB(naranja));
    // Dibujo diagonales naranja-amarillentas
    DrawAALine(imagen, x0, y1, x3, y6, HexToRGB(naranjito));
    DrawAALine(imagen, x0, y5, x3, y2, HexToRGB(naranjito));
    // Dibujo diagonales amarillas
    DrawAALine(imagen, (x0 + x2) / 2, (y1 + y0) / 2, (x1 + x3) / 2, (y7 + y6) / 2, HexToRGB(amarillo));
    DrawAALine(imagen, (x0 + x2) / 2, (y5 + y4) / 2, (x1 + x3) / 2, (y3 + y2) / 2, HexToRGB(amarillo));
    // Dibujo diagonales verdes
    DrawAALine(imagen, (x0 + x1) / 2, (y5 + y7) / 2, (x2 + x3) / 2, (y0 + y2) / 2, HexToRGB(verde));
    DrawAALine(imagen, (x0 + x1) / 2, (y1 + y3) / 2, (x2 + x3) / 2, (y4 + y6) / 2, HexToRGB(verde));

    cout << "Listo!\nDibujando Pivotes Indicadores... ";

    // Dibujo pivotes bordo
    dibujarCirculo(imagen, (x1 + x2) / 2, (y3 + y0) / 2, r1, 0, (2 * _PI_), bordo);
    dibujarCirculo(imagen, (x1 + x2) / 2, (y3 + y0) / 2, r2);

    dibujarCirculo(imagen, (x1 + x2) / 2, (y7 + y4) / 2, r1, 0, (2 * _PI_), bordo);
    dibujarCirculo(imagen, (x1 + x2) / 2, (y7 + y4) / 2, r2);

    dibujarCirculo(imagen, (x0 + x2) / 2, (y5 + y0) / 2, r1, 0, (2 * _PI_), bordo);
    dibujarCirculo(imagen, (x0 + x2) / 2, (y5 + y0) / 2, r2);

    dibujarCirculo(imagen, (x1 + x3) / 2, (y7 + y2) / 2, r1, 0, (2 * _PI_), bordo);
    dibujarCirculo(imagen, (x1 + x3) / 2, (y7 + y2) / 2, r2);

    dibujarCirculo(imagen, (x0 + x1) / 2, (y5 + y3) / 2, r1, 0, (2 * _PI_), bordo);
    dibujarCirculo(imagen, (x0 + x1) / 2, (y5 + y3) / 2, r2);

    dibujarCirculo(imagen, (x2 + x3) / 2, (y4 + y2) / 2, r1, 0, (2 * _PI_), bordo);
    dibujarCirculo(imagen, (x2 + x3) / 2, (y4 + y2) / 2, r2);


    // Dibujo pivotes rojos
    dibujarCirculo(imagen, x1, (y3 + y7) / 2, r1, 0, (2 * _PI_), rojo);
    dibujarCirculo(imagen, x1, (y3 + y7) / 2, r2);

    dibujarCirculo(imagen, x2, (y0 + y4) / 2, r1, 0, (2 * _PI_), rojo);
    dibujarCirculo(imagen, x2, (y0 + y4) / 2, r2);

    dibujarCirculo(imagen, x0, (y1 + y5) / 2, r1, 0, (2 * _PI_), rojo);
    dibujarCirculo(imagen, x0, (y1 + y5) / 2, r2);

    dibujarCirculo(imagen, x3, (y2 + y6) / 2, r1, 0, (2 * _PI_), rojo);
    dibujarCirculo(imagen, x3, (y2 + y6) / 2, r2);


    // Dibujo pivotes naranjas
    dibujarCirculo(imagen, x1, y7, r1, 0, (2 * _PI_), naranja);
    dibujarCirculo(imagen, x1, y7, r2);

    dibujarCirculo(imagen, x2, y0, r1, 0, (2 * _PI_), naranja);
    dibujarCirculo(imagen, x2, y0, r2);

    dibujarCirculo(imagen, x1, y3, r1, 0, (2 * _PI_), naranja);
    dibujarCirculo(imagen, x1, y3, r2);

    dibujarCirculo(imagen, x2, y4, r1, 0, (2 * _PI_), naranja);
    dibujarCirculo(imagen, x2, y4, r2);


    // Dibujo pivotes naranja-amarillentos
    dibujarCirculo(imagen, x0, y1, r1, 0, (2 * _PI_), naranjito);
    dibujarCirculo(imagen, x0, y1, r2);

    dibujarCirculo(imagen, x3, y6, r1, 0, (2 * _PI_), naranjito);
    dibujarCirculo(imagen, x3, y6, r2);

    dibujarCirculo(imagen, x0, y5, r1, 0, (2 * _PI_), naranjito);
    dibujarCirculo(imagen, x0, y5, r2);

    dibujarCirculo(imagen, x3, y2, r1, 0, (2 * _PI_), naranjito);
    dibujarCirculo(imagen, x3, y2, r2);


    // Dibujo pivotes amarillos
    dibujarCirculo(imagen, (x0 + x2) / 2, (y1 + y0) / 2, r1, 0, (2 * _PI_), amarillo);
    dibujarCirculo(imagen, (x0 + x2) / 2, (y1 + y0) / 2, r2);

    dibujarCirculo(imagen, (x1 + x3) / 2, (y7 + y6) / 2, r1, 0, (2 * _PI_), amarillo);
    dibujarCirculo(imagen, (x1 + x3) / 2, (y7 + y6) / 2, r2);

    dibujarCirculo(imagen, (x0 + x2) / 2, (y5 + y4) / 2, r1, 0, (2 * _PI_), amarillo);
    dibujarCirculo(imagen, (x0 + x2) / 2, (y5 + y4) / 2, r2);

    dibujarCirculo(imagen, (x1 + x3) / 2, (y3 + y2) / 2, r1, 0, (2 * _PI_), amarillo);
    dibujarCirculo(imagen, (x1 + x3) / 2, (y3 + y2) / 2, r2);


    // Dibujo pivotes verdes
    dibujarCirculo(imagen, (x0 + x1) / 2, (y5 + y7) / 2, r1, 0, (2 * _PI_), verde);
    dibujarCirculo(imagen, (x0 + x1) / 2, (y5 + y7) / 2, r2);

    dibujarCirculo(imagen, (x2 + x3) / 2, (y0 + y2) / 2, r1, 0, (2 * _PI_), verde);
    dibujarCirculo(imagen, (x2 + x3) / 2, (y0 + y2) / 2, r2);

    dibujarCirculo(imagen, (x0 + x1) / 2, (y1 + y3) / 2, r1, 0, (2 * _PI_), verde);
    dibujarCirculo(imagen, (x0 + x1) / 2, (y1 + y3) / 2, r2);

    dibujarCirculo(imagen, (x2 + x3) / 2, (y4 + y6) / 2, r1, 0, (2 * _PI_), verde);
    dibujarCirculo(imagen, (x2 + x3) / 2, (y4 + y6) / 2, r2);


    // Dibujo pivote central
    dibujarCirculo(imagen, (x1 + x2) / 2, (y7 + y0) / 2, r1, 0, (2 * _PI_), blanco);
    dibujarCirculo(imagen, (x1 + x2) / 2, (y7 + y0) / 2, r2);

    cout << "Listo!\n\nLa imagen fue completada!\n" << endl;

    imagen.WriteToFile(argv[1]);

    return 0;
}