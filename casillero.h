#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "constantes.h"

/* ----- DECLARACIONES ----- */

template <class TipoCasillero>
class Casillero {

    private:

        TipoCasillero contenido;

    public:

        /*
        Crea un casillero. El mismo tiene un determinado contenido, que de
        no ser especificado se define VACIO, que viene de "constantes.h".
        */
        Casillero(TipoCasillero nuevoContenido=VACIO);

        /*
        Devuelve el dato que contiene el casillero.
        */
        TipoCasillero& verContenido();

        /*
        Cambia el contenido del casillero por otro dado. Dicho contenido nuevo
        debe ser del mismo tipo que el casillero.
        */
        void cambiarContenido(TipoCasillero nuevoContenido);
};

/* ----- DEFINICIONES ----- */

template <class TipoCasillero>
Casillero<TipoCasillero>::Casillero(TipoCasillero nuevoContenido) {

    contenido = nuevoContenido;
}

template <class TipoCasillero>
TipoCasillero& Casillero<TipoCasillero>::verContenido() {

    return contenido;
}

template <class TipoCasillero>
void Casillero<TipoCasillero>::cambiarContenido(TipoCasillero nuevoContenido) {

    contenido = nuevoContenido;
}

#endif /* CASILLERO_H_ */