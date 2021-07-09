#include "menu.h"

Menu::Menu() {

    this->tipo = menuPrincipal;
    this->rondaActual = 1;

    this->tamanioX = 5;
    this->tamanioY = 6;
    this->tamanioZ = 5;

    this->nEnLinea = 4;

    this->cantidadJugadores = 3;
    this->cantidadDeFichasPorJugador = 20;

    this->cantidadCartasJuegaDoble = 5;
    this->cantidadCartasBloquearTurno = 5;
    this->cantidadCartasAgarrarCincoFichas = 5;
    this->cantidadCartasEliminarMazoJugadorSiguiente = 5;
    
    this->juego = new Juego(this->getTamanioY(), this->getTamanioX(), this->getTamanioZ(),
                            this->getCantidadJugadores(), this->getCantidadFichasPorJugador(), this->getNenLinea(),
                            this->getCartasJuegaDoble(), this->getCartasBloquearTurno(), this->getCartasAgarrarCincoFichas(),
                            this->getCartasEliminarMazoJugadorSiguiente());

    this->exportador = new Exportador(this->juego);
}

Menu::~Menu() {

    delete this->juego;
    delete this->exportador;
}

TipoDeMenu Menu::getTipoMenu() {

    return this->tipo;
}

int Menu::getRondaActual() {

    return this->rondaActual;
}

Exportador* Menu::getExportador() {

    return this->exportador;
}

int Menu::getTamanioX() {

    return this->tamanioX;
}

int Menu::getTamanioY() {

    return this->tamanioY;
}

int Menu::getTamanioZ() {

    return this->tamanioZ;

}

int Menu::getNenLinea() {

    return this->nEnLinea;
}

int Menu::getCantidadJugadores() {

    return this->cantidadJugadores;

}

int Menu::getCantidadFichasPorJugador() {

    return this->cantidadDeFichasPorJugador;

}

int Menu::getCartasJuegaDoble() {

    return this->cantidadCartasJuegaDoble;
}

int Menu::getCartasBloquearTurno() {

    return this->cantidadCartasBloquearTurno;
}

int Menu::getCartasAgarrarCincoFichas() {

    return this->cantidadCartasAgarrarCincoFichas;
}

int Menu::getCartasEliminarMazoJugadorSiguiente() {

    return this->cantidadCartasEliminarMazoJugadorSiguiente;
}

void Menu::setTipoMenu(TipoDeMenu nuevoTipo) {

    this->tipo = nuevoTipo;
}

void Menu::setRondaActual(int nuevaRonda) {

    this->rondaActual = nuevaRonda;
}

void Menu::setExportador(Exportador* nuevoExportador) {

    this->exportador = nuevoExportador;
}

void Menu::setTamanioX(int nuevoTamanioX) {

    this->tamanioX = nuevoTamanioX;
}

void Menu::setTamanioY(int nuevoTamanioY) {

    this->tamanioY = nuevoTamanioY;
}

void Menu::setTamanioZ(int nuevoTamanioZ) {

    this->tamanioZ = nuevoTamanioZ;
}

void Menu::setNenLinea(int nuevoNenLinea) {

    this->nEnLinea = nuevoNenLinea;
}

void Menu::setCantidadJugadores(int nuevaCantidadJugadores) {

    this->cantidadJugadores = nuevaCantidadJugadores;
}

void Menu::setCantidadDeFichasPorJugador(int nuevaCantidadDeFichasPorJugador) {

    this->cantidadDeFichasPorJugador = nuevaCantidadDeFichasPorJugador;
}

void Menu::setCartasJuegaDoble(int nuevasCartasJuegaDoble) {

    this->cantidadCartasJuegaDoble = nuevasCartasJuegaDoble;
}

void Menu::setCartasBloquearTurno(int nuevasCartasBloquearTurno) {

    this->cantidadCartasBloquearTurno = nuevasCartasBloquearTurno;
}

void Menu::setCartasAgarrarCincoFichas(int nuevasCartasAgarrarCincoFichas) {

    this->cantidadCartasAgarrarCincoFichas = nuevasCartasAgarrarCincoFichas;
}

