#pragma once
#include "especialidad.h"
#include "Persona.h"
#include "vecEspecialidades.h"
#include "fecha.h"
#include <string>

using namespace std;

class instructor : public Persona {
public:
    instructor();
    instructor(int cedula, const string& nombre, const string& telefono,
        const string& correo, const fecha& fechaNac);
	instructor(const instructor& other);
    instructor& operator=(const instructor& other);
    ~instructor();

    // Especialidades (usa VecEspecialidades interno)
    void agregarEspecialidad(const Especialidad& esp);
    int obtenerCantidadEspecialidades() const;
    const Especialidad& obtenerEspecialidad(int indice) const;
    void limpiarEspecialidades();

    // Datos personales
    void setTelefono(const string& t);
    void setCorreo(const string& c);
    void setFechaNacimiento(const fecha& f);

    string getTelefono() const;
    string getCorreo() const;
    fecha getFechaNacimiento() const;

    string toString() const;

private:
    vecEspecialidades especialidades; // contenedor propio de especialidades
    string telefono;
    string correo;
    fecha fechaNacimiento;
};