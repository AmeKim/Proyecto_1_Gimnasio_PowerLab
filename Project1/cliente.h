#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"
#include "reporteM.h"
#include "Rutina.h"
using namespace std;

// Forward declaration para evitar dependencias circulares
class instructor;

class cliente : public Persona {
private:
    char sexo;
    Fecha* fechaInscripcion;
    instructor* instructorAsignado;
    reporteM** historialMediciones;
    int cantMediciones;
    int maxMediciones;
    Rutina* rutinaActual;  // Rutina creada por el instructor y almacenada aquí

public:
    cliente(string nombre, string cedula, int telefono, string correo,
        const Fecha& fechaNac, char sexo, const Fecha& fechaInsc,
        instructor* inst = nullptr);
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

    // Métodos para que el instructor gestione la rutina
    void recibirRutinaDelInstructor(Rutina* rutina);
    void eliminarRutinaActual();

    // Métodos para mediciones
    bool agregarMedicion(reporteM* medicion);
    reporteM* getUltimaMedicion() const;

    // Métodos de visualización
    string toString() const override;
    string toStringDetallado() const;
    void mostrarHistorialMediciones() const;
    void mostrarRutinaActual() const;
    bool tieneRutina() const;
};