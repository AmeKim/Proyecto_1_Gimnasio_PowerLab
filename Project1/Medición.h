#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Fecha.h"
using namespace std;

class Medicion {
private:
    Fecha fechaMedicion;
    string cedulaCliente;
    string cedulaInstructor;
    double peso;           // en kg
    double estatura;       // en metros
    double porcentajeGrasa;
    double porcentajeMusculo;
    double imc;            // calculado automáticamente
    string clasificacionIMC; // calculado automáticamente
    bool altoRiesgo;       // calculado automáticamente
    int vasosAgua;         // calculado automáticamente
    double proteinaRecomendada; // calculado automáticamente
    char sexoCliente;      // necesario para cálculo de proteína

    void calcularIMC();
    void determinarClasificacionIMC();
    void calcularVasosAgua();
    void calcularProteinaRecomendada();
    void calcularTodosLosValores(); // Método helper

public:
    // Constructores
    Medicion(const Fecha& fecha, string cedCliente, string cedInstructor,
        double p, double est, double pGrasa, double pMusculo, char sexo);
    Medicion(const string& fechaStr, string cedCliente, string cedInstructor,
        double p, double est, double pGrasa, double pMusculo, char sexo);
    ~Medicion();

    // Getters
    Fecha getFecha() const;
    string getCedulaCliente() const;
    string getCedulaInstructor() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    double getIMC() const;
    string getClasificacionIMC() const;
    bool esAltoRiesgo() const;
    int getVasosAgua() const;
    double getProteinaRecomendada() const;
    char getSexoCliente() const;

    // Setters que recalculan automáticamente
    void setPeso(double p);
    void setEstatura(double est);
    void setPorcentajeGrasa(double pGrasa);
    void setPorcentajeMusculo(double pMusculo);
    void setFecha(const Fecha& fecha);
    void setFecha(const string& fechaStr);

    // Métodos de presentación
    string toStringCompleto() const;
    string toStringResumen() const;
    string toStringParaHistorial() const;
};