#include "juego.h"

//PRIVATE
char Juego::getFichaAleatoria(){

    char fichaAleatoria = 0;

    while( fichaAleatoria < CARACTER_A ){

        fichaAleatoria = (rand() % CARACTER_Z) + 1;

    }
    return fichaAleatoria;
}


bool Juego::esFichaUsada(char ficha){

    this->jugadores->iniciarCursor();
    while(this->jugadores->avanzarCursor()){
        if( this->jugadores->obtenerDatoCursor()->getFicha() == ficha){
            return true;
        }
    }
    return false;
}


int Juego::getNumeroSiguienteJugador(){

    if( this->getNumeroJugadorActual() == (this->jugadores->len() - 1) ){
        return 0;
    }
    else{
        return (this->getNumeroJugadorActual() + 1);
    }

}


bool Juego::jugadoresTienenCartas(){

    this->jugadores->iniciarCursor();
    while(this->jugadores->avanzarCursor()){
        if( this->jugadores->obtenerDatoCursor()->getCantidadDeCartasEnMano() > 0){
            return true;
        }
    }
    return false;

}


bool Juego::jugadorActualTieneMenosDeTresCartas(){

    return (this->getJugadorActual()->getCantidadDeCartasEnMano() < MAX_CARTAS );

}


bool Juego::jugadoresTienenFichas(){

    this->jugadores->iniciarCursor();
    while(this->jugadores->avanzarCursor()){
        if( this->jugadores->obtenerDatoCursor()->getCantidadDeFichasRestantes() > 0){
            return true;
        }
    }
    return false; 

}


void Juego::cargarJugadores(int cantidadDeFichas, int cantidadJugadores){

    char ficha = this->getFichaAleatoria();
    Jugador *jugador = new Jugador(ficha, cantidadDeFichas);
    this->jugadores->agregarFin(jugador);
    for(int i=1; i<cantidadJugadores; i++){

        while( this->esFichaUsada(ficha) ){
            ficha = this->getFichaAleatoria();
        }

        jugador = new Jugador(ficha, cantidadDeFichas);
        this->jugadores->agregarFin(jugador);
    }

}


int Juego::getCantidadFichasEnLinea(){

    return this->cantidadFichasEnLinea;

}


Jugador* Juego::getJugadorActual(){

    return this->getJugadores()->obtener(this->getNumeroJugadorActual());

}


Jugador* Juego::getJugadorSiguiente(){

    return this->getJugadores()->obtener(this->getNumeroSiguienteJugador());

}


//PUBLIC
Juego::Juego(int cantidadFilas, int cantidadColumnas, int profundidad, int cantidadJugadores, int cantidadDeFichas, int fichasEnLinea,
				int cartasJuegaDoble, int cartasBloquearTurno, int cartasAgarrarCincoFichas, int cartasEliminarMazoSiguienteJugador){


        srand(time(NULL));

        this->jugadores = new Lista<Jugador*>;
        this->mazoJuego = new Mazo(cartasJuegaDoble, cartasBloquearTurno, cartasAgarrarCincoFichas, cartasEliminarMazoSiguienteJugador);
        this->tablero = new Tablero<char>(cantidadColumnas, cantidadFilas, profundidad);
        this->numeroJugadorActual = 0;
        this->cantidadFichasEnLinea = fichasEnLinea;
        this->estadoActual = Jugando;
        this->cartaActualElegida = NINGUNA;
        this->numeroDeTurno = 1;

        this->cargarJugadores(cantidadDeFichas, cantidadJugadores);
}


Lista<Jugador*>* Juego::getJugadores(){

    return this->jugadores;

}


Tablero<char>* Juego::getTablero(){

    return this->tablero;

}


Mazo* Juego::getMazo(){

	return this->mazoJuego;

}


int Juego::getTurnoActual(){

	return this->numeroDeTurno;
}


int Juego::getNumeroJugadorActual(){

    return this->numeroJugadorActual;

}


