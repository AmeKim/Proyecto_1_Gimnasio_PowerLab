#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"
#include "reporteM.h"
using namespace std;

class cliente : public Persona {
private:
    string fechaInscripcion;
    string sexo;
    reporteM** mediciones;
    int canMediciones;
    int tamMediciones;
    string cedulaInstructorAsignado;

public:
    // Constructores
    cliente();
    cliente(const string& nombre, const string& cedula, const string& telefono,
        const string& correo, const string& fechaNacimiento, const string& sexo,
        const string& fechaInscripcion);
    ~cliente();

    // Getters
    string getFechaInscripcion() const;
    string getSexo() const;
    char getSexoChar() const; // Devuelve 'M' o 'F'
    string getCedulaInstructorAsignado() const;
    int getCanMediciones() const;
    int getTamMediciones() const;
    reporteM* getMedicion(int indice) const;

    // Setters
    void setFechaInscripcion(const string& fechaInscripcion);
    void setSexo(const string& sexo);
    void setCedulaInstructorAsignado(const string& cedulaInstructor);

    // Métodos para mediciones
    bool agregarMedicion(reporteM* medicion);
    reporteM* getMedicionMasReciente() const;
    void mostrarHistorialMediciones() const;

    // Métodos de visualización
    string toString() const;
    string toStringResumido() const;
    string toStringDetallado() const;
    void mostrar() const;
};