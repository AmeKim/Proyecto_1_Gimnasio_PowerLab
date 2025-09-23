#pragma once
#include "vecReportesM.h"
#include "utiles.h"

vecReportesM::vecReportesM() {
    tam = 10; // Máximo 10 mediciones por cliente
    cant = 0;
    mediciones = new Medicion * [tam];
    for (int i = 0; i < tam; i++) {
        mediciones[i] = nullptr;
    }
}

vecReportesM::~vecReportesM() {
    for (int i = 0; i < cant; i++) {
        delete mediciones[i];
    }
    delete[] mediciones;
}

void vecReportesM::agregar(Medicion* medicion) {
    if (cant < tam) {
        mediciones[cant] = medicion;
        cant++;
    }
}

Medicion* vecReportesM::obtener(int indice) {
    if (indice >= 0 && indice < cant) {
        return mediciones[indice];
    }
    return nullptr;
}

int vecReportesM::getCantidad() const {
    return cant;
}

void vecReportesM::mostrarHistorial() const {
    print("HISTORIAL DE MEDICIONES\n");
    for (int i = 0; i < cant; i++) {
        print(to_string(i + 1) + "- " + mediciones[i]->toStringResumen() + "\n");
    }
}