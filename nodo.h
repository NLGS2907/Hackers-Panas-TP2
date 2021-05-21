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
        Crea un nuevo nodo con la info y posible nodo siguiente pasados por
        parametro.
        */
        Nodo(T info, Nodo<T>* siguiente=NULL);

        /*
        Devuelve el dato del nodo.
        */
        T dato();

        /*
        Devuelve una REFERENCIA al dato del nodo, lo que permite modifcarlo.
        Es desaconsejable usarlo salvo que se lo necesite explicitamente.
        */
        T& datoRef();

        /*
        Devuelve el nodo siguiente (NULL si es el ultimo).
        */
        Nodo<T>* prox();

        /*
        Cambia el valor del dato del nodo.
        */
        void setDato(T datoNuevo);

        /*
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