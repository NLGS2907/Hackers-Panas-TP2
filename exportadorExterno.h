#ifndef EXPORTADOR_H_
#define EXPORTADOR_H_

/*
Este archivo contiene declaraciones de funciones externas al TDA,
pero que igual pueden modificarlo pasándolo por parámetro.
Se las separa en un archivo distinto por temas de organización,
además de que se consideran que las funciones aquí declaradas
son un poco generalizadas y no tan ligadas al TDA hecho.

Sin embargo, siguen estando definidas en 'exportador.cpp', el
mismo lugar que el TDA.
*/

#include "EasyBMP.h"
#include "EasyBMP_Geometry.h"

#define _PI_ 3.14159265358979 // Para hacer los calculos más fáciles.

/*
__________________________________________________
PRE: -
-
POS: Invierte los valores de 'a' y 'b'.
__________________________________________________
*/
template <class TipoVariable>
void _swap(TipoVariable& a, TipoVariable& b);

/*
__________________________________________________
PRE: -
-
POS: Devuelve el valor de 'y' para un valor 'x' al
     que se le aplica la fórmula de la recta que
     pasa por dos puntos.
__________________________________________________

Aplica la fórmula de la recta que pasa por dos puntos.

Cabe aclarar que se ha notado una función similar en
'EasyBMP_Geometry.h': me refiero a 'LineFunction', pero
la misma no devuelve el valor de 'y' como aquí se hace.
*/
double _funcionRecta(double xInicial, double yInicial, double xFinal, double yFinal, double xAEvaluar);

/*
__________________________________________________
PRE: -
-
POS: Se dibuja en la imagen una iteración de puntos.
__________________________________________________

Dibuja en la imagen una línea que va desde una función
'piso' hasta una función 'techo'.
*/
void _dibujarArea(BMP& imagen, double funcPiso, double funcTecho, double xEvaluado, RGBApixel colorRGB, double alpha);

/*
__________________________________________________
PRE: -
-
POS: Devuelve 'true' si el color está entre 0 y 255 inclusive.
     En caso contrario, devuelve 'false'.
__________________________________________________

Detecta si el número RGB pasado por parámetro cumple con las condiciones
(está entre 0 y 255) para que pueda ser usado correctamente en el
modelo de color RGB.
*/
bool esRGBValido(int color);

/*
__________________________________________________
PRE: -
-
POS: Devuelve 'true' si el color está entre 0 y 100 inclusive.
     En caso contrario, devuelve 'false'.
__________________________________________________

Detecta si el número alpha pasado por parámetro cumple con las condiciones
(está entre 0 y 10) para que pueda ser usado correctamente en el modelo de
color RGBA.
*/
bool esAlphaValido(double color);

/*
__________________________________________________
PRE: -
-
POS: Devuelve 'true' si el arreglo de chars es del formato
     '#RRGGBB'. Caso contrario devuelve 'false'.
__________________________________________________

Detecta si el arreglo de chars pasado por parámetro es un
numero hexadecimal válido para el modelo de color RRGGBB,
verificando si tiene no más de 6 caracteres (7 contando el '#'),
y si cada caracter es un numero hexadecimal válido en sí. 
*/
bool esHexValido(const char* hex);

/*
__________________________________________________
PRE: -
-
POS: Devuelve 'true' si la posición (x, y) está dentro de las
     dimensiones de 'imagen'. En caso contrario, devuelve 'false'.
__________________________________________________

Detecta si el pixel de coordenadas (x, y) está dentro de los límites
de la imagen, también pasada por parámetro.
*/
bool esPosicionValida(BMP imagen, double x, double y);

/*
__________________________________________________
PRE: El TipoVariable es una clase de número a la que se
     puede comparar con 0 y los límites de la imagen.
-
POS: Modifica el/los valor/es de las coordenadas de
     forma que x1 es menor o igual a x2; e y1 menor
     o igual a y2.
__________________________________________________

Recibe las referencias a las coordenadas y, de no
cumplirse las condiciones (x1 <= x2 && y1 <= y2),
las acomoda para que así sea.
*/
template <class TipoVariable>
void acomodarCoordenadas(TipoVariable& x1, TipoVariable& y1, TipoVariable& x2, TipoVariable& y2);

