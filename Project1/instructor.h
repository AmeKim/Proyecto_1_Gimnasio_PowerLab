#pragma once
#include <string>
#include <sstream>
#include "Persona.h"
using namespace std;

class Instructor : public Persona {
private:
    string* especialidades;
    int maxEspecialidades;
    int cantEspecialidades;
    string codigoSucursal;

public:
    Instructor();
    Instructor(string nombre, string cedula, string telefono, string correo, const string& fechaNacimientoStr);
    ~Instructor();

    bool agregarEspecialidad(const string& esp);
    bool tieneEspecialidad(const string& esp) const;
    int getCantEspecialidades() const;
    string getEspecialidad(int idx) const;

    void setCodigoSucursal(const string& codigo);
    string getCodigoSucursal() const;

    virtual string toString() override;
};
