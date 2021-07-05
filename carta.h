#ifndef CARTA_H_
#define CARTA_H_

#include<string>

enum CartaEspecial {
    JuegaDoble,
    BloquearTurno,
    AgarrarCincoFichas,
    EliminarMazoJugadorSiguiente
};

class Carta {

private:
	CartaEspecial tipoDeCarta;
	std::string descripcionCarta;

public:

	/*
	 * PRE:
	 * POST: asigna carta especial
	 */
	Carta(CartaEspecial tipoDeCarta);

	/*
	 * PRE:
	 * POST: devuelve carta especial
	 */
	CartaEspecial getCartaEspecial();
	
	/*
	 * PRE:
	 * POST: devuelve descripcion de la carta
	 */
	std::string getDescripcionCarta();
};


/* ----- DEFINICIONES ----- */

Carta::Carta(CartaEspecial tipoCartaNueva) {

	this->tipoDeCarta = tipoCartaNueva;

	switch(this->getCartaEspecial()){

	case JuegaDoble:

		this->descripcionCarta = "El jugador actual juega dos veces";

	break;

	case BloquearTurno:

		this->descripcionCarta = "Bloquea turno al jugador siguiente";

	break;

	case AgarrarCincoFichas:

		this->descripcionCarta = "Suma cinco fichas";

	break;

	case EliminarMazoJugadorSiguiente:

		this->descripcionCarta = "Elimina el mazo del jugador siguiente";

	break;

	}
}


CartaEspecial Carta::getCartaEspecial() {

	return this->tipoDeCarta;
}

std::string Carta::getDescripcionCarta() {

	return this->descripcionCarta;
}

#endif /* CARTA_H_ */
