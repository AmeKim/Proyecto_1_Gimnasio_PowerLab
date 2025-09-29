#include "Medicion.h"

Medicion::Medicion() : fechaMedicion(), peso(0), estatura(0),
porcentajeGrasa(0), porcentajeMusculo(0), imc(0),
clasificacion(""), altoRiesgo(false) {
}

Medicion::Medicion(const fecha& f, double p, double e, double g, double m)
    : fechaMedicion(f), peso(p), estatura(e),
    porcentajeGrasa(g), porcentajeMusculo(m) {
    calcularIMC();
    determinarClasificacion();
    determinarRiesgo();
}

Medicion::~Medicion() {}

void Medicion::calcularIMC() {
    if (estatura > 0) {
        imc = peso / (estatura * estatura);
    }
    else {
        imc = 0;
    }
}

void Medicion::determinarClasificacion() {
    if (imc < 16.00) {
        clasificacion = "Delgadez severa";
    }
    else if (imc >= 16.00 && imc <= 16.99) {
        clasificacion = "Delgadez moderada";
    }
    else if (imc >= 17.00 && imc <= 18.49) {
        clasificacion = "Delgadez leve";
    }
    else if (imc >= 18.50 && imc <= 24.99) {
        clasificacion = "Normal";
    }
    else if (imc >= 25.00 && imc <= 29.99) {
        clasificacion = "Pre-obesidad";
    }
    else if (imc >= 30.00 && imc <= 34.99) {
        clasificacion = "Obesidad leve";
    }
    else if (imc >= 35.00 && imc <= 39.99) {
        clasificacion = "Obesidad media";
    }
    else {
        clasificacion = "Obesidad morbida";
    }
}

void Medicion::determinarRiesgo() {
    altoRiesgo = (imc >= 30.00);
}

fecha Medicion::getFecha() const { return fechaMedicion; }
double Medicion::getPeso() const { return peso; }
double Medicion::getEstatura() const { return estatura; }
double Medicion::getPorcentajeGrasa() const { return porcentajeGrasa; }
double Medicion::getPorcentajeMusculo() const { return porcentajeMusculo; }
double Medicion::getImc() const { return imc; }
string Medicion::getClasificacion() const { return clasificacion; }
bool Medicion::esAltoRiesgo() const { return altoRiesgo; }

int Medicion::calcularVasos() const {
    if (peso <= 0) return 0;
    return static_cast<int>(peso / 7.0);
}

int Medicion::calcularVasosAgua() const {
    return calcularVasos();
}

double Medicion::calcularProteina(bool esHombre) const {
    if (esHombre) {
        return peso * 2.1;
    }
    else {
        return peso * 1.7;
    }
}

string Medicion::toString() const {
    stringstream ss;
    ss << "Fecha: " << fechaMedicion.toString() << "\n";
    ss << "Peso (kg): " << peso << "\n";
    ss << "Estatura (m): " << estatura << "\n";
    ss << "% de grasa: " << porcentajeGrasa << "\n";
    ss << "% de musculo: " << porcentajeMusculo << "\n";
    ss << "IMC: " << imc << "\n";
    ss << "Clasificacion: " << clasificacion << "\n";
    ss << "Alto Riesgo: " << (altoRiesgo ? "SI" : "NO") << "\n";
    return ss.str();
}