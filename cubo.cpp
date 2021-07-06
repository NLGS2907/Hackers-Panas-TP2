#include "cubo.h"
using namespace std;

void dibujarGranCubo(const char* rutaSalida, bool activarLineasCentrales) {

    // Dimensiones (pueden cambiarla a gusto)
    double ancho = 1300;
    double alto = 1100;

    // Acomodamos coordenadas para que no quede feo. El ancho optimamente debe ser mayor al alto.
    if (alto > ancho) {

        _swap(ancho, alto);
    }

    // Definimos todos los puntos vértice a utilizar en cálculos
    double x0, x1, x2, x3, y0, y1, y2, y3, y4, y5, y6, y7, h;
    x0 = ancho / 13; x1 = ancho / 2.6; x2 = ancho / 1.625; x3 = ancho / (13.0 / 12.0);
    y0 = alto / 11; y1 = alto / (110.0 / 15.0); y2 = alto / 5.5; y3 = alto / 4.4;
    h = (ancho + alto) / 3.2;
    y4 = y0 + h; y5 = y1 + h; y6 = y2 + h; y7 = y3 + h;

    // Defino el radio exterior de los pivotes y el radio interior
    double r1, r2;
    r1 = 15; r2 = 10;

    if (r2 > r1) {

        _swap(r1, r2);
    }

    // Defino también los colores para más comodidad
    RGBApixel fondo = HexToRGB("#dddddd"); RGBApixel azulOscuro = HexToRGB("#113a57"); RGBApixel azulClaro = HexToRGB("#688aab");
    RGBApixel bordo = HexToRGB("#780000"); RGBApixel rojo = HexToRGB("#ff0000"); RGBApixel naranja = HexToRGB("#ff9900");
    RGBApixel naranjito = HexToRGB("#ffd000"); RGBApixel amarillo = HexToRGB("#ffff00"); RGBApixel verde = HexToRGB("#00ff00");
    RGBApixel blanco = HexToRGB("#ffffff"); RGBApixel grisOscuro = HexToRGB("#b5b5b5");

    // Declaramos el objeto BMP y sus dimensiones.
    cout << "\nGenerando Imagen de Prueba... ";

    BMP imagen;

    cout << "Listo!\n"
         << "Cambiando el tamaño a (" << ancho << " x " << alto << ") px... ";

    imagen.SetSize(ancho, alto);

    cout << "Listo!\nDibujando fondo... ";

    // Primero pinto el fondo
    for (int j = 0; j < alto; j++) {

        for (int i = 0; i < ancho; i++) {

            cambiarColor(imagen, i, j, fondo.Red, fondo.Green, fondo.Blue);
        }
    }

    cout << "Listo!\nDibujando Líneas Externas... ";
    // Dibujo Cara Superior
    DrawAALine(imagen, x0, y1, x2, y0, azulOscuro);
    DrawAALine(imagen, x0, y1, x1, y3, azulOscuro);
    DrawAALine(imagen, x2, y0, x3, y2, azulOscuro);
    DrawAALine(imagen, x1, y3, x3, y2, azulOscuro);
    // Dibujo Cara Inferior
    DrawAALine(imagen, x0, y5, x2, y4, azulClaro);
    DrawAALine(imagen, x0, y5, x1, y7, azulOscuro);
    DrawAALine(imagen, x2, y4, x3, y6, azulClaro);
    DrawAALine(imagen, x1, y7, x3, y6, azulOscuro);
    // Dibujo Pilares
    DrawAALine(imagen, x0, y1, x0, y5, azulOscuro);
    DrawAALine(imagen, x1, y3, x1, y7, azulOscuro);
    DrawAALine(imagen, x2, y0, x2, y4, azulClaro);
    DrawAALine(imagen, x3, y2, x3, y6, azulOscuro);

    if (activarLineasCentrales) {

        cout << "Listo!\nDibujando Líneas Externas Centrales... ";

        // Diubjo plano rojo
        DrawAALine(imagen, x0, (y1 + y5) / 2, x2, (y0 + y4) / 2, grisOscuro);
        DrawAALine(imagen, x0, (y1 + y5) / 2, x1, (y3 + y7) / 2, grisOscuro);
        DrawAALine(imagen, x2, (y0 + y4) / 2, x3, (y2 + y6) / 2, grisOscuro);
        DrawAALine(imagen, x1, (y3 + y7) / 2, x3, (y2 + y6) / 2, grisOscuro);

        // Dibujo plano amarillo
        DrawAALine(imagen, (x0 + x2) / 2, (y1 + y0) / 2, (x1 + x3) / 2, (y3 + y2) / 2, grisOscuro);
        DrawAALine(imagen, (x0 + x2) / 2, (y1 + y0) / 2, (x0 + x2) / 2, (y5 + y4) / 2, grisOscuro);
        DrawAALine(imagen, (x0 + x2) / 2, (y5 + y4) / 2, (x1 + x3) / 2, (y7 + y6) / 2, grisOscuro);
        DrawAALine(imagen, (x1 + x3) / 2, (y3 + y2) / 2, (x1 + x3) / 2, (y7 + y6) / 2, grisOscuro);

        // Dibujo plano verde
        DrawAALine(imagen, (x0 + x1) / 2, (y1 + y3) / 2, (x0 + x1) / 2, (y5 + y7) / 2, grisOscuro);
        DrawAALine(imagen, (x0 + x1) / 2, (y1 + y3) / 2, (x2 + x3) / 2, (y0 + y2) / 2, grisOscuro);
        DrawAALine(imagen, (x0 + x1) / 2, (y5 + y7) / 2, (x2 + x3) / 2, (y4 + y6) / 2, grisOscuro);
        DrawAALine(imagen, (x2 + x3) / 2, (y0 + y2) / 2, (x2 + x3) / 2, (y4 + y6) / 2, grisOscuro);
    }

    cout << "Listo!\nDibujando Diagonales que pasan por el centro... ";
    // Se sigue los esquemas de los archivos imagen 'CuboCoordenadas.png' y 'Cubo.png'

    // Dibujo diagonales bordo
    DrawAALine(imagen, (x1 + x2) / 2, (y3 + y0) / 2, (x1 + x2) / 2, (y7 + y4) / 2, bordo);
    DrawAALine(imagen, (x0 + x2) / 2, (y5 + y0) / 2, (x1 + x3) / 2, (y7 + y2) / 2, bordo);
    DrawAALine(imagen, (x0 + x1) / 2, (y5 + y3) / 2, (x2 + x3) / 2, (y4 + y2) / 2, bordo);
    // Dibujo diagonales rojas
    DrawAALine(imagen, x1, (y3 + y7) / 2, x2, (y0 + y4) / 2, rojo);
    DrawAALine(imagen, x0, (y1 + y5) / 2, x3, (y2 + y6) / 2, rojo);
    // Dibujo diagonales naranjas
    DrawAALine(imagen, x1, y7, x2, y0, naranja);
    DrawAALine(imagen, x1, y3, x2, y4, naranja);
    // Dibujo diagonales naranja-amarillentas
    DrawAALine(imagen, x0, y1, x3, y6, naranjito);
    DrawAALine(imagen, x0, y5, x3, y2, naranjito);
    // Dibujo diagonales amarillas
    DrawAALine(imagen, (x0 + x2) / 2, (y1 + y0) / 2, (x1 + x3) / 2, (y7 + y6) / 2, amarillo);
    DrawAALine(imagen, (x0 + x2) / 2, (y5 + y4) / 2, (x1 + x3) / 2, (y3 + y2) / 2, amarillo);
    // Dibujo diagonales verdes
    DrawAALine(imagen, (x0 + x1) / 2, (y5 + y7) / 2, (x2 + x3) / 2, (y0 + y2) / 2, verde);
    DrawAALine(imagen, (x0 + x1) / 2, (y1 + y3) / 2, (x2 + x3) / 2, (y4 + y6) / 2, verde);

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

    imagen.WriteToFile(rutaSalida);
}