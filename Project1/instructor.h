#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "vecEspecialidades.h"
using namespace std;

class instructor {
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNacimiento;
    vecEspecialidades* especialidades;

public:
    instructor();
    instructor(const string& cedula, const string& nombre, const string& telefono,
        const string& correo, const string& fechaNacimiento);
    ~instructor();

    // Getters
    string getCedula() const;
    string getNombre() const;
    string getTelefono() const;
    string getCorreo() const;
    string getFechaNacimiento() const;
    vecEspecialidades* getEspecialidades() const;

    // Setters
    void setCedula(const string& cedula);
    void setNombre(const string& nombre);
    void setTelefono(const string& telefono);
    void setCorreo(const string& correo);
    void setFechaNacimiento(const string& fechaNacimiento);

    // Métodos para especialidades
    bool agregarEspecialidad(especialidad* esp);
    bool tieneEspecialidad(const string& nombreEspecialidad) const;
    bool tieneEspecialidad(int idEspecialidad) const;
    string getEspecialidadesString() const;
    void mostrarEspecialidades() const;

    // Métodos de utilidad
    void mostrar() const;
    string toString() const;
    string toStringCompleto() const;
};