#include "vecReportesM.h"

vecReportesM::vecReportesM(int capacidad) {
    tam = capacidad;
    can = 0;
    reportes = new reporteM * [tam];
    mediciones = new Medicion * [tam];
    for (int i = 0; i < tam; i++) {
        reportes[i] = nullptr;
        mediciones[i] = nullptr;
    }
}

vecReportesM::~vecReportesM() {
    for (int i = 0; i < can; i++) {
        delete reportes[i];
        reportes[i] = nullptr;
        delete mediciones[i];
        mediciones[i] = nullptr;
    }
    delete[] reportes;
    reportes = nullptr;
    delete[] mediciones;
    mediciones = nullptr;
}

// Se elimina el metodo agregarReporte(reporteM* reporte) ya que su gestion de memoria
// es incompatible con crearYAgregarReporte y el destructor, causando problemas.

bool vecReportesM::crearYAgregarReporte(Medicion* medicion) {
    if (can < tam && medicion != nullptr) {
        reporteM* nuevoReporte = new reporteM(medicion);
        reportes[can] = nuevoReporte;
        mediciones[can] = medicion; // Guardar referencia para gestionar memoria
        can++;
        return true;
    }
    return false;
}

reporteM* vecReportesM::getReportePorIndice(int indice) const {
    if (indice >= 0 && indice < can) {
        return reportes[indice];
    }
    return nullptr;
}

reporteM* vecReportesM::getUltimoReporte() const {
    if (can > 0) {
        return reportes[can - 1];
    }
    return nullptr;
}

int vecReportesM::getCan() const {
    return can;
}

int vecReportesM::getTam() const {
    return tam;
}

bool vecReportesM::estaLleno() const {
    return can >= tam;
}

void vecReportesM::mostrarHistorialResumen() const {
    cout << "HISTORIAL DE MEDICIONES" << endl;
    for (int i = 0; i < can; i++) {
        if (reportes[i] != nullptr) {
            cout << (i + 1) << "- " << reportes[i]->mostrarResumen() << endl;
        }
    }
}

void vecReportesM::mostrarReporteDetallado(int indice) const {
    if (indice >= 0 && indice < can && reportes[indice] != nullptr) {
        reportes[indice]->mostrarDetalle();
    }
    else {
        cout << "Indice invalido." << endl;
    }
}