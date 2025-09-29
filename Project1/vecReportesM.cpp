#include "vecReportesM.h"
#include <iostream>
#include <sstream>

vecReportesM::vecReportesM() : tam(10), cant(0) {
    mediciones = new Medicion * [tam];
    for (int i = 0; i < tam; i++) {
        mediciones[i] = nullptr;
    }
}

vecReportesM::~vecReportesM() {
    for (int i = 0; i < cant; i++) {
        if (mediciones[i]) {
            delete mediciones[i];
        }
    }
    delete[] mediciones;
}

void vecReportesM::agregar(Medicion* medicion) {
    if (!medicion || cant >= tam) return;
    mediciones[cant++] = medicion;
}

Medicion* vecReportesM::obtener(int indice) {
    if (indice < 0 || indice >= cant) return nullptr;
    return mediciones[indice];
}

int vecReportesM::getCantidad() const {
    return cant;
}

void vecReportesM::mostrarHistorial() const {
    for (int i = 0; i < cant; i++) {
        if (mediciones[i]) {
            cout << (i + 1) << "- Fecha: " << mediciones[i]->getFecha().toString()
                << " | Peso: " << mediciones[i]->getPeso() << " kg"
                << " | IMC: " << mediciones[i]->getImc() << "\n";
        }
    }
}