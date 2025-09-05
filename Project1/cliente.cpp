#include "cliente.h"
cliente::cliente(int cedula, int telefono, string nombre, string correo, char sexo, string fecha_Nacimiento, string fecha_Inscripcion, instructor* instructor){//, rutina* rutina){
	this->cedula = cedula;
	this->telefono = telefono;
	this->nombre = nombre;
	this->correo = correo;
	this->sexo = sexo;
	this->fecha_Nacimiento = fecha_Nacimiento;
	this->fecha_Inscripcion = fecha_Inscripcion;
	this->inst = instructor;
	//this->rutina = rutina;
}
cliente::~cliente(){
	delete inst;
	//delete r;
}
int cliente::getCedula(){
	return cedula;
}
int cliente::getTelefono(){
	return telefono;
}
string cliente::getNombre(){
	return nombre;
}
string cliente::getCorreo(){
	return correo;
}
char cliente::getSexo(){
	return sexo;
}
string cliente::getFechaNacimiento(){
	return fecha_Nacimiento;
}
string cliente::getFechaInscripcion(){
	return fecha_Inscripcion;
}
instructor* cliente::getInstructor(){
	return inst;
}
//rutina* cliente::getRutina(){
	//return r;
	//}
void cliente::setCedula(int cedula) {
	this->cedula = cedula;
}
void cliente::setTelefono(int telefono) {
	this->telefono = telefono;
}
void cliente::setNombre(string nombre) {
	this->nombre = nombre;
}
void cliente::setCorreo(string correo) {
	this->correo = correo;
}
void cliente::setSexo(char sexo) {
	this->sexo = sexo;
}
void cliente::setFechaNacimiento(string fecha_Nacimiento) {
	this->fecha_Nacimiento = fecha_Nacimiento;
}
void cliente::setFechaInscripcion(string fecha_Inscripcion) {
	this->fecha_Inscripcion = fecha_Inscripcion;
}
void cliente::setInstructor(instructor* instructor) {
	this->inst = instructor;
}
//void cliente::setRutina(rutina* rutina) {
	//this->r = rutina;
	//}
string cliente::toString() {
	stringstream s;
	s << "Cedula: " << cedula << endl;
	s << "Telefono: " << telefono << endl;
	s << "Nombre: " << nombre << endl;
	s << "Correo: " << correo << endl;
	s << "Sexo: " << sexo << endl;
	s << "Fecha de Nacimiento: " << fecha_Nacimiento << endl;
	s << "Fecha de Inscripcion: " << fecha_Inscripcion << endl;
	s << "Instructor: " << endl;
	s << inst->toString() << endl;
	//s << "Rutina: " << endl;
	//s << r->toString() << endl;
	return s.str();
}
