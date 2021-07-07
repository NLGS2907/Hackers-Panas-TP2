#ifndef TABLERO_H_
#define TABLERO_H_

#include "listaLigada.h"
#include "casillero.h"

#include <iostream>

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

        Deuelve 'true' si las coordenadas pasadas por parámetro están
        dentro de los límites del tablero. En caso contrario, devuelve
        'false'.
        */
        bool _coordenadasSonValidas(int x, int y, int z);

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
        POS: El tablero permanece inalterado.
        __________________________________________________

        Recorre toda dirección desde el ultimo casillero jugando, en busca de
        que haya N fichas alineadas del mismo tipo en dicha dirección, en tal
        caso devuelve 'true'. En caso contrario devuelve 'false'.
        */
        bool ganoAlguien(int nEnLinea);

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

    this->espacio = new Lista<Lista<Lista<Casillero<TipoTablero>*>*>*>;
    this->ultimoCasillero = NULL;

    for (int fila = 0; fila < altoInicial; fila++) {

        Lista<Lista<Casillero<TipoTablero>*>*>* listaFila = new Lista<Lista<Casillero<TipoTablero>*>*>;
        this->espacio->agregarFin(listaFila);

        for (int columna = 0; columna < anchoInicial; columna++) {

            Lista<Casillero<TipoTablero>*>* listaColumna = new Lista<Casillero<TipoTablero>*>;
            listaFila->agregarFin(listaColumna);

            for (int profundidad = 0; profundidad < largoInicial; profundidad++) {

                Casillero<TipoTablero>* nuevoCasillero = new Casillero<TipoTablero>(columna, fila, profundidad);
                listaColumna->agregarFin(nuevoCasillero);
            }
        }
    }

    for (int fila = 0; fila < altoInicial; fila++) {

        for (int columna = 0; columna < anchoInicial; columna++) {

            for (int profundidad = 0; profundidad < largoInicial; profundidad++) {

                for (int i = -1; i <= 1; i++) {

                    for (int j = -1; j <= 1; j++) {

                        for (int k = -1; k <= 1; k++) {
                            
                            Casillero<TipoTablero>* casilleroVecino = this->casillero(fila + j, columna + i, profundidad + k);
                            this->casillero(fila, columna, profundidad)->cambiarVecino(casilleroVecino, i, j, k);
                        }
                    }
                }
            }
        }
    }
}

template <class TipoTablero>
Tablero<TipoTablero>::~Tablero() {

    int filas = this->alto();
    int columnas = this->ancho();

    for (int fil = 0; fil < filas; fil++) {

        for (int col = 0; col < columnas; col++) {

            delete this->espacio->obtener(fil)->obtener(col);
        }

        delete this->espacio->obtener(fil);
    }

    delete this->espacio;
}

template <class TipoTablero>
int Tablero<TipoTablero>::alto() {

    return this->espacio->len();
}

template <class TipoTablero>
int Tablero<TipoTablero>::ancho() {

    return this->espacio->obtener(0)->len();
}

template <class TipoTablero>
int Tablero<TipoTablero>::largo() {

    return this->espacio->obtener(0)->obtener(0)->len();
}

template <class TipoTablero>
TipoTablero Tablero<TipoTablero>::celda(int fil, int col, int prof) {

    return this->casillero(fil, col, prof)->verContenido();
}

template <class TipoTablero>
Casillero<TipoTablero>* Tablero<TipoTablero>::casillero(int fil, int col, int prof) {

    if (!_coordenadasSonValidas(col, fil, prof)) {

        return NULL;
    }

    return this->espacio->obtener(fil)->obtener(col)->obtener(prof);
}

template <class TipoTablero>
void Tablero<TipoTablero>::cambiarCelda(int fil, int col, int prof, TipoTablero nuevoContenido) {

    this->casillero(fil, col, prof)->cambiarContenido(nuevoContenido);
}

template <class TipoTablero>
Casillero<TipoTablero>* Tablero<TipoTablero>::conseguirUltimoCasillero() {

    return this->ultimoCasillero;
}

template <class TipoTablero>
void Tablero<TipoTablero>::cambiarUltimoCasillero(Casillero<TipoTablero>* nuevoCasillero) {

    this->ultimoCasillero = nuevoCasillero;
}

template <class TipoTablero>
bool Tablero<TipoTablero>::columnaEstaLlena(int columna, int profundo) {

    if (this->celda(0, columna, profundo) != VACIO) {

        return true;
    }

    return false;
}

