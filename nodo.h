#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

/* ----- DECLARACIONES ----- */

template <class T>
class Nodo {

    private:

        T datoNodo;
        Nodo<T>* sig;

    public:

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Nodo es creado con sus valores predeterminados o los
             pasados por parámetros.
        __________________________________________________

        Crea un nuevo nodo con la info y posible nodo siguiente pasados por
        parametro.
        */
        Nodo(T info, Nodo<T>* siguiente=NULL);

        /*
        __________________________________________________
        PRE: El Nodo tiene un tipo de dato válido.
        -
        POS: El Nodo se mantiene igual, ya que se pasa una copia del dato.
        __________________________________________________

        Devuelve el dato del nodo.
        */
        T dato();

        /*
        __________________________________________________
        PRE: El Nodo tiene un tipo de dato válido.
        -
        POS: Se pasa una referencia, por lo que el dato puede ser modificado luego.
        __________________________________________________

        Devuelve una REFERENCIA al dato del nodo, lo que permite modifcarlo.
        Es desaconsejable usarlo salvo que se lo necesite explícitamente.
        */
        T& datoRef();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Nodo actual permanece inalterado.
        __________________________________________________

        Devuelve el nodo siguiente (NULL si es el ultimo).
        */
        Nodo<T>* prox();

        /*
        __________________________________________________
        PRE: -
        -
        POS: Se modifica el dato del Nodo.
        __________________________________________________

        Cambia el valor del dato del nodo.
        */
        void setDato(T datoNuevo);

        /*
        __________________________________________________
        PRE: -
        -
        POS: Modifica el Nodo siguiente al actual.
        __________________________________________________

        Cambia el nodo siguiente.
        */
        void setProx(Nodo<T>* nodoSig);
};

/* ----- DEFINICIONES ----- */

template <class T>
Nodo<T>::Nodo(T info, Nodo<T>* siguiente) {

    datoNodo = info;
    sig = siguiente;
}

template <class T>
T Nodo<T>::dato() {

    return datoNodo;
}

template <class T>
T& Nodo<T>::datoRef() {

    return datoNodo;
}

template <class T>
Nodo<T>* Nodo<T>::prox() {

    return sig;
}

template <class T>
void Nodo<T>::setDato(T datoNuevo) {

    datoNodo = datoNuevo;
}

template <class T>
void Nodo<T>::setProx(Nodo<T>* nodoSig) {

    sig = nodoSig;
}

#endif /* NODO_H_ */