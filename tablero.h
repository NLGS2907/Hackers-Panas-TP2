#ifndef TABLERO_H_
#define TABLERO_H_
#include "listaLigada.h"
#include "constantes.h"
#include <iostream>

/* ----- DECLARACIONES ----- */

template <class TipoTablero>
class Tablero {

    private:

        Lista<Lista<Lista<TipoTablero>*>*>* espacio;

        void _imprimir(char ladoCorto);

        /*
        Deuelve el dato que hay en las coordenadas corresponientes, las cuales
        cambian segun que ejes sean `prim`, `seg` y `ter`. Por eso se decide con
        un parametro adicional `ladoCorto`.
        */
        TipoTablero _verificarCelda(int prim, int seg, int ter, char ladoCorto);

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

        /*
        Se detecta el lado mas corto automaticamente y se usa el plano normal al mismo.
        Si los tres lados tienen la misma longitud se utilizara el plano ANCHO-ALTO.
        */
       void imprimir();

        /*
        Imprime el tablero por pantalla mostrando slices de un un plano que sea
        normal al lado seleccionado.

        'x' o 'X' utiliza el plano de ALTO ^ LARGO >.
        'y' o 'Y' utiliza el plano de ANCHO ^ LARGO >.
        'z' o 'Z' utiliza el plano de ANCHO ^ ALTO >.

        Cualquier otro caracter hará que se llame a `imprimir()`.
        */
        void imprimir(char ladoCorto);
};

/* ----- DEFINICIONES ----- */

template <class TipoTablero>
Tablero<TipoTablero>::Tablero(int anchoInic, int altoInic, int largoInic) {

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

template <class TipoTablero>
void Tablero<TipoTablero>::imprimir() {

    int lados[] = {alto(), ancho(), largo()};
    int ladoMasCorto = 99999999; // Valor Basura

        for (int i = 0; i < 3; i++) {

            if (lados[i] <= ladoMasCorto) {

                ladoMasCorto = lados[i];
            }
        }

        if (ladoMasCorto == lados[2]) {

            _imprimir('z');

        } else if (ladoMasCorto == lados[1]) {

            _imprimir('x');

        } else {

            _imprimir('y');
        }
}

template <class TipoTablero>
void Tablero<TipoTablero>::imprimir(char ladoCorto) {

    switch (ladoCorto) {

        case 'x':
        case 'X':
        case 'y':
        case 'Y':
        case 'z':
        case 'Z':
        _imprimir(ladoCorto);
        break;

        default:

        imprimir();
    }
}

template <class TipoTablero>
void Tablero<TipoTablero>::_imprimir(char ladoCorto) {

    int filas = alto();
    int columnas = ancho();
    int profundidad = largo();

    int primero, segundo, tercero;
    char primEje, segEje;

    if (ladoCorto == 'x' || ladoCorto == 'X') {

        primero = columnas;
        segundo = filas;
        tercero = profundidad;

        primEje = 'Y';
        segEje = 'Z';

    } else if (ladoCorto == 'y' || ladoCorto == 'Y') {

        primero = filas;
        segundo = profundidad;
        tercero = columnas;

        primEje = 'Z';
        segEje = 'X';

    } else if (ladoCorto == 'z' || ladoCorto == 'Z') {

        primero = profundidad;
        segundo = filas;
        tercero = columnas;

        primEje = 'Y';
        segEje = 'X';
    }

    for (int prim = 0; prim < primero; prim++) {

        std::cout << primEje << " ^ " << segEje << " >\n" << std::endl;

        for (int seg = 0; seg < segundo; seg++) {

            std::cout << "[  ";

            for (int ter = 0; ter < tercero; ter++) {

                std::cout << _verificarCelda(prim, seg, ter, ladoCorto) << "  ";

            }

            std::cout << "]\n\n";
        }
    }

}

template <class TipoTablero>
TipoTablero Tablero<TipoTablero>::_verificarCelda(int prim, int seg, int ter, char ladoCorto) {

    if (ladoCorto == 'x' || ladoCorto == 'X') {

        return celda(seg, prim, ter);

    } else if (ladoCorto == 'y' || ladoCorto == 'Y') {

        return celda(prim, ter, seg);

    } else /* if (ladoCorto == 'z' || ladoCorto == 'Z') */ {

        return celda(seg, ter, prim);
    }
}

#endif /* TABLERO_H_ */