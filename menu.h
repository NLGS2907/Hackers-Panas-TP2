#ifndef MENU_H_
#define MENU_H_

#include "juego.h"
#include "exportador.h"
#include <iostream>

enum TipoDeMenu {

    enJuego,
    menuPrincipal,
    menuOpciones,
    saliendo
};

class Menu {

private:

    Juego* juego;
    int rondaActual;
    Exportador* exportador;

    TipoDeMenu tipo;

	int tamanioX;
	int tamanioY;
	int tamanioZ;

    int nEnLinea;

	int cantidadJugadores;
	int cantidadDeFichasPorJugador;

    int cantidadCartasJuegaDoble;
    int cantidadCartasBloquearTurno;
    int cantidadCartasAgarrarCincoFichas;
    int cantidadCartasEliminarMazoJugadorSiguiente;


public:

    /*
    __________________________________________________
    PRE: -
    -
    POS: Crea una instancia Menu, lista para ser usada.
    __________________________________________________
    */
	Menu();

    /*
    __________________________________________________
    PRE: -
    -
    POS: Elimina 'this->juego', liberando la memoria
         dinámica que anteriormente ocupaba.
    __________________________________________________
    */
	~Menu();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve el tipo de Menu Actual.
    */
    TipoDeMenu getTipoMenu();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve el numero de la ronda actual.
    */
    int getRondaActual();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve el exportador del juego.
    */
    Exportador* getExportador();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve el ANCHO del tablero.
    */
	int getTamanioX();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve el ALTO del tablero.
    */
	int getTamanioY();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve el LARGO del tablero.
    */
	int getTamanioZ();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve la cantidad de fichas puestas en línea necesarias
    para ganar la partida.
    */
	int getNenLinea();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve la cantidad de personas jugando.
    */
	int getCantidadJugadores();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve la cantidad de fichas inicial que cada jugador
    tiene a su disposición.
    */
	int getCantidadFichasPorJugador();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve la cantidad de cartas de tipo 'JuegaDoble'.
    */
    int getCartasJuegaDoble();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve la cantidad de cartas de tipo 'BloquearTurno'.
    */
    int getCartasBloquearTurno();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________

    Devuelve la cantidad de cartas de tipo 'AgarrarCincoFichas'.
    */
    int getCartasAgarrarCincoFichas();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve la cantidad de cartas de tipo 'EliminarMazoJugadorSiguiente'.
    */
    int getCartasEliminarMazoJugadorSiguiente();

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica el tipo del Menu actual.
    */
    void setTipoMenu(TipoDeMenu nuevoTipo);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica el numero de la ronda actual.
    */
    void setRondaActual(int nuevaRonda);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica el exportador del juego.
    */
    void setExportador(Exportador* nuevoExportador);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica el ANCHO del tablero.
    */
	void setTamanioX(int nuevoTamanioX);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica el ALTO del tablero.
    */
	void setTamanioY(int nuevoTamanioY);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica el LARGO del tablero.
    */
	void setTamanioZ(int nuevoTamanioZ);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica la cantidad de fichas puestas en línea necesarias
    para ganar la partida.
    */
    void setNenLinea(int nuevoNenLinea);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica la cantidad de personas jugando.
    */
	void setCantidadJugadores(int nuevaCantidadJugadores);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica la cantidad de fichas inicial que cada jugador
    tiene a su disposición.
    */
	void setCantidadDeFichasPorJugador(int nuevaCantidadDeFichasPorJugador);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica la cantidad de cartas de tipo 'JuegaDoble'.
    */
    void setCartasJuegaDoble(int nuevasCartasJuegaDoble);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica la cantidad de cartas de tipo 'BloquearTurno'.
    */
    void setCartasBloquearTurno(int nuevasCartasBloquearTurno);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica la cantidad de cartas de tipo 'AgarrarCincoFichas'.
    */
    void setCartasAgarrarCincoFichas(int nuevasCartasAgarrarCincoFicha);

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu es modificado.
    __________________________________________________

    Modifica la cantidad de cartas de tipo 'EliminarMazoJugadorSiguiente'.
    */
    void setCartasEliminarMazoJugadorSiguiente(int nuevasCartasEliminarMazoJugadorSiguiente);

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Devuelve la suma de todas las cantidades de tipos de cartas.
    */

