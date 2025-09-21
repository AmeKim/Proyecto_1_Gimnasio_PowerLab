#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "reporteM.h"
#include "Medicion.h"
using namespace std;

class vecReportesM {
private:
    reporteM** reportes;
    Medicion** mediciones;
    int can;
    int tam;

public:
    vecReportesM(int capacidad = 10);
    ~vecReportesM();

    // Métodos para agregar reportes
    bool agregarReporte(reporteM* reporte);
    bool crearYAgregarReporte(Medicion* medicion);

    // Getters
    reporteM* getReportePorIndice(int indice) const;
    reporteM* getUltimoReporte() const;
    int getCan() const;
    int getTam() const;
    bool estaLleno() const;

    // Métodos de presentación (solo guardan/organizan reportes)
    void mostrarHistorialResumen() const;
    void mostrarReporteDetallado(int indice) const;
    void mostrarTodosLosReportes() const;
};