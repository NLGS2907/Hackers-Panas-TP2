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

#include "exportadorTDA.h"

/*
__________________________________________________
PRE: -
-
POS: Invierte los valores de 'a' y 'b'.
__________________________________________________
*/
void swapInt(int& a, int& b);

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
bool esPosicionValida(BMP imagen, int x, int y);

/*
__________________________________________________
PRE: -
-
POS: Modifica el/los valor/es de las coordenadas de
     forma que x1 es menor o igual a x2; e y1 menor
     o igual a y2.
__________________________________________________

Recibe las referencias a las coordenadas y, de no
cumplirse las condiciones (x1 <= x2 && y1 <= y2),
las acomoda para que así sea.
*/
void acomodarCoordenadas(int& x1, int& y1, int& x2, int& y2);

/*
__________________________________________________
PRE: -
-
POS: Modifica el/los valor/es de las coordenadas que
     sean necesarios para estar dentro de los límites
     de la imagen.
__________________________________________________

Recibe las referencias a las coordenadas y, de estar
fuera de los límites de la imagen, se los trunca para
caber dentro.
*/
void corregirCoordenadas(BMP imagen, int& x1, int& y1, int& x2, int& y2);

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
POS: Si x1 es mayor a x2, se invierten los valores.
     Ídem con y1 e y2.
__________________________________________________

Dibuja un rectángulo de vértices opuestos (x1, y1)
y (x2, y2). El color por defecto es un negro opaco.
*/
void dibujarRectangulo(BMP& imagen, int x1, int y1, int x2, int y2, bool esRelleno=true, const char* colorRGB="#000000", double alpha=1);

/*
__________________________________________________
PRE: -
-
POS: Si x1 es mayor a x2, se invierten los valores.
     Ídem con y1 e y2.
__________________________________________________

Dibuja un círculo que cuyo centro está en el medio
de la caja de vértices (x1, y1) y (x2, y2).
El color por defecto es un negro opaco.
*/
void dibujarCirculo(BMP& imagen, double centroX, double centroY, double radio, double anguloInicial=0, double anguloFinal=(2 * _PI_), const char* colorRGB="#000000", double alpha=1);

#endif /* EXPORTADOR_H_ */