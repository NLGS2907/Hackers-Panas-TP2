#include "Jugador.h"

using namespace std;

Jugador::Jugador(char ficha, int cantidadFichasJugador){

    if (cantidadDeFichas<=0){
        throw("La cantidad de fichas es invalida");
    }
    this->fichaJugador = ficha;
    this->cantidadDeFichas = cantidadFichasJugador;
    this->cartasJugador = new Lista<Carta*>; 
    this->turno = Comun;

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

Carta* Jugador::obtenerCarta(CartaElegida posicionCarta){
    
    return ( this->cartasJugador->obtener(posicionCarta - 1) );

}

void Jugador::eliminarCarta(CartaElegida posicionCarta){
    
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

~Jugador(){

    for(int i=0; i<(this->cartasJugador->len()); i++){
        delete this->cartasJugador->obtener(i);
    }
    
    delete this->cartasJugador;

}