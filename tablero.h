#ifndef TABLERO_H_
#define TABLERO_H_
#include "listaLigada.h"
#include "constantes.h"

/* ----- DECLARACIONES ----- */

template <class TipoTablero>
class Tablero {

    private:

        Lista<Lista<Lista<TipoTablero>*>*>* espacio;

    public:

        /*
        Crea un tablero de tres (3) dimensiones ALTO-ANCHO-LARGO, que deben ser
        especificadas en el constructor.
        */
        Tablero(int altoInic, int anchoInic, int largoInic);

        /*
        Devuelve el ALTO del tablero.
        */
        int alto();

        /*
        Devuelve el ANCHO del tablero.
        */
        int ancho();

        /*
        Devuelve el LARGO del tablero.
        */
        int largo();

        /*
        Verifica el contenido de la celda y devuelve una refencia a su contenido,
        permitiendo modificarlo.
        */
        TipoTablero& celda(int fil, int col, int prof);
};

/* ----- DEFINICIONES ----- */

template <class TipoTablero>
Tablero<TipoTablero>::Tablero(int altoInic, int anchoInic, int largoInic) {

    espacio = new Lista<Lista<Lista<TipoTablero>*>*>;

    for (int fila = 0; fila < altoInic; fila++) {

        Lista<Lista<TipoTablero>*>* listaFila = new Lista<Lista<TipoTablero>*>;
        espacio->agregarFin(listaFila);

        for (int columna = 0; columna < anchoInic; columna++) {

            Lista<TipoTablero>* listaColumna = new Lista<TipoTablero>;
            (*espacio)[fila]->agregarFin(listaColumna);

            for (int profundidad = 0; profundidad < largoInic; profundidad++) {

                (*(*espacio)[fila])[columna]->agregarFin(VACIO);
            }
        }
    }
}

template <class TipoTablero>
int Tablero<TipoTablero>::alto() {

    return espacio->len();
}

template <class TipoTablero>
int Tablero<TipoTablero>::ancho() {

    return (*espacio)[0]->len();
}

template <class TipoTablero>
int Tablero<TipoTablero>::largo() {

    return (*(*espacio)[0])[0]->len();
}

template <class TipoTablero>
TipoTablero& Tablero<TipoTablero>::celda(int fil, int col, int prof) {

    return (*(*(*espacio)[fil])[col])[prof];
}

#endif /* TABLERO_H_ */