#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "fecha.h"

using namespace std;


class Persona {
protected:
    string nombre;
    string cedula;
    string telefono;
    string correo;
    fecha* fechaNacimiento;

public:
    // Constructores
    Persona(string nombre, string cedula, string telefono, string correo, int dia, int mes, int anio);
    Persona(string nombre, string cedula, string telefono, string correo, fecha* fecha);
    Persona(string nombre, string cedula, string telefono, string correo, string fechaStr);
    Persona();
    virtual ~Persona();

    // Getters
    string getNombre() const;
    string getCedula() const;
    string getTelefono() const;
    string getCorreo() const;
    fecha* getFechaNacimiento() const;
    int getEdad() const;

    // Setters
    void setNombre(string nombre);
    void setCedula(string cedula);
    void setTelefono(string telefono);
    void setCorreo(string correo);
    void setFechaNacimiento(fecha* fecha);
    void setFechaNacimiento(int dia, int mes, int anio);
    void setFechaNacimiento(string fechaStr);

    // Métodos virtuales
    virtual string toString();
};