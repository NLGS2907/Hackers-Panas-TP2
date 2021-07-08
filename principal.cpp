#include "menu.h"
using namespace std;

int main() {

    Menu* menusito = new Menu();

    menusito->mostrarMenuActual();

    delete menusito;

    return 0;
}