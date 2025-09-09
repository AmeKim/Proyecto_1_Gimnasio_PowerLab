#include "persona.h"

persona::persona(string nom, string ced, int numT, string cor, fecha* fechaNacimiento){
    this->nombre = nom;
    this->cedula = ced;
    this->numeroTelefono = numT;
    this->correo = cor;
	this->fechaNacimiento = fechaNacimiento;

}
persona::~persona(){}

void persona::setNombre(string nom)
{
	this->nombre = nom;
}

string persona::getNombre()
{
    return nombre;
}

void persona::setCedula(string ced)
{
	this->cedula = ced;
}

string persona::getCedula()
{
    return cedula;
}

void persona::setNumeroTelefono(int numT)
{
	this->numeroTelefono = numT;
}

int persona::getNumeroTelefono()
{
	return numeroTelefono;
}

void persona::setCorreo(string cor)
{
	this->correo = cor;
}

string persona::getCorreo()
{
    return correo;
}

fecha* persona::getFechaNacimiento(){
	return fechaNacimiento;
}
string persona::toString(){
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Cedula: " << cedula << endl;
	s << "Numero de Telefono : " << numeroTelefono << endl;
	s << "Correo : " << correo << endl;
	s<< "Fecha de Nacimiento : " << fechaNacimiento->toString() << endl;
	return s.str();	
}


