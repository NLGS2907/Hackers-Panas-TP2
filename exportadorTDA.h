#ifndef EXPORTADORTDA_H_
#define EXPORTADORTDA_H_

/*
Este archivo contiene al TDA Exportador, y sus funciones internas.
*/

#include "easyBMP.h"

class Exportador {

     private:

          BMP imagen;
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

#endif /* EXPORTADORTDA_H_ */