#include "reporteM.h"

reporteM::reporteM() {
    fechaMedicion = new Fecha();
    peso = 0.0;
    estatura = 0.0;
    porcentajeGrasa = 0.0;
    porcentajeMusculo = 0.0;
    imc = 0.0;
    clasificacion = "";
    altoRiesgo = false;
    vasosAgua = 0;
    proteina = 0.0;
}

reporteM::reporteM(const Fecha& fecha, double peso, double estatura, double pGrasa, double pMusculo) {
    this->fechaMedicion = new Fecha(fecha);
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = pGrasa;
    this->porcentajeMusculo = pMusculo;

    calcularIMC();
    determinarClasificacion();
    calcularVasosAgua();
}

reporteM::~reporteM() {
    delete fechaMedicion;
}

// Getters
Fecha* reporteM::getFechaMedicion() const { return fechaMedicion; }
double reporteM::getPeso() const { return peso; }
double reporteM::getEstatura() const { return estatura; }
double reporteM::getPorcentajeGrasa() const { return porcentajeGrasa; }
double reporteM::getPorcentajeMusculo() const { return porcentajeMusculo; }
double reporteM::getIMC() const { return imc; }
string reporteM::getClasificacion() const { return clasificacion; }
bool reporteM::esAltoRiesgo() const { return altoRiesgo; }
int reporteM::getVasosAgua() const { return vasosAgua; }
double reporteM::getProteina() const { return proteina; }

// Setters
void reporteM::setFechaMedicion(const Fecha& fecha) {
    if (fechaMedicion) delete fechaMedicion;
    fechaMedicion = new Fecha(fecha);
}

void reporteM::setPeso(double peso) { this->peso = peso; }
void reporteM::setEstatura(double estatura) { this->estatura = estatura; }
void reporteM::setPorcentajeGrasa(double pGrasa) { this->porcentajeGrasa = pGrasa; }
void reporteM::setPorcentajeMusculo(double pMusculo) { this->porcentajeMusculo = pMusculo; }

void reporteM::calcularIMC() {
    if (estatura > 0) {
        imc = peso / (estatura * estatura);
    }
}

void reporteM::determinarClasificacion() {
    if (imc < 16.00) {
        clasificacion = "Delgadez severa";
        altoRiesgo = false;
    }
    else if (imc >= 16.00 && imc <= 16.99) {
        clasificacion = "Delgadez moderada";
        altoRiesgo = false;
    }
    else if (imc >= 17.00 && imc <= 18.49) {
        clasificacion = "Delgadez leve";
        altoRiesgo = false;
    }
    else if (imc >= 18.50 && imc <= 24.99) {
        clasificacion = "Normal";
        altoRiesgo = false;
    }
    else if (imc >= 25.00 && imc <= 29.99) {
        clasificacion = "Pre-obesidad";
        altoRiesgo = false;
    }
    else if (imc >= 30.00 && imc <= 34.99) {
        clasificacion = "Obesidad leve";
        altoRiesgo = true;
    }
    else if (imc >= 35.00 && imc <= 39.99) {
        clasificacion = "Obesidad media";
        altoRiesgo = true;
    }
    else {
        clasificacion = "Obesidad mórbida";
        altoRiesgo = true;
    }
}

void reporteM::calcularVasosAgua() {
    vasosAgua = static_cast<int>(peso / 7);
}

void reporteM::calcularProteina(char sexo) {
    if (sexo == 'M' || sexo == 'm') {
        // Hombre que hace ejercicio: 1.7 - 2.5 g/kg (usamos 2.0 como promedio)
        proteina = peso * 2.0;
    }
    else {
        // Mujer que hace ejercicio: 1.6 - 1.8 g/kg (usamos 1.7 como promedio)
        proteina = peso * 1.7;
    }
}

string reporteM::toString() const {
    stringstream s;
    s << "Fecha: " << fechaMedicion->toString() << " | Peso: " << peso << " kg | IMC: " << imc;
    return s.str();
}

void reporteM::mostrarDetalle() const {
    cout << "=============== Detalle Medición ===============" << endl;
    cout << "Fecha: " << fechaMedicion->toString() << endl;
    cout << "Peso (kg): " << peso << endl;
    cout << "Estatura (m): " << estatura << endl;
    cout << "% de grasa: " << porcentajeGrasa << endl;
    cout << "% de músculo: " << porcentajeMusculo << endl;
    cout << "IMC: " << imc << endl;
    cout << "Clasificación: " << clasificacion << endl;
    cout << "Alto Riesgo: " << (altoRiesgo ? "SÍ" : "NO") << endl;
    cout << "Cantidad de vasos recomendados: " << vasosAgua << endl;
    cout << "Cantidad de proteína recomendada: " << proteina << " gramos" << endl;
}