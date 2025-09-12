#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "instructor.h"
//#include "rutina.h"
#include "Persona.h"
using namespace std;

class cliente : public Persona {
private:
    char sexo;
    string fecha_Inscripcion;
    instructor* inst;
    //rutina* r;
public:
    cliente(string nombre, string cedula, int telefono, string correo, int dia, int mes, int anio,
            char sexo, string fecha_Inscripcion, instructor* inst, rutina* r);
    ~cliente();

    char getSexo();
    string getFechaInscripcion();
    instructor* getInstructor();
    //rutina* getRutina();

    void setSexo(char);
    void setFechaInscripcion(string);
    void setInstructor(instructor*);
    //void setRutina(rutina*);

    string toString();
};

