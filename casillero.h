#ifndef CASILLERO_H_
#define CASILLERO_H_

#include "constantes.h"

/* ----- DECLARACIONES ----- */

template <class TipoCasillero>
class Casillero {

    private:

        TipoCasillero contenido;
        int* coordenadas;

    public:

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Casillero es creado con el valor predeterminado o el
             pasado por parámetro.
        __________________________________________________

        Crea un casillero. El mismo tiene un determinado contenido, que de
        no ser especificado se define VACIO, que viene de "constantes.h".
        */
        Casillero(TipoCasillero nuevoContenido=VACIO);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Casillero ya no existe
        __________________________________________________
        */
        ~Casillero();

        /*
        __________________________________________________
        PRE: El Casillero contiene un dato de tipo válido.
        -
        POS: Se pasa una referencia, así que el Casillero podría ser
             modificado luego.
        __________________________________________________

        Devuelve el dato que contiene el casillero.
        */
        TipoCasillero verContenido();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Contenido del Casillero es modificado.
        __________________________________________________

        Cambia el contenido del casillero por otro dado. Dicho contenido nuevo
        debe ser del mismo tipo que el casillero.
        */
        void cambiarContenido(TipoCasillero nuevoContenido);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Casillero permanece inalterado.
        __________________________________________________

        Verifica el contenido del casillero. Devuelve 'true' si el contenido es
        VACIO, si no devuelve 'false'.
        */
        bool estaVacio();
};

/* ----- DEFINICIONES ----- */

template <class TipoCasillero>
Casillero<TipoCasillero>::Casillero(TipoCasillero nuevoContenido) {

    this->contenido = nuevoContenido;
}

template <class TipoCasillero>
Casillero<TipoCasillero>::~Casillero() {

    // Por el momento no se usó memoria dinámica, por lo que no hay que eliminar nada realmente.
}

template <class TipoCasillero>
TipoCasillero Casillero<TipoCasillero>::verContenido() {

    return this->contenido;
}

template <class TipoCasillero>
void Casillero<TipoCasillero>::cambiarContenido(TipoCasillero nuevoContenido) {

    this->contenido = nuevoContenido;
}

template <class TipoCasillero>
bool Casillero<TipoCasillero>::estaVacio() {

    if (this->contenido == VACIO) {

        return true;
    }

    return false;
}

#endif /* CASILLERO_H_ */