#ifndef MAZO_H_
#define MAZO_H_

#include"Nodo.h"

/*
 Principio FIFO (First In - First Out)
 Primer elemento = FRENTE
 Ultimo elemento = FONDO (en la clase se usaron estos nombres)
 El primer elemento en entrar es el primer elemento en salir.
 Sólo permite el acceso al elemento que denomina frente.
*/

class Mazo {

private:

	Nodo* frente;
	Nodo* fondo;

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
	Carta* desacolar();

	/*
	 * PRE:
	 * POST: agrega Nodo al final de Mazo
	 */
	void acolar(std::string descripcionCarta);

	/*
	 * PRE: Mazo no esta vacio
	 * POST:devuelve frente
	 */
	Carta* obtenerFrente();
};

#endif /* MAZO_H_ */
