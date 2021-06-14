#ifndef NODO_H_
#define NODO_H_

#include"Carta.h"

class Nodo {

private:

	Carta* carta;
	Nodo* siguiente;

public:

	/*
	 * PRE:
	 * POST: crea Nodo, asigna siguiente y crea carta con descripcion
	 */
	Nodo(std::string descripcionCarta);

	/*
	 * PRE:
	 * POST: elimina el nodo
	 */
	~Nodo();

	/*
	 * PRE:
	 * POST: devuelve la carta
	 */
	Carta* obtenerCarta();

	/*
	 * PRE:
	 * POST: cambia la descripcion de la carta
	 */
	void cambiarCarta(std::string descripcionCarta);

	/*
	 * PRE:
	 * POST: devuelve el Nodo siguiente
	 */
	Nodo* obtenerSiguente();

	/*
	 * PRE:
	 * POST: cambia siguente por nuevoNodo
	 */
	void cambiarSiguiente(Nodo* nuevoNodo);

#endif /* NODO_H_ */
