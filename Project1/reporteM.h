#pragma once
#include "vecClientes.h"
#include <string>
using namespace std;

class reporteM {
public:
    reporteM();
    ~reporteM();
    void generarReporteIMCporSucursal(vecClientes* clientes, string nombreSucursal);
};