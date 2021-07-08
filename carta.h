#ifndef CARTA_H_
#define CARTA_H_

#include<string>

enum CartaEspecial {
    JuegaDoble,
    BloquearTurno,
    AgarrarCincoFichas,
    EliminarMazoJugadorSiguiente
};

class Carta {

private:
	CartaEspecial tipoDeCarta;
	std::string descripcionCarta;

public:

	/*
	 * PRE:
	 * POST: asigna carta especial
	 */
	Carta(CartaEspecial tipoDeCarta);

	/*
	 * PRE:
	 * POST: devuelve carta especial
	 */
	CartaEspecial getCartaEspecial();

	/*
	 * PRE:
	 * POST: devuelve descripcion de la carta
	 */
	std::string getDescripcionCarta();
};



#endif /* CARTA_H_ */