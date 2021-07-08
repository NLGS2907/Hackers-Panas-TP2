#include "Jugador.h"


std::string Jugador::generarColorAleatorio(){

    string clave;

    const char alphanum[] =
        "0123456789"
        "ABCDEF";

    srand( (unsigned) time(NULL) );

    for(int i = 0; i < len; i++){
    	clave += alphanum[ rand() % (sizeof(alphanum) - 1) ];
    }

    return clave;
}


Jugador::Jugador(char ficha, int cantidadFichasJugador){

    this->fichaJugador = ficha;
    this->cantidadDeFichas = cantidadFichasJugador;
    this->cartasJugador = new Lista<Carta*>;
    this->turno = Comun;
    this->colorJugador = generarColorAleatorio();

}


Lista<Carta*>* Jugador::getCartasJugador(){

	return this->cartasJugador;

}


std::string Jugador::getColorJugador(){

	return this->colorJugador;

}


char Jugador::getFicha(){

    return this->fichaJugador;

}


int Jugador::getCantidadDeFichasRestantes(){
    
    return this->cantidadDeFichas;

}


int Jugador::getCantidadDeCartasEnMano(){
    
    return this->cartasJugador->len();

}


void Jugador::cargarCarta(Carta* cartaAgarrada){
    
    this->cartasJugador->agregarFin(cartaAgarrada);

}


Carta* Jugador::obtenerCarta(int posicionCarta){
    
    return ( this->cartasJugador->obtener(posicionCarta - 1) );

}


void Jugador::eliminarCarta(int posicionCarta){
    
    this->cartasJugador->pop(posicionCarta - 1);

}


void Jugador::duplicarTurno(){

    if(this->getTipoDeTurno() == Doble){
        throw("El turno ya es Doble");
    }
    
    this->setTipoDeTurno(Doble);

}


void Jugador::bloquearTurno(){

    if(this->getTipoDeTurno() == Bloqueado){
        throw("El turno ya esta Bloqueado");
    }

    this->setTipoDeTurno(Bloqueado);

}


void Jugador::sumarCincoFichas(){
    
    this->cantidadDeFichas += CINCO_FICHAS;

}


void Jugador::reestablecerTurno(){

    if(this->getTipoDeTurno() == Comun){
        throw("El turno ya es Comun");
    }

    this->setTipoDeTurno(Comun);

}


TipoDeTurno Jugador::getTipoDeTurno(){

    return this->turno;

}


void Jugador::setTipoDeTurno(TipoDeTurno turno){

    this->turno = turno;

}


void Jugador::descontarFichaColocada(){

    this->cantidadDeFichas--;

}


Jugador::~Jugador(){

    for(int i=0; i<(this->cartasJugador->len()); i++){
        delete this->cartasJugador->obtener(i);
    }
    
    delete this->cartasJugador;

}
