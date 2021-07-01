#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

/* ----- DECLARACIONES ----- */

template <class TipoNodo>
class Nodo {

    private:

        TipoNodo datoNodo;
        Nodo<TipoNodo>* sig;

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
        Nodo(TipoNodo info, Nodo<TipoNodo>* siguiente=NULL);

        /*
        __________________________________________________
        PRE: El Nodo tiene un tipo de dato válido.
        -
        POS: El Nodo se mantiene igual, ya que se pasa una copia del dato.
        __________________________________________________

        Devuelve el dato del nodo.
        */
        TipoNodo dato();

        /*
        __________________________________________________
        PRE: El Nodo tiene un tipo de dato válido.
        -
        POS: Se pasa una referencia, por lo que el dato puede ser modificado luego.
        __________________________________________________

        Devuelve una REFERENCIA al dato del nodo, lo que permite modifcarlo.
        Es desaconsejable usarlo salvo que se lo necesite explícitamente.
        */
        TipoNodo& datoRef();

        /*
        __________________________________________________
        PRE: -
        -
        POS: El Nodo actual permanece inalterado.
        __________________________________________________

        Devuelve el nodo siguiente (NULL si es el ultimo).
        */
        Nodo<TipoNodo>* prox();

        /*
        __________________________________________________
        PRE: -
        -
        POS: Se modifica el dato del Nodo.
        __________________________________________________

        Cambia el valor del dato del nodo.
        */
        void setDato(TipoNodo datoNuevo);

        /*
        __________________________________________________
        PRE: -
        -
        POS: Modifica el Nodo siguiente al actual.
        __________________________________________________

        Cambia el nodo siguiente.
        */
        void setProx(Nodo<TipoNodo>* nodoSig);
};

/* ----- DEFINICIONES ----- */

template <class TipoNodo>
Nodo<TipoNodo>::Nodo(TipoNodo info, Nodo<TipoNodo>* siguiente) {

    datoNodo = info;
    sig = siguiente;
}

template <class TipoNodo>
TipoNodo Nodo<TipoNodo>::dato() {

    return datoNodo;
}

template <class TipoNodo>
TipoNodo& Nodo<TipoNodo>::datoRef() {

    return datoNodo;
}

template <class TipoNodo>
Nodo<TipoNodo>* Nodo<TipoNodo>::prox() {

    return sig;
}

template <class TipoNodo>
void Nodo<TipoNodo>::setDato(TipoNodo datoNuevo) {

    datoNodo = datoNuevo;
}

template <class TipoNodo>
void Nodo<TipoNodo>::setProx(Nodo<TipoNodo>* nodoSig) {

    sig = nodoSig;
}

#endif /* NODO_H_ */