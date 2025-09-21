#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"
#include "reporteM.h"
#include "Rutina.h"
#include "fecha.h"
using namespace std;

class cliente : public Persona {
private:
    char sexo;
    fecha* fechaInscripcion;
    instructor* instructorAsignado;
    reporteM** historialMediciones;
    int cantMediciones;
    int maxMediciones;
    Rutina* rutinaActual;

public:
    cliente(string, string, string, string, const fecha&, char, const fecha&, instructor*);
    ~cliente();

    // Getters
    char getSexo() const;
fecha* getFechaInscripcion() const;
    instructor* getInstructorAsignado() const;
    int getCantMediciones() const;
    reporteM* getMedicion(int indice) const;
    Rutina* getRutinaActual() const;

    // Setters
    void setSexo(char sexo);
    void setfechaInscripcion(const fecha& fecha);
    void setInstructorAsignado(instructor* inst);

    // Métodos para que el instructor gestione la rutina
    void recibirRutinaDelInstructor(Rutina* rutina);
    void eliminarRutinaActual();

    // Métodos para mediciones
    bool agregarMedicion(reporteM* medicion);
    reporteM* getUltimaMedicion() const;

    // Métodos de visualización
    string toString() const;
    string toStringDetallado() const;
    void mostrarHistorialMediciones() const;
    void mostrarRutinaActual() const;
    bool tieneRutina() const;
};