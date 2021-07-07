#include"mazo.h"
#include<iostream>
/* ----- DEFINICIONES ----- */

Mazo::Mazo(int cantidadDeCartasJuegaDoble, int cantidadDeCartasBloquearTurno, int cantidadDeCartasAgarrarCincoFichas, int cantidadDeCartasEliminarMazoJugadorSiguiente) {

	    int cantidadTotal = cantidadDeCartasJuegaDoble + cantidadDeCartasBloquearTurno + cantidadDeCartasAgarrarCincoFichas + cantidadDeCartasEliminarMazoJugadorSiguiente;

	    int contador1 = 0;
	    int contador2 = 0;
	    int contador3 = 0;
	    int contador4 = 0;

	    int cantidadDeCartas = 0;

	    while (cantidadDeCartas < cantidadTotal) {

	        Carta* cartaAAgregar = new Carta(generarNumeroRandom());
	        if (cartaAAgregar->getCartaEspecial() == JuegaDoble) {

	            if (contador1 < cantidadDeCartasJuegaDoble) {

	                mazo->acolar(cartaAAgregar);
	                contador1++;
	                cantidadDeCartas++;

	            } else {

	                delete cartaAAgregar;
	            }
	        } else if (cartaAAgregar->getCartaEspecial() == BloquearTurno) {

	            if (contador2 < cantidadDeCartasBloquearTurno) {

	                mazo->acolar(cartaAAgregar);
	                contador2++;
	                cantidadDeCartas++;

	            } else {

	                delete cartaAAgregar;
	            }
	        } else if (cartaAAgregar->getCartaEspecial() == AgarrarCincoFichas) {

	            if (contador3 < cantidadDeCartasAgarrarCincoFichas) {

	                mazo->acolar(cartaAAgregar);
	                contador3++;
	                cantidadDeCartas++;

	            } else {

	                delete cartaAAgregar;
	            }

	        } else if (cartaAAgregar->getCartaEspecial() == EliminarMazoJugadorSiguiente) {

	            if (contador3 < cantidadDeCartasEliminarMazoJugadorSiguiente) {

	                mazo->acolar(cartaAAgregar);
	                contador4++;
	                cantidadDeCartas++;

	            } else {

	                delete cartaAAgregar;
	            }
	        }
	    }

}

bool Mazo::esMazoVacio(){

	return this->mazo->estaVacia();
}

Carta* Mazo::acolarCarta(Carta* carta) {
		mazo->acolar(carta);

	return carta;
}

Carta* Mazo::darCarta(){

	return mazo->desacolar();
}

CartaEspecial Mazo::generarNumeroRandom(){

	srand(time(NULL));
	int aleatorio = rand() % 4;

	CartaEspecial tipoDeCarta;

	switch(aleatorio) {

	case 0:
		tipoDeCarta = JuegaDoble;
	break;

	case 1:
		tipoDeCarta = BloquearTurno;
	break;

	case 2:
		tipoDeCarta = AgarrarCincoFichas;
	break;

	case 3:
		tipoDeCarta = EliminarMazoJugadorSiguiente;
	break;

	}

	return tipoDeCarta;
}

Mazo::~Mazo(){
	delete mazo;
}


