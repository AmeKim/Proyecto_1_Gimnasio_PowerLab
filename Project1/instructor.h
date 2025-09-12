#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "vecEspecialidades.h"
#include "utiles.h"
//#include "rutina.h"
#include "Persona.h"
using namespace std;

class instructor : public Persona {
private:
    vecEspecialidades* v;
public:
    instructor(string nombre, string cedula, int telefono, string correo,
               int dia, int mes, int anio, vecEspecialidades* vec);
    ~instructor();
    vecEspecialidades* getEspecialidades();
    string toString();
};

