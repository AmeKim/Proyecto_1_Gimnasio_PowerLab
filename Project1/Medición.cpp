#include "Medicion.h"

// Constructores
Medicion::Medicion(const Fecha& fecha, string cedCliente, string cedInstructor,
    double p, double est, double pGrasa, double pMusculo, char sexo)
    : fechaMedicion(fecha), cedulaCliente(cedCliente), cedulaInstructor(cedInstructor),
    peso(p), estatura(est), porcentajeGrasa(pGrasa), porcentajeMusculo(pMusculo),
    sexoCliente(sexo) {
    calcularTodosLosValores();
}

Medicion::Medicion(const string& fechaStr, string cedCliente, string cedInstructor,
    double p, double est, double pGrasa, double pMusculo, char sexo)
    : fechaMedicion(fechaStr), cedulaCliente(cedCliente), cedulaInstructor(cedInstructor),
    peso(p), estatura(est), porcentajeGrasa(pGrasa), porcentajeMusculo(pMusculo),
    sexoCliente(sexo) {
    calcularTodosLosValores();
}

Medicion::~Medicion() {
}

// Métodos privados de cálculo
void Medicion::calcularIMC() {
    if (estatura > 0) {
        imc = peso / (estatura * estatura);
    }
    else {
        imc = 0;
    }
}

void Medicion::determinarClasificacionIMC() {
    if (imc < 16.00) {
        clasificacionIMC = "Delgadez severa";
        altoRiesgo = false;
    }
    else if (imc <= 16.99) {
        clasificacionIMC = "Delgadez moderada";
        altoRiesgo = false;
    }
    else if (imc <= 18.49) {
        clasificacionIMC = "Delgadez leve";
        altoRiesgo = false;
    }
    else if (imc <= 24.99) {
        clasificacionIMC = "Normal";
        altoRiesgo = false;
    }
    else if (imc <= 29.99) {
        clasificacionIMC = "Pre-obesidad";
        altoRiesgo = false;
    }
    else if (imc <= 34.99) {
        clasificacionIMC = "Obesidad leve";
        altoRiesgo = true;
    }
    else if (imc <= 39.99) {
        clasificacionIMC = "Obesidad media";
        altoRiesgo = true;
    }
    else {
        clasificacionIMC = "Obesidad mórbida";
        altoRiesgo = true;
    }
}

void Medicion::calcularVasosAgua() {
    if (peso > 0) {
        vasosAgua = static_cast<int>(peso / 7);
    }
    else {
        vasosAgua = 0;
    }
}

void Medicion::calcularProteinaRecomendada() {
    if (peso <= 0) {
        proteinaRecomendada = 0;
        return;
    }

    if (sexoCliente == 'M' || sexoCliente == 'm') {
        // Hombre que hace ejercicio: 1.7 - 2.5 g/kg (usamos 2.1 como promedio)
        proteinaRecomendada = peso * 2.1;
    }
    else {
        // Mujer que hace ejercicio: 1.6 - 1.8 g/kg (usamos 1.7 como promedio)
        proteinaRecomendada = peso * 1.7;
    }
}

void Medicion::calcularTodosLosValores() {
    calcularIMC();
    determinarClasificacionIMC();
    calcularVasosAgua();
    calcularProteinaRecomendada();
}

// Getters
Fecha Medicion::getFecha() const { return fechaMedicion; }
string Medicion::getCedulaCliente() const { return cedulaCliente; }
string Medicion::getCedulaInstructor() const { return cedulaInstructor; }
double Medicion::getPeso() const { return peso; }
double Medicion::getEstatura() const { return estatura; }
double Medicion::getPorcentajeGrasa() const { return porcentajeGrasa; }
double Medicion::getPorcentajeMusculo() const { return porcentajeMusculo; }
double Medicion::getIMC() const { return imc; }
string Medicion::getClasificacionIMC() const { return clasificacionIMC; }
bool Medicion::esAltoRiesgo() const { return altoRiesgo; }
int Medicion::getVasosAgua() const { return vasosAgua; }
double Medicion::getProteinaRecomendada() const { return proteinaRecomendada; }
char Medicion::getSexoCliente() const { return sexoCliente; }

// Setters que recalculan automáticamente
void Medicion::setPeso(double p) {
    peso = p;
    calcularTodosLosValores();
}

void Medicion::setEstatura(double est) {
    estatura = est;
    calcularTodosLosValores();
}

void Medicion::setPorcentajeGrasa(double pGrasa) {
    porcentajeGrasa = pGrasa;
}

void Medicion::setPorcentajeMusculo(double pMusculo) {
    porcentajeMusculo = pMusculo;
}

void Medicion::setFecha(const Fecha& fecha) {
    fechaMedicion = fecha;
}

void Medicion::setFecha(const string& fechaStr) {
    fechaMedicion.parsearFecha(fechaStr);
}

// Métodos de presentación
string Medicion::toStringCompleto() const {
    stringstream s;
    s << fixed << setprecision(2);
    s << "=============== Detalle Medición ===============" << endl;
    s << "Fecha: " << fechaMedicion.toString() << endl;
    s << "Cliente: " << cedulaCliente << endl;
    s << "Instructor: " << cedulaInstructor << endl;
    s << "Peso (kg): " << peso << endl;
    s << "Estatura (m): " << estatura << endl;
    s << "% de grasa: " << porcentajeGrasa << endl;
    s << "% de músculo: " << porcentajeMusculo << endl;
    s << "IMC: " << imc << endl;
    s << "Clasificación: " << clasificacionIMC << endl;
    s << "Alto Riesgo: " << (altoRiesgo ? "SÍ" : "NO") << endl;
    s << "Cantidad de vasos recomendados: " << vasosAgua << endl;
    s << "Cantidad de proteína recomendada: " << proteinaRecomendada << " gramos" << endl;
    s << "===============================================" << endl;
    return s.str();
}

string Medicion::toStringResumen() const {
    stringstream s;
    s << fixed << setprecision(1);
    s << "Fecha: " << fechaMedicion.toString() << " | Peso: " << peso << " kg | IMC: " << imc;
    return s.str();
}

string Medicion::toStringParaHistorial() const {
    stringstream s;
    s << fixed << setprecision(1);
    s << fechaMedicion.toString() << " - Peso: " << peso << "kg, IMC: " << imc
        << " (" << clasificacionIMC << ")";
    return s.str();
}