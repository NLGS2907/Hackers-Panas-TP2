#ifndef CASILLERO_H_
#define CASILLERO_H_

#include <iostream>

#define VACIO '.' // Valor que se guarda en una celda vacía del tablero.

/* ----- DECLARACIONES ----- */

template <class TipoCasillero>
class Casillero {

    private:

        TipoCasillero contenido;
        Casillero<TipoCasillero>* vecinos[3][3][3]; // El centro es NULL.
        int coordX;
        int coordY;
        int coordZ;

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Deuelve 'true' si tanto 'i', 'j' y 'k' son numeros enteros con valores
        entre -1 y 1 inclusive. Si alguno no cumple esa función devuelve 'false'.
        */
        bool _verficiarCoordenadasVecino(int i, int j, int k);

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
        Casillero(int x, int y, int z, TipoCasillero nuevoContenido=VACIO);

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
        POS: El Casillero permanece inalterado.
        __________________________________________________

        Devuelve el valor de la coordenada X del Casillero.
        */
        int coordenadaX();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Casillero permanece inalterado.
        __________________________________________________

        Devuelve el valor de la coordenada Y del Casillero.
        */
        int coordenadaY();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Casillero permanece inalterado.
        __________________________________________________

        Devuelve el valor de la coordenada Z del Casillero.
        */
        int coordenadaZ();

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

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Casillero permanece inalterado.
        __________________________________________________

        Verifica el contenido de otro casillero pasado por parámetro, y devuelve
        'true' si dicho contenido es el mismo. En caso contrario, devuelve 'false'.
        */
        bool esMismoContenido(Casillero<TipoCasillero>* otroCasillero);

        /*
        __________________________________________________
        PRE: Los numeros pasados por parámetro tienen que estar entre
             -1 y 1 inclusive.
        -
        POS: El Casillero permanece inalterado.
        __________________________________________________

        Devuelve un casillero que es vecino del que estamos parados, segun las
        coordenadas relativas que se pasan por parámetro.
        */
        Casillero<TipoCasillero>* conseguirVecino(int x, int y, int z);

        /*
        __________________________________________________
        PRE: Los numeros pasados por parámetro tienen que estar entre
             -1 y 1 inclusive.
        -
        POS: Se cambian uno de los vecinos del casillero.
        __________________________________________________

        Modifica uno de los valores de la matriz de vecinos del casillero, de
        manera que ahora tiene el pasado por parámetro.
        */
        void cambiarVecino(Casillero<TipoCasillero>* nuevoVecino, int x, int y, int z);
};

/* ----- DEFINICIONES ----- */

template <class TipoCasillero>
Casillero<TipoCasillero>::Casillero(int x, int y, int z, TipoCasillero nuevoContenido) {

    this->coordX = x;
    this->coordY = y;
    this->coordZ = z;
    this->contenido = nuevoContenido;
}

template <class TipoCasillero>
Casillero<TipoCasillero>::~Casillero() {}

template <class TipoCasillero>
TipoCasillero Casillero<TipoCasillero>::verContenido() {

    return this->contenido;
}

template <class TipoCasillero>
int Casillero<TipoCasillero>::coordenadaX() {

    return this->coordX;
}

template <class TipoCasillero>
int Casillero<TipoCasillero>::coordenadaY() {

    return this->coordY;
}

template <class TipoCasillero>
int Casillero<TipoCasillero>::coordenadaZ() {

    return this->coordZ;
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

template <class TipoCasillero>
bool Casillero<TipoCasillero>::esMismoContenido(Casillero<TipoCasillero>* otroCasillero) {

    if (this->verContenido() == otroCasillero->verContenido()) {

        return true;
    }

    return false;
}

template <class TipoCasillero>
Casillero<TipoCasillero>* Casillero<TipoCasillero>::conseguirVecino(int x, int y, int z) {

    if (!_verficiarCoordenadasVecino(x, y, z)) {

        std::cout << "Las coordenadas (" << x << ", " << y << ", " << z << ") no son válidas. Cada valor debe estar entre -1 y 1 inclusive." << std::endl;
    }

    return this->vecinos[x + 1][y + 1][z + 1];
}

template <class TipoCasillero>
void Casillero<TipoCasillero>::cambiarVecino(Casillero<TipoCasillero>* nuevoVecino, int x, int y, int z) {

    if (!_verficiarCoordenadasVecino(x, y, z)) {

        std::cout << "Las coordenadas (" << x << ", " << y << ", " << z << ") no son válidas. Cada valor debe estar entre -1 y 1 inclusive." << std::endl;
    }

    if (x == 0 && y == 0 && z == 0) {

        return;
    }

    this->vecinos[x + 1][y + 1][z + 1] = nuevoVecino;
}

template <class TipoCasillero>
bool Casillero<TipoCasillero>::_verficiarCoordenadasVecino(int i, int j, int k) {

    if (i < -1 || i > 1 || j < -1 || j > 1 || k < -1 || k > 1) {

        return false;
    }

    return true;
}

#endif /* CASILLERO_H_ */