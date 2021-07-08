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
    __________________________________________________
    PRE: -
    -
    POS: Asigna Carta Especial.
    __________________________________________________
    */
	Carta(CartaEspecial tipoDeCarta);

	/*
    __________________________________________________
    PRE: -
    -
    POS: Devuelve Carta Especial.
    __________________________________________________
    */
	CartaEspecial getCartaEspecial();

	/*
    __________________________________________________
    PRE: -
    -
    POS: Devuelve la descripción de la Carta.
    __________________________________________________
    */
	std::string getDescripcionCarta();
};

#endif /* CARTA_H_ */