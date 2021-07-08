#ifndef MAZO_H_
#define MAZO_H_

#include"carta.h"
#include"cola.h"
#include<cstdlib>

class Mazo {

private:

	Cola<Carta*>* mazo;

public:

	/*
	__________________________________________________
	PRE: -
	-
	POS: Crea una instancia de Mazo con las cantidades
		 de cartas indicadas en los parámetros.
	__________________________________________________
	*/
	Mazo(int cantidadDeCartasJuegaDoble, int cantidadDeCartasBloquearTurno, int cantidadDeCartasAgarrarCincoFichas, int cantidadDeCartasEliminarMazoJugadorSiguiente);

	Cola<Carta*>* getMazo();

	/*
	__________________________________________________
	PRE: -
	-
	POS: Devuelve 'true' si el Mazo está vacío. En caso
		 contrario, devuelve 'false'.
	__________________________________________________
	*/
	bool esMazoVacio();

	/*
	__________________________________________________
	PRE: Recibe puntero a carta ( Carta* carta = new Carta*; )
		 creada en otro lado.
	-
	POS: Acola la carta en la Cola del Mazo.
	__________________________________________________
	*/
	Carta* acolarCarta(Carta* carta);

	/*
	__________________________________________________
	PRE: -
	-
	POS: Devuelve el puntero a una carta que es desacolada
		 del Mazo.
	__________________________________________________
	*/
	Carta* darCarta();

	/*
	__________________________________________________
	PRE: -
	-
	POS: Genera un numero entre 0 y 3 inclusive, y con
		 estos numeros devuelve el enum de CartaEspecial
		 correspondiente.
	__________________________________________________
	*/
	CartaEspecial generarNumeroRandom();

	/*
	__________________________________________________
	PRE: -
	-
	POS: Destruye el Mazo, liberando los recursos que
		 ocupaba la estructura de datos.
	__________________________________________________
	*/
	~Mazo();
};

#endif /* MAZO_H_ */

