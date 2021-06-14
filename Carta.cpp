#include"Carta.h"

Carta::Carta(std::string descripcion){
	this->descripcion = descripcion;
}

void Carta::asignarDescripcion(std::string descripcion){
	this->descripcion = descripcion;
}

std::string Carta::obtenerDescripcion(){
	return descripcion;
}
