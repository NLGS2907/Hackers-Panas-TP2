#ifndef COLA_H_
#define COLA_H_

#include"nodo.h"
#include<iostream>
#include<string>

template<class Tipo> class Cola {

	private:

        Nodo<Tipo>* frente;

        Nodo<Tipo>* fondo;

    public:

    	/*
        __________________________________________________
        PRE: -
        -
        POS: Se crea una instancia de COla vacía y lista para
             ser usada.
        __________________________________________________
        */
        Cola();

    	/*
        __________________________________________________
        PRE: -
        -
        POS: Devuelve 'true' si la Cola no tiene ningún elemento.
             Caso contrario, devuelve 'false'.
        __________________________________________________
        */
        bool estaVacia();

    	/*
        __________________________________________________
        PRE: -
        -
        POS: Agrega 'elemento' al fondo de la Cola.
        __________________________________________________
        */
        void acolar(Tipo elemento);

    	/*
        __________________________________________________
        PRE: La Cola no está vacía.
        -
        POS: Remueve el frente de la Cola y lo devuelve.
        __________________________________________________
        */
        Tipo desacolar();

    	/*
        __________________________________________________
        PRE: La Cola no está vacía.
        -
        POS: Devuelve el frente de la Cola.
        __________________________________________________
        */
        Tipo obtenerFrente();

    	/*
        __________________________________________________
        PRE: -
        -
        POS: Imprime por pantalla la Cola.
        __________________________________________________
        */
        void imprimir();

    	/*
        __________________________________________________
        PRE: -
        -
        POS: Remueve todos los elementos y libera los recursos
             tomados por la estructura de datos.
        __________________________________________________
        */
        ~Cola();
};

template<class Tipo>
Cola<Tipo>::Cola() {

    this->frente = NULL;
    this->fondo = NULL;
}

template<class Tipo>
bool Cola<Tipo>::estaVacia() {

    return (this->frente == NULL);
}

template<class Tipo>
void Cola<Tipo>::acolar(Tipo elemento) {

    Nodo<Tipo>* nuevoFondo = new Nodo<Tipo>(elemento);

    if (this->estaVacia()) {
        this->frente = nuevoFondo;

    } else {
        this->fondo->setProx(nuevoFondo);
    }

    this->fondo = nuevoFondo;
}

template<class Tipo>
Tipo Cola<Tipo>::desacolar() {

    if (this->estaVacia()) {
        throw std::string("No se puede desacolar, la cola está vacía.");
    }

    /* remueve el frente de la estructura */
    Nodo<Tipo>* frenteAnterior = this->frente;

    this->frente = frenteAnterior->prox();

    if (this->frente == NULL) {
        this->fondo = NULL;
    }

    /* devuelve el elemento y libera los recursos asociados */
    Tipo elemento = frenteAnterior->dato();
    delete frenteAnterior;

    return elemento;
}

template<class Tipo>
Tipo Cola<Tipo>::obtenerFrente() {

    if (this->estaVacia()) {
        throw std::string("No se puede obtener el frente, la cola está vacía.");
    }

    Tipo elemento = this->frente->dato();

    return elemento;
}

template<class Tipo>
Cola<Tipo>::~Cola() {

    while (! this->estaVacia()) {

        this->desacolar();
    }
}

template<class Tipo>
void Cola<Tipo>::imprimir(){
	  Nodo<Tipo>* aux = frente;

	    while (aux) {

	        std::cout << aux->dato();

	        if (aux->prox()) {

	            std::cout << " -> ";
	        }

	        aux = aux->prox();
	    }

	    std::cout << std::endl;
}

#endif /* COLA_H_ */