#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "persona.h"
#include "instructor.h"
#include "rutina.h"
#include "fecha.h"
using namespace std;

class cliente: public persona{
private:
	char sexo;
	fecha* fechaInscrip;
	instructor* inst;
	rutina* r;
	//Medicion* medicion;
public:
	
	string toString();
	
};

