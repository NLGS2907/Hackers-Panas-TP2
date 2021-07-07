#ifndef JUEGO_H_
#define JUEGO_H_

#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"

const int MAX_CARTAS = 3;
const int CARACTER_A = 65, CARACTER_Z = 90;

enum EstadoJuego{
    Jugando,
    Ganado,
    Empatado
};

class Juego{

    private:    
    
        Lista<Jugador*>* jugadores;
        Mazo* mazoJuego;
        Tablero<char>* tablero;
        int numeroJugadorActual;
        int cantidadFichasEnLinea;
        EstadoJuego estadoActual;
        int cartaActualElegida;
        int numeroDeTurno;

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve un char aleatorio entre A y Z de la tabla ascii a usar como ficha en el juego.
        __________________________________________________
        */
        char getFichaAleatoria();

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true si la ficha ya esta usada por otro jugador, false sino.
        __________________________________________________
        */
        bool esFichaUsada(char ficha);

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve el numero del jugador siguiente jugador, si es el ultimo devuelve al primero de la lista.
        __________________________________________________
        */
        int getNumeroSiguienteJugador();
        
        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true algun jugador tiene cartas en mano, false sino.
        __________________________________________________
        */
        bool jugadoresTienenCartas();
        
        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true algun jugador tiene fichas, false sino.
        __________________________________________________
        */
        bool jugadoresTienenFichas();

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true si el jugador actual tiene menos de 3 cartas en mano, false sino.
        __________________________________________________
        */
        bool jugadorActualTieneMenosDeTresCartas();

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve la lista de jugadores cargada.
        __________________________________________________
        */
        void cargarJugadores(int cantidadDeFichas, int cantidadJugadores);


        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve la cantidad de fichas a alinear para ganar.
        __________________________________________________
        */
        int getCantidadFichasEnLinea();

    public:

        /*
        __________________________________________________
        PRE: Los datos del parametro tienen q ser validados por el "Menu" antes de jugar. 
        -
        POS:Crea un juego N en Linea con las caracteristicas pasadas por parametros:
                    -La cantidadDeFilas, cantidadDeColumnas y profundidad sera la dimension de nuestro tablero.
                    -la cantidadDeJugadores sera la cantidad total de personas a jugar.
                    -La cantidadDeFichas son la cantidad de fichas totales para cada jugador.
                    -Las fichasEnLinea es la cantidad de fichas a alinear para ganar el juego.
                    -La cartasJuegaDoble, cartasBloquearTurno, cartasAgarrarCincoFichas y cartasEliminarMazoSiguienteJugador son las cartas que tendra el mazoJuego.
        __________________________________________________
        */
        Juego(int cantidadFilas, int canitdadColumnas, int profundidad, int cantidadJugadores, int cantidadDeFichas, int fichasEnLinea,
        		int cartasJuegaDoble, int cartasBloquearTurno, int cartasAgarrarCincoFichas, int cartasEliminarMazoSiguienteJugador);

        /*
        __________________________________________________
        PRE:
        -
        POS:-Devuelve el numero del turno actual.
        __________________________________________________
        */
        int getTurnoActual();

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve el numero del jugador actual que esta jugando.
        __________________________________________________
        */
        int getNumeroJugadorActual();

        /*
        __________________________________________________
        PRE: El numero de jugador debe ser mayor a 0 y menor a la cantidad de jugadores.
        -
        POS:-Establece el numero del jugador actual a jugar.
        __________________________________________________
        */
        void setNumeroJugadorActual(int numeroJugador);

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true si el jugador actual tiene el turno "Bloqueado", false sino .
        __________________________________________________
        */
        bool jugadorActualEstaBloqueado();

        /*
        __________________________________________________
        PRE: El jugador Actual no puede agarrar si tiene 3 cartas en mano. 
        -
        POS:-Si el jugador actual tiene menos de 3 cartas en mano se le da una carta y la guarda en su lista de cartas, si tiene 3 no agarra.
            -Le resta una carta al mazo.
        __________________________________________________
        */
        void agarrarCarta();

