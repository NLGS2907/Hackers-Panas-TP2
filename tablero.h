#ifndef TABLERO_H_
#define TABLERO_H_
#include "listaLigada.h"
#include "casillero.h"
#include "constantes.h"
// '<iostream>' ya fue incluido en "listaLigada.h"

/* ----- DECLARACIONES ----- */

/*
__________________________________________________
PRE: El arreglo pasado debe de tener al menos 1 elemento.
-
POS: El arreglo permanece inalterado, ya que solo se lo usa
     para leer los datos.
__________________________________________________

Devuelve el elemento de menor valor del arreglo de enteros pasado
por parametro.
*/
int menorValor(int cantidadElementos, int* elementos);

template <class TipoTablero>
class Tablero {

    private:

        Lista<Lista<Lista<Casillero<TipoTablero> >*>*>* espacio;

        void _imprimir(char ladoCorto);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Deuelve el dato que hay en las coordenadas corresponientes, las cuales
        cambian segun que ejes sean `prim`, `seg` y `ter`. Por eso se decide con
        un parametro adicional `ladoCorto`.
        */
        TipoTablero _verificarCelda(int prim, int seg, int ter, char ladoCorto);

    public:

        /*
        __________________________________________________
        PRE: -
        -
        POS: Se crea un tablero con los datos pasados por parámetro.
        __________________________________________________

        Crea un tablero de tres (3) dimensiones ALTO-ANCHO-LARGO, que deben ser
        especificadas en el constructor.
        */
        Tablero(int anchoInicial, int altoInicial, int largoInicial);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero ya no existe.
        __________________________________________________

        Libera la memoria que ocupa el tablero llamando al destructor de cada lista
        que conforma el mismo.
        */
        ~Tablero();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Devuelve el ALTO del tablero.
        */
        int alto();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Devuelve el ANCHO del tablero.
        */
        int ancho();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Devuelve el LARGO del tablero.
        */
        int largo();
        

        /*
        __________________________________________________
        PRE: -
        -
        POS: Se pasa una referencia, por lo que el Tablero podría ser modificado.
        __________________________________________________

        Verifica el contenido de la celda y devuelve una refencia a su contenido,
        permitiendo modificarlo.
        */
        TipoTablero& celda(int fil, int col, int prof);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero es modificado, porque se cambia el valor de uno de sus
             casilleros.
        __________________________________________________

        Deja caer una ficha en la columna correspondiente segun las coordenadas
        (columna, profundo) que se elijan.
        */
        void tirarFicha(int columna, int profundo, TipoTablero tipoFicha);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Se detecta el lado mas corto automaticamente y se usa el plano normal al mismo.
        Si los tres lados tienen la misma longitud se utilizara el plano ALTO ^ ANCHO >.
        */
        void imprimir();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Imprime el tablero por pantalla mostrando slices de un un plano que sea
        normal al lado seleccionado.

        'x' o 'X' utiliza el plano de ALTO ^ LARGO >.
        'y' o 'Y' utiliza el plano de LARGO ^ ANCHO >.
        'z' o 'Z' utiliza el plano de ALTO ^ ANCHO >.

        Cualquier otro caracter hará que se llame a `imprimir()`.
        */
        void imprimir(char ladoCorto);
};

/* ----- DEFINICIONES ----- */

int menorValor(int cantidadElementos, int* elementos) {

    int valorMasChiquito = 99999999; // Valor Basura

    for (int i = 0; i < cantidadElementos; i++) {

        if (elementos[i] <= valorMasChiquito) {

            valorMasChiquito = elementos[i];
        }
    }

    return valorMasChiquito;
}

template <class TipoTablero>
Tablero<TipoTablero>::Tablero(int anchoInicial, int altoInicial, int largoInicial) {

    espacio = new Lista<Lista<Lista<Casillero<TipoTablero> >*>*>;

    for (int fila = 0; fila < altoInicial; fila++) {

        Lista<Lista<Casillero<TipoTablero> >*>* listaFila = new Lista<Lista<Casillero<TipoTablero> >*>;
        espacio->agregarPrin(listaFila);

        for (int columna = 0; columna < anchoInicial; columna++) {

            Lista<Casillero<TipoTablero> >* listaColumna = new Lista<Casillero<TipoTablero> >;
            (*espacio)[0]->agregarPrin(listaColumna);

            for (int profundidad = 0; profundidad < largoInicial; profundidad++) {

                (*(*espacio)[0])[0]->agregarPrin(Casillero<TipoTablero>());
            }
        }
    }
}

template <class TipoTablero>
Tablero<TipoTablero>::~Tablero() {

    int filas = alto();
    int columnas = ancho();

    for (int fil = 0; fil < filas; fil++) {

        for (int col = 0; col < columnas; col++) {

            delete (*(*espacio)[fil])[col];
        }

        delete (*espacio)[fil];
    }

    delete espacio;
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

    return (*(*(*espacio)[fil])[col])[prof].verContenido();
}

template <class TipoTablero>
void Tablero<TipoTablero>::tirarFicha(int columna, int profundo, TipoTablero tipoFicha) {

    int filas = alto();
    int filaElegida = 0;
    int filaActual = 0;

    while (filaActual < filas && celda(filaActual, columna, profundo) == VACIO) {

        filaElegida = filaActual++;
    }

    celda(filaElegida, columna, profundo) = tipoFicha;
}

template <class TipoTablero>
void Tablero<TipoTablero>::imprimir() {

    int lados[] = {alto(), ancho(), largo()};
    int ladoMasCorto = menorValor(3, lados);

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