#include"carta.h"

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
