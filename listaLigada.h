#ifndef LISTALIGADA_H_
#define LISTALIGADA_H_

#include "nodo.h"
#include <iostream>

/* ----- DECLARACIONES ----- */

template <class TipoLista>
class Lista {

    private:

        Nodo<TipoLista>* prim; // Primer nodo de la lista
        int cant; // Sin importar el TipoLista de dato, la cantidad debería ser <int>
        Nodo<TipoLista>* cursor;

        /*
        __________________________________________________
        PRE: -
        -
        POS: Devuelve el nodo en la posición especificada.
        __________________________________________________
        */
        Nodo<TipoLista>* obtenerNodo(int posicion);
    
    public:

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista es creada con sus valores predeterminados.
        __________________________________________________

        Inicializa una nueva lista, cuyo primer nodo apunta a NULL.
        */
        Lista();

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista es creada con sus valores copiados de otra
             pasada por parámetro.
        __________________________________________________

        Inicializa una nueva lista con los mismos elementos que otra
        lista indicada, creando una copia.
        */
        Lista(Lista<TipoLista>& otraLista);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La lista ya no existe.
        __________________________________________________

        Destruye todos los nodos de la lista, liberando el espacio que ocupaban en la
        memoria dinamica
        */
        ~Lista();

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Verifica si el nodo primero es NULL, y devulve 'true' si es el caso. Caso contrario
        devuelve 'false'.
        */
        bool estaVacia();

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Devuelve la cantidad de elementos de la lista.
        */
        int len();

        /*
        __________________________________________________
        PRE: -
        -
        POS: Deja el cursor de la lista preparado para hacer
             un nuevo recorrido.
        __________________________________________________
        */
        void iniciarCursor();

        /*
        __________________________________________________
        PRE: Se ha iniciado ya el cursor mediante iniciarCursor().
             y no se ha mutado la lista, quitando ni agregando Nodos,
             desde entonces.
        -
        POS: Mueve el cursor posicionándolo en el Nodo siguiente al
             cual está parado actualmente dicho cursor.
        __________________________________________________

        Devuelve 'true' si el cursor queda parado sobre un Nodo. Si, por el contrario, el
        cursor queda apuntando a NULL, devuelve 'false'.
        */
        bool avanzarCursor();

        /*
        __________________________________________________
        PRE: El cursor está posicionado sobre un Nodo con dato (avanazarCursor() devolvió
             'true').
        -
        POS: Devuelve el dato del Nodo al cual está apuntando el cursor actualmente.
        __________________________________________________
        */
        TipoLista obtenerDatoCursor();

        /*
        __________________________________________________
        PRE: La lista no debe estar vacía y el índice indicado debe ser
             entre 0 y uno menos que la cantidad de Nodos (los índices van
             desde 0 hasta n - 1).
        -
        POS: Se pasa el dato de la posición indicada.
        __________________________________________________

        Devuelve el dato que esta en el nodo cuyo indice es el pasado por parametro.
        */
        TipoLista obtener(int indice);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Ingresa un nodo con un nuevo dato al principio de toda la lista, antes del primer nodo.
        */
        void agregarPrin(TipoLista elemento);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Ingresa un nodo con un nuevo dato al final de toda la lista, despues del ultimo nodo.
        */
        void agregarFin(TipoLista elemento);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Ingresa una  lista pasada por parámetro al final de todo.
        */
        void agregarFin(Lista<TipoLista>& otraLista);

        /*
        __________________________________________________
        PRE: El índice indicado debe ser entre 0 y la cantidad de Nodos actual de la lista inclusive.
        -
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Recibe un indice, y agrega un nodo con un nuevo dato justo antes del nodo que corresponde
        al indice dado.
        Si el indice esta fuera de rango y/o no existe se lanza una excepcion.
        */
        void insertar(int indice, TipoLista elemento);

        /*
        __________________________________________________
        PRE: El índice indicado debe ser entre 0 y la cantidad de Nodos actual menos uno.
        -
        POS: La Lista es modificada, pues se cambia el dato de uno de los Nodos.
        __________________________________________________

        Va a la posición especificada y cambia el dato de ese nodo por el pasado por parámetro.
        */
        void asignar(int indice, TipoLista elemento);

        /*
        __________________________________________________
        PRE: La Lista no está vacía y el elemento que se busca debe existir dentro de
             la misma.
        -
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Busca en la lista si el elemento pasado por parametro existe y, de ser así, elimina la
        primera aparicion de este.
        Si el elemento no se encuentra se lanza una excepcion.
        */
        void borrar(TipoLista elemento);

