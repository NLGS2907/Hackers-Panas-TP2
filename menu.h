#ifndef MENU_H_
#define MENU_H_

#include "juego.h"
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
    POS: -
    __________________________________________________
    */
	Menu();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	~Menu();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    TipoDeMenu getTipoMenu();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	int getTamanioX();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	int getTamanioY();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	int getTamanioZ();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	int getNenLinea();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	int getCantidadJugadores();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	int getCantidadFichasPorJugador();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    int getCartasJuegaDoble();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    int getCartasBloquearTurno();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    int getCartasAgarrarCincoFichas();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    int getCartasEliminarMazoJugadorSiguiente();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void setTipoMenu(TipoDeMenu nuevoTipo);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	void setTamanioX(int nuevoTamanioX);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	void setTamanioY(int nuevoTamanioY);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void setNenLinea(int nuevoNenLinea);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	void setTamanioZ(int nuevoTamanioZ);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	void setCantidadJugadores(int nuevaCantidadJugadores);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	void setCantidadDeFichasPorJugador(int nuevaCantidadDeFichasPorJugador);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void setCartasJuegaDoble(int nuevasCartasJuegaDoble);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void setCartasBloquearTurno(int nuevasCartasBloquearTurno);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void setCartasAgarrarCincoFichas(int nuevasCartasAgarrarCincoFicha);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void setCartasEliminarMazoJugadorSiguiente(int nuevasCartasEliminarMazoJugadorSiguiente);

    int cartasTotales();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	//POST: imprime menu principal
	void mostrarMenuPrincipal();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	//POST: Imprime opciones de datos a modificar	
	void mostrarMenuOpciones();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void mostrarMenuDeJuego();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void mostrarMenuActual();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	//POST: imprime menu principal
	//      pide seleccionar opcion
	//      si selecciona 2, lleva a funcion modificar opciones
	void seleccionarUnaOpcion();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	//POST: Pregunta si desea modificar si se ingresa otro numero que
	//no sea 0 entra en loop preguntado si desea modificar
	// cuando selecciona cero muestra menu principal
	// al seleccionar del 1-5 modifica el dato pedido e imprime datos actualizados.	
	void modificarOpcion(int opcionElegida);

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	void iniciarJuego();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
	void salir();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    int pedirColumna();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    int pedirProfundidad();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void tirarUnaFicha();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    bool quiereJugarCarta();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void mostrarCartas();

    /*
    __________________________________________________
    PRE: -
    -
    POS: -
    __________________________________________________
    */
    void utilizarCarta();
};

#endif /* MENU_H_ */