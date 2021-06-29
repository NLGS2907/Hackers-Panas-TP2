#ifndef MAZO_H_
#define MAZO_H_

#include "carta2.h"
#include"cola.h"


class Mazo {
private:

	Cola<Carta*>* mazo;
	int cantidadDeCartas;

public:
	Mazo(int);

	~Mazo();

	Carta* acolarCarta(Carta* carta);

	Carta* darCarta();


};

/* ----- DEFINICIONES ----- */


Mazo::Mazo(int numeroDeCartas){
	if(numeroDeCartas > 0){
		cantidadDeCartas = numeroDeCartas;
	}
	mazo = new Cola<Carta*>;
}


Carta* Mazo::acolarCarta(Carta* carta){

		mazo->acolar(carta);

	return carta;
}

Carta* Mazo::darCarta(){ //desacolar ya checkea q no este vacia

	return mazo->desacolar();
}

Mazo::~Mazo(){
	delete mazo;
}

#endif /* MAZO_H_ */
