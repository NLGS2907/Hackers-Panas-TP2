#ifndef LISTALIGADA_H_
#define LISTALIGADA_H_
#include "nodo.h"
#include <iostream>

/* ----- DECLARACIONES ----- */

template <class Tipo>
class Lista {

    private:

        Nodo<Tipo>* prim; // Primer nodo de la lista
        int cant; // Sin importar el tipo de dato, la cantidad debería ser <int>
    
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
        void agregarPrin(Tipo elem);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista es modificada, pues se cambia su cantidad de Nodos.
        __________________________________________________

        Ingresa un nodo con un nuevo dato al final de toda la lista, despues del ultimo nodo.
        */
        void agregarFin(Tipo elem);

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
        void insertar(int indice, Tipo elem);

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
        void borrar(Tipo elem);

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
        Tipo pop(int indice);

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
        int indice(Tipo elem);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Devuelve 'true' si existe al menos una (1) aparicion del elemento dado dentro de la lista.
        Devuelve 'false' si no se encuentra nada.
        */
        bool existe(Tipo elem);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Cuenta las apariciones del elemento dado que hay dentro de la lista. Devuelve 0 si no
        encuentra nada.
        */
        int contar(Tipo elem);

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
        Tipo& operator[](int indice);

        /*
        __________________________________________________
        PRE: -
        -
        POS: La Lista permanece inalterada.
        __________________________________________________

        Compara dos listas y devuelve 'true' si tienen la msima cantidad de elementos y estos son los
        mismos. Si no devuelve 'false'.
        */
        bool operator==(Lista<Tipo> otraLista);

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

template <class Tipo>
Lista<Tipo>::Lista() {

    prim = NULL;
    cant = 0;
}

template <class Tipo>
Lista<Tipo>::~Lista() {

    if (prim) {

        Nodo<Tipo>* aux = prim;
        while (aux) {

            prim = prim->prox();
            delete aux;
            aux = prim;
        }
    }
}

template <class Tipo>
bool Lista<Tipo>::estaVacia() {

    return prim == NULL;
}

template <class Tipo>
int Lista<Tipo>::len() {

    return cant;
}

template <class Tipo>
void Lista<Tipo>::agregarPrin(Tipo elem) {

    prim = new Nodo<Tipo>(elem, prim);
    cant++;
}

template <class Tipo>
void Lista<Tipo>::agregarFin(Tipo elem) {

    Nodo<Tipo>* aux = prim;
    while (aux && aux->prox()) {

        aux = aux->prox();
    }

    if (aux) {

        aux->setProx(new Nodo<Tipo>(elem));

    } else {

        prim = new Nodo<Tipo>(elem, prim);
    }

    cant++;
}

template <class Tipo>
void Lista<Tipo>::insertar(int indice, Tipo elem) {

    if (indice < 0 || indice > cant) {

        std::cout << "El indice indicado (" << indice << ") no valido o fuera de rango" << std::endl;
        throw indice;
    }

    if (indice == 0) {

        agregarPrin(elem);

    } else {

        Nodo<Tipo>* posterior = prim;
        for (int contador = 0; (posterior) && (posterior->prox()) && (contador < indice - 1); contador++) {

            posterior = posterior->prox();
        }

        if (posterior) {

            posterior->setProx(new Nodo<Tipo>(elem, posterior->prox()));
            cant++;

        } else {

            agregarFin(elem);
        }
    }
}

template <class Tipo>
void Lista<Tipo>::borrar(Tipo elem) {

    if (estaVacia()) {

        std::cout << "La lista esta vacia" << std::endl;
        throw elem;
    }

    Nodo<Tipo>* anterior = NULL;
    Nodo<Tipo>* posterior = prim;
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

template <class Tipo>
Tipo Lista<Tipo>::pop(int indice) {

    if (estaVacia() || indice < 0 || indice >= cant) {

        std::cout << "El indice indicado (" << indice << ") esta fuera de rango o la lista esta vacia" << std::endl;
        throw indice;
    }

    Nodo<Tipo>* anterior = NULL;
    Nodo<Tipo>* posterior = prim;
    Tipo datoEliminado;

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

template <class Tipo>
int Lista<Tipo>::indice(Tipo elem) {

    if (estaVacia()) {

        std::cout << "La lista esta vacia" << std::endl;
        throw elem;
    }

    Nodo<Tipo>* aux = prim;
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

template <class Tipo>
bool Lista<Tipo>::existe(Tipo elem) {

    if (!estaVacia()) {

        Nodo<Tipo>* aux = prim;

        while (aux) {

            if (aux->dato() == elem) {

                return true;
            }

            aux = aux->prox();
        }
    }

    return false;
}

template <class Tipo>
int Lista<Tipo>::contar(Tipo elem) {

    int suma = 0;

    if (!estaVacia()) {

        Nodo<Tipo>* aux = prim;

        while (aux) {

            if (aux->dato() == elem) {

                suma++;
            }

            aux = aux->prox();
        }
    }

    return suma;
}

template <class Tipo>
Tipo& Lista<Tipo>::operator[](int indice) {

    if (estaVacia() || indice < 0 || indice >= cant) {

        std::cout << "El indice indicado (" << indice << ") esta fuera de rango o la lista esta vacia" << std::endl;
        throw indice;
    }

    Nodo<Tipo>* aux = prim;

    for (int contador = 0; contador < indice; contador++) {

        aux = aux->prox();
    }

    return aux->datoRef();
}

template <class Tipo>
bool Lista<Tipo>::operator==(Lista<Tipo> otraLista) {

    if (len() != otraLista.len()) {

        return false;
    }

    Nodo<Tipo>* aux1 = prim;
    Nodo<Tipo>* aux2 = otraLista.prim;

    while (aux1 && aux1->prox()) {

        if (aux1->dato() != aux2->dato()) {

            return false;
        }

        aux1 = aux1->prox();
        aux2 = aux2->prox();
    }

    return true;
}

template <class Tipo>
void Lista<Tipo>::imprimir() {

    Nodo<Tipo>* aux = prim;

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