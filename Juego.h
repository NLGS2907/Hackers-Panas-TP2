#ifndef JUEGO_H_
#define JUEGO_H_

#include "Jugador.h"
#include "Mazo.h"
#include "Casillero.h"
#include "tablero.h"

const int MAX_CARTAS = 3;

enum EstadoJuego{
    Jugando,
    Ganado,
    Empatado
};

enum CartaElegida{
    Ninguna,
    Primera,
    Segunda,
    Tercera
};


class Juego{

    private:    
        Lista<Jugador>* jugadores;
        Mazo mazoJuego;
        Tablero tablero;
        CartaElegida cartaActualElegida;
        Casillero ultimoCasilleroOcupado; //Lo pongo aca por q solo me importa el anterior jugador.
        
    public:

        /*
        __________________________________________________
        PRE: Los datos del parametro tienen q ser validados por el "Menu" antes de jugar. 
        -
        POS:Crea un juego N en Linea con las caracteristicas pasadas por parametros:
                    -La cantidadDeFilas, cantidadDeColumnas y profundidad sera la dimension de nuestro tablero.
                    -la cantidadDeJugadores sera la cantidad total de persona a jugar.
                    -La cantidadCartasDelMazo son las cantidad de cartas total que habra en el mazo.
                    -La cantidadDeFichas son la cantidad de fichas totales para cada jugador.
        __________________________________________________
        */
        Juego(int cantidadFilas, int canitdadColumnas, int profundidad, int cantidadJugadores, int cantidadCartasDelMazo, int cantidadDeFichas, int fichasEnLinea);

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true si el jugador tiene el turno "Bloqueado", false sino .
        __________________________________________________
        */
        bool estaBloqueado();

        /*
        __________________________________________________
        PRE: El jugadorActual no puede tener 3 o mas cartas en mano. ACLARACION: EL JUGADOR PUEDE AGARRAR CARTA SI NO TIENE FICHAS PARA JUGAR.
        -
        POS:-El jugadorActual recibe una carta del mazo y la guarda en su lista de cartas.
            -Le resta una carta al mazo.
        __________________________________________________
        */
        void agarrarCarta();

        /*
        __________________________________________________
        PRE: La cartaSeleccionada es la Primera, Segunda o Tercera.
        -
        POS:-Devuelve true si hay una carta en la posicion elegida, false sino.
        __________________________________________________
        */
        bool tieneLaCartaElgida(CartaElegida cartaSeleccionada);

        /*
        __________________________________________________
        PRE: -El jugador tiene la carta.
        -
        POS: Establece la carta elegida en el turno por el jugador.
        __________________________________________________
        */
        void setCartaElegida(CartaElegida cartaSeleccionada);

        /*
        __________________________________________________
        PRE:
        -
        POS: Devuelve la carta elegida por el jugador.
        __________________________________________________
        */
        CartaElegida getCartaElegida();

        /*
        __________________________________________________
        PRE:  
        -
        POS:-Devuelve true si la cartaSeleccionada es la  Primera, Segunda o Tercera, false si es Ninguna.
        __________________________________________________
        */
        bool arrojoCarta();

        /*
        __________________________________________________
        PRE: El jugadorActual eligio una carta para usar. ACLARACION: EL JUGADOR PUEDE TIRAR LA CARTA SI NO TIENE FICHAS PARA JUGAR.
        -
        POS: Si usa la carta:
                -Juega Doble: Establece el turno de tipo "Doble" al jugador actual. 
                -Bloquear Turno: Establece el turno de tipo "Bloqueado" al siguiente jugador del actual. 
                -Agarrar Cinco Fichas: Le suma 5 fichas al jugadorActual. SI EL JUGADOR NO TIENE FICHAS Y TIRA ESTA CARTA PUEDE JUGAR
                -Eliminar Mazo Siguiente: Elimina las cartas en mano del siguiente jugador.
                -Reemplazar Ultima Ficha Colocada: El jugador cambia la ultima ficha jugada en el turno anterior por una propia.
                        (Se va a tener q analizar si con el cambio de ficha se hizo N en Linea.)
            Elimina la carta usada por el jugador. 
        __________________________________________________
        */
        void usarCarta(CartaElegida cartaSeleccionada);

        /*
        __________________________________________________
        PRE: El jugador uso la carta "Reemplazar Ultima Ficha Colocada".  
        -
        POS:-Intercambia la ficha colocada del jugador anterior por una del jugador actual en el tablero.
        __________________________________________________
        */
        void reemplazarUltimaFichaColocada();

        /*
        __________________________________________________
        PRE:
        -
        POS:-Devuelve true si la columna esta completa, false sino.
        __________________________________________________
        */
        bool esColumnaCompleta();

        /*
        __________________________________________________
        PRE:
        -
        POS:-Devuelve true si el jugador le quedan fichas, false sino.
        __________________________________________________
        */
        bool tieneFichas();

        /*
        __________________________________________________
        PRE:
        -
        POS:-Establece el ultimo casillero ocupado en el turno.
        __________________________________________________
        */
        void setUltimoCasilleroOcupado();

        /*
        __________________________________________________
        PRE:
        -
        POS:-Devuelve el ultimo casillero ocupado en el turno.
        __________________________________________________
        */
        Casillero getUltimoCasilleroOcupado();

        /*
        __________________________________________________
        PRE: La columna no esta completa.
             El jugador tiene fichas para colocar.
        -
        POS:-Coloca la ficha del jugador en el tablero en la posicion elegida.
            -Le resta una ficha al jugadorActual.
            -Si tiene turno "Doble" coloca 2 veces
        __________________________________________________
        */
        void colocarFicha();

        /*
        __________________________________________________
        PRE: Se coloco una ficha en el tablero.
        -
        POS:-Si todavia el tablero esta incompleto, no hay N en linea y los jugadores tienen cartas para usar: Jugando.
            -Si hay N en linea el estado sera: Ganado
            -Si el tablero esta completo, no hay N en linea y los jugadores ya no tienen cartas para jugar: Empatado.
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
        __________________________________________________
        */
        void avanzarTurno();



};


#endif /* JUEGO_H_ */