        /*
        __________________________________________________
        PRE: 
        -
        POS:-Devuelve true si hay una carta en la posicion elegida del jugador actual, false sino.
        __________________________________________________
        */
        bool jugadorActualTieneLaCartaElegida(int cartaSeleccionada);

        /*
        __________________________________________________
        PRE: -El jugador actual tiene la carta.
        -
        POS: Establece la carta elegida en el turno por el jugador actual.
        __________________________________________________
        */
        void setCartaElegida(int cartaSeleccionada);

        /*
        __________________________________________________
        PRE:
        -
        POS: Devuelve la carta elegida por el jugador actual.
        __________________________________________________
        */
        int getCartaElegida();

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true si la cartaSeleccionada es la  Primera, Segunda o Tercera, false si es Ninguna.
        __________________________________________________
        */
        bool jugadorActualArrojoCarta();

        /*
        __________________________________________________
        PRE: El jugador Actual eligio una carta para usar. 
        -
        POS: Si usa la carta:
                -Juega Doble: Establece el turno de tipo "Doble" al jugador actual. 
                -Bloquear Turno: Establece el turno de tipo "Bloqueado" al siguiente jugador del actual. 
                -Agarrar Cinco Fichas: Le suma 5 fichas al jugadorActual. SI EL JUGADOR NO TIENE FICHAS Y TIRA ESTA CARTA PUEDE JUGAR
                -Eliminar Mazo Siguiente: Elimina las cartas en mano del siguiente jugador.

            Elimina la carta usada por el jugador. 
        __________________________________________________
        */
        void usarCarta(int cartaSeleccionada);

        /*
        __________________________________________________
        PRE:
        -
        POS:-Devuelve true si el jugador actual le quedan fichas, false sino.
        __________________________________________________
        */
        bool jugadorActualTieneFichas();

        /*
        __________________________________________________
        PRE:
        -
        POS: Devuelve true si el jugaor actual tiene turno doble, false sino.
        __________________________________________________
        */
        bool jugadorActualJuegaDoble();

        /*
        __________________________________________________
        PRE:
        -
        POS: Devuelve el true si esta completa la columna donde se quiere colocar la ficha, false sino.
        __________________________________________________
        */
        bool esColumnaCompleta(int columnaElegida, int profundidadElegida);

        /*
        __________________________________________________
        PRE: La columna no esta completa.
             El jugador tiene fichas para colocar.
        -
        POS:-Coloca la ficha del jugador en el tablero en la posicion elegida.
            -Le resta una ficha al jugadorActual.
        __________________________________________________
        */
        void colocarFicha(int columnaElegida, int profundidadElegida);

        /*
        __________________________________________________
        PRE: Se coloco una ficha en el tablero.
        -
        POS:-Si hay N en linea el estado sera: Ganado
            -Si todavia el tablero esta incompleto y los jugadores tienen cartas o fichas para usar o hay cartas en el mazo: Jugando.
            -En el caso de que no se cumpla ninguna de las anteriores condiciones: Empatado.
        __________________________________________________
        */
        void actualizarEstadoDeJuego();
        
        /*
        __________________________________________________
        PRE:
        -
        POS:Devuelve el estado en que se encuentra el juego: Jugando, Ganado o Empatado.
        __________________________________________________
        */
        EstadoJuego getEstadoJuego();
        
        /*
        __________________________________________________
        PRE:
        -
        POS: -Reestablece el turno de tipo "Comun" al jugador si fue afectado por la carta "JuegaDoble" o "BloquearTurno". 
             -Pasa al siguiente jugador en la lista de jugadores.
             -Incrementa el numero de turno.
        __________________________________________________
        */
        void avanzarTurno();


        /*
        __________________________________________________
        PRE:
        -
        POS: -Libera la memoria que ocupa el Juego
        __________________________________________________
        */
        ~Juego();

};


#endif /* JUEGO_H_ */