/*
__________________________________________________
PRE: El TipoVariable es una clase de número a la que se
     puede comparar con 0 y los límites de la imagen.
-
POS: Modifica el/los valor/es de las coordenadas de
     forma que se cumpla x1 <= x2 <= x3.
__________________________________________________

Recibe las referencias a las coordenadas y, de no
cumplirse las condiciones x1 <= x2 <= x3, las acomoda
para que así sea.
*/
template <class TipoVariable>
void _acomodarCoordenadasTriangulo(TipoVariable& x1, TipoVariable& y1, TipoVariable& x2, TipoVariable& y2, TipoVariable& x3, TipoVariable& y3);

/*
__________________________________________________
PRE: El TipoVariable es una clase de número a la que se
     puede comparar con 0 y los límites de la imagen.
-
POS: Modifica el/los valor/es de las coordenadas de
     forma que se cumpla x1 <= x2 <= x3 <= x4.
__________________________________________________

Recibe las referencias a las coordenadas y, de no
cumplirse las condiciones x1 <= x2 <= x3 <= x4, las
acomoda para que así sea.
*/
template <class TipoVariable>
void _acomodarCoordenadasCuadrilatero(TipoVariable& x1, TipoVariable& y1, TipoVariable& x2, TipoVariable& y2, TipoVariable& x3, TipoVariable& y3, TipoVariable& x4, TipoVariable&y4);

/*
__________________________________________________
PRE: El TipoVariable es una clase de número a la que se
     puede comparar con 0 y los límites de la imagen.
-
POS: Modifica el/los valor/es de las coordenadas que
     sean necesarios para estar dentro de los límites
     de la imagen.
__________________________________________________

Recibe las referencias a las coordenadas y, de estar
fuera de los límites de la imagen, se los trunca para
caber dentro.
*/
template <class TipoVariable>
void _corregirCoordenadas(BMP imagen, TipoVariable& x, TipoVariable& y);

/*
__________________________________________________
PRE: El digito pasado por parámetro debe estar:
     entre '0' y '9',
     entre 'A' y 'F', o
     entre 'a' y 'f'.
-
POS: Devuelve un entero entre 0 y 15.
__________________________________________________

Devuelve el equivalente decimal de un único carácter
que se considera un número hexadecimal de una cifra
(de 0 a f).

EJ: '4' devolvería el número 4, mientras que 'e' o
'E' devolverían el número 14.
*/
int HexDigitToInt(const char digitoHexadecimal);

/*
__________________________________________________
PRE: El arreglo de chars pasado es del tipo '#RRGGBB'.
-
POS: Devuelve un TDA RGBApixel que contiene en su
     interior los valores RGB (Alpha se desprecia).
__________________________________________________

Crea un TDA RGBApixel, que contiene datos RGBA de un
color, y es guardado dentro los valores resultantes
de interpretar al arreglo de chars pasado por
parámetro como un número hexadecimal válido.
*/
RGBApixel HexToRGB(const char* numeroHexadecimal);

/*
__________________________________________________
PRE: -
-
POS: El color del pixel de las coordenadas pasadas por parámetro
     son cambiadas por los valores especificados, también por
     parámetros.
__________________________________________________

Se va a buscar el pixel en las coordenadas (x, y) y, si esta dentro
de las dimensiones de 'imagen', se cambia el color del mismo según
el modelo RGBA, por el conformado por los valores pasados por parámetro.
Si alguno de los colores llegara a estar ausente o ser incorrecto
(no está en el rango [0, 255]), no se modificará el valor de esa
parte del color. 
*/
void cambiarColor(BMP& imagen, int x, int y, int rojo=256, int verde=256, int azul=256, double alpha=1.1);

/*
__________________________________________________
PRE: -
-
POS: Dibuja un rectángulo en la imagen.
__________________________________________________

Dibuja un rectángulo de vértices opuestos (x1, y1)
y (x2, y2). El color por defecto es un negro opaco.

Si x1 es mayor a x2, se invierten los valores.
Ídem con y1 e y2.
*/
void dibujarRectangulo(BMP& imagen, int x1, int y1, int x2, int y2, bool esRelleno=true, RGBApixel colorRGB=HexToRGB("#000000"), double alpha=1);

