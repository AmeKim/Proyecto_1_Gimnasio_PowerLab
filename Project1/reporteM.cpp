#include "reporteM.h"
#include "utiles.h"
#include <sstream>

reporteM::reporteM() {}
reporteM::~reporteM() {}

void reporteM::generarReporteIMCporSucursal(const vecClientes* clientes, const string& nombreSucursal) const {
    if (clientes == nullptr) {
        print("No hay clientes para generar reporte.\n");
        return;
    }

    // Contadores por categoría (8 categorías)
    int contadores[8] = { 0 };
    // Almacenamos punteros temporalmente igual que en vecClientes::generarReporteIMC
    cliente* categorias[8][100];
    int cantPorCategoria[8] = { 0 };

    for (int i = 0; i < clientes->getCantidad(); i++) {
		cliente* c = clientes->
        if (c == nullptr) continue;
        double imc = c->getUltimoIMC();
        if (imc <= 0.0) continue; // sin mediciones, ignorar
        int categoria = -1;
        if (imc < 16.0) categoria = 0;
        else if (imc <= 16.99) categoria = 1;
        else if (imc <= 18.49) categoria = 2;
        else if (imc <= 24.99) categoria = 3;
        else if (imc <= 29.99) categoria = 4;
        else if (imc <= 34.99) categoria = 5;
        else if (imc <= 39.99) categoria = 6;
        else categoria = 7;

        if (categoria >= 0 && categoria < 8) {
            categorias[categoria][cantPorCategoria[categoria]] = c;
            cantPorCategoria[categoria]++;
            contadores[categoria]++;
        }
    }

    // Nombres de categorías
    string nombresCategorias[8] = {
        "Delgadez severa (<16.00)",
        "Delgadez moderada (16.00 - 16.99)",
        "Delgadez leve (17.00 - 18.49)",
        "Normal (18.50 - 24.99)",
        "Pre-obesidad (25.00 - 29.99)",
        "Obesidad leve (30.00 - 34.99)",
        "Obesidad media (35.00 - 39.99)",
        "Obesidad morbida (>=40.00)"
    };

    print("REPORTE DE IMC - SUCURSAL " + nombreSucursal + "\n\n");

    for (int i = 0; i < 8; i++) {
        print(nombresCategorias[i] + ":\n");
        if (contadores[i] == 0) {
            print("Ninguno\n\n");
        }
        else {
            print("(Cantidad " + to_string(contadores[i]) + ")\n");
            for (int j = 0; j < cantPorCategoria[i]; j++) {
                double imc = categorias[i][j]->getUltimoIMC();
                print(to_string(j + 1) + "- " + categorias[i][j]->getCedula() + " " +
                    categorias[i][j]->getNombre() + " IMC: " + to_string(imc) + "\n");
            }
            print("\n");
        }
    }
}