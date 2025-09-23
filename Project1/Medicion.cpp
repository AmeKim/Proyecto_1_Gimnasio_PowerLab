#include "Medicion.h"

Medicion::Medicion() {
    fechaMedicion = new fecha();
    peso = 0.0;
    estatura = 0.0;
    porcentajeGrasa = 0.0;
    porcentajeMusculo = 0.0;
    imc = 0.0;
    clasificacion = "";
    altoRiesgo = false;
    vasosRecomendados = 0;
    proteinaRecomendada = 0.0;
}

Medicion::Medicion(string fechaStr, double peso, double estatura, double grasa, double musculo) {
    fechaMedicion = new fecha(fechaStr);
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = grasa;
    this->porcentajeMusculo = musculo;
    imc = 0.0;
    clasificacion = "";
    altoRiesgo = false;
    vasosRecomendados = 0;
    proteinaRecomendada = 0.0;
}

Medicion::~Medicion() {
    delete fechaMedicion;
}

fecha* Medicion::getFecha() const {
    return fechaMedicion;
}

double Medicion::getPeso() const {
    return peso;
}

double Medicion::getEstatura() const {
    return estatura;
}

double Medicion::getPorcentajeGrasa() const {
    return porcentajeGrasa;
}

double Medicion::getPorcentajeMusculo() const {
    return porcentajeMusculo;
}

double Medicion::getImc() const {
    return imc;
}

string Medicion::getClasificacion() const {
    return clasificacion;
}

bool Medicion::getAltoRiesgo() const {
    return altoRiesgo;
}

int Medicion::getVasosRecomendados() const {
    return vasosRecomendados;
}

double Medicion::getProteinaRecomendada() const {
    return proteinaRecomendada;
}

void Medicion::setFecha(string fechaStr) {
    delete fechaMedicion;
    fechaMedicion = new fecha(fechaStr);
}

void Medicion::setPeso(double peso) {
    this->peso = peso;
}

void Medicion::setEstatura(double estatura) {
    this->estatura = estatura;
}

void Medicion::setPorcentajeGrasa(double grasa) {
    this->porcentajeGrasa = grasa;
}

void Medicion::setPorcentajeMusculo(double musculo) {
    this->porcentajeMusculo = musculo;
}

void Medicion::calcularIMC() {
    if (estatura > 0) {
        imc = peso / (estatura * estatura);
    }
}

void Medicion::calcularClasificacion() {
    if (imc < 16.0) {
        clasificacion = "Delgadez severa";
    }
    else if (imc <= 16.99) {
        clasificacion = "Delgadez moderada";
    }
    else if (imc <= 18.49) {
        clasificacion = "Delgadez leve";
    }
    else if (imc <= 24.99) {
        clasificacion = "Normal";
    }
    else if (imc <= 29.99) {
        clasificacion = "Pre-obesidad";
    }
    else if (imc <= 34.99) {
        clasificacion = "Obesidad leve";
    }
    else if (imc <= 39.99) {
        clasificacion = "Obesidad media";
    }
    else {
        clasificacion = "Obesidad mórbida";
    }
}

void Medicion::calcularAltoRiesgo() {
    altoRiesgo = (imc >= 30.0); // Obesidad leve, media o mórbida
}

void Medicion::calcularVasos() {
    vasosRecomendados = static_cast<int>(peso / 7.0);
}

void Medicion::calcularProteina(char sexo) {
    if (sexo == 'M' || sexo == 'm') {
        // Hombre que hace ejercicio: 1.7 - 2.5, usamos promedio 2.1
        proteinaRecomendada = peso * 2.1;
    }
    else {
        // Mujer que hace ejercicio: 1.6 - 1.8, usamos promedio 1.7
        proteinaRecomendada = peso * 1.7;
    }
}

void Medicion::calcularTodo(char sexo) {
    calcularIMC();
    calcularClasificacion();
    calcularAltoRiesgo();
    calcularVasos();
    calcularProteina(sexo);
}

string Medicion::toString() const {
    return "=============== Detalle Medición ===============\n"
        "Fecha: " + fechaMedicion->toString() + "\n" +
        "Peso (kg): " + to_string(peso) + "\n" +
        "Estatura (m): " + to_string(estatura) + "\n" +
        "% de grasa: " + to_string(porcentajeGrasa) + "\n" +
        "% de músculo: " + to_string(porcentajeMusculo) + "\n" +
        "IMC: " + to_string(imc) + "\n" +
        "Clasificación: " + clasificacion + "\n" +
        "Alto Riesgo: " + (altoRiesgo ? "SÍ" : "NO") + "\n" +
        "Cantidad de vasos recomendados: " + to_string(vasosRecomendados) + "\n" +
        "Cantidad de proteína recomendada: " + to_string(proteinaRecomendada) + " gramos\n";
}

string Medicion::toStringResumen() const {
    return "Fecha: " + fechaMedicion->toString() + " | Peso: " +
        to_string(peso) + " kg | IMC: " + to_string(imc);
}