void Menu::setCartasEliminarMazoJugadorSiguiente(int nuevasCartasEliminarMazoJugadorSiguiente) {

    this->cantidadCartasEliminarMazoJugadorSiguiente = nuevasCartasEliminarMazoJugadorSiguiente;
}

int Menu::cartasTotales() {

    return this->cantidadCartasJuegaDoble +
           this->cantidadCartasBloquearTurno +
           this->cantidadCartasAgarrarCincoFichas +
           this->cantidadCartasEliminarMazoJugadorSiguiente;
}

void Menu::mostrarMenuPrincipal() {

    std::cout << "\n\n- Menu Principal -\n\n"
                << "1. Jugar\n"
                << "2. Opciones\n"
                << "3. Salir" << std::endl;
}

void Menu::mostrarMenuOpciones() {

    std::cout << "\n\n- Opciones -\n\n"
              << "\n1. Ancho del tablero (x): " << this->getTamanioX()
              << "\n2. Alto del tablero (y): " << this->getTamanioY()
              << "\n3. Largo del tablero (z): " << this->getTamanioZ()

              << "\n\n4. Fichas Necesarias para ganar: " << this->getNenLinea()

              << "\n\n5. Cantidad de Jugadores: " << this->getCantidadJugadores()
              << "\n6. Cantidad de fichas por jugador: " << this->getCantidadFichasPorJugador()

              << "\n\nCantidad de Cartas Totales del Mazo: " << this->cartasTotales()

              << "\n\n7. Cantidad de Cartas 'Juega Doble': " << this->getCartasJuegaDoble()
              << "\n8. Cantidad de Cartas 'Bloquear Turno': " << this->getCartasBloquearTurno()
              << "\n9. Cantidad de Cartas 'Agarrar Cinco (5) Fichas': " << this->getCartasAgarrarCincoFichas()
              << "\n10. Cantidad de Cartas 'Eliminar Mazo del Jugador Siguiente': " << this->getCartasEliminarMazoJugadorSiguiente() << std::endl;
}

bool Menu::mostrarMenuDeJuego() {

    bool seRepite = false;

    do {
        do {
            if (!this->juego->jugadorActualEstaBloqueado()) {

                this->juego->getTablero()->imprimir();

                std::cout << "Turno " << this->juego->getTurnoActual() << " (le toca al Jugador '" << this->juego->getJugadorActual()->getFicha() << "')\n"
                        << "Cantidad de Fichas Restantes: " << this->juego->getJugadorActual()->getCantidadDeFichasRestantes() << std::endl;

                if (this->juego->agarrarCartaDelMazo()) {

                    std::cout << "\n¡Agarraste una carta del Mazo!" << std::endl;
                }

                if (this->juego->getJugadorActual()->getCantidadDeCartasEnMano() > 0 && this->quiereJugarCarta()) {

                    this->mostrarCartas();
                    this->utilizarCarta();
                }

                this->tirarUnaFicha();
            }

            if (this->juego->actualizarEstadoDeJuego()) {

                this->juego->avanzarTurno();
            }

        } while (this->juego->getEstadoJuego() == Jugando);

        this->juego->getTablero()->imprimir();

        this->exportarTablero();

        std::cout << "\n¡Ha finalizado la ronda " << this->getRondaActual() << "!\n";

        if (this->juego->getEstadoJuego() == Empatado) {

            std::cout << "\nHubo Empate!\n" << std::endl;

        } else if (this->juego->getEstadoJuego() == Ganado) {

            std::cout << "\nHa ganado el Jugador " << this->juego->getJugadorActual()->getFicha() << "!\n" << std::endl;
        }

        if (this->consultarRevancha()) {

            this->iniciarJuego();
            seRepite = true;
            this->setRondaActual(this->getRondaActual() + 1);

        } else {

            seRepite = false;
            this->setTipoMenu(menuPrincipal);
        }

    } while (seRepite);

    if (this->volverAlMenuPrincipal()) {

        return true;
    }

    return false;
}

