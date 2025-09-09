#include "Persona.h"

Persona::Persona(string nom, string ced, int numT, string cor, int dia, int mes, int annio)
{
    this->nombre = nom;
    this->cedula = ced;
    this->numeroT = numT;
    this->correo = cor;
    this->fechaN[0] = dia; // day
    this->fechaN[1] = mes; // month
    this->fechaN[2] = annio; // year|
}

void Persona::setNombre(string nom)
{
	this->nombre = nom;
}

string Persona::getNombre()
{
    return nombre;
}

void Persona::setCedula(string ced)
{
	this->cedula = ced;
}

string Persona::getCedula()
{
    return cedula;
}

void Persona::setNumeroT(int numT)
{
	this->numeroT = numT;
}

int Persona::getNumeroT()
{
    return numeroT
}

void Persona::setCorreo(string cor)
{
	this->correo = cor;
}

string Persona::getCorreo()
{
    return correo;
}

void Persona::setFechaN(int dia, int mes, int annio)
{
	fechaN[0] = dia; 
	fechaN[1] = mes;
	fechaN[2] = annio;
}

int Persona::getDia()
{
    return fechaN[0];
}

int Persona::getMes()
{
    return fechaN[1];
}

int Persona::getAnnio()
{
    return fechaN[2];
}

void Persona::mostrarDatos()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Cedula: " << cedula << endl;
	cout << "Numero de Telefono: " << numeroT << endl;
	cout << "Correo Electronico: " << correo << endl;
	cout << "Fecha de Nacimiento: "
		<< fechaN[0] << "/"
		<< fechaN[1] << "/"
		<< fechaN[2] << endl;
}

Persona::~Persona()
{
}
