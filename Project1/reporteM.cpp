#include "reporteM.h"

reporteM::reporteM() {
    medicion = nullptr;
}

reporteM::reporteM(Medicion* med) {
    this->medicion = med;
}

reporteM::~reporteM() {
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

// Métodos de presentación
void reporteM::mostrarDetalle() const {
    if (medicion == nullptr) {
        cout << "No hay datos de medicion disponibles" << endl;
        return;
    }

    cout << "=============== Detalle Medicion ===============" << endl;
    if (medicion->getFecha()) {
        cout << "Fecha: " << medicion->getFecha()->toString() << endl;
    }
    cout << "Peso (kg): " << medicion->getPeso() << endl;
    cout << "Estatura (m): " << medicion->getEstatura() << endl;
    cout << "% de grasa: " << medicion->getPorcentajeGrasa() << endl;
    cout << "% de musculo: " << medicion->getPorcentajeMusculo() << endl;
    cout << "Edad metabolica: " << medicion->getEdadMetabolica() << " anios" << endl;
    cout << "% de grasa visceral: " << medicion->getPorcentajeGrasaVisceral() << "%" << endl;
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
    cout << "Alto Riesgo: " << (medicion->getAltoRiesgo() ? "SI" : "NO") << endl;
    cout << "=======================================================" << endl;
    cout << "RECOMENDACIONES:" << endl;
    cout << "Cantidad de vasos de agua recomendados: " << medicion->getVasosRecomendados() << endl;
    cout << "Cantidad de proteina recomendada: " << medicion->getProteinaRecomendada() << " gramos" << endl;
    cout << "=======================================================" << endl;
}

string reporteM::mostrarResumen() const {
    if (medicion == nullptr) {
        return "No hay datos de medicion disponibles";
    }

    stringstream s;
    if (medicion->getFecha()) {
        s << "Fecha: " << medicion->getFecha()->toString() << " | ";
    }
    s << "Peso: " << medicion->getPeso() << " kg | IMC: " << medicion->getIMC() << " | Clasificacion: " << medicion->getClasificacion();
    return s.str();
}