#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"
#include "reporteM.h"
#include "Rutina.h"
using namespace std;

class cliente : public Persona {
private:
    char sexo;
    Fecha* fechaInscripcion;
    instructor* instructorAsignado;
    reporteM** historialMediciones;
    int cantMediciones;
    int maxMediciones;
    Rutina* rutinaActual; 

public:
    cliente(string, string, string, string,const Fecha&, char, const Fecha&, instructor*);
    ~cliente();

    // Getters
    char getSexo() const;
    Fecha* getFechaInscripcion() const;
    instructor* getInstructorAsignado() const;
    int getCantMediciones() const;
    reporteM* getMedicion(int indice) const;
    Rutina* getRutinaActual() const;

    // Setters
    void setSexo(char sexo);
    void setFechaInscripcion(const Fecha& fecha);
    void setInstructorAsignado(instructor* inst);

    // M�todos para que el instructor gestione la rutina
    void recibirRutinaDelInstructor(Rutina* rutina);
    void eliminarRutinaActual();

    // M�todos para mediciones
    bool agregarMedicion(reporteM* medicion);
    reporteM* getUltimaMedicion() const;

    // M�todos de visualizaci�n
    string toString() const;
    string toStringDetallado() const;
    void mostrarHistorialMediciones() const;
    void mostrarRutinaActual() const;
    bool tieneRutina() const;
};