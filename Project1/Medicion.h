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
    double edadMetabolica;
    double porcentajeGrasaVisceral;
    double cintura;
    double cadera;
    double pecho;
    double muslo;
    double imc;
    string clasificacion;
    bool altoRiesgo;
    int vasosRecomendados;
    double proteinaRecomendada;

public:
    Medicion();
    Medicion(fecha* fecha, cliente* cli, instructor* inst, double peso, double estatura,
        double porcentajeGrasa, double porcentajeMusculo, double edadMetabolica,
        double porcentajeGrasaVisceral, double cintura, double cadera, double pecho, double muslo);
    ~Medicion();

    // Getters
    fecha* getFecha() const;
    cliente* getCliente() const;
    instructor* getInstructor() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    double getEdadMetabolica() const;
    double getPorcentajeGrasaVisceral() const;
    double getCintura() const;
    double getCadera() const;
    double getPecho() const;
    double getMuslo() const;
    double getIMC() const;
    string getClasificacion() const;
    bool getAltoRiesgo() const;
    int getVasosRecomendados() const;
    double getProteinaRecomendada() const;

    // Setters
    void setFecha(fecha* fecha);
    void setCliente(cliente* cli);
    void setInstructor(instructor* inst);
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double porcentajeGrasa);
    void setPorcentajeMusculo(double porcentajeMusculo);
    void setEdadMetabolica(double edadMetabolica);
    void setPorcentajeGrasaVisceral(double porcentajeGrasaVisceral);
    void setCintura(double cintura);
    void setCadera(double cadera);
    void setPecho(double pecho);
    void setMuslo(double muslo);
    void setIMC(double imc);
    void setClasificacion(string clasificacion);
    void setAltoRiesgo(bool altoRiesgo);
    void setVasosRecomendados(int vasosRecomendados);
    void setProteinaRecomendada(double proteinaRecomendada);

    // Métodos de cálculo
    void calcularIMC();
    void determinarClasificacion();
    void calcularAltoRiesgo();
    void calcularVasosRecomendados();
    void calcularProteinaRecomendada();
    void calcularTodo();
};