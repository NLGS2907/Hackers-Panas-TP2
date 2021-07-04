#ifndef CARTA2_H_
#define CARTA2_H_

enum CartaEspecial {
    BloquearTurno,
    JuegaDoble,
    CambiaSentido,
    SacaFichaDeColumna,
};

class Carta {

private:
	CartaEspecial tipoDeCarta;
	//tipoCarta datoCarta;

public:

	/*
	 * PRE:
	 * POST: asigna carta especial
	 */
	Carta(CartaEspecial tipoDeCarta);

	/*
	 * PRE:
	 * POST: asigna carta especial
	 */
	void asignarCartaEspecial(CartaEspecial tipoDeCarta);

	/*
	 * PRE:
	 * POST: devuelve carta especial
	 */
	CartaEspecial obtenerCartaEspecial();

	/*
	 * PRE:
	 * POST:
	 */
	void usarCartaEspecial(CartaEspecial tipoDeCarta);

};


/* ----- DEFINICIONES ----- */


Carta::Carta(CartaEspecial datoCartaNuevo)  {

	tipoDeCarta = datoCartaNuevo;
}


void Carta::asignarCartaEspecial(CartaEspecial datoCartaNuevo) {

	tipoDeCarta = datoCartaNuevo;
}


CartaEspecial Carta::obtenerCartaEspecial() {

	return tipoDeCarta;
}
/*
void Carta::usarCartaEspecial(CartaEspecial tipoDeCarta){

}
*/
#endif /* CARTA2_H_ */
