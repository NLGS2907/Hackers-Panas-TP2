#ifndef EXPORTADORTDA_H_
#define EXPORTADORTDA_H_

/*
Este archivo contiene las declaraciones del TDA Exportador, y sus
funciones internas.
*/
#include "exportadorExterno.h"
#include "juego.h"
#include <string>
#include <sstream>

// Para cálculos internos
#define TAMANIO_CELDA 50
#define MARGEN_X 25
#define MARGEN_Y 25
#define ANCHURA 8
#define RADIO_FICHAS 10

// Colores
#define COLOR_FONDO "#aaaaaa"
#define AZUL_OSCURO "#0f0052"

/*
__________________________________________________
PRE: 'numero' es un tipo de dato válido (normalmente uno
      de tipo <int>).
-
POS: Convierte al dato en uno de tipo 'std::string'.
__________________________________________________
*/
template <class Tipo>
std::string numeroAString(Tipo numero) {

     std::ostringstream ss;
     ss << numero;

     return ss.str();
}

class Exportador {

     private:

          BMP imagen;
          Juego* juego;
          std::string rutaSalida;

     public:

          /*
          __________________________________________________
          PRE: Las rutas de entrada y salida son direcciones válidas.
          -
          POS: El Exportador es creado y se guarda su ruta de salida.
          __________________________________________________
          */
          Exportador(std::string rutaDeEntrada, std::string rutaDeSalida);

          /*
          __________________________________________________
          PRE: La ruta de salida es una dirección válida.
          -
          POS: El Exportador es creado y se guarda su ruta de salida.
          __________________________________________________
          */
          Exportador(Juego* nuevoJuego);

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
          void setRutaEntrada(std::string nuevaEntrada);

          /*
          __________________________________________________
          PRE: -
          -
          POS: Se devuelve un arreglo de chars que es la dirección
               de la ruta de salida.
          __________________________________________________
          */
          std::string getRutaSalida();

          /*
          __________________________________________________
          PRE: La nueva ruta de salida ingresada debe ser una dirección
               válida.
          -
          POS: El atributo interno 'rutaSalida' es cambiado por la
               dirección pasada por parámetro.
          __________________________________________________
          */
          void setRutaSalida(std::string nuevaSalida);

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

          /*
          __________________________________________________
          PRE: -
          -
          POS: La ruta de salida del Exportador se cambia.
          __________________________________________________

          Modifica 'this->rutaSalida' según la ronda y turno actuales
          en el que se esté jugando en el juego.
          */
          void actualizarRutaSalida(int rondaActual=1, int turnoActual=1);

          /*
          __________________________________________________
          PRE: -
          -
          POS: El Exportador permanece inalterado.
          __________________________________________________
          
          Dibuja en un BMP el estado actual del tablero del juego.
          */
          void dibujarTablero();
};

#endif /* EXPORTADORTDA_H_ */