#ifndef JUGADOR_H_
#define JUGADOR_H_

#include"listaLigada.h"
#include"carta.h"
#include<ctime>
#include<cstdlib>
#include<unistd.h>
#include<string>

const int CINCO_FICHAS = 5;

enum TipoDeTurno{
    Comun,
    Doble,
    Bloqueado
};


class Jugador{

    private:
        char fichaJugador;
        int cantidadDeFichas;
        Lista<Carta*>* cartasJugador;
        TipoDeTurno turno;
        std::string colorJugador;

        /*
       __________________________________________________
        PRE: -
        -
        POS: Devuelve un color en hexadecimal aleatorio.
        __________________________________________________
        */
        std::string generarColorAleatorio();

    public:

        /*
        __________________________________________________
        PRE:La cantidadFichasJugador tiene que ser mayor a 0.
        -
        POS: Crea un jugador con: 
                -Un tipo de ficha "char" para identificarla en el juego.
                -La cantidad de fichas que tendra para jugar.
        __________________________________________________
        */
        Jugador(char ficha, int cantidadFichasJugador);

        /*
        __________________________________________________
        PRE: -
        -
        POS: Devuelve la lista de cartas del jugador.
        __________________________________________________
        */
        Lista<Carta*>* getCartasJugador();

        /*
        __________________________________________________
        PRE: -
        -
        POS: Devuelve la ficha que identifica al jugador.
        __________________________________________________
        */
        std::string getColorJugador();

        /*
        __________________________________________________
        PRE: -
        -
        POS: Devuelve la ficha que identifica al jugador.
        __________________________________________________
        */
        char getFicha();

        /*
        __________________________________________________
        PRE: -
        -
        POS: Devuelve la cantidad de fichas que le quedan al jugador.
        __________________________________________________
        */
        int getCantidadDeFichasRestantes();

        /*
        __________________________________________________
        PRE: -
        -
        POS: Devuelve la cantidad de cartas que tiene el jugador. 
        __________________________________________________
        */
        int getCantidadDeCartasEnMano();

        /*
        __________________________________________________
        PRE: El jugador agarro una carta.
        -
        POS: Carga a la lista de cartas del jugador la carta pasada por parametro.
        __________________________________________________
        */
        void cargarCarta(Carta* cartaAgarrada);

        /*
        __________________________________________________
        PRE: El jugador eligio usar la carta en la posicion pasada por parametro.
        -
        POS: Devuelve un puntero a la carta en la posicion elegida.
        __________________________________________________
        */
        Carta* obtenerCarta(int posicionCarta);

        /*
        __________________________________________________
        PRE: La carta fue usada en el juego o se uso la carta
             "Eliminar Mazo Siguiente Jugador" en su contra.
        -
        POS:Elimina la carta pasada por parametro de la lista. 
        __________________________________________________
        */
        void eliminarCarta(int posicionCarta);

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
        PRE: Termino el turno del jugador y este fue afectado por
             una carta (Juega Doble o Bloqueado).
        -
        POS: Convierte el turno del jugador a tipo "Comun".
        __________________________________________________
        */
        void reestablecerTurno();

        /*
        __________________________________________________
        PRE: -
        -
        POS:-Devuelve el tipo de turno que tiene el jugador.
        __________________________________________________
        */
        TipoDeTurno getTipoDeTurno();

        /*
        __________________________________________________
        PRE: -
        -
        POS:-Establece el tipo de turno que el jugador tendra.
        __________________________________________________
        */
        void setTipoDeTurno(TipoDeTurno turno);

        /*
        __________________________________________________
        PRE: El jugador coloco una ficha en el tablero.
        -
        POS: Le descuenta una ficha a la cantidadDeFichas.
        __________________________________________________
        */
        void descontarFichaColocada();

        /*
        __________________________________________________
        PRE: -
        -
        POS: Libera la memoria que ocupa el jugador.
        __________________________________________________
        */
        ~Jugador();
};

#endif /* JUGADOR_H_ */
