#include "Medicion.h"
#include "cliente.h"
#include "instructor.h"
#include <iomanip>

Medicion::Medicion() {
    fechaMedicion = nullptr;
    clienteRef = nullptr;
    instructorRef = nullptr;
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

Medicion::Medicion(fecha* fecha, cliente* cli, instructor* inst, double peso, double estatura,
    double porcentajeGrasa, double porcentajeMusculo) {
    this->fechaMedicion = fecha;
    this->clienteRef = cli;
    this->instructorRef = inst;
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = porcentajeGrasa;
    this->porcentajeMusculo = porcentajeMusculo;

    // Calcular automáticamente los valores derivados
    calcularTodo();
}

Medicion::~Medicion() {
    // No eliminamos fecha, cliente ni instructor porque son referencias
}

// Getters
fecha* Medicion::getFecha() const { return fechaMedicion; }
cliente* Medicion::getCliente() const { return clienteRef; }
instructor* Medicion::getInstructor() const { return instructorRef; }
double Medicion::getPeso() const { return peso; }
double Medicion::getEstatura() const { return estatura; }
double Medicion::getPorcentajeGrasa() const { return porcentajeGrasa; }
double Medicion::getPorcentajeMusculo() const { return porcentajeMusculo; }
double Medicion::getIMC() const { return imc; }
string Medicion::getClasificacion() const { return clasificacion; }
bool Medicion::getAltoRiesgo() const { return altoRiesgo; }
int Medicion::getVasosRecomendados() const { return vasosRecomendados; }
double Medicion::getProteinaRecomendada() const { return proteinaRecomendada; }

// Setters
void Medicion::setFecha(fecha* fecha) { fechaMedicion = fecha; }
void Medicion::setCliente(cliente* cli) { clienteRef = cli; }
void Medicion::setInstructor(instructor* inst) { instructorRef = inst; }
void Medicion::setPeso(double peso) { this->peso = peso; calcularTodo(); }
void Medicion::setEstatura(double estatura) { this->estatura = estatura; calcularTodo(); }
void Medicion::setPorcentajeGrasa(double porcentajeGrasa) { this->porcentajeGrasa = porcentajeGrasa; }
void Medicion::setPorcentajeMusculo(double porcentajeMusculo) { this->porcentajeMusculo = porcentajeMusculo; }

// Métodos de cálculo
void Medicion::calcularIMC() {
    if (estatura > 0) {
        imc = peso / (estatura * estatura);
    }
}

void Medicion::determinarClasificacion() {
    if (imc < 16.00) clasificacion = "Delgadez severa";
    else if (imc >= 16.00 && imc <= 16.99) clasificacion = "Delgadez moderada";
    else if (imc >= 17.00 && imc <= 18.49) clasificacion = "Delgadez leve";
    else if (imc >= 18.50 && imc <= 24.99) clasificacion = "Normal";
    else if (imc >= 25.00 && imc <= 29.99) clasificacion = "Pre-obesidad";
    else if (imc >= 30.00 && imc <= 34.99) clasificacion = "Obesidad leve";
    else if (imc >= 35.00 && imc <= 39.99) clasificacion = "Obesidad media";
    else if (imc >= 40.00) clasificacion = "Obesidad mórbida";
    else clasificacion = "No determinado";
}

void Medicion::calcularAltoRiesgo() {
    altoRiesgo = (imc >= 30.00); // Obesidad leve, media o mórbida
}

void Medicion::calcularVasosRecomendados() {
    vasosRecomendados = static_cast<int>(peso / 7.0);
}

void Medicion::calcularProteinaRecomendada() {
    if (clienteRef) {
        char sexo = clienteRef->getSexo();
        if (sexo == 'M' || sexo == 'm') {
            proteinaRecomendada = peso * 2.1; // Promedio entre 1.7 y 2.5
        }
        else {
            proteinaRecomendada = peso * 1.7; // Promedio entre 1.6 y 1.8
        }
    }
    else {
        proteinaRecomendada = peso * 0.8; // Valor base de la OMS
    }
}

void Medicion::calcularTodo() {
    calcularIMC();
    determinarClasificacion();
    calcularAltoRiesgo();
    calcularVasosRecomendados();
    calcularProteinaRecomendada();
}

string Medicion::toString() const {
    stringstream s;
    s << fixed << setprecision(2);
    if (fechaMedicion) {
        s << "Fecha: " << fechaMedicion->toString() << " | ";
    }
    s << "Peso: " << peso << " kg | IMC: " << imc;
    return s.str();
}

void Medicion::mostrar() const {
    cout << "=============== Detalle Medición ===============" << endl;
    if (fechaMedicion) {
        cout << "Fecha: " << fechaMedicion->toString() << endl;
    }
    cout << fixed << setprecision(2);
    cout << "Peso (kg): " << peso << endl;
    cout << "Estatura (m): " << estatura << endl;
    cout << "% de grasa: " << porcentajeGrasa << endl;
    cout << "% de músculo: " << porcentajeMusculo << endl;
    cout << "IMC: " << imc << endl;
    cout << "Clasificación: " << clasificacion << endl;
    cout << "Alto Riesgo: " << (altoRiesgo ? "SÍ" : "NO") << endl;
    cout << "Cantidad de vasos recomendados: " << vasosRecomendados << endl;
    cout << "Cantidad de proteína recomendada: " << proteinaRecomendada << " gramos" << endl;
}