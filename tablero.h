#ifndef TABLERO_H_
#define TABLERO_H_

#include "listaLigada.h"
#include "casillero.h"

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
template <class TipoVariable>
int menorValor(TipoVariable* elementos, int cantidadElementos);

template <class TipoTablero>
class Tablero {

    private:

        Lista<Lista<Lista<Casillero<TipoTablero>*>*>*>* espacio;

        Casillero<TipoTablero>* ultimoCasillero;

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
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Verifica el contenido de la celda y devuelve una refencia a su contenido,
        permitiendo modificarlo.
        */
        TipoTablero celda(int fil, int col, int prof);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Devuelve una refencia a una celda, más que su contenido, permitiendo su
        potencial modificación.
        */
        Casillero<TipoTablero>* casillero(int fil, int col, int prof);

        /*
        __________________________________________________
        PRE: -
        -
        POS: Se cambia el valor de uan celda del tablero.
        __________________________________________________

        Modifica el valor del contenido del casillero que se encuentra en las
        coordenadas pasadas por parámetro, reemplazándolo por un valor también
        pasado por parámetro.
        */
        void cambiarCelda(int fil, int col, int prof, TipoTablero nuevoContenido);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Devuelve un puntero al último casillero con el que
        se ha interactuado en el último turno.
        */
        Casillero<TipoTablero>* conseguirUltimoCasillero();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Tablero permanece inalterado.
        __________________________________________________

        Cambia el último casillero con el que
        se ha interactuado en el último turno.
        */
        void cambiarUltimoCasillero(Casillero<TipoTablero>* nuevoCasillero);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El tablero permanece inalterado.
        __________________________________________________

        Va a la primera posición de la columna elegida segun las coordenadas
        (columna, profundo) que se elijan, y devuelve un booleano que indica
        si dicha columna no soporta agregar más fichas.
        */
        bool columnaEstaLlena(int columna, int profundo);

        /*
        __________________________________________________
        PRE: -
        -
        POS: El tablero permanece inalterado.
        __________________________________________________

        Devuelve 'false' si alguno de los casilleros en la
        fila más alta de toda el tablero, en cada combinación
        de columnas y profundidad, es la constante VACIO.
        En caso contrario, devuelve 'true'.
        */
        bool tableroEstaLleno();

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

template <class TipoVariable>
int menorValor(TipoVariable* elementos, int cantidadElementos) {

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

    espacio = new Lista<Lista<Lista<Casillero<TipoTablero>*>*>*>;
    ultimoCasillero = NULL;

    for (int fila = 0; fila < altoInicial; fila++) {

        Lista<Lista<Casillero<TipoTablero>*>*>* listaFila = new Lista<Lista<Casillero<TipoTablero>*>*>;
        espacio->agregarPrin(listaFila);

        for (int columna = 0; columna < anchoInicial; columna++) {

            Lista<Casillero<TipoTablero>*>* listaColumna = new Lista<Casillero<TipoTablero>*>;
            (*espacio)[0]->agregarPrin(listaColumna);

            for (int profundidad = 0; profundidad < largoInicial; profundidad++) {

                Casillero<TipoTablero>* nuevoCasillero = new Casillero<TipoTablero>;
                (*(*espacio)[0])[0]->agregarPrin(nuevoCasillero);
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
TipoTablero Tablero<TipoTablero>::celda(int fil, int col, int prof) {

    return casillero(fil, col, prof)->verContenido();
}

template <class TipoTablero>
Casillero<TipoTablero>* Tablero<TipoTablero>::casillero(int fil, int col, int prof) {

    return (*(*(*espacio)[fil])[col])[prof];
}

template <class TipoTablero>
void Tablero<TipoTablero>::cambiarCelda(int fil, int col, int prof, TipoTablero nuevoContenido) {

    casillero(fil, col, prof)->cambiarContenido(nuevoContenido);
}

template <class TipoTablero>
Casillero<TipoTablero>* Tablero<TipoTablero>::conseguirUltimoCasillero() {

    return ultimoCasillero;
}

template <class TipoTablero>
void Tablero<TipoTablero>::cambiarUltimoCasillero(Casillero<TipoTablero>* nuevoCasillero) {


    ultimoCasillero = nuevoCasillero;
}

template <class TipoTablero>
bool Tablero<TipoTablero>::columnaEstaLlena(int columna, int profundo) {

    if (celda(0, columna, profundo) != VACIO) {

        return true;
    }

    return false;
}

template <class TipoTablero>
bool Tablero<TipoTablero>::tableroEstaLleno() {

    int anchoTablero = ancho();
    int largoTablero = largo();

    for (int columna = 0; columna < anchoTablero; columna++) {

        for (int profundo = 0; profundo < largoTablero; profundo++) {

            if (columnaEstaLlena(columna, profundo)) {

                return true;
            }
        }
    }

    return false;
}

template <class TipoTablero>
void Tablero<TipoTablero>::tirarFicha(int columna, int profundo, TipoTablero tipoFicha) {

    if (!columnaEstaLlena(columna, profundo)) {

        int filas = alto();
        int filaElegida = 0;
        int filaActual = 0;

        while (filaActual < filas && celda(filaActual, columna, profundo) == VACIO) {

            filaElegida = filaActual++;
        }

        cambiarUltimoCasillero(casillero(filaElegida, columna, profundo));
        ultimoCasillero->cambiarContenido(tipoFicha);
    }
}

template <class TipoTablero>
void Tablero<TipoTablero>::imprimir() {

    int lados[] = {alto(), ancho(), largo()};
    int ladoMasCorto = menorValor(lados, 3);

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