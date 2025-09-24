#include "vecClientes.h"
#include "utiles.h"

vecClientes::vecClientes() {
    tam = 100;
    cant = 0;
    clientes = new cliente * [tam];
    for (int i = 0; i < tam; i++) {
        clientes[i] = nullptr;
    }
}

vecClientes::~vecClientes() {
    for (int i = 0; i < cant; i++) {
        delete clientes[i];
    }
    delete[] clientes;
}

bool vecClientes::agregar(cliente* cli) {
    if (cant < tam) {
        clientes[cant] = cli;
        cant++;
		return true;
    }
	return false;
}

// Versión no-const
cliente* vecClientes::obtener(int indice) {
    if (indice >= 0 && indice < cant) {
        return clientes[indice];
    }
    return nullptr;
}

// Versión const
cliente* vecClientes::obtener(int indice) const {
    if (indice >= 0 && indice < cant) {
        return clientes[indice];
    }
    return nullptr;
}

// Versión no-const
cliente* vecClientes::buscarPorCedula(string cedula) {
    for (int i = 0; i < cant; i++) {
        if (clientes[i]->getCedula() == cedula) {
            return clientes[i];
        }
    }
    return nullptr;
}

// Versión const
cliente* vecClientes::buscarPorCedula(string cedula) const {
    for (int i = 0; i < cant; i++) {
        if (clientes[i]->getCedula() == cedula) {
            return clientes[i];
        }
    }
    return nullptr;
}

int vecClientes::getCantidad() const {
    return cant;
}

void vecClientes::mostrarLista() const {
    print("Lista de clientes de la sucursal:\n");
    for (int i = 0; i < cant; i++) {
        print(to_string(i + 1) + "- " + clientes[i]->toString() + "\n");
    }
}

void vecClientes::generarReporteIMC() const {
    // Contadores por categoría
    int contadores[8] = { 0 }; // índices 0-7 para las 8 categorías

    // Arrays para almacenar clientes por categoría
    cliente* categorias[8][100]; // máximo 100 clientes por categoría
    int cantPorCategoria[8] = { 0 };

    string nombresCategorias[8] = {
        "Delgadez severa (<16.00)",
        "Delgadez moderada (16.00 - 16.99)",
        "Delgadez leve (17.00 - 18.49)",
        "Normal (18.50 - 24.99)",
        "Pre-obesidad (25.00 - 29.99)",
        "Obesidad leve (30.00 - 34.99)",
        "Obesidad media (35.00 - 39.99)",
        "Obesidad mórbida (>=40.00)"
    };

    // Clasificar clientes según su último IMC
    for (int i = 0; i < cant; i++) {
        double imc = clientes[i]->getUltimoIMC();
        if (imc > 0) { // Solo si tiene mediciones
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
                categorias[categoria][cantPorCategoria[categoria]] = clientes[i];
                cantPorCategoria[categoria]++;
                contadores[categoria]++;
            }
        }
    }

    // Mostrar reporte
    for (int i = 0; i < 8; i++) {
        print(nombresCategorias[i] + ":\n");
        if (contadores[i] == 0) {
            print("Ninguno\n");
        }
        else {
            print("(Cantidad " + to_string(contadores[i]) + ")\n");
            for (int j = 0; j < cantPorCategoria[i]; j++) {
                double imc = categorias[i][j]->getUltimoIMC();
                print(to_string(j + 1) + "- " + categorias[i][j]->getCedula() + " " +
                    categorias[i][j]->getNombre() + " IMC: " + to_string(imc) + "\n");
            }
        }
        print("\n");
    }
}