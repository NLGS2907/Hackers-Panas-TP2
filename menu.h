/*
 * menu.h
 *
 *  Created on: Jul 5, 2021
 *      Author: Guillermina
 */

#ifndef MENU_H_
#define MENU_H_

#include<iostream>
#include<string>

class Menu {

private:

	int tamanioX;
	int tamanioY;
	int tamanioZ;
	int cantidadJugadores;
	int cantidadDeFichasPorJugador;


public:

	Menu(){

		tamanioX = 0;
		tamanioY = 0;
		tamanioZ = 0;
		cantidadJugadores = 0;
		cantidadDeFichasPorJugador = 0;

	}

	int getTamanioX(){

		return this->tamanioX;
	}

	int getTamanioY(){

		return this->tamanioY;
	}

	int getTamanioZ(){

		return this->tamanioZ;

	}

	int getCantidadJugadores(){

		return this->cantidadJugadores;

	}

	int getCantidadDeFichasPorJugador(){

		return this->cantidadDeFichasPorJugador;

	}

	void setTamanioX(int nuevoTamanioX){

		this->tamanioX = nuevoTamanioX;
	}

	void setTamanioY(int nuevoTamanioY){

		this->tamanioY = nuevoTamanioY;
	}

	void setTamanioZ(int nuevoTamanioZ){

		this->tamanioZ = nuevoTamanioZ;

	}

	void setCantidadJugadores(int nuevaCantidadJugadores){

		this->cantidadJugadores = nuevaCantidadJugadores;

	}

	void setCantidadDeFichasPorJugador(int nuevaCantidadDeFichasPorJugador){

		this->cantidadDeFichasPorJugador = nuevaCantidadDeFichasPorJugador;

	}

	void mostrarMenuPrincipal() {

		std::cout << "Menu Principal" << std::endl
				  << "1. Jugar" << std::endl
				  << "2. Opciones" << std::endl
				  << "3. Salir" << std::endl;

	}

	void seleccionarUnaOpcion() {

		this->mostrarMenuPrincipal();

		int opcion;
		std::cout<< "Seleccione opción:" << std::endl;
		std::cin >> opcion;

		//validarOpcion(opcion);

		switch(opcion) {

		case 1:
			jugar();
		break;

		case 2:
			this->modificarOpciones();
		break;

		case 3:
			salir();
		break;
		}

	}

	void mostrarOpciones(){

		std::cout << "Opciones" << std::endl
				  << "1. Cantidad de Jugadores: " << this->cantidadJugadores << std::endl
				  << "2. Cantidad de fichas por jugador: " << this->cantidadDeFichasPorJugador << std::endl
				  << "3. Tamaño del tablero (x): " << this->tamanioX << std::endl
				  << "4. Tamaño del tablero (y): " << this->tamanioY <<std::endl
				  << "5. Tamaño del tablero (z): " << this->tamanioZ <<std::endl;
	}

	void modificarOpciones(){

		this->mostrarOpciones();

		int opcion;
		std::cout << "¿Desea cambiar algo? (Presione 0 para volver): " << std::endl;
		std::cin >> opcion;

		while(opcion != 0){

			switch(opcion) {

				case 1:

					int nuevaCantidadJugadores;
					std::cout << "Ingrese la nueva cantidad de jugadores: " << std::endl;
					std::cin >> nuevaCantidadJugadores;
					this->setCantidadJugadores(nuevaCantidadJugadores);

				break;

				case 2:

					int nuevaCantidadDeFichasPorJugador;
					std::cout << "Ingrese la nueva cantidad de fichas por jugador: " << std::endl;
					std::cin >> nuevaCantidadDeFichasPorJugador;
					this->setCantidadDeFichasPorJugador(nuevaCantidadDeFichasPorJugador);

				break;

				case 3:
					int nuevoTamanioX;
					std::cout << "Ingrese el nuevo Tamaño del tablero (x): " << std::endl;
					std::cin >> nuevoTamanioX;
					this->setTamanioX(nuevoTamanioX);

				break;

				case 4:
					int nuevoTamanioY;
					std::cout << "Ingrese el nuevo Tamaño del tablero (y): " << std::endl;
					std::cin >> nuevoTamanioY;
					this->setTamanioY(nuevoTamanioY);

				break;

				case 5:
					int nuevoTamanioZ;
					std::cout << "Ingrese el nuevo Tamaño del tablero (z): " << std::endl;
					std::cin >> nuevoTamanioZ;
					this->setTamanioZ(nuevoTamanioZ);

				break;

				}

			this->mostrarOpciones();
			std::cout << "¿Desea cambiar algo? (Presione 0 para volver): " << std::endl;
			std::cin >> opcion;
		}
		if(opcion == 0) {
			this->seleccionarUnaOpcion();
		}
	}

	void salir(){

	}

	void jugar(){

	}

	~Menu(){

	}
};




#endif /* MENU_H_ */
