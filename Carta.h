#ifndef CARTA_H_
#define CARTA_H_

#include<string>

template <class T>
class Carta {

private:

	T descripcion;

public:

	/*
	 * PRE:
	 * POST: asigna decripcion
	 */
	Carta(T descripcion);

	/*
	 * PRE:
	 * POST: asigna decripcion
	 */
	void asignarDescripcion(T descripcion);

	/*
	 * PRE:
	 * POST: devuelve descripcion de carta
	 */
	T obtenerDescripcion();

};


/* ----- DEFINICIONES ----- */
template <class T>
Carta<T>::Carta(T descripcion)  {

	this->descripcion = descripcion;
}

template <class T>
void Carta<T>::asignarDescripcion(T descripcion) {

	this->descripcion = descripcion;
}

template <class T>
T Carta<T>::obtenerDescripcion() {

	return descripcion;
}

#endif /* CARTA_H_ */
