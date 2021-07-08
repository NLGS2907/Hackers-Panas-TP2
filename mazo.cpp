#include"mazo.h"
#include<iostream>

Mazo::Mazo(int cantidadDeCartasJuegaDoble, int cantidadDeCartasBloquearTurno, int cantidadDeCartasAgarrarCincoFichas, int cantidadDeCartasEliminarMazoJugadorSiguiente) {

        this->mazo = new Cola<Carta*>();

	    int cantidadTotal = cantidadDeCartasJuegaDoble + cantidadDeCartasBloquearTurno + cantidadDeCartasAgarrarCincoFichas + cantidadDeCartasEliminarMazoJugadorSiguiente;

	    int contador1 = 0;
	    int contador2 = 0;
	    int contador3 = 0;
	    int contador4 = 0;

	    int cantidadDeCartas = 0;

	    while (cantidadDeCartas < cantidadTotal) {

	        CartaEspecial tipoAleatorio = this->generarNumeroRandom();

	        if (tipoAleatorio == JuegaDoble) {

	            if (contador1 < cantidadDeCartasJuegaDoble) {

	                this->acolarCarta(new Carta(tipoAleatorio));
	                contador1++;
	                cantidadDeCartas++;
	            }
	        } else if (tipoAleatorio == BloquearTurno) {

	            if (contador2 < cantidadDeCartasBloquearTurno) {

	                this->acolarCarta(new Carta(tipoAleatorio));
	                contador2++;
	                cantidadDeCartas++;
	            }
	        } else if (tipoAleatorio == AgarrarCincoFichas) {

	            if (contador3 < cantidadDeCartasAgarrarCincoFichas) {

	                this->acolarCarta(new Carta(tipoAleatorio));
	                contador3++;
	                cantidadDeCartas++;
	            }

	        } else if (tipoAleatorio == EliminarMazoJugadorSiguiente) {

	            if (contador4 < cantidadDeCartasEliminarMazoJugadorSiguiente) {

	                this->acolarCarta(new Carta(tipoAleatorio));
	                contador4++;
	                cantidadDeCartas++;

	            }
	        }
	    }
}

Cola<Carta*>* Mazo::getMazo() {

	return this->mazo;
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

