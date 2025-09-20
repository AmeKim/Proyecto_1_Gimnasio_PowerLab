#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "fecha.h"
using namespace std;

class reporteM {
private:
    Fecha* fechaMedicion;
    double peso;
    double estatura;
    double porcentajeGrasa;
    double porcentajeMusculo;
    double imc;
    string clasificacion;
    bool altoRiesgo;
    int vasosAgua;
    double proteina;

public:
    reporteM();
    reporteM(const Fecha& fecha, double peso, double estatura, double pGrasa, double pMusculo);
    ~reporteM();

    // Getters
    Fecha* getFechaMedicion() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    double getIMC() const;
    string getClasificacion() const;
    bool esAltoRiesgo() const;
    int getVasosAgua() const;
    double getProteina() const;

    // Setters
    void setFechaMedicion(const Fecha& fecha);
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double pGrasa);
    void setPorcentajeMusculo(double pMusculo);

    // Métodos de cálculo
    void calcularIMC();
    void determinarClasificacion();
    void calcularVasosAgua();
    void calcularProteina(char sexo); // 'M' o 'F'

    // Métodos de visualización
    string toString() const;
    void mostrarDetalle() const;
};
