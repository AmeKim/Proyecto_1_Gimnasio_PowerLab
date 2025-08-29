#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "vecEspecialidades.h"
#include "utiles.h"
using namespace std;

class instructor{
private:
	int cedula;
	string nombre;
	string correo;
	int telefono;
	string fecha_Nacimiento;
	vecEspecialidades* v;
public:
	instructor(int, string, string, int, string, vecEspecialidades*);
	~instructor();
	int getCedula();
	string getNombre();
	int getTelefono();
	string getCorreo();
	string getFechaNacimiento();
	vecEspecialidades* getEspecialidades();
	void setCedula(int);
	void setNombre(string);
	void setTelefono(int);
	void setCorreo(string);
	void setFechaNacimiento(string);
	string toString();
};

