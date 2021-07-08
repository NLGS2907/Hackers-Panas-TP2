#include "menu.h"

int main() {

    Menu* menu = new Menu();

    menu->mostrarMenuActual();

    delete menu;

    return 0;
}