        /*
        __________________________________________________
        PRE: La lista no debe estar vacía y el índice indicado debe ser
             entre 0 y uno menos que la cantidad de Nodos (los índices van
             desde 0 hasta n - 1).
        -
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Recorre la lista hasta el indice dado y remueve el elemento que esta alli, y devolviendo
        su valor.
        Si el indice esta fuera de rango y/o no existe se lanza una excepcion.
        */
        TipoLista pop(int indice);

        /*
        __________________________________________________
        PRE: La Lista no está vacía y el elemento que se busca debe existir dentro de
             la misma.
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Busca en la lista el elemento pasado por parámetro y devuelve el indice que corresponda
        a la primera aparicion de este.
        Si el elemento no se encuentra se lanza una excepcion.
        */
        int indice(TipoLista elemento);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Devuelve 'true' si existe al menos una (1) aparición del elemento dado dentro de la lista.
        Devuelve 'false' si no se encuentra nada.
        */
        bool existe(TipoLista elemento);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Cuenta las apariciones del elemento dado que hay dentro de la lista. Devuelve 0 si no
        encuentra nada.
        */
        int contar(TipoLista elemento);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Imprime por pantalla todos los elementos de la lista, para que se los pueda ver comodamente.
        */
        void imprimir();
};

/* ----- DEFINICIONES ----- */

template <class TipoLista>
Nodo<TipoLista>* Lista<TipoLista>::obtenerNodo(int posicion) {

    if (posicion < 0 || posicion >= this->len()) {

        std::cout << "La posicion indicada (" << posicion << ") no es valida o esta fuera de rango" << std::endl;
        throw posicion;
    }

    Nodo<TipoLista>* auxiliar = this->prim;

    for (int i = 0; i < posicion; i++) {

        auxiliar = auxiliar->prox();
    }

    return auxiliar;
}

template <class TipoLista>
Lista<TipoLista>::Lista() {

    this->prim = NULL;
    this->cant = 0;
    this->cursor = NULL;
}

template <class TipoLista>
Lista<TipoLista>::Lista(Lista<TipoLista>& otraLista) {

    this->prim = NULL;
    this->cant = 0;
    this->cursor = NULL;

    this->agregarFin(otraLista);
}

template <class TipoLista>
Lista<TipoLista>::~Lista() {

    if (!this->estaVacia()) {

        Nodo<TipoLista>* auxiliar = this->prim;
        while (auxiliar) {

            this->prim = prim->prox();
            delete auxiliar;
            auxiliar = this->prim;
        }
    }
}

template <class TipoLista>
bool Lista<TipoLista>::estaVacia() {

    return this->prim == NULL;
}

template <class TipoLista>
int Lista<TipoLista>::len() {

    return this->cant;
}

template <class TipoLista>
void Lista<TipoLista>::iniciarCursor() {

    this->cursor = NULL;
}

template <class TipoLista>
bool Lista<TipoLista>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->prim;

    } else {

        this->cursor = this->cursor->prox();
    }

    return (this->cursor != NULL);
}

template <class TipoLista>
TipoLista Lista<TipoLista>::obtenerDatoCursor() {

    if (this->cursor == NULL) {

        std::cout << "El cursor apunta a NULL." << std::endl;
    }

    return this->cursor->dato();
}

template <class TipoLista>
TipoLista Lista<TipoLista>::obtener(int indice) {

    if (this->estaVacia() || indice < 0 || indice >= this->cant) {

        std::cout << "El indice indicado (" << indice << ") esta fuera de rango o la lista esta vacia" << std::endl;
        throw indice;
    }

    this->iniciarCursor();

    for (int contador = 0; contador <= indice; contador++) {

        this->avanzarCursor();
    }

    return this->obtenerDatoCursor();
}

template <class TipoLista>
void Lista<TipoLista>::agregarPrin(TipoLista elemento) {

    this->prim = new Nodo<TipoLista>(elemento, prim);
    this->cant++;

    this->iniciarCursor(); // Anula el posible recorrido que podría haber hecho el cursor.
}

template <class TipoLista>
void Lista<TipoLista>::agregarFin(TipoLista elemento) {

    this->iniciarCursor();
    Nodo<TipoLista>* auxiliar = NULL;

    while (this->avanzarCursor()) {

        auxiliar = this->cursor;
    }

    if (!this->estaVacia()) {

        auxiliar->setProx(new Nodo<TipoLista>(elemento));

    } else {

        this->prim = new Nodo<TipoLista>(elemento, prim);
    }

    this->cant++;

    this->iniciarCursor(); // Anula el posible recorrido que podría haber hecho el cursor.
}

