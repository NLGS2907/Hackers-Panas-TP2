#ifndef EXPORTADORTDA_H_
#define EXPORTADORTDA_H_

/*
Este archivo contiene las declaraciones del TDA Exportador, y sus
funciones internas.
*/

#include "easyBMP.h"
#include "EasyBMP_Geometry.h"
#include "constantes.h"

typedef struct Cubo {

     // Basándonos en el diagrama "Cubo_Coordenadas.png":

     double x0, x1, x2, x3,
            y0, y1, y2, y3,
            y4, y5, y6, y7; // Los componentes de las coordenadas de los vértices.

     double dy; // La distancia entre y0-y4, y1-y5, etc.

     double r1; // Radio para indicar qué tan grandes se dibujan las fichas.

} Cubo;

class Exportador {

     private:

          BMP imagen;
          Cubo cubo;
          const char* rutaSalida;

     public:

          /*
          __________________________________________________
          PRE: Las rutas de entrada y salida son direcciones válidas.
          -
          POS: El Exportador es creado y se guarda su ruta de salida.
          __________________________________________________
          */
          Exportador(const char* rutaDeEntrada, const char* rutaDeSalida);

          // /*
          // __________________________________________________
          // PRE: La ruta de salida es uan dirección válida.
          // -
          // POS: El Exportador es creado y se guarda su ruta de salida.
          // __________________________________________________
          // */
          // template <class TipoTablero>
          // Exportador(Tablero<TipoTablero> tablero, const char* rutaDeSalida);

          /*
          __________________________________________________
          PRE: -
          -
          POS: Se edita el archivo que hay en la dirección de salida
               con los cambios hechos en el BMP hasta el momento. Si el
               archivo en cuestión no existe, se crea.
          __________________________________________________

          "Guarda" el TDA BMP, escribiendo los cambios en la ruta de
          salida correspondiente.
          */
          void guardar();

          /*
          __________________________________________________
          PRE: La nueva ruta de entrada ingresada debe ser una dirección
               válida.
          -
          POS: El TDA BMP es modificado.
          __________________________________________________

          El TDA BMP, guardado en el atributo interno 'imagen',
          es descartado (aunque no se hayan guardado los posibles
          cambios); y se lo reemplaza por el que esta en la dirección
          pasada por parámetro.
          */
          void setRutaEntrada(const char* nuevaEntrada);

          /*
          __________________________________________________
          PRE: -
          -
          POS: Se devuelve un arreglo de chars que es la dirección
               de la ruta de salida.
          __________________________________________________
          */
          const char* getRutaSalida();

          /*
          __________________________________________________
          PRE: La nueva ruta de salida ingresada debe ser una dirección
               válida.
          -
          POS: El atributo interno 'rutaSalida' es cambiado por la
               dirección pasada por parámetro.
          __________________________________________________
          */
          void setRutaSalida(const char* nuevaSalida);

          /*
          __________________________________________________
          PRE: Las coordenadas pasadas por parámetro están dentro
               de los márgenes de la imagen.
          -
          POS: El Exportador permanece inalterado.
          __________________________________________________

          Devuelve un TDA RGBApixel con los valores RGBA del
          color cuyos datos guarda.
          Si las coordenadas no están dentro de la imagen, tira
          una excepción en lugar de no hacer nada, ya que es peligroso
          que devuelva valores erróneos.
          */
          RGBApixel conseguirPixel(int x, int y);
};

// template <class TipoTablero>
// Exportador::Exportador(Tablero<TipoTablero> tablero, const char* rutaDeSalida) {

//      imagen.SetSize(tablero.ancho() * (1300.0 / 6.0), tablero.alto() * (1100.0 / 6.0));

//      double anchoImagen, altoImagen;
//      anchoImagen = imagen.TellWidth();
//      altoImagen = imagen.TellHeight();

//      // Inicializamos los valores de los ejes de los vértices
//      cubo.x0 = anchoImagen / 13; cubo.x1 = anchoImagen / 2.6; cubo.x2 = anchoImagen / 1.625; cubo.x3 = anchoImagen / (13.0 / 12.0);
//      cubo.y0 = altoImagen / 11; cubo.y1 = altoImagen / (110.0 / 15.0); cubo.y2 = altoImagen / 5.5; cubo.y3 = altoImagen / 4.4;
//      cubo.dy = (anchoImagen + altoImagen) / 3.2;
//      cubo.y4 = cubo.y0 + cubo.dy; cubo.y5 = cubo.y1 + cubo.dy; cubo.y6 = cubo.y2 + cubo.dy; cubo.y7 = cubo.y3 + cubo.dy;

// }

#endif /* EXPORTADORTDA_H_ */