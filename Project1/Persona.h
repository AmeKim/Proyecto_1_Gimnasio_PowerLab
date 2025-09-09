#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "fecha.h"
using namespace std;

class persona {
private:
	string nombre;
	string cedula;
	int numeroTelefono;
	string correo;
	fecha* fechaNacimiento; 
public:
	persona(string = "", string = "", int = 0, string = "", fecha* = nullptr);
	~persona();
	void setNombre(string);
	string getNombre();
	void setCedula(string);
	string getCedula();
	void setNumeroTelefono(int);
	int getNumeroTelefono();
	void setCorreo(string);
	string getCorreo();
	fecha* getFechaNacimiento();
	string toString();
	
};