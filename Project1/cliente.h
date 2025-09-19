#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "instructor.h"
#include "Fecha.h"
#include "Persona.h"
using namespace std;

class cliente : public Persona {
private:
    char sexo;
    Fecha fechaInscripcion;
    instructor* inst;

public:
    // Constructores
    cliente(string nombre, string cedula, int telefono, string correo, int dia, int mes, int anio,
        char sexo, const Fecha& fechaIns, instructor* inst);
    cliente(string nombre, string cedula, int telefono, string correo, const Fecha& fechaNac,
        char sexo, const Fecha& fechaIns, instructor* inst);
    cliente(string nombre, string cedula, int telefono, string correo, const string& fechaNacStr,
        char sexo, const string& fechaInsStr, instructor* inst);
    ~cliente();

    // Getters
    char getSexo() const;
    Fecha getFechaInscripcion() const;
    instructor* getInstructor() const;
    //rutina* getRutina();

    // Setters
    void setSexo(char);
    void setFechaInscripcion(const Fecha& fecha);
    void setFechaInscripcion(const string& fechaStr);
    void setInstructor(instructor*);

    string toString() override;
    int getAntiguedad() const; // Calcula antiguedad en el gimnasio
};