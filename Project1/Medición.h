#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Fecha.h"
#include "utiles.h"
#include "cliente.h"
#include "instructor.h"

using namespace std;

class Medicion {
private:
	instructor* instructorAsociado; // Instructor que realizó la medición
    cliente* clienteAsociado; // Cliente al que pertenece la medición
    Fecha* fecha;
    double peso;          // en kg
    double estatura;      // en metros
    double porcentajeGrasa;
    double porcentajeMusculo;
    double imc;
    string clasificacion;
    bool altoRiesgo;
    int vasosAgua;        // cantidad recomendada
    double proteinaRecomendada; // en gramos

    // Medidas corporales opcionales
    double cintura;
    double cadera;
    double pecho;
    double muslo;

public:
    // Constructores
    Medicion(const Fecha& fecha, double peso, double estatura,double porcGrasa, double porcMusculo);
    Medicion();
    ~Medicion();

    // Getters
    Fecha* getFecha() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    double getIMC() const;
    string getClasificacion() const;
    bool getAltoRiesgo() const;
    int getVasosAgua() const;
    double getProteinaRecomendada() const;

    // Setters
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double porc);
    void setPorcentajeMusculo(double porc);
    void setMedidasCorporales(double cintura, double cadera, double pecho, double muslo);

    // Cálculos
    void calcularIMC();
    void calcularClasificacion();
    void calcularRecomendaciones(char sexo, bool haceEjercicio);

    // Utilidades
    string toString() const;
    string toStringDetallado() const;
    string toStringResumen() const;
};