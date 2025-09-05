#include "instructor.h"
instructor::instructor(int cedula, string nombre, string correo, int telefono, string fecha_Nacimiento, vecEspecialidades* v){
	this->cedula = cedula;
	this->nombre = nombre;
	this->correo = correo;
	this->telefono = telefono;
	this->fecha_Nacimiento = fecha_Nacimiento;
	this->v = v;
}
instructor::~instructor(){
	delete v;
}
int instructor::getCedula(){
	return this->cedula;
}
string instructor::getNombre(){
	return this->nombre;
}
int instructor::getTelefono(){
	return this->telefono;
}
string instructor::getCorreo(){
	return this->correo;
}
string instructor::getFechaNacimiento(){
	return this->fecha_Nacimiento;
}
vecEspecialidades* instructor::getEspecialidades(){
	return this->v;
}
void instructor::setCedula(int cedula){
	this->cedula = cedula;
}
void instructor::setNombre(string nombre){
	this->nombre = nombre;
}
void instructor::setTelefono(int telefono){
	this->telefono = telefono;
}
void instructor::setCorreo(string correo){
	this->correo = correo;
}
void instructor::setFechaNacimiento(string fecha_Nacimiento){
	this->fecha_Nacimiento = fecha_Nacimiento;
}
string instructor::toString(){
	stringstream s;
	s << "Cedula: " << this->cedula << endl;
	s << "Nombre: " << this->nombre << endl;
	s << "Correo: " << this->correo << endl;
	s << "Telefono: " << this->telefono << endl;
	s << "Fecha de Nacimiento: " << this->fecha_Nacimiento << endl;
	s << "Especialidades: " << endl;
	s << this->v->toString() << endl;
	return s.str();
}

