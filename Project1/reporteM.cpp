#include "reporteM.h"

reporteM::reporteM() {
    medicion = nullptr;
}

reporteM::reporteM(Medicion* med) {
    this->medicion = med;
}

reporteM::~reporteM() {
    // No eliminar medicion aquí ya que puede ser compartida
    // La gestión de memoria de medicion se hace en el vecReportesM
}

// Getters
Medicion* reporteM::getMedicion() const {
    return medicion;
}

// Setters
void reporteM::setMedicion(Medicion* med) {
    this->medicion = med;
}

// Métodos de presentación (solo imprimen)
string reporteM::toString() const {
    if (medicion == nullptr) {
        return "No hay datos de medicion disponibles";
    }

    stringstream s;
    s << "=============== Detalle Medicion ===============" << endl;
    s << "Fecha: " << medicion->getFechaMedicion()->toString() << endl;
    s << "Peso (kg): " << medicion->getPeso() << endl;
    s << "Estatura (m): " << medicion->getEstatura() << endl;
    s << "% de grasa: " << medicion->getPorcentajeGrasa() << endl;
    s << "% de musculo: " << medicion->getPorcentajeMusculo() << endl;
    s << "Edad metabolica: " << medicion->getEdadMetabolica() << " años" << endl;
    s << "% de grasa visceral: " << medicion->getPorcentajeGrasaVisceral() << endl;
    s << "Cintura: " << medicion->getCintura() << " cm" << endl;
    s << "Cadera: " << medicion->getCadera() << " cm" << endl;
    s << "Pecho: " << medicion->getPecho() << " cm" << endl;
    s << "Muslo: " << medicion->getMuslo() << " cm" << endl;
    s << "IMC: " << medicion->getIMC() << endl;
    s << "Clasificacion: " << medicion->getClasificacion() << endl;
    s << "Alto Riesgo: " << (medicion->esAltoRiesgo() ? "SI" : "NO") << endl;
    s << "Cantidad de vasos recomendados: " << medicion->getVasosAgua() << endl;
    s << "Cantidad de proteina recomendada: " << medicion->getProteina() << " gramos" << endl;
    return s.str();
}

void reporteM::mostrarDetalle() const {
    cout << toString();
}

void reporteM::mostrarReporteCompleto() const {
    if (medicion == nullptr) {
        cout << "No hay datos de medicion disponibles" << endl;
        return;
    }

    cout << "=======================================================" << endl;
    cout << "REPORTE DE MEDICION COMPLETO" << endl;
    cout << "=======================================================" << endl;
    cout << "Nombre del cliente: " << medicion->getNombreCliente() << endl;
    cout << "ID del cliente: " << medicion->getIdCliente() << endl;
    cout << "Nombre del instructor: " << medicion->getNombreInstructor() << endl;
    cout << "Fecha de la medicion: " << medicion->getFechaMedicion()->toString() << endl;
    cout << "=======================================================" << endl;
    cout << "DATOS DE LA MEDICION:" << endl;
    cout << "Peso: " << medicion->getPeso() << " kg" << endl;
    cout << "Estatura: " << medicion->getEstatura() << " m" << endl;
    cout << "Porcentaje de grasa: " << medicion->getPorcentajeGrasa() << "%" << endl;
    cout << "Porcentaje de musculo: " << medicion->getPorcentajeMusculo() << "%" << endl;
    cout << "Edad metabolica: " << medicion->getEdadMetabolica() << " años" << endl;
    cout << "Porcentaje de grasa visceral: " << medicion->getPorcentajeGrasaVisceral() << "%" << endl;
    cout << "=======================================================" << endl;
    cout << "MEDIDAS CORPORALES:" << endl;
    cout << "Cintura: " << medicion->getCintura() << " cm" << endl;
    cout << "Cadera: " << medicion->getCadera() << " cm" << endl;
    cout << "Pecho: " << medicion->getPecho() << " cm" << endl;
    cout << "Muslo: " << medicion->getMuslo() << " cm" << endl;
    cout << "=======================================================" << endl;
    cout << "CALCULOS AUTOMATICOS:" << endl;
    cout << "IMC: " << medicion->getIMC() << endl;
    cout << "Clasificacion: " << medicion->getClasificacion() << endl;
    cout << "Alto Riesgo: " << (medicion->esAltoRiesgo() ? "SI" : "NO") << endl;
    cout << "=======================================================" << endl;
    cout << "RECOMENDACIONES:" << endl;
    cout << "Cantidad de vasos de agua recomendados: " << medicion->getVasosAgua() << endl;
    cout << "Cantidad de proteina recomendada: " << medicion->getProteina() << " gramos" << endl;
    cout << "=======================================================" << endl;
}

string reporteM::mostrarResumen() const {
    if (medicion == nullptr) {
        return "No hay datos disponibles";
    }

    stringstream s;
    s << "Fecha: " << medicion->getFechaMedicion()->toString();
    s << " | Peso: " << medicion->getPeso() << " kg";
    s << " | IMC: " << medicion->getIMC();
    return s.str();
}