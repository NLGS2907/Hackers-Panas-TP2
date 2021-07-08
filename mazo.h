#ifndef MAZO_H_
#define MAZO_H_

#include"carta.h"
#include"cola.h"
#include<ctime>
#include<cstdlib>

class Mazo {

private:

	Cola<Carta*>* mazo;

public:

	/*
	*pre:
	*post: crea un mazo con cantidad de cartas indicado en parametros
	*/
	Mazo(int cantidadDeCartasJuegaDoble, int cantidadDeCartasBloquearTurno, int cantidadDeCartasAgarrarCincoFichas, int cantidadDeCartasEliminarMazoJugadorSiguiente);

	Cola<Carta*>* getMazo();

	/*
	*pre:
	*post: devuelve true si el mazo esta vacio y sino false.
	*/
	bool esMazoVacio();

	/*
	*pre: recibe puntero a carta ( Carta* carta = new Carta*; ) creada en otro lado
	*post:
	*/
	Carta* acolarCarta(Carta* carta);

	/*
	*pre:
	*post: devuelve puntero a una carta
	*/
	Carta* darCarta();

	/*
	*pre:
	*post: genera un numero entre 0 y 3, y con esots numeros devuelver el enum de CartaEspecial correspondiente
	*/
	CartaEspecial generarNumeroRandom();

	/*
	*pre:
	*post:
	*/
	~Mazo();


};


#endif /* MAZO_H_ */