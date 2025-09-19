#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "fecha.h"
#include "cliente.h"
#include "instructor.h"
using namespace std;

class reporteM {
private:
    cliente* clienteRef;
    instructor* instructorRef;
    Fecha fechaMedicion;
    double peso;            // en kg
    double estatura;        // en metros
    double porcentajeGrasa;
    double porcentajeMusculo;
    int edadMetabolica;
    double porcentajeGrasaVisceral;
    // Medidas corporales
    double medidaCintura;   // en cm
    double medidaCadera;    // en cm
    double medidaPecho;     // en cm
    double medidaMuslo;     // en cm
    // Calculados automáticamente
    double imc;
    string clasificacionIMC;
    bool altoRiesgo;
    int vasosAgua;          // cantidad de vasos de 250ml
    double proteinaRecomendada; // en gramos

public:
    // Constructores
    reporteM();
    reporteM(cliente* cli, instructor* inst, const Fecha& fecha, double peso, double estatura,
        double pGrasa, double pMusculo, int edadMet = 0, double grasaVisc = 0.0,
        double cintura = 0.0, double cadera = 0.0, double pecho = 0.0, double muslo = 0.0);
    ~reporteM();

    // Métodos para calcular valores automáticos
    void calcularIMC();
    void determinarClasificacionIMC();
    void determinarAltoRiesgo();
    void calcularVasosAgua();
    void calcularProteinaRecomendada();
    void calcularTodosLosValores();

    // Getters
    cliente* getCliente() const;
    instructor* getInstructor() const;
    Fecha getFechaMedicion() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    int getEdadMetabolica() const;
    double getPorcentajeGrasaVisceral() const;
    double getMedidaCintura() const;
    double getMedidaCadera() const;
    double getMedidaPecho() const;
    double getMedidaMuslo() const;
    double getIMC() const;
    string getClasificacionIMC() const;
    bool getAltoRiesgo() const;
    int getVasosAgua() const;
    double getProteinaRecomendada() const;

    // Setters
    void setCliente(cliente* cli);
    void setInstructor(instructor* inst);
    void setFechaMedicion(const Fecha& fecha);
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double pGrasa);
    void setPorcentajeMusculo(double pMusculo);
    void setEdadMetabolica(int edadMet);
    void setPorcentajeGrasaVisceral(double grasaVisc);
    void setMedidaCintura(double cintura);
    void setMedidaCadera(double cadera);
    void setMedidaPecho(double pecho);
    void setMedidaMuslo(double muslo);

    // Métodos de utilidad
    string toString() const;
    string toStringDetallado() const;
    void mostrar() const;
    void mostrarDetallado() const;
};