void Menu::mostrarMenuActual() {

    while (this->tipo != saliendo) {

        if (this->tipo == menuPrincipal) {

            this->mostrarMenuPrincipal();
            this->seleccionarUnaOpcion();

        } else if (this->tipo == menuOpciones) {

            this->mostrarMenuOpciones();
            this->seleccionarUnaOpcion();
            
        } else if (this->tipo == enJuego) {

            if (!this->mostrarMenuDeJuego()) {

                break;
            }
        }
    }
}

void Menu::seleccionarUnaOpcion() {

    int opcion;

    if (this->tipo == menuPrincipal) {

        do {

            std::cout<< "\nSeleccione una opción (1-3): ";
            std::cin >> opcion;

        } while (opcion < 1 || opcion > 3);

        switch(opcion) {

            case 1: // Jugar

            this->iniciarJuego();
            break;

            case 2: // Opciones

            this->setTipoMenu(menuOpciones);
            break;

            case 3: // Salir

            this->salir();
            break;
        }

    } else if (this->tipo == menuOpciones) {

        do {

            std::cout<< "\nSeleccione una opción (1-10) (o presione '0' para volver): ";
            std::cin >> opcion;

        } while (opcion < 0 || opcion > 10);

        switch(opcion) {

            case 0: // Volver

            this->setTipoMenu(menuPrincipal);
            break;

            case 1: // Alto del Tablero
            case 2: // Largo del Tablero
            case 3: // Fichas para ganar
            case 4: // Fichas para ganar
            case 5: // Cantidad de Jugadores
            case 6: // Cantidad de Fichas por Jugador
            case 7: // Cartas 'Juega Doble'
            case 8: // Cartas 'Juega Bloquear Turno'
            case 9: // Cartas 'Agarrar 5 Fichas'
            case 10: // Cartas 'Eliminar Mazo del Jugador Siguiente'

            this->modificarOpcion(opcion);
            break;
        }
    }
}

