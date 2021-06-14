#ifndef CARTA_H_
#define CARTA_H_

#include<iostream>
#include<string>

class Carta {

private:

	std::string descripcion;

public:

	/*
	 * PRE:
	 * POST: asigna decripcion
	 */
	Carta(std::string descripcion);

	/*
	 * PRE:
	 * POST: asigna decripcion
	 */
	void asignarDescripcion(std::string descripcion);

	/*
	 * PRE:
	 * POST: devuelve descripcion de carta
	 */
	std::string obtenerDescripcion();

};

#endif /* CARTA_H_ */
