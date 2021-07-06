#include "exportador.h"
#include <iostream>

/*
==============================
-=-=  FUNCIONES EXTERNAS  =-=-
==============================
*/

double _funcionRecta(double xInicial, double yInicial, double xFinal, double yFinal, double xAEvaluar) {

    double m = (yFinal - yInicial) / (xFinal - xInicial);

    return (m * (xAEvaluar - xInicial)) + yInicial;
}

void _dibujarArea(BMP& imagen, double funcPiso, double funcTecho, double xEvaluado, RGBApixel colorRGB, double alpha) {

    if (funcPiso > funcTecho) {

        _swap(funcPiso, funcTecho);
    }

    for (int y = funcPiso; y <= funcTecho; y++) {

        cambiarColor(imagen, xEvaluado, y, colorRGB.Red, colorRGB.Green, colorRGB.Blue, alpha);
    }
}

bool esRGBValido(int color) {

    if (color >= 0 && color <= 255) {

        return true;
    }

    return false;
}

bool esAlphaValido(double color) {

    if (color >= 0 && color <= 1) {

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

bool esPosicionValida(BMP imagen, double x, double y) {

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

void dibujarRectangulo(BMP& imagen, int x1, int y1, int x2, int y2, bool esRelleno, RGBApixel colorRGB, double alpha) {

    if (!esPosicionValida(imagen, x1, y1)) {

        _corregirCoordenadas(imagen, x1, y1);
    }

    if (!esPosicionValida(imagen, x2, y2)) {

        _corregirCoordenadas(imagen, x2, y2);
    }

    acomodarCoordenadas(x1, y1, x2, y2);

    if (esRelleno) {

        for (int y = y1; y <= y2; y++) {

            for (int x = x1; x <= x2; x++) {

                cambiarColor(imagen, x, y, colorRGB.Red, colorRGB.Green, colorRGB.Blue, alpha);
            }
        }

    } else {

        DrawAALine(imagen, x1, y1, x1, y2, colorRGB);
        DrawAALine(imagen, x1, y1, x2, y1, colorRGB);
        DrawAALine(imagen, x2, y1, x2, y2, colorRGB);
        DrawAALine(imagen, x1, y2, x2, y2, colorRGB);
    }
}

void dibujarCirculo(BMP& imagen, double centroX, double centroY, double radio, double anguloInicial, double anguloFinal, RGBApixel colorRGB, double alpha) {

    for (double i = 0; i <= radio; i += 0.5) {

        DrawArc(imagen, centroX, centroY, i, anguloInicial, anguloFinal, colorRGB);
    }
}

void dibujarTriangulo(BMP& imagen, double x1, double y1, double x2, double y2, double x3, double y3, bool esRelleno, RGBApixel colorRGB, double alpha) {


    if (!esPosicionValida(imagen, x1, y1)) {

        _corregirCoordenadas(imagen, x1, y1);
    }

    if (!esPosicionValida(imagen, x2, y2)) {

        _corregirCoordenadas(imagen, x2, y2);
    }

    if (!esPosicionValida(imagen, x3, y3)) {

        _corregirCoordenadas(imagen, x3, y3);
    }

    _acomodarCoordenadasTriangulo(x1, y1, x2, y2, x3, y3);
    
    if (esRelleno) {

        double funcionPiso, funcionTecho;

        for (int x = x1; x < x2; x++) {

            funcionPiso = _funcionRecta(x1, y1, x2, y2, x);
            funcionTecho = _funcionRecta(x1, y1, x3, y3, x);

            _dibujarArea(imagen, funcionPiso, funcionTecho, x, colorRGB, alpha);
        }

        for (int x = x2; x < x3; x++) {

            funcionPiso = _funcionRecta(x2, y2, x3, y3, x);
            funcionTecho = _funcionRecta(x1, y1, x3, y3, x);

            _dibujarArea(imagen, funcionPiso, funcionTecho, x, colorRGB, alpha);
        }
    } else {

        DrawAALine(imagen, x1, y1, x2, y2, colorRGB);
        DrawAALine(imagen, x1, y1, x3, y3, colorRGB);
        DrawAALine(imagen, x2, y2, x3, y3, colorRGB);
    }
}

void dibujarCuadrilatero(BMP& imagen, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, bool esRelleno, RGBApixel colorRGB, double alpha) {

    if (!esPosicionValida(imagen, x1, y1)) {

        _corregirCoordenadas(imagen, x1, y1);
    }

    if (!esPosicionValida(imagen, x2, y2)) {

        _corregirCoordenadas(imagen, x2, y2);
    }

    if (!esPosicionValida(imagen, x3, y3)) {

        _corregirCoordenadas(imagen, x3, y3);
    }

    if (!esPosicionValida(imagen, x4, y4)) {

        _corregirCoordenadas(imagen, x4, y4);
    }

    _acomodarCoordenadasCuadrilatero(x1, y1, x2, y2, x3, y3, x4, y4);

    if (esRelleno) {

        dibujarTriangulo(imagen, x1, y1, x2, y2, x3, y3, true, colorRGB, alpha);
        dibujarTriangulo(imagen, x2, y2, x3, y3, x4, y4, true, colorRGB, alpha);

    } else {

        DrawAALine(imagen, x1, y1, x2, y2, colorRGB);
        DrawAALine(imagen, x1, y1, x3, y3, colorRGB);
        DrawAALine(imagen, x2, y2, x4, y4, colorRGB);
        DrawAALine(imagen, x3, y3, x4, y4, colorRGB);
    }
}

/*
==============================
-=-=    TDA EXPORTADOR    =-=-
==============================
*/

Exportador::Exportador(const char* rutaDeEntrada, const char* rutaDeSalida) {

    this->imagen.ReadFromFile(rutaDeEntrada);
    this->rutaSalida = rutaDeSalida;
}

void Exportador::guardar() {

    this->imagen.WriteToFile(rutaSalida);
}

void Exportador::setRutaEntrada(const char* nuevaEntrada) {

    this->imagen.ReadFromFile(nuevaEntrada);
}

const char* Exportador::getRutaSalida() {

    return this->rutaSalida;
}

void Exportador::setRutaSalida(const char* nuevaSalida) {

    this->rutaSalida = nuevaSalida;
}

RGBApixel Exportador::conseguirPixel(int x, int y) {

    if (!esPosicionValida(imagen, x, y)) {

        std::cout << "La posición (" << x << ", " << y << ") no está dentro de los límites de la imagen." << std::endl;
        throw (x);
    }

    return this->imagen.GetPixel(x, y);
}