#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"
#include "fecha.h"
using namespace std;

class cliente : public Persona {
private:
    fecha* fechaInscripcion;
    char sexo;
    void* instructorAsignado;     // Usamos void* para evitar inclusiones circulares
    void** mediciones;            // Array de void* para las mediciones
    int canMediciones;
    int tamMediciones;
    void* rutinaActual;           // Usamos void* para evitar inclusiones circulares

public:
    cliente();
    cliente(const string& cedula, const string& nombre, const string& telefono,
        const string& correo, fecha* fechaNac, fecha* fechaInsc, char sexo);
    ~cliente();

    // Getters
    fecha* getFechaInscripcion() const;
    char getSexo() const;
    void* getInstructorAsignado() const;
    int getCanMediciones() const;
    void* getRutinaActual() const;
    void* getMedicion(int indice) const;

    // Setters
    void setFechaInscripcion(fecha* fechaInsc);
    void setSexo(char sexo);
    void setInstructorAsignado(void* inst);
    void setRutinaActual(void* rutina);

    // Métodos para mediciones
    bool agregarMedicion(void* medicion);
    void mostrarHistorialMediciones() const;
    void* getUltimaMedicion() const;

    // Métodos heredados y propios
    string toString() const;
    void mostrar() const;
    string toStringDetallado() const;
};