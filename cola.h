#ifndef COLA_H_
#define COLA_H_

#include"nodo.h"
#include<string>

template<class Tipo> class Cola {

	private:

        Nodo<Tipo>* frente;

        Nodo<Tipo>* fondo;

    public:

        /*
         * post: instancia de Cola vacía y lista para ser usada.
         */
        Cola();

        /*
         * post: devuelve si la Cola no tiene ningún elemento.
         */
        bool estaVacia();

        /*
         * post: agrega 'elemento' en el fondo de la Cola.
         */
        void acolar(Tipo elemento);

        /*
         * pre : la Cola no está vacía.
         * post: remueve el frente de la Cola y lo devuelve.
         */
        Tipo desacolar();

        /*
         * pre : la Cola no está vacía.
         * post: devuelve el frente de la Cola.
         */
        Tipo obtenerFrente();

        /*
         *pre:
         *post:
         */
        void imprimir();


        /*
         * post: remueve todos los elementos y libera
         *       los recursos tomados por la estructura de datos.
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
