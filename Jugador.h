#ifndef JUGADOR_H_
#define JUGADOR_H_

#include"listaLigada.h"
#include"Carta.h"

enum TipoDeTurno{
    Comun,
    Doble,
    Bloqueado
}

class Jugador{

    private:
        
        char fichaJugador;
        int cantidadDeFichas;
        int profundidadElegida;
        int columnaElegida;
        Lista<Carta>* cartasJugador;
        TipoDeTurno turno;

        
    public:

        /*
        __________________________________________________
        PRE:
        -
        POS:Crea un jugador con: 
                -Un tipo de ficha "char" para identificarla en el juego.
                -La cantidad de fichas que tendra para jugar.
        __________________________________________________
        */
        Jugador(char ficha, int cantidadDeFichasPorJugador);

        /*
        __________________________________________________
        PRE:
        -
        POS: Devuelve la cantidad de fichas que le quedan al jugador.
        __________________________________________________
        */
        int getCantidadDeFichasRestantes();

        /*
        __________________________________________________
        PRE: 
        -
        POS: Devuelve la cantidad de cartas que tiene el jugador. (Con sizeof de la lista de cartas)
        __________________________________________________
        */
        int getCantidadDeCartasEnMano();

        /*
        __________________________________________________
        PRE: 
        -
        POS: Carga a la lista de cartas del jugador la carta pasada por parametro.
        __________________________________________________
        */
        void cargarCarta(Carta cartaAgarrada);

        /*
        __________________________________________________
        PRE: La carta fue usada en el juego.
        -
        POS:Elimina la carta pasada por parametro de la lista. 
        __________________________________________________
        */
        void eliminarCarta(CartaElegida carta);

        /*
        __________________________________________________
        PRE: El jugador uso la carta "JuegaDoble".
        -
        POS: Convierte el turno del jugador a tipo "Doble".
        __________________________________________________
        */
        void duplicarTurno();

        /*
        __________________________________________________
        PRE: Usaron la carta "BloquearTurno" en contra del jugador.
        -
        POS: Bloquea el turno del jugador.
        __________________________________________________
        */
        void bloquearTurno();

        /*
        __________________________________________________
        PRE: El jugador uso la carta "Agarrar Cinco Fichas".
        -
        POS: Le suma cinco fichas a la cantidad de fichas del jugador.
        __________________________________________________
        */
        void sumarCincoFichas();

        /*
        __________________________________________________
        PRE: Termino el turno del jugador y este fue afectado por una carta(Juega Doble o Bloqueado).
        -
        POS: Convierte el turno del jugador a tipo "Comun".
        __________________________________________________
        */
        void reestablecerTurno();

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve el tipo de turno que tiene el jugador.
        __________________________________________________
        */
        TipoDeTurno getTipoDeTurno();

        /*
        __________________________________________________
        PRE:
        -
        POS: Establece la columna elegida por el jugador.
        __________________________________________________
        */
        void setColumnaElegida(int columnaSeleccionada);

        /*
        __________________________________________________
        PRE:
        -
        POS: Establece la profundidad elegida por el jugador.
        __________________________________________________
        */
        void setProfundidadElegida(int profundidadSeleccionada);

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true si hay carta en la posicion elegida, false sino .
        __________________________________________________
        */
        int getColumnaElegida();

        /*
        __________________________________________________
        PRE:
        -
        POS:Devuelve la profundidad elegida por el jugador.
        __________________________________________________
        */
        int getProfundidadElegida();

        /*
        __________________________________________________
        PRE:
        -
        POS:Le descuenta una ficha a la cantidadDeFichas.
        __________________________________________________
        */
        void descontarUnaFicha();

        

};

#endif /* JUGADOR_H_ */