#include "exportador.h"
#include <iostream>

/*
==============================
-=-=  FUNCIONES EXTERNAS  =-=-
==============================
*/

void _swapInt(int &a, int &b) {

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

bool esAlphaValido(double color) {

    if (color >= 0 && color <= 1000) {

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

void acomodarCoordenadas(int& x1, int& y1, int& x2, int& y2) {

    if (x1 > x2) {

        _swapInt(x1, x2);
    }

    if (y1 > y2) {

        _swapInt(y1, y2);
    }
}

void corregirCoordenadas(BMP imagen, int& x1, int& y1, int& x2, int& y2) {

    int ancho = imagen.TellWidth();
    int alto = imagen.TellHeight();

    if (x1 < 0) {

        x1 = 0;
    }

    if (y1 < 0) {

        y1 = 0;
    }

    if (x2 >= ancho) {

        x2 = ancho - 1;
    }

    if (y2 >= alto) {

        y2 = alto - 1;
    }
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

void cambiarColor(BMP& imagen, int x, int y, int rojo, int verde, int azul, double alpha) {

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

void dibujarRectangulo(BMP& imagen, int x1, int y1, int x2, int y2, bool esRelleno, const char* colorRGB, double alpha) {

    acomodarCoordenadas(x1, y1, x2, y2);

    if (!esPosicionValida(imagen, x1, y1) || !esPosicionValida(imagen, x2, y2)) {

        corregirCoordenadas(imagen, x1, y1, x2, y2);
    }

    RGBApixel pixelTemporal = HexToRGB(colorRGB);

    if (esRelleno) {

        for (int y = y1; y <= y2; y++) {

            for (int x = x1; x <= x2; x++) {

                cambiarColor(imagen, x, y, pixelTemporal.Red, pixelTemporal.Green, pixelTemporal.Blue, alpha);
            }
        }

    } else {

        DrawAALine(imagen, x1, y1, x1, y2, pixelTemporal);
        DrawAALine(imagen, x1, y1, x2, y1, pixelTemporal);
        DrawAALine(imagen, x2, y1, x2, y2, pixelTemporal);
        DrawAALine(imagen, x1, y2, x2, y2, pixelTemporal);
    }
}

void dibujarCirculo(BMP& imagen, double centroX, double centroY, double radio, double anguloInicial, double anguloFinal, const char* colorRGB, double alpha) {

    RGBApixel colorPixel = HexToRGB(colorRGB);

    for (double i = 0; i <= radio; i += 0.5) {

        DrawArc(imagen, centroX, centroY, i, anguloInicial, anguloFinal, colorPixel);
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