template <class TipoLista>
void Lista<TipoLista>::agregarFin(Lista<TipoLista>& otraLista) {

    otraLista.iniciarCursor();

    while (otraLista.avanzarCursor()) {

        this->agregarFin(otraLista.obtenerDatoCursor());
    }

    this->iniciarCursor(); // Anula el posible recorrido que podría haber hecho el cursor.
}

template <class TipoLista>
void Lista<TipoLista>::insertar(int indice, TipoLista elemento) {

    if (indice < 0 || indice > this->len()) {

        std::cout << "El indice indicado (" << indice << ") no valido o fuera de rango" << std::endl;
        throw indice;
    }

    if (indice == 0) {

        this->agregarPrin(elemento);

    } else {

        Nodo<TipoLista>* anterior = obtenerNodo(indice - 1);
        anterior->setProx(new Nodo<TipoLista>(elemento, anterior->prox()));
        this->cant++;
    }

    this->iniciarCursor(); // Anula el posible recorrido que podría haber hecho el cursor.
}

template <class TipoLista>
void Lista<TipoLista>::asignar(int indice, TipoLista elemento) {

    this->obtenerNodo(indice)->setDato(elemento);
}

template <class TipoLista>
void Lista<TipoLista>::borrar(TipoLista elemento) {

    if (this->estaVacia()) {

        std::cout << "La lista esta vacia" << std::endl;
        throw elemento;
    }

    this->iniciarCursor();
    Nodo<TipoLista>* anterior = NULL;

    while (this->avanzarCursor() && this->obtenerDatoCursor() != elemento) {
    
        anterior = this->cursor;
    }

    if (!this->cursor) {

        std::cout << "El elemento especificado (" << elemento << ") no fue encontrado" << std::endl;
        throw elemento;
    }

    if (anterior) {

        anterior->setProx(this->cursor->prox());
        
    } else {

        this->prim = this->cursor->prox();
    }

    delete this->cursor;
    this->cant--;

    this->iniciarCursor(); // Anula el posible recorrido que podría haber hecho el cursor.
}

template <class TipoLista>
TipoLista Lista<TipoLista>::pop(int indice) {

    if (this->estaVacia() || indice < 0 || indice >= this->cant) {

        std::cout << "El indice indicado (" << indice << ") esta fuera de rango o la lista esta vacia" << std::endl;
        throw indice;
    }

    Nodo<TipoLista>* nodoARemover = NULL;

    if (indice == 0) {

        nodoARemover = this->prim;
        this->prim = nodoARemover->prox();

    } else {

        Nodo<TipoLista>* anterior = this->obtenerNodo(indice - 1);
        nodoARemover = anterior->prox();
        anterior->setProx(nodoARemover->prox());
    }

    TipoLista datoEliminado = nodoARemover->dato();
    delete nodoARemover;
    this->cant--;

    this->iniciarCursor(); // Anula el posible recorrido que podría haber hecho el cursor.

    return datoEliminado;
}

template <class TipoLista>
int Lista<TipoLista>::indice(TipoLista elemento) {

    if (this->estaVacia()) {

        std::cout << "La lista esta vacia" << std::endl;
        throw elemento;
    }

    this->iniciarCursor();
    int contador = 0;

    while (this->avanzarCursor() && this->obtenerDatoCursor() != elemento) {

        contador++;
    }

    if (!this->cursor) {

        std::cout << "El elemento especificado (" << elemento << ") no fue encontrado" << std::endl;
        throw elemento;
    }

    this->iniciarCursor(); // Anula el posible recorrido que podría haber hecho el cursor.

    return contador;
}

template <class TipoLista>
bool Lista<TipoLista>::existe(TipoLista elemento) {

    if (!this->estaVacia()) {

        this->iniciarCursor();

        while (this->avanzarCursor()) {

            if (this->obtenerDatoCursor() == elemento) {

                return true;
            }
        }
    }

    return false;
}

template <class TipoLista>
int Lista<TipoLista>::contar(TipoLista elemento) {

    int suma = 0;

    if (!this->estaVacia()) {

        this->iniciarCursor();

        while (this->avanzarCursor()) {

            if (this->obtenerDatoCursor() == elemento) {

                suma++;
            }
        }
    }

    return suma;
}

template <class TipoLista>
void Lista<TipoLista>::imprimir() {

    Nodo<TipoLista>* auxiliar = prim;

    while (auxiliar) {

        std::cout << auxiliar->dato();

        if (auxiliar->prox()) {

            std::cout << " -> ";
        }

        auxiliar = auxiliar->prox();
    }

    std::cout << std::endl;
}

#endif /* LISTALIGADA_H_ */