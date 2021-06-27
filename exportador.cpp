#include "exportador.h"
#include <iostream>

/*
==============================
-=-=  FUNCIONES EXTERNAS  =-=-
==============================
*/

void swapInt(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

bool esRGBValido(int color) {

    if (color >= 0 && color <= 255) {

        return true;
    }

    return false;
}

bool esAlphaValido(int color) {

    if (color >= 0 && color <= 100) {

        return true;
    }

    return false;
}

bool esHexValido(const char* hex) {

    if (hex[0] == '#') {

        int i = 1;
        while (hex[i] != '\0') {

            if (i > 6 || hex[i] < '0' || (hex[i] > '9' && hex[i] < 'A') || (hex[i] > 'F' && hex[i] < 'a') || hex[i] > 'f') {

                return false;
            }

            i++;
        }

        return true;
    }

    return false;
}

bool esPosicionValida(BMP imagen, int x, int y) {

    int ancho = imagen.TellWidth();
    int alto = imagen.TellHeight();

    if (x >= 0 && x < ancho && y >= 0 && y < alto) {

        return true;
    }

    return false;
}

int HexDigitToInt(const char digitoHexadecimal) {

    if (digitoHexadecimal >= '0' && digitoHexadecimal <= '9') {

        return (int)(digitoHexadecimal - 48);

    } else if (digitoHexadecimal >= 'A' && digitoHexadecimal <= 'F') {

        return (int)(digitoHexadecimal - 55);

    } else if (digitoHexadecimal >= 'a' && digitoHexadecimal <= 'f') {

        return (int)(digitoHexadecimal - 87);
    }

    std::cout << "¡El dígito ingresado '" << digitoHexadecimal << "' no es un dígito hexadecimal válido!" << std::endl;
    throw(digitoHexadecimal);
}

RGBApixel HexToRGB(const char* numeroHexadecimal) {

    if (!esHexValido(numeroHexadecimal)) {

        std::cout << "¡El número ingresado '" << numeroHexadecimal << "' no es un número hexadecimal válido!" << std::endl;
        throw(numeroHexadecimal);
    }

    RGBApixel pixelNuevo;

    pixelNuevo.Red = 16 * HexDigitToInt(numeroHexadecimal[1]) + HexDigitToInt(numeroHexadecimal[2]);
    pixelNuevo.Green = 16 * HexDigitToInt(numeroHexadecimal[3]) + HexDigitToInt(numeroHexadecimal[4]);
    pixelNuevo.Blue = 16 * HexDigitToInt(numeroHexadecimal[5]) + HexDigitToInt(numeroHexadecimal[6]);

    return pixelNuevo;
}

void cambiarColor(BMP& imagen, int x, int y, int rojo, int verde, int azul, int alpha) {

    if (esRGBValido(rojo)) {

        imagen(x, y)->Red = rojo;
    }

    if (esRGBValido(verde)) {

        imagen(x, y)->Green = verde;
    }

    if (esRGBValido(azul)) {

        imagen(x, y)->Blue = azul;
    }

    if (esAlphaValido(alpha)) {

        imagen(x, y)->Alpha = alpha;
    }
}

void dibujarLinea(BMP& imagen, int x1, int y1, int x2, int y2, const char* colorRGB, int alpha) {

    if (x1 > x2) {

        swapInt(x1, x2);
    }

    if (y1, y2) {

        swapInt(y1, y2);
    }

    RGBApixel pixelTemporal = HexToRGB(colorRGB);

    if (x1 == x2) {

        for (int y = y1; y <= y2; y++) {

            if (!esPosicionValida(imagen, x1, y)) {

                break;
            }

            cambiarColor(imagen, x1, y, pixelTemporal.Red, pixelTemporal.Green, pixelTemporal.Blue, alpha);
        }

    } else if (y1 == y2) {

        for (int x = x1; x <= x2; x++) {

           if (!esPosicionValida(imagen, x, y1)) {

               break;
           }

           cambiarColor(imagen, x, y1, pixelTemporal.Red, pixelTemporal.Green, pixelTemporal.Blue, alpha);
        }
    }
}

void dibujarRectangulo(BMP& imagen, int x1, int y1, int x2, int y2, const char* colorRGB, int alpha, bool esRelleno) {

    if (esRelleno) {

        for (int y = y1; y <= y2; y++) {

            dibujarLinea(imagen, x1, y, x2, y, colorRGB, esRelleno);
        }
    } else {

        dibujarLinea(imagen, x1, y1, x1, y2, colorRGB, esRelleno);
        dibujarLinea(imagen, x1, y1, x2, y1, colorRGB, esRelleno);
        dibujarLinea(imagen, x2, y1, x2, y2, colorRGB, esRelleno);
        dibujarLinea(imagen, x1, y2, x2, y2, colorRGB, esRelleno);
    }
}

/*
==============================
-=-=    TDA EXPORTADOR    =-=-
==============================
*/

Exportador::Exportador(const char* rutaDeEntrada, const char* rutaDeSalida) {

    imagen.ReadFromFile(rutaDeEntrada);
    rutaSalida = rutaDeSalida;
}

void Exportador::guardar() {

    imagen.WriteToFile(rutaSalida);
}

void Exportador::setRutaEntrada(const char* nuevaEntrada) {

    imagen.ReadFromFile(nuevaEntrada);
}

const char* Exportador::getRutaSalida() {

    return rutaSalida;
}

void Exportador::setRutaSalida(const char* nuevaSalida) {

    rutaSalida = nuevaSalida;
}

RGBApixel Exportador::conseguirPixel(int x, int y) {

    if (!esPosicionValida(imagen, x, y)) {

        std::cout << "La posición (" << x << ", " << y << ") no está dentro de los límites de la imagen." << std::endl;
        throw (x);   
    }

    return imagen.GetPixel(x, y);
}