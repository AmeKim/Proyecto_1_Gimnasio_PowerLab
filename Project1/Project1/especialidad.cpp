#include "especialidad.h"
especialidad::especialidad(string nombre){
	this->nombre = nombre;
}
especialidad::especialidad(){
	this->nombre = "";
}
especialidad::~especialidad() {}
string especialidad::getNombre(){
	return nombre;
}
string especialidad::toString(){
	stringstream s;
	s << "Nombre: " << nombre << endl;
	
	return s.str();
}
