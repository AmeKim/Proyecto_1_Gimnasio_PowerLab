#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "utiles.h"
#include "instructor.h"
#include "Fecha.h"
#include "Persona.h"
#include "Medición.h"
#include "Rutina.h"
using namespace std;

class cliente : public Persona {
private:
    char sexo;
    Fecha fechaInscripcion;
    instructor* inst;
    Rutina* r;
    vector<Medicion*> historialMediciones;

public:
    // Constructores
    cliente(string nombre, string cedula, int telefono, string correo, int dia, int mes, int anio,
        char sexo, const Fecha& fechaIns, instructor* inst, Rutina* r = nullptr);
    cliente(string nombre, string cedula, int telefono, string correo, const Fecha& fechaNac,
        char sexo, const Fecha& fechaIns, instructor* inst, Rutina* r = nullptr);
    cliente(string nombre, string cedula, int telefono, string correo, const string& fechaNacStr,
        char sexo, const string& fechaInsStr, instructor* inst, Rutina* r = nullptr);
    ~cliente();

    // Getters
    char getSexo() const;
    Fecha getFechaInscripcion() const;
    instructor* getInstructor() const;
    Rutina* getRutina() const;
    const vector<Medicion*>& getHistorialMediciones() const;
    Medicion* getUltimaMedicion() const;

    // Setters
    void setSexo(char);
    void setFechaInscripcion(const Fecha& fecha);
    void setFechaInscripcion(const string& fechaStr);
    void setInstructor(instructor*);
    void setRutina(Rutina* nuevaRutina);

    // Métodos para gestionar mediciones
    void agregarMedicion(Medicion* nuevaMedicion);
    void eliminarMedicion(const Fecha& fecha);
    Medicion* buscarMedicion(const Fecha& fecha) const;
    string obtenerHistorialMedicionesStr() const;

    string toString() override;
    int getAntiguedad() const; // Calcula antiguedad en el gimnasio
};