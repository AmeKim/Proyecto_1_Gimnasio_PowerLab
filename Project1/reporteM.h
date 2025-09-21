#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Medicion.h"
using namespace std;

class reporteM {
private:
    Medicion* medicion;

public:
    reporteM();
    reporteM(Medicion* med);
    ~reporteM();

    // Getters
    Medicion* getMedicion() const;

    // Setters
    void setMedicion(Medicion* med);

    // Métodos de presentación (solo imprimen)
    string toString() const;
    void mostrarDetalle() const;
    void mostrarReporteCompleto() const;

    // Método para mostrar resumen (fecha, peso, IMC)
    string mostrarResumen() const;
};