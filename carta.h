#ifndef CARTA_H_
#define CARTA_H_

#include<string>

template <class tipoCarta>
class Carta {

private:

	tipoCarta datoCarta; 

public:

	/*
	 * PRE:
	 * POST: asigna decripcion
	 */
	Carta(tipoCarta datoCartaNuevo);

	/*
	 * PRE:
	 * POST: asigna decripcion
	 */
	void asignarDescripcion(tipoCarta datoCartaNuevo);

	/*
	 * PRE:
	 * POST: devuelve descripcion de carta
	 */
	tipoCarta obtenerDescripcion();

};


/* ----- DEFINICIONES ----- */
template <class tipoCarta>
Carta<tipoCarta>::Carta(tipoCarta datoCarta)  {

	datoCarta = datoCartaNuevo;
}

template <class tipoCarta>
void Carta<tipoCarta>::asignarDescripcion(tipoCarta datoCartaNuevo) {

	datoCarta = datoCartaNuevo;
}

template <class tipoCarta>
tipoCarta Carta<tipoCarta>::obtenerDescripcion() {

	return datoCarta;
}

#endif /* CARTA_H_ */
