#pragma once
#include "Medicion.h"

class vecReportesM {
private:
    Medicion** mediciones;
    int tam;
    int cant;

public:
    vecReportesM();
    ~vecReportesM();

    void agregar(Medicion* medicion);
    Medicion* obtener(int indice);
    int getCantidad() const;
    void mostrarHistorial() const;
};