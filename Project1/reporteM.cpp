#include "reporteM.h"
#include "utiles.h"
#include <iostream>
#include <sstream>

reporteM::reporteM() {}
reporteM::~reporteM() {}

void reporteM::generarReporteIMCporSucursal(vecClientes* clientes, string nombreSucursal) {
    if (!clientes || clientes->getCantidad() == 0) {
        print("No hay clientes registrados en esta sucursal.\n");
        return;
    }

    cout << "=== Reporte de IMC para Sucursal: " << nombreSucursal << " ===" << endl;
    cout << "Nombre          Cedula          IMC       Categoria" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < clientes->getCantidad(); ++i) {
        cliente* cli = clientes->obtener(i);
        if (cli) {
            // Obtener la última medición del cliente
            vecReportesM* historial = cli->getHistorialMediciones();
            if (historial && historial->getCantidad() > 0) {
                Medicion* ultimaMedicion = historial->obtener(historial->getCantidad() - 1);
                if (ultimaMedicion) {
                    double imc = ultimaMedicion->getImc();
                    string categoria = ultimaMedicion->getClasificacion();
                    string nombre = cli->getNombre().substr(0, 14);
                    string cedula = cli->getCedula();

                    // Rellenar espacios para alineación
                    while (nombre.length() < 15) nombre += " ";
                    while (cedula.length() < 15) cedula += " ";

                    // Convertir IMC a string con 2 decimales
                    stringstream ss;
                    ss.precision(2);
                    ss << fixed << imc;
                    string imcStr = ss.str();
                    while (imcStr.length() < 9) imcStr += " ";

                    cout << nombre << cedula << imcStr << " " << categoria << endl;
                }
            }
            else {
                string nombre = cli->getNombre().substr(0, 14);
                string cedula = cli->getCedula();

                while (nombre.length() < 15) nombre += " ";
                while (cedula.length() < 15) cedula += " ";

                cout << nombre << cedula << "N/A      Sin mediciones" << endl;
            }
        }
    }
    cout << "===================================================" << endl;
}