void Menu::modificarOpcion(int opcionElegida) {

    int fichasParaGanar = this->getNenLinea();
    int opcion;

    switch (opcionElegida) {

        case 1: // Ancho del Tablero

        opcion = fichasParaGanar;

        do {

            std::cout << "\nIngrese el nuevo ancho del tablero";

            if (opcion < fichasParaGanar) {

               std::cout << " (debe ser mayor a la cantidad necesaria para ganar)"; 
            }

            std::cout << " (o presione '0' para cancelar): ";

            std::cin >> opcion;

        } while (opcion < 0 || (opcion > 0 && opcion < fichasParaGanar));

        if (opcion != 0) {

            this->setTamanioX(opcion);
        }

        break;

        case 2: // Alto del Tablero

        opcion = fichasParaGanar;

        do {

            std::cout << "\nIngrese el nuevo alto del tablero";

            if (opcion < fichasParaGanar) {

               std::cout << " (debe ser mayor a la cantidad necesaria para ganar)"; 
            }

            std::cout << " (o presione '0' para cancelar): ";

            std::cin >> opcion;

        } while (opcion < 0 || (opcion > 0 && opcion < fichasParaGanar));

        if (opcion != 0) {

            this->setTamanioY(opcion);
        }

        break;

        case 3: // Largo del Tablero

        opcion = fichasParaGanar;

        do {

            std::cout << "\nIngrese el nuevo largo del tablero";

            if (opcion < fichasParaGanar) {

               std::cout << " (debe ser mayor a la cantidad necesaria para ganar)"; 
            }

            std::cout << " (o presione '0' para cancelar): ";

            std::cin >> opcion;

        } while (opcion < 0 || (opcion > 0 && opcion < fichasParaGanar));

        if (opcion != 0) {

            this->setTamanioZ(opcion);
        }

        break;

        case 4: // Fichas para ganar

        do {

            std::cout << "\nIngrese la nueva cantidad de fichas para ganar (o presione '0' para cancelar): ";
            std::cin >> opcion;

        } while (opcion < 0);

        if (opcion != 0) {

            this->setNenLinea(opcion);

            if (this->getTamanioX() < opcion) {

                this->setTamanioX(opcion);
            }

            if (this->getTamanioY() < opcion) {

                this->setTamanioY(opcion);
            }

            if (this->getTamanioZ() < opcion) {

                this->setTamanioZ(opcion);
            }
        }

        break;

        case 5: // Cantidad de Jugadores

        do {

            std::cout << "\nIngrese la nueva cantidad de jugadores (o presione '0' para cancelar): ";
            std::cin >> opcion;

        } while (opcion < 0);

        if (opcion != 0) {

            this->setCantidadJugadores(opcion);            
        }

        break;

        case 6: // Cantidad de Fichas por Jugador

        opcion = fichasParaGanar;

        do {

            std::cout << "\nIngrese la nueva cantidad de Fichas por Jugador";

            if (opcion < fichasParaGanar) {

               std::cout << " (debe ser mayor a la cantidad necesaria para ganar)"; 
            }

            std::cout << " (o presione '0' para cancelar): ";

            std::cin >> opcion;

        } while (opcion < 0 || (opcion > 0 && opcion < fichasParaGanar));

        if (opcion != 0) {

            this->setCantidadDeFichasPorJugador(opcion);            
        }

        break;

        case 7: // Cartas 'Juega Doble'

        do {

            std::cout << "\nIngrese la nueva cantidad de Cartas 'Juega Doble' (o presione '-1' para cancelar): ";
            std::cin >> opcion;

        } while (opcion < -1);

        if (opcion != -1) {

            this->setCartasJuegaDoble(opcion);
        }

        break;

        case 8: // Cartas 'Juega Bloquear Turno'

        do {

            std::cout << "\nIngrese la nueva cantidad de Cartas 'Bloquear Turno' (o presione '-1' para cancelar): ";
            std::cin >> opcion;

        } while (opcion < -1);

        if (opcion != -1) {

            this->setCartasBloquearTurno(opcion);   
        }

        break;

        case 9: // Cartas 'Agarrar 5 Fichas'

        do {

            std::cout << "\nIngrese la nueva cantidad de Cartas 'Agarrar Cinco (5) Fichas' (o presione '-1' para cancelar): ";
            std::cin >> opcion;

        } while (opcion < -1);

        if (opcion != -1) {

            this->setCartasAgarrarCincoFichas(opcion);         
        }

        break;

        case 10: // Cartas 'Eliminar Mazo del Jugador Siguiente'

        do {

            std::cout << "\nIngrese la nueva cantidad de Cartas 'Eliminar Mazo del Jugador Siguiente' (o presione '-1' para cancelar): ";
            std::cin >> opcion;

        } while (opcion < -1);

        if (opcion != -1) {

            this->setCartasEliminarMazoJugadorSiguiente(opcion);        
        }

        break;
    }
}

void Menu::iniciarJuego() {

    this->juego = new Juego(this->getTamanioY(), this->getTamanioX(), this->getTamanioZ(),
                            this->getCantidadJugadores(), this->getCantidadFichasPorJugador(), this->getNenLinea(),
                            this->getCartasJuegaDoble(), this->getCartasBloquearTurno(), this->getCartasAgarrarCincoFichas(),
                            this->getCartasEliminarMazoJugadorSiguiente());

    this->setExportador(new Exportador(this->juego));

    this->setTipoMenu(enJuego);
}

void Menu::salir() {

    this->setTipoMenu(saliendo);
}

int Menu::pedirColumna() {

    int anchoTablero = this->juego->getTablero()->ancho();
    int columnaElegida;

    do {

        std::cout << "Seleccione una columna en la que tirar ficha (0-" << (anchoTablero - 1) << "): ";
        std::cin >> columnaElegida;

    } while (columnaElegida < 0 || columnaElegida >= anchoTablero);

    return columnaElegida;
}

int Menu::pedirProfundidad() {

    int largoTablero = this->juego->getTablero()->largo();
    int profundidadElegida;

    do {

        std::cout << "Seleccione la profundidad en la que tirar ficha (0-" << (largoTablero - 1) << "): ";
        std::cin >> profundidadElegida;

    } while (profundidadElegida < 0 || profundidadElegida >= largoTablero);

    return profundidadElegida;
}

