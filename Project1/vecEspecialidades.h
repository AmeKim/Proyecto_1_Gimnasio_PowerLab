#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "especialidad.h"
#include "utiles.h"
using namespace std;

class vecEspecialidades{
	private:
	especialidad** vEspecialidades;
	int can;
	int tam = 8;
public:
	vecEspecialidades();
	~vecEspecialidades();
	void agregarEspecialidad(especialidad*);
	void eliminarEspecialidad(string);
	especialidad* getEspecialidad(string);
	int getCan();
	string toString();
	string toStringEspecifico(string);
};

