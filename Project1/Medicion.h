#pragma once
#include "fecha.h"
#include <string>
using namespace std;

class Medicion {
private:
    fecha* fechaMedicion;
    double peso;
    double estatura;
    double porcentajeGrasa;
    double porcentajeMusculo;
    double imc;
    string clasificacion;
    bool altoRiesgo;
    int vasosRecomendados;
    double proteinaRecomendada;

public:
    Medicion();
    Medicion(string fechaStr, double peso, double estatura, double grasa, double musculo);
    ~Medicion();

    // Getters
    fecha* getFecha() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    double getImc() const;
    string getClasificacion() const;
    bool getAltoRiesgo() const;
    int getVasosRecomendados() const;
    double getProteinaRecomendada() const;

    // Setters
    void setFecha(string fechaStr);
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double grasa);
    void setPorcentajeMusculo(double musculo);

    // Métodos
    void calcularIMC();
    void calcularClasificacion();
    void calcularAltoRiesgo();
    void calcularVasos();
    void calcularProteina(char sexo);
    void calcularTodo(char sexo);

    string toString() const;
    string toStringResumen() const;
};