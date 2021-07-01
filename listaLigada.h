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
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Ingresa un nodo con un nuevo dato al principio de toda la lista, antes del primer nodo.
        */
        void agregarPrin(TipoLista elem);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Ingresa un nodo con un nuevo dato al final de toda la lista, despues del ultimo nodo.
        */
        void agregarFin(TipoLista elem);

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
        void insertar(int indice, TipoLista elem);

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
        void borrar(TipoLista elem);

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

        Busca en la lista el elemento pasado por parametro y devuelve el indice que corresponda
        a la primera aparicion de este.
        Si el elemento no se encuentra se lanza una excepcion.
        */
        int indice(TipoLista elem);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Devuelve 'true' si existe al menos una (1) aparicion del elemento dado dentro de la lista.
        Devuelve 'false' si no se encuentra nada.
        */
        bool existe(TipoLista elem);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Cuenta las apariciones del elemento dado que hay dentro de la lista. Devuelve 0 si no
        encuentra nada.
        */
        int contar(TipoLista elem);

        /*
        __________________________________________________
        PRE: La lista no debe estar vacía y el índice indicado debe ser
             entre 0 y uno menos que la cantidad de Nodos (los índices van
             desde 0 hasta n - 1).
        -
        POS: Se pasa una referencia, por lo que la Lista podría ser
             modificada.
        __________________________________________________

        Devuelve el dato que esta en el nodo cuyo indice es el pasado por parametro.
        */
        TipoLista& operator[](int indice);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Compara dos listas y devuelve 'true' si tienen la msima cantidad de elementos y estos son los
        mismos. Si no devuelve 'false'.
        */
        bool operator==(Lista<TipoLista> otraLista);

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
Lista<TipoLista>::Lista() {

    prim = NULL;
    cant = 0;
}

template <class TipoLista>
Lista<TipoLista>::~Lista() {

    if (prim) {

        Nodo<TipoLista>* aux = prim;
        while (aux) {

            prim = prim->prox();
            delete aux;
            aux = prim;
        }
    }
}

template <class TipoLista>
bool Lista<TipoLista>::estaVacia() {

    return prim == NULL;
}

template <class TipoLista>
int Lista<TipoLista>::len() {

    return cant;
}

template <class TipoLista>
void Lista<TipoLista>::agregarPrin(TipoLista elem) {

    prim = new Nodo<TipoLista>(elem, prim);
    cant++;
}

template <class TipoLista>
void Lista<TipoLista>::agregarFin(TipoLista elem) {

    Nodo<TipoLista>* aux = prim;
    while (aux && aux->prox()) {

        aux = aux->prox();
    }

    if (aux) {

        aux->setProx(new Nodo<TipoLista>(elem));

    } else {

        prim = new Nodo<TipoLista>(elem, prim);
    }

    cant++;
}

template <class TipoLista>
void Lista<TipoLista>::insertar(int indice, TipoLista elem) {

    if (indice < 0 || indice > cant) {

        std::cout << "El indice indicado (" << indice << ") no valido o fuera de rango" << std::endl;
        throw indice;
    }

    if (indice == 0) {

        agregarPrin(elem);

    } else {

        Nodo<TipoLista>* posterior = prim;
        for (int contador = 0; (posterior) && (posterior->prox()) && (contador < indice - 1); contador++) {

            posterior = posterior->prox();
        }

        if (posterior) {

            posterior->setProx(new Nodo<TipoLista>(elem, posterior->prox()));
            cant++;

        } else {

            agregarFin(elem);
        }
    }
}

template <class TipoLista>
void Lista<TipoLista>::borrar(TipoLista elem) {

    if (estaVacia()) {

        std::cout << "La lista esta vacia" << std::endl;
        throw elem;
    }

    Nodo<TipoLista>* anterior = NULL;
    Nodo<TipoLista>* posterior = prim;
    while (posterior && posterior->prox() && posterior->dato() != elem) {

        anterior = posterior;
        posterior = posterior->prox();
    }

    if (posterior->dato() == elem) {
        
        if (anterior) {

            anterior->setProx(posterior->prox());

        } else {

            prim = posterior->prox();
        }

        delete posterior;

    } else {

        std::cout << "El elemento especificado (" << elem << ") no fue encontrado" << std::endl;
        throw elem;
    }

    cant--;
}

template <class TipoLista>
TipoLista Lista<TipoLista>::pop(int indice) {

    if (estaVacia() || indice < 0 || indice >= cant) {

        std::cout << "El indice indicado (" << indice << ") esta fuera de rango o la lista esta vacia" << std::endl;
        throw indice;
    }

    Nodo<TipoLista>* anterior = NULL;
    Nodo<TipoLista>* posterior = prim;
    TipoLista datoEliminado;

    for (int contador = 0; (posterior) && (posterior->prox()) && (contador < indice); contador++) {

        anterior = posterior;
        posterior = posterior->prox();
    }

    if (anterior) {

        anterior->setProx(posterior->prox());

    } else {

        prim = posterior->prox();
    }

    datoEliminado = posterior->dato();
    delete posterior;

    cant--; 
    return datoEliminado;
}

template <class TipoLista>
int Lista<TipoLista>::indice(TipoLista elem) {

    if (estaVacia()) {

        std::cout << "La lista esta vacia" << std::endl;
        throw elem;
    }

    Nodo<TipoLista>* aux = prim;
    int contador = 0;

    while (aux && aux->prox() && aux->dato() != elem) {

        aux = aux->prox();
        contador++;
    }

    if (aux->dato() == elem) {

        return contador;

    } else {

        std::cout << "El elemento especificado (" << elem << ") no fue encontrado" << std::endl;
        throw elem;
    }
}

template <class TipoLista>
bool Lista<TipoLista>::existe(TipoLista elem) {

    if (!estaVacia()) {

        Nodo<TipoLista>* aux = prim;

        while (aux) {

            if (aux->dato() == elem) {

                return true;
            }

            aux = aux->prox();
        }
    }

    return false;
}

template <class TipoLista>
int Lista<TipoLista>::contar(TipoLista elem) {

    int suma = 0;

    if (!estaVacia()) {

        Nodo<TipoLista>* aux = prim;

        while (aux) {

            if (aux->dato() == elem) {

                suma++;
            }

            aux = aux->prox();
        }
    }

    return suma;
}

template <class TipoLista>
TipoLista& Lista<TipoLista>::operator[](int indice) {

    if (estaVacia() || indice < 0 || indice >= cant) {

        std::cout << "El indice indicado (" << indice << ") esta fuera de rango o la lista esta vacia" << std::endl;
        throw indice;
    }

    Nodo<TipoLista>* aux = prim;

    for (int contador = 0; contador < indice; contador++) {

        aux = aux->prox();
    }

    return aux->datoRef();
}

template <class TipoLista>
bool Lista<TipoLista>::operator==(Lista<TipoLista> otraLista) {

    if (len() != otraLista.len()) {

        return false;
    }

    Nodo<TipoLista>* aux1 = prim;
    Nodo<TipoLista>* aux2 = otraLista.prim;

    while (aux1 && aux1->prox()) {

        if (aux1->dato() != aux2->dato()) {

            return false;
        }

        aux1 = aux1->prox();
        aux2 = aux2->prox();
    }

    return true;
}

template <class TipoLista>
void Lista<TipoLista>::imprimir() {

    Nodo<TipoLista>* aux = prim;

    while (aux) {

        std::cout << aux->dato();

        if (aux->prox()) {

            std::cout << " -> ";
        }

        aux = aux->prox();
    }

    std::cout << std::endl;
}

#endif /* LISTALIGADA_H_ */