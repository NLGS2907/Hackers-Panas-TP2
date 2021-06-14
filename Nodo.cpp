#include"Nodo.h"

Nodo::Nodo(std::string descripcionCarta){

	this->siguiente = NULL;
	this->carta = new Carta(descripcionCarta);

}

Carta* Nodo::obtenerCarta(){
	return carta->obtenerDescripcion();
}

void Nodo::cambiarCarta(std::string descripcionCarta){
	carta->asignarDescripcion(descripcionCarta);
}


Nodo* Nodo::obtenerSiguente(){
	 return this->siguiente;
}

void Nodo::cambiarSiguiente(Nodo* nuevoNodo){
	 this->siguiente = nuevoNodo;
}

Nodo::~Nodo(){
	delete carta;

}

