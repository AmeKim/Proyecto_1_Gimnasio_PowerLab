#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "instructor.h"
//#include "rutina.h"
using namespace std;

class cliente{
private:
	int cedula;
	int telefono;
	string nombre;
	string correo;
	char sexo;
	string fecha_Nacimiento;
	string fecha_Inscripcion;
	instructor* inst;
	//rutina* r;
public:
	cliente(int, int, string, string, char, string, string, instructor*);//, rutina*);
	~cliente();
	int getCedula();
	int getTelefono();
	string getNombre();
	string getCorreo();
	char getSexo();
	string getFechaNacimiento();
	string getFechaInscripcion();
	instructor* getInstructor();
	//rutina* getRutina();
	void setCedula(int);
	void setTelefono(int);
	void setNombre(string);
	void setCorreo(string);
	void setSexo(char);
	void setFechaNacimiento(string);
	void setFechaInscripcion(string);
	void setInstructor(instructor*);
	//void setRutina(rutina*);
	string toString();
	
};

