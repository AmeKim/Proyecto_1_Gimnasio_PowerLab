#pragma once
#include <string>
#include <sstream>
#include "instructor.h"
#include "Persona.h"
#include "vecReportesM.h"
#include "Rutina.h"

class cliente : public Persona {
private:
    char sexo;
    fecha* fechaInscripcion;
    string cedulaInstructor;
    vecReportesM* historialMediciones;
    Rutina* rutinaActual;
	Instructor* instructor; // Instructor asociado al cliente

public:
    cliente();
    cliente(string nombre, string cedula, string telefono, string correo,
        string fechaNac, char sexo, string fechaInsc, string cedulaInst);
    ~cliente();

    // Getters
    char getSexo() const;
    fecha* getFechaInscripcion() const;
    string getCedulaInstructor() const;
    vecReportesM* getHistorialMediciones();
    Rutina* getRutinaActual();
    Instructor* getInstructor() const;

    // Setters
    void setSexo(char sexo);
    void setFechaInscripcion(string fechaStr);
    void setCedulaInstructor(string cedula);

    // Métodos
    void agregarMedicion(Medicion* medicion);
    string toString() override;
    string toStringDetalle(string nombreInstructor, string nombreSucursal) const;
    double getUltimoIMC() const;
};