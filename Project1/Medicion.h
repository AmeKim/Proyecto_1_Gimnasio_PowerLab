#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "fecha.h"
#include "cliente.h"
#include "instructor.h"
using namespace std;

class Medicion {
private:
    fecha* fechaMedicion;
    cliente* clienteRef;
    instructor* instructorRef;
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
    Medicion(fecha* fecha, cliente* cli, instructor* inst, double peso, double estatura,
        double porcentajeGrasa, double porcentajeMusculo);
    ~Medicion();

    fecha* getFecha() const;
    cliente* getCliente() const;
    instructor* getInstructor() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    double getIMC() const;
    string getClasificacion() const;
    bool getAltoRiesgo() const;
    int getVasosRecomendados() const;
    double getProteinaRecomendada() const;

    void setFecha(fecha* fecha);
    void setCliente(cliente* cli);
    void setInstructor(instructor* inst);
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double porcentajeGrasa);
    void setPorcentajeMusculo(double porcentajeMusculo);

    void calcularIMC();
    void determinarClasificacion();
    void calcularAltoRiesgo();
    void calcularVasosRecomendados();
    void calcularProteinaRecomendada();
    void calcularTodo();

    string toString() const;
    void mostrar() const;
};