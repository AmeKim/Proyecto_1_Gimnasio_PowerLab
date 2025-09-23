#pragma once
#include "vecClientes.h"
#include <string>
using namespace std;

class reporteM {
public:
    reporteM();
    ~reporteM();

    // Genera el reporte IMC para la colección de clientes recibida.
    // Imprime en formato similar al pedido en la guía.
    void generarReporteIMCporSucursal(const vecClientes* clientes, const string& nombreSucursal) const;
};