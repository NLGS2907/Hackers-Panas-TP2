#include "Juego.h"

//PRIVATE
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
        if( this->jugadores->obtenerCursor()->getCantidadDeCartasEnMano() > 0){
            return true;
        }
    }
    return false;

}


bool Juego::tieneMenosDeTresCartas(){

    return (this->jugadores->obtener(this->getNumeroJugadorActual())->getCantidadDeCartasEnMano() < MAX_CARTAS );

}


bool Juego::jugadoresTienenFichas(){

    this->jugadores->iniciarCursor();
    while(this->jugadores->avanzarCursor()){
        if( this->jugadores->obtenerCursor()->getCantidadDeFichasRestantes() > 0){
            return true;
        }
    }
    return false; 

}


char Juego::getFichaAleatoria(){

    srand(time(NULL));
    char fichaAleatoria = 0;

    while( fichaAleatoria < CARACTER_A ){
	    
        fichaAleatoria = rand() % CARACTER_Z;

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


void Juego::cargarJugadores(int cantidadJugadores){

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


//PUBLIC
Juego::Juego(int cantidadFilas, int cantidadColumnas, int profundidad, int cantidadJugadores, int cantidadCartasDelMazo, int cantidadDeFichas, int fichasEnLinea){

        this->jugadores = new Lista<Jugador*>;
        this->mazoJuego = new Mazo(cantidadCartasDelMazo);
        this->tablero = new Tablero(cantidadColumnas, cantidadFilas, profundidad);
        this->numeroJugadorActual = 0;
        this->cantidadFichasEnLinea = fichasEnLinea;
        this->estadoActual = Jugando;
        this->cartaActualElegida = Ninguna;

        this->cargarJugadores(cantidadJugadores);
        
}


int Juego::getNumeroJugadorActual(){

    return this->numeroJugadorActual;

}


void Juego::setNumeroJugadorActual(int numeroJugador){

    if(numeroJugador < 0 && numeroJugador <= this->jugadores->len() ){
        throw("El numero del jugador no existe");
    }
    this->numeroJugadorActual = numeroJugador;

}


bool Juego::estaBloqueado(){

    return (this->jugadores->obtener(this->getNumeroJugadorActual())->getTipoDeTurno() == Bloqueado); 

}


void Juego::agarrarCarta(){
    
    if( this->tieneMenosDeTresCartas() ){
        this->jugadores->obtener(this->getNumeroJugadorActual())->cargarCarta(this->mazoJuego->darCarta());
    }

}


bool Juego::tieneLaCartaElegida(CartaElegida cartaSeleccionada){

    return ( this->jugadores->obtener(this->getNumeroJugadorActual())->getCantidadDeCartasEnMano >= cartaSeleccionada );

}


bool Juego::arrojoCarta(){

    return ( this->getCartaElegida() != Ninguna );

}


void Juego::setCartaElegida(CartaElegida cartaSeleccionada){

    this->cartaActualElegida = cartaSeleccionada;

}


CartaElegida Juego::getCartaElegida(){

    return this->cartaActualElegida; 

}


void Juego::usarCarta(CartaElegida cartaSeleccionada){
  
    switch(this->jugadores->obtener(this->getNumeroJugadorActual())->obtenerCarta(cartaSeleccionada)->getCartaEspecial()){
        case JuegaDoble: 
            this->jugadores->obtener(this->getNumeroJugadorActual())->duplicarTurno();
        break;
        case BloquearTurno:
            this->jugadores->obtener(this->getNumeroSiguienteJugador())->bloquearTurno();
        break;
        case AgarrarCincoFichas:
            this->jugadores->obtener(this->getNumeroJugadorActual())->sumarCincoFichas();
        break;
        case EliminarMazoSiguiente:
            while (this->jugadores->obtener(this->getNumeroSiguienteJugador())->getCantidadDeCartasEnMano() > 0){
                this->jugadores->obtener(this->getNumeroSiguienteJugador())->eliminarCarta(this->jugadores->obtener(this->getNumeroSiguienteJugador())->getCantidadDeCartasEnMano());
            } 
        break;    
    }

    this->jugadores->obtener(this->getNumeroJugadorActual())->eliminarCarta(cartaSeleccionada);
    
}


bool Juego::tieneFichas(){

    return (this->jugadores->obtener(this->getNumeroJugadorActual())->getCantidadDeFichasRestantes() > 0);

}


bool Juego::juegaDoble(){

    return (this->jugadores->obtener(this->getNumeroJugadorActual())->getTipoDeTurno() == Doble);

}


bool Juego::esColumnaCompleta(int columnaElegida, int profundidadElegida){

    return (this->tablero->columnaEstaLlena(columnaElegida, profundidadElegida));

}


void Juego::colocarFicha(int columnaElegida, int profundidadElegida){

    this->tablero->tirarFicha(columnaElegida, profundidadElegida, this->jugadores->obtener(this->getNumeroJugadorActual())->getFicha());
    this->jugadores->obtener(this->getNumeroJugadorActual())->descontarFichaColocada();
    
}


void Juego::actualizarEstadoDeJuego(){

    if( this->tablero->ganoAlguien(this->getCantidadFichasEnLinea()) ){
        this->estadoActual = Ganado;
    }
    else if( !(this->tablero->tableroEstaLleno()) && (this->jugadoresTienenCartas() || this->jugadoresTienenFichas() || !(this->mazoJuego->esMazoVacio()))){
        this->estadoActual = Jugando;
    }
    else{
        this->estadoActual = Empatado;
    }

}


EstadoJuego Juego::getEstadoJuego(){

    return (this->estadoActual);

}


void Juego::avanzarTurno(){

    if( (this->jugadores->obtener(this->getNumeroJugadorActual())->getTipoDeTurno() == Bloqueado) ||
        (this->jugadores->obtener(this->getNumeroJugadorActual())->getTipoDeTurno() == Doble) ){
            
            this->jugadores->obtener(this->getNumeroJugadorActual())->reestablecerTurno();
        }

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