/*
__________________________________________________
PRE: -
-
POS: Dibuja un círculo en la imagen.
__________________________________________________

Dibuja un círculo que cuyo centro está en el medio
de la caja de vértices (x1, y1) y (x2, y2).
El color por defecto es un negro opaco.

Si x1 es mayor a x2, se invierten los valores.
Ídem con y1 e y2.
*/
void dibujarCirculo(BMP& imagen, double centroX, double centroY, double radio, double anguloInicial=0, double anguloFinal=(2 * _PI_), RGBApixel colorRGB=HexToRGB("#000000"), double alpha=1);

/*
__________________________________________________
PRE: -
-
POS: Dibuja un triángulo en la imagen.
__________________________________________________

Dibuja un triángulo de vértices (x1, y1), (x2, y2),
y (x3, y3). Si algún par de coordenadas está fuera
de la imagen se las corrige.

Se acomoda las coordenadas de manera que x1 <= x2 <= x3
e y1 <= y2 <= y3.
*/
void dibujarTriangulo(BMP& imagen, double x1, double y1, double x2, double y2, double x3, double y3, bool esRelleno=true, RGBApixel colorRGB=HexToRGB("#000000"), double alpha=1);

/*
__________________________________________________
PRE: -
-
POS: Dibuja un cuadrilátero en la imagen.
__________________________________________________

Dibuja un cuadrilátero de vértices (x1, y1), (x2, y2),
(x3, y3) y (x4, y4); de manera que en realidad se dibujan
dos triángulos formando la figura.
*/
void dibujarCuadrilatero(BMP& imagen, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, bool esRelleno=true, RGBApixel colorRGB=HexToRGB("#000000"), double alpha=1);


/* ----- DEFINICIONES DE FUNCIONES CON TEMPLATE ----- */


template <class TipoVariable>
void _swap(TipoVariable& a, TipoVariable& b) {

    TipoVariable temp = a;
    a = b;
    b = temp;
}

template <class TipoVariable>
void acomodarCoordenadas(TipoVariable& x1, TipoVariable& y1, TipoVariable& x2, TipoVariable& y2) {

    if (x1 > x2) {

        _swap(x1, x2);
    }

    if (y1 > y2) {

        _swap(y1, y2);
    }
}

template <class TipoVariable>
void _acomodarCoordenadasTriangulo(TipoVariable& x1, TipoVariable& y1, TipoVariable& x2, TipoVariable& y2, TipoVariable& x3, TipoVariable& y3) {

     if (x1 > x3) {

          _swap(x1, x3);
          _swap(y1, y3);
     }

     if (x1 > x2) {

          _swap(x1, x2);
          _swap(y1, y2);
     }

     if (x2 > x3) {

          _swap(x2, x3);
          _swap(y2, y3);
     }
}

template <class TipoVariable>
void _acomodarCoordenadasCuadrilatero(TipoVariable& x1, TipoVariable& y1, TipoVariable& x2, TipoVariable& y2, TipoVariable& x3, TipoVariable& y3, TipoVariable& x4, TipoVariable&y4) {

     if (x1 > x4) {

          _swap(x1, x4);
          _swap(y1, y4);    
     }

     _acomodarCoordenadasTriangulo(x1, y1, x2, y2, x3, y3); // Para no copiar código ;)

     if (x3 > x4) {

          _swap(x3, x4);
          _swap(y3, y4);
     }
}

template <class TipoVariable>
void _corregirCoordenadas(BMP imagen, TipoVariable& x, TipoVariable& y) {

    int ancho = imagen.TellWidth();
    int alto = imagen.TellHeight();

    if (x < 0) {

        x = 0;

    } else if (x >= ancho) {

        x = ancho - 1;
    }

    if (y < 0) {

        y = 0;

    } else if (y >= alto) {

        y = alto - 1;
    }
}

#endif /* EXPORTADOR_H_ */