    int cartasTotales();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Imprime por pantalla el Menu principal, mostrando las opciones
    disponibles.
    */
	void mostrarMenuPrincipal();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Imprime por pantalla el Menu de Opciones, mostrando todos
    los parámetros de juego personalizables disponibles.
    */
	void mostrarMenuOpciones();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Imprime por pantalla a cada turno el estado de tablero, así
    como toda la información necesaria para que el jugador juegue
    satisfactoriamente.
    Devuelve 'true' si el usuario elije salir al menus principal al
    terminar la ronda. En caso contrario, devuelve 'false'.
    */
    bool mostrarMenuDeJuego();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Detecta cuál es el estado del Menu (si está en el Menu principal,
    si está en Opciones o si está en medio del juego), e imprime
    por pantalla la información correspondiente.
    */
    void mostrarMenuActual();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Dependiendo de cuál sea el menú actual, ofrece al usuario la
    información de cuáles son los elementos, y la forma de interactuar
    con ellos.
    */
	void seleccionarUnaOpcion();

    /*
    __________________________________________________
    PRE: -
    -
    POS: Un atributo del Menu podría ser modificado.
    __________________________________________________

    Elegida una opción, y dependiendo a cuál parámetro se
    refiere la misma, se procesa las compatibilidades
    correspondiente y, de ser posible, modifica el valor del
    atributo.
    */	
	void modificarOpcion(int opcionElegida);

    /*
    __________________________________________________
    PRE: -
    -
    POS: El atributo 'this->juego' del Menu es inicializado.
    __________________________________________________

    Inicializa el juego con los parámetros del Menu.
    */
	void iniciarJuego();

    /*
    __________________________________________________
    PRE: -
    -
    POS: Cambia el estado del Menu.
    __________________________________________________

    El estado en sí está puramente para verificar si se está
    saliendo del programa, en cuyo caso pasa de largo en los
    ciclos y finaliza existosamente la ejecución del programa.
    */
	void salir();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Le pide al usuario que ingrese un numero, y valida que
esté entre 0 y el ANCHO del tablero, en cuyo caso devuelve
    el valor.
    */
    int pedirColumna();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Le pide al usuario que ingrese un numero, y valida que
esté entre 0 y el LARGO del tablero, en cuyo caso devuelve
    el valor.
    */
    int pedirProfundidad();

    /*
    __________________________________________________
    PRE: -
    -
    POS: Modifica el tablero del juego.
    __________________________________________________

    Se tira una ficha, de ser posible, en el tablero del
    juego, en las coordenadas seleccionadas.
    */
    void tirarUnaFicha();

    /*
    __________________________________________________
    PRE: -
    -
    POS: Devuelve 'true' si el usuario responde con 's'.
         En cualquier otro caso devuelve 'false'.
    __________________________________________________

    Le pregunta al usuario si, de tener cartas, quiere verlas
    para posiblemente usar alguna.
    */
    bool quiereJugarCarta();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Imprime por pantalla las cartas que el jugador actual
    tiene a su disposición.
    */
    void mostrarCartas();

    /*
    __________________________________________________
    PRE: -
    -
    POS: Dependiendo del tipo de carta usada, el Menu podría
         ser modificado.
    __________________________________________________

    Pregunta al usuario si quiere usar la o las cartas disponibles.
    De aceptar, se aplica el efecto correspondiente.
    */
    void utilizarCarta();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Imprime por pantalla un mensaje que le pregunta al usuario si
    quiere iniciar otra ronda, en la que si acepta, devuelve 'true'.
    En caso contrario, devuelve 'false'.
    */
    bool consultarRevancha();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Pregunta al usuario si quiere ir al menú principal. Si responde
    que sí, devuelve 'true'. En caso contrario, devuelve 'false'.
    */
    bool volverAlMenuPrincipal();

    /*
    __________________________________________________
    PRE: -
    -
    POS: El Menu permanece inalterado.
    __________________________________________________

    Se exporta el estado del tablero a un archivo BMP en la carpeta
    'historial'.
    */
    void exportarTablero();
};

#endif /* MENU_H_ */