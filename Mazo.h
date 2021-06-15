#ifndef MAZO_H_
#define MAZO_H_

#include"Nodo.h"
#include"Carta.h"
/*
 Principio FIFO (First In - First Out)
 Primer elemento = FRENTE
 Ultimo elemento = FONDO (en la clase se usaron estos nombres)
 El primer elemento en entrar es el primer elemento en salir.
 Sólo permite el acceso al elemento que denomina frente.
*/

template <class T>
class Mazo {

private:

	Nodo<T>* frente;
	Nodo<T>* fondo;

public:
	/*
	 * PRE:
	 * POST: crea Mazo vacio
	 */
	Mazo(); //int numeroDeCartas

	/*
	 * PRE:
	 * POST: elimina Mazo con metodo desacolar
	 */
	~Mazo();

	/*
	 * PRE:
	 * POST: devuelve TRUE o FALSE segun si frente=NULL o no
	 * (no recorrere Mazo)
	 */
	bool estaVacia();

	/*
	 * PRE: Mazo no esta vacio
	 * POST: quita frente de Mazo y lo devuelve
	 */
	Carta<T>* desacolar();

	/*
	 * PRE:
	 * POST: agrega Nodo al final de Mazo
	 */
	void acolar(T descripcionCarta);

	/*
	 * PRE: Mazo no esta vacio
	 * POST:devuelve frente
	 */
	Carta<T>* obtenerFrente();
};


/* ----- DEFINICIONES ----- */


template <class T>
Mazo<T>::Mazo(){
    this->frente = NULL;
    this->fondo = NULL;
}


template <class T>
Mazo<T>::~Mazo(){

    while (! this->estaVacia()) {
        this->desacolar();
	}

}


template <class T>
bool Mazo<T>::estaVacia(){

	return (this->frente == NULL);
}


template <class T>
void Mazo<T>::acolar(T descripcionCarta){ // NO PONGO Nodo<T>* siguiente=NULL Porque tiene parametro por defecto

	Nodo<T>* nuevoNodo = new Nodo<T>(descripcionCarta);

	if (this->estaVacia()) {
		this->frente = nuevoNodo;

	} else {
		this->fondo->setProx(nuevoNodo);
	}

	this->fondo = nuevoNodo;
	}


template <class T>
Carta<T>* Mazo<T>::desacolar(){

	Carta<T>* carta = NULL;

    if (this->estaVacia()) {
        throw std::string("El mazo esta vacio");
    }


	if (!this->estaVacia()) {
	//asigna a frente Nodo siguente y a frenteAnterior frente antes de cambiarlo
		Nodo<T>* frenteAnterior = this->frente;
		this->frente = frenteAnterior->prox();

	    if (this->frente == NULL) {
	       this->fondo = NULL;
	    }

	 /* devuelve el elemento y libera los recursos asociados */
	    carta = frenteAnterior->dato(); //dato() METODO de nodo.h devuelve dato de nodo
	    delete frenteAnterior;
	}

	return carta;

}


template <class T>
Carta<T>* Mazo<T>::obtenerFrente(){

	Carta<T>* carta = NULL;

    if (this->estaVacia()) {
        throw std::string("El mazo esta vacio");
    }

	if (!this->estaVacia()) {

		carta = this->frente->dato();
	    }

	return carta;
}


#endif /* MAZO_H_ */