void Menu::tirarUnaFicha() {

    if (this->juego->jugadorActualTieneFichas()) {

        int tiros;

        if (juego->getJugadorActual()->getTipoDeTurno() == Doble) {

            tiros = 2;

        } else {

            tiros = 1;
        }

        for (int i = 0; i < tiros; i++) {

            bool columnaLlena;
            int columnaElegida;
            int profundidadElegida;

            do {

                columnaElegida = this->pedirColumna();
                profundidadElegida = this->pedirProfundidad();

                if (this->juego->getTablero()->columnaEstaLlena(columnaElegida, profundidadElegida)) {

                    std::cout << "\n¡La columna en las coordenadas (" << columnaElegida << ", " << profundidadElegida
                              << ") está llena! Por favor elige otra.\n" << std::endl;

                    columnaLlena = true;

                } else {

                    columnaLlena = false;
                }

            } while (columnaLlena);

            this->juego->colocarFicha(columnaElegida, profundidadElegida);

            if (!this->juego->actualizarEstadoDeJuego()) {

                break;
            }

            this->exportarTablero();
        }
    }
}

bool Menu::quiereJugarCarta() {

    char eleccion;

    std::cout << "\n¿Desea jugar una de sus cartas Especiales? (s/n): ";
    std::cin >> eleccion;

    return (eleccion == 's' || eleccion == 'S');
}

void Menu::mostrarCartas() {

    Lista<Carta*>* cartas = this->juego->getJugadorActual()->getCartasJugador();
    int cartasEnMano = this->juego->getJugadorActual()->getCantidadDeCartasEnMano();

    std::cout << "\n-= Cartas de '" << this->juego->getJugadorActual()->getFicha() << "' =-\n\n";

    for (int i = 0; i < cartasEnMano; i++) {

        std::cout << "[ " << (i + 1) << ". " << cartas->obtener(i)->getDescripcionCarta() << " ]\n";
    }
}

void Menu::utilizarCarta() {

    int cartasEnMano = this->juego->getJugadorActual()->getCantidadDeCartasEnMano();
    int eleccion;

    do {

        if (cartasEnMano <= 1) {

            std::cout << "\n¿Desea utilizar su carta? (1) ";

        } else {

            std::cout << "\n¿Desea utilizar alguna carta? (1-" << cartasEnMano << ") ";
        }

        std::cout << "(o presione '0' para negarse): ";
        std::cin >> eleccion;

    } while (eleccion < 0 || eleccion > cartasEnMano);

    if (eleccion != 0) {

        CartaEspecial tipoCarta = this->juego->getJugadorActual()->obtenerCarta(eleccion)->getCartaEspecial();
        this->juego->usarCarta(eleccion);

        switch (tipoCarta) {

            case JuegaDoble:

            std::cout << "\n¡Este turno tiras una ficha dos (2) veces!\n" << std::endl;
            break;

            case BloquearTurno:

            std::cout << "\n¡Le bloqueaste el turno al siguiente Jugador!\n" << std::endl;
            break;

            case AgarrarCincoFichas:

            std::cout << "\n¡Ahora tienes cinco (5) fichas mas!\n"
                      << "Nueva Cantidad de Fichas: " << this->juego->getJugadorActual()->getCantidadDeFichasRestantes() << '\n' << std::endl;
            break;

            case EliminarMazoJugadorSiguiente:

            std::cout << "\n¡El Jugador siguiente se quedó sin cartas!\n" << std::endl;
            break;
        }
    }
}

bool Menu::consultarRevancha() {

    char eleccion;

    std::cout << "¿Quieres jugar otra ronda? (s/n): ";
    std::cin >> eleccion;

    if (eleccion == 's' || eleccion == 'S') {

        return true;
    }

    return false;
}

bool Menu::volverAlMenuPrincipal() {

    char eleccion;

    std::cout << "¿Quieres ir al Menu Principal? (s/n): ";
    std::cin >> eleccion;

    if (eleccion == 's' || eleccion == 'S') {

        return true;
    }

    return false;
}

void Menu::exportarTablero() {

    this->getExportador()->dibujarTablero();
    this->getExportador()->actualizarRutaSalida(this->getRondaActual(), this->juego->getTurnoActual());
    this->getExportador()->guardar();
}