template <class TipoTablero>
bool Tablero<TipoTablero>::tableroEstaLleno() {

    int anchoTablero = this->ancho();
    int largoTablero = this->largo();

    for (int columna = 0; columna < anchoTablero; columna++) {

        for (int profundo = 0; profundo < largoTablero; profundo++) {

            if (this->columnaEstaLlena(columna, profundo)) {

                return true;
            }
        }
    }

    return false;
}

template <class TipoTablero>
void Tablero<TipoTablero>::tirarFicha(int columna, int profundo, TipoTablero tipoFicha) {

    if (!this->columnaEstaLlena(columna, profundo)) {

        int filas = alto();
        int filaElegida = 0;
        int filaActual = 0;

        while (filaActual < filas && celda(filaActual, columna, profundo) == VACIO) {

            filaElegida = filaActual;
            filaActual++;
        }

        this->cambiarUltimoCasillero(casillero(filaElegida, columna, profundo));
        this->conseguirUltimoCasillero()->cambiarContenido(tipoFicha);
    }
}

template <class TipoTablero>
bool Tablero<TipoTablero>::ganoAlguien(int nEnLinea) {

    int cantidadades [3][3][3];

    for(int i = -1; i < 2 ; i++) {

        for (int j = -1; j < 2; j++) {

            for (int k = -1; k < 2; k++) {

                cantidadades[i + 1][j + 1][k + 1] = 0;
            }
        }
    }

    for(int i = -1; i < 2 ; i++){

        for(int j = -1; j < 2; j++){

            for(int k = -1; k < 2; k++){

                if (!(i == 0 && j == 0 && k == 0) && this->_coordenadasSonValidas(this->conseguirUltimoCasillero()->coordenadaX() + i,
                                                                                  this->conseguirUltimoCasillero()->coordenadaY() + j,
                                                                                  this->conseguirUltimoCasillero()->coordenadaZ() + k)) {

                    Casillero<TipoTablero>* vecino = this->conseguirUltimoCasillero()->conseguirVecino(i, j, k);

                    while(vecino->esMismoContenido(this->conseguirUltimoCasillero())) {

                        cantidadades[i + 1][j + 1][k + 1]++;

                        if (!this->_coordenadasSonValidas(vecino->coordenadaX() + i, vecino->coordenadaY()+ j, vecino->coordenadaZ() + k)) {

                            break;
                        }

                        vecino = vecino->conseguirVecino(i, j, k);
                    }
                }
            }
        }
    }

    for(int i = -1; i <= 1; i++) {

        for (int j = -1; j <= 1; j++) {

            for (int k = -1; k <= 1; k++) {

                if ((cantidadades[i + 1][j + 1][k + 1] + cantidadades[-i + 1][-j + 1][-k + 1] + 1) >= nEnLinea) {

                    return true;
                }
            }
        }
    }

    return false;
}

template <class TipoTablero>
void Tablero<TipoTablero>::imprimir() {

    int lados[] = {this->alto(), this->ancho(), this->largo()};
    int ladoMasCorto = menorValor(lados, 3);

    if (ladoMasCorto == lados[2]) {

        this->_imprimir('z');

    } else if (ladoMasCorto == lados[1]) {

        this->_imprimir('x');

    } else {

        this->_imprimir('y');
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
        this->_imprimir(ladoCorto);
        break;

        default:
        this->imprimir();
    }
}

template <class TipoTablero>
void Tablero<TipoTablero>::_imprimir(char ladoCorto) {

    int filas = this->alto();
    int columnas = this->ancho();
    int profundidad = this->largo();

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

                std::cout << this->_verificarCelda(prim, seg, ter, ladoCorto) << "  ";

            }

            std::cout << "]\n\n";
        }
    }

}

template <class TipoTablero>
bool Tablero<TipoTablero>::_coordenadasSonValidas(int x, int y, int z) {

    if (x < 0 || x >= this->ancho() || y < 0 || y >= this->alto() || z < 0 || z >= this->largo()) {

        return false;
    }

    return true;
}

template <class TipoTablero>
TipoTablero Tablero<TipoTablero>::_verificarCelda(int prim, int seg, int ter, char ladoCorto) {

    if (ladoCorto == 'x' || ladoCorto == 'X') {

        return this->celda(seg, prim, ter);

    } else if (ladoCorto == 'y' || ladoCorto == 'Y') {

        return this->celda(prim, ter, seg);

    } else /* if (ladoCorto == 'z' || ladoCorto == 'Z') */ {

        return this->celda(seg, ter, prim);
    }
}

#endif /* TABLERO_H_ */