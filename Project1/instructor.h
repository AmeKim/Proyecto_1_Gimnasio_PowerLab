#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"
#include "vecEspecialidades.h"
using namespace std;

class instructor : public Persona {
private:
    vecEspecialidades* especialidades;
public:
    instructor(string nombre, string cedula, int telefono, string correo, int dia, int mes, int anio, vecEspecialidades* esp);
    instructor(string nombre, string cedula, int telefono, string correo, const Fecha& fechaNac, vecEspecialidades* esp);
    instructor(string nombre, string cedula, int telefono, string correo, const string& fechaNacStr, vecEspecialidades* esp);
    ~instructor();
    vecEspecialidades* getEspecialidades() const;
    void setEspecialidades(vecEspecialidades* esp);
    bool tieneEspecialidad(const string& nombreEsp) const;
    int getCantidadEspecialidades() const;
    string toString();
};