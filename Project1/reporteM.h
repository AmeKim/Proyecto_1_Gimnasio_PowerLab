#pragma once
#include "vecClientes.h"
#include <string>
using namespace std;

class reporteM {
public:
    reporteM();
    ~reporteM();

    // Genera el reporte IMC para la colecci�n de clientes recibida.
    // Imprime en formato similar al pedido en la gu�a.
    void generarReporteIMCporSucursal(const vecClientes* clientes, const string& nombreSucursal) const;
};