void Juego::setNumeroJugadorActual(int numeroJugador){


    if(numeroJugador < 0 && numeroJugador < this->jugadores->len() ){

        std::cout << "El numero del jugador (" << numeroJugador << ") no existe" << std::endl;
        throw("El numero del jugador no existe");
    }
    this->numeroJugadorActual = numeroJugador;

}


bool Juego::jugadorActualEstaBloqueado(){

    return (this->getJugadorActual()->getTipoDeTurno() == Bloqueado); 

}


bool Juego::agarrarCartaDelMazo(){

    if( this->jugadorActualTieneMenosDeTresCartas() && !(this->mazoJuego->esMazoVacio()) ){
        this->getJugadorActual()->cargarCarta(this->mazoJuego->darCarta());
        return true;
    }
    return false;

}


bool Juego::jugadorActualTieneLaCartaElegida(int cartaSeleccionada){

    return ( this->getJugadorActual()->getCantidadDeCartasEnMano() >= cartaSeleccionada );

}


bool Juego::jugadorActualArrojoCarta(){

    return ( this->getCartaElegida() != NINGUNA );

}


void Juego::setCartaElegida(int cartaSeleccionada){

    this->cartaActualElegida = cartaSeleccionada;

}


int Juego::getCartaElegida(){

    return this->cartaActualElegida; 

}


void Juego::usarCarta(int cartaSeleccionada){

    switch(this->getJugadorActual()->obtenerCarta(cartaSeleccionada)->getCartaEspecial()){
        case JuegaDoble:
            this->getJugadorActual()->duplicarTurno();
        break;
        case BloquearTurno:
            this->getJugadorSiguiente()->bloquearTurno();
        break;
        case AgarrarCincoFichas:
            this->getJugadorActual()->sumarCincoFichas();
        break;
        case EliminarMazoJugadorSiguiente:
        	int cantidadCartas = this->getJugadorSiguiente()->getCantidadDeCartasEnMano();
            while (cantidadCartas > 0){
                this->getJugadorSiguiente()->eliminarCarta(cantidadCartas);
                cantidadCartas = this->getJugadorSiguiente()->getCantidadDeCartasEnMano();
            } 
        break;    
    }

    this->getJugadorActual()->eliminarCarta(cartaSeleccionada);

}


bool Juego::jugadorActualTieneFichas(){

    return (this->getJugadorActual()->getCantidadDeFichasRestantes() > 0);

}


bool Juego::jugadorActualJuegaDoble(){

    return (this->getJugadorActual()->getTipoDeTurno() == Doble);

}


bool Juego::esColumnaCompleta(int columnaElegida, int profundidadElegida){

    return (this->tablero->columnaEstaLlena(columnaElegida, profundidadElegida));

}


void Juego::colocarFicha(int columnaElegida, int profundidadElegida){

    this->tablero->tirarFicha(columnaElegida, profundidadElegida, this->getJugadorActual()->getFicha());
    this->getJugadorActual()->descontarFichaColocada();
}


bool Juego::actualizarEstadoDeJuego(){

    if( this->getTablero()->ganoAlguien(this->getCantidadFichasEnLinea()) ){
        this->estadoActual = Ganado;
    }

    else if( !(this->getTablero()->tableroEstaLleno()) || (this->jugadoresTienenCartas() || this->jugadoresTienenFichas() || !(this->mazoJuego->esMazoVacio()))){

        this->estadoActual = Jugando;
    }
    else{
        this->estadoActual = Empatado;
    }

    return (this->getEstadoJuego() == Jugando);
}


EstadoJuego Juego::getEstadoJuego(){

    return (this->estadoActual);

}


void Juego::avanzarTurno(){

    if( (this->getJugadorActual()->getTipoDeTurno() == Bloqueado) || (this->getJugadorActual()->getTipoDeTurno() == Doble) ){

            this->getJugadorActual()->reestablecerTurno();
        }

    this->numeroDeTurno++;
    this->setNumeroJugadorActual(this->getNumeroSiguienteJugador());
}



Juego::~Juego(){

    for (int i=0; i<(this->jugadores->len()); i++){
        delete this->jugadores->obtener(i);    
    }
    delete this->jugadores;

    delete this->mazoJuego;

    delete this->tablero;
}
