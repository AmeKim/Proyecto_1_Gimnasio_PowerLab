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
        delete mediciones[i]; // Eliminar las mediciones también
    }
    delete[] reportes;
    delete[] mediciones;
}

bool vecReportesM::agregarReporte(reporteM* reporte) {
    if (can < tam && reporte != nullptr) {
        reportes[can] = reporte;
        mediciones[can] = nullptr; // No gestiona esta medición
        can++;
        return true;
    }
    return false;
}

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
        cout << "Indice invalido o reporte no encontrado." << endl;
    }
}

void vecReportesM::mostrarTodosLosReportes() const {
    cout << "HISTORIAL COMPLETO DE MEDICIONES" << endl;
    cout << "=================================" << endl;
    for (int i = 0; i < can; i++) {
        if (reportes[i] != nullptr) {
            cout << "REPORTE #" << (i + 1) << endl;
            reportes[i]->mostrarReporteCompleto();
            cout << endl;
        }
    }
}