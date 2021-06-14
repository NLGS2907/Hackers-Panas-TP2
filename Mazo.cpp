#include"Mazo.h"


Mazo::Mazo(){
    this->frente = NULL;
    this->fondo = NULL;
}


Mazo::~Mazo(){

    while (! this->estaVacia()) {
        this->desacolar();
	}

}

bool Mazo::estaVacia(){

	return (this->frente == NULL);
}

void Mazo::acolar(std::string descripcionCarta){

	Nodo* nuevoNodo = new Nodo(descripcionCarta);

	if (this->estaVacia()) {
		this->frente = nuevoNodo;

	} else {
		this->fondo->cambiarSiguiente(nuevoNodo);
	}

	this->fondo = nuevoNodo;
	}


Carta* Mazo::desacolar(){

	Carta* carta = NULL;

    if (this->estaVacia()) {
        throw std::string("El mazo esta vacio");
    }


	if (!this->estaVacia()) {
	//asigna a frente Nodo siguente y a frenteAnterior frente antes de cambiarlo
		Nodo* frenteAnterior = this->frente;
		this->frente = frenteAnterior->obtenerSiguiente();

	    if (this->frente == NULL) {
	       this->fondo = NULL;
	    }

	 /* devuelve el elemento y libera los recursos asociados */
	    carta = frenteAnterior->obtenerCarta();
	    delete frenteAnterior;
	}

	return carta;

}

Carta* Mazo::obtenerFrente(){

	Carta* carta = NULL;

    if (this->estaVacia()) {
        throw std::string("El mazo esta vacio");
    }

	if (!this->estaVacia()) {

		carta = this->frente->obtenerCarta();
	    }

	return carta;
}
