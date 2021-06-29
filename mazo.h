#ifndef MAZO_H_
#define MAZO_H_

#include "carta2.h"
#include"cola.h"


class Mazo {
private:

	Cola<Carta*>* mazo;
	int cantidadDeCartas;

public:
	/*
	*pre:
	*post:
	*/
	Mazo();

	/*
	*pre:
	*post:
	*/
	Mazo(int numeroDeCartas);

	/*
	*pre:
	*post:
	*/
	~Mazo();

	/*
	*pre:
	*post:
	*/
	void setCantidadDeCartas(int numeroDeCartas);

	/*
	*pre:
	*post:
	*/
	Carta* acolarCarta(Carta* carta);

	/*
	*pre:
	*post:
	*/
	Carta* darCarta();


};

/* ----- DEFINICIONES ----- */

Mazo::Mazo() {
	mazo = new Cola<Carta*>;
	cantidadDeCartas = 20; //puse un numero cualquiera
}

Mazo::Mazo(int numeroDeCartas) {
	if(numeroDeCartas > 0) {
		cantidadDeCartas = numeroDeCartas;
	}
	mazo = new Cola<Carta*>;
}

void Mazo::setCantidadDeCartas(int numeroDeCartas) {
	cantidadDeCartas = numeroDeCartas;
}

Carta* Mazo::acolarCarta(Carta* carta) {

	mazo->acolar(carta);

	return carta;
}

Carta* Mazo::darCarta() { //desacolar ya checkea q no este vacia

	return mazo->desacolar();
}

Mazo::~Mazo() {
	delete mazo;
}

#endif /* MAZO_H_ */
