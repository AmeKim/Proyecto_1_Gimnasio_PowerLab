#pragma once
#include "fecha.h"
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

class Medicion {
private:
    fecha fechaMedicion;
    double peso;
    double estatura;
    double porcentajeGrasa;
    double porcentajeMusculo;
    double imc;
    string clasificacion;
    bool altoRiesgo;

    void calcularIMC();
    void determinarClasificacion();
    void determinarRiesgo();

public:
    Medicion();
    Medicion(const fecha& f, double p, double e, double g, double m);
    ~Medicion();

    // Getters
    fecha getFecha() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    double getImc() const;
    string getClasificacion() const;
    bool esAltoRiesgo() const;

    // Cálculos
    int calcularVasos() const;
    int calcularVasosAgua() const;
    double calcularProteina(bool esHombre) const;

    // Utilidades
    string toString() const;
};