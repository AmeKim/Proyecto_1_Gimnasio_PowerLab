#pragma once
#include "Persona.h"
#include "fecha.h"
#include "vecReportesM.h"
#include "Rutina.h"
#include "instructor.h"
#include "ClaseGrupal.h"
#include <string>

using namespace std;

class cliente : public Persona {
private:
    string telefono;
    string correo;
    fecha fechaNacimiento;
    fecha fechaInscripcion;
    string sexo;
    instructor* instructorAsignado;
    vecReportesM* mediciones;
    Rutina* rutina;
    ClaseGrupal** clasesMatriculadas;
    int tamClases;
    int cantClases;

public:
    cliente();
    cliente(const string& ced, const string& nom, const string& tel, const string& corr,
        const fecha& fechaNac, const fecha& fechaInsc, const string& sex);

    cliente(const cliente& other);
    cliente& operator=(const cliente& other);

    ~cliente();

    // Getters
    string getTelefono() const;
    string getCorreo() const;
    string getNombreCompleto();
    fecha getFechaNacimiento() const;
    fecha getFechaInscripcion() const;
    string getSexo() const;
    instructor* getInstructor() const;
    vecReportesM* getMediciones() const;
    Rutina* getRutina() const;

    // Setters
    void setTelefono(const string& tel);
    void setCorreo(const string& corr);
    void setFechaNacimiento(const fecha& f);
    void setFechaInscripcion(const fecha& f);
    void setSexo(const string& s);
    void setInstructor(instructor* ins);

    // Mediciones
    void agregarMedicion(Medicion* med);

    // Clases grupales
    bool matricularClase(ClaseGrupal* clase);
    int getCantidadClasesMatriculadas() const;
    string mostrarClasesMatriculadas() const;

    // Utilidades
    string toString() const;
};