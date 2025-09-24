#pragma once
#include <string>
#include <sstream>
#include "Persona.h"
#include "Rutina.h"
#include "Medicion.h"
#include "vecEspecialidades.h"
using namespace std;

class Instructor : public Persona {
private:
    vecEspecialidades* especialidades;
    string codigoSucursal;
public:
    Instructor();
    Instructor(string nombre, string cedula, string telefono, string correo, const string& fechaNacimientoStr);
    ~Instructor();

    bool agregarEspecialidad(const string& esp);
    bool tieneEspecialidad(const string& esp) const;
    int getCantEspecialidades() const;

    // Devuelve el nombre de la especialidad en la posición idx (la posicion de la especialidad en la lista)
    string getEspecialidad(int idx) const;

    void agregarRutinaCliente(Rutina* rutina, const string& nombreCliente);
    void realizarMedicionCliente(Medicion* medicion, const string& nombreCliente);

    virtual string toString() override;

    //Métodos para el código de sucursal
    void setCodigoSucursal(const string& codigo) { codigoSucursal = codigo; }
    string getCodigoSucursal() const { return codigoSucursal; }
};