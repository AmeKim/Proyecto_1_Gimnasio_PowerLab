#include "Medicion.h"

Medicion::Medicion() {
    fechaMedicion = nullptr;
    clienteRef = nullptr;
    instructorRef = nullptr;
    peso = 0.0;
    estatura = 0.0;
    porcentajeGrasa = 0.0;
    porcentajeMusculo = 0.0;
    edadMetabolica = 0.0;
    porcentajeGrasaVisceral = 0.0;
    cintura = 0.0;
    cadera = 0.0;
    pecho = 0.0;
    muslo = 0.0;
    imc = 0.0;
    clasificacion = "";
    altoRiesgo = false;
    vasosRecomendados = 0;
    proteinaRecomendada = 0.0;
}

Medicion::Medicion(fecha* fecha, cliente* cli, instructor* inst, double peso, double estatura,
    double porcentajeGrasa, double porcentajeMusculo, double edadMetabolica,
    double porcentajeGrasaVisceral, double cintura, double cadera, double pecho, double muslo) {
    this->fechaMedicion = fecha;
    this->clienteRef = cli;
    this->instructorRef = inst;
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = porcentajeGrasa;
    this->porcentajeMusculo = porcentajeMusculo;
    this->edadMetabolica = edadMetabolica;
    this->porcentajeGrasaVisceral = porcentajeGrasaVisceral;
    this->cintura = cintura;
    this->cadera = cadera;
    this->pecho = pecho;
    this->muslo = muslo;

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
double Medicion::getEdadMetabolica() const { return edadMetabolica; }
double Medicion::getPorcentajeGrasaVisceral() const { return porcentajeGrasaVisceral; }
double Medicion::getCintura() const { return cintura; }
double Medicion::getCadera() const { return cadera; }
double Medicion::getPecho() const { return pecho; }
double Medicion::getMuslo() const { return muslo; }
double Medicion::getIMC() const { return imc; }
string Medicion::getClasificacion() const { return clasificacion; }
bool Medicion::getAltoRiesgo() const { return altoRiesgo; }
int Medicion::getVasosRecomendados() const { return vasosRecomendados; }
double Medicion::getProteinaRecomendada() const { return proteinaRecomendada; }

// Setters
void Medicion::setFecha(fecha* fecha) { fechaMedicion = fecha; }
void Medicion::setCliente(cliente* cli) { clienteRef = cli; }
void Medicion::setInstructor(instructor* inst) { instructorRef = inst; }
void Medicion::setPeso(double peso) { this->peso = peso; }
void Medicion::setEstatura(double estatura) { this->estatura = estatura; }
void Medicion::setPorcentajeGrasa(double porcentajeGrasa) { this->porcentajeGrasa = porcentajeGrasa; }
void Medicion::setPorcentajeMusculo(double porcentajeMusculo) { this->porcentajeMusculo = porcentajeMusculo; }
void Medicion::setEdadMetabolica(double edadMetabolica) { this->edadMetabolica = edadMetabolica; }
void Medicion::setPorcentajeGrasaVisceral(double porcentajeGrasaVisceral) { this->porcentajeGrasaVisceral = porcentajeGrasaVisceral; }
void Medicion::setCintura(double cintura) { this->cintura = cintura; }
void Medicion::setCadera(double cadera) { this->cadera = cadera; }
void Medicion::setPecho(double pecho) { this->pecho = pecho; }
void Medicion::setMuslo(double muslo) { this->muslo = muslo; }
void Medicion::setIMC(double imc) { this->imc = imc; }
void Medicion::setClasificacion(string clasificacion) { this->clasificacion = clasificacion; }
void Medicion::setAltoRiesgo(bool altoRiesgo) { this->altoRiesgo = altoRiesgo; }
void Medicion::setVasosRecomendados(int vasosRecomendados) { this->vasosRecomendados = vasosRecomendados; }
void Medicion::setProteinaRecomendada(double proteinaRecomendada) { this->proteinaRecomendada = proteinaRecomendada; }

// Métodos de cálculo
void Medicion::calcularIMC() {
    if (estatura > 0) {
        imc = peso / (estatura * estatura);
    }
    else {
        imc = 0.0;
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

void Medicion::calcularAltoRiesgo() {
    // Según el Ministerio de Salud[cite: 413], las personas con obesidad leve, media o mórbida son de alto riesgo
    altoRiesgo = (imc >= 30.00);
}

void Medicion::calcularVasosRecomendados() {
    vasosRecomendados = static_cast<int>(peso / 7.0); // Según el PDF [cite: 416]
}

void Medicion::calcularProteinaRecomendada() {
    // Asumimos que cliente y su método getSexo() existen
    if (clienteRef) {
        // La lógica de `haceEjercicio()` no está en el pdf, por lo tanto,
        // no se puede replicar la lógica original del código del usuario.
        // Se asume que el usuario realiza ejercicio para aplicar la recomendación del PDF.
        if (clienteRef->getSexo() == 'm') { // Asumiendo que 'm' es para masculino
            proteinaRecomendada = peso * 2.1; // Promedio entre 1.7 y 2.5
        }
        else { // Femenino
            proteinaRecomendada = peso * 1.7; // Promedio entre 1.6 y 1.8
        }
    }
    else {
        proteinaRecomendada = peso * 0.8; // Valor base de la OMS [cite: 414]
    }
}

void Medicion::calcularTodo() {
    calcularIMC();
    determinarClasificacion();
    calcularAltoRiesgo();
    calcularVasosRecomendados();
    calcularProteinaRecomendada();
}