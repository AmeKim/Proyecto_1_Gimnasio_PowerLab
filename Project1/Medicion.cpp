#include "Medicion.h"

Medicion::Medicion() {
    clienteRef = nullptr;
    instructorRef = nullptr;
    fechaMedicion = new fecha();
    peso = 0.0;
    estatura = 0.0;
    porcentajeGrasa = 0.0;
    porcentajeMusculo = 0.0;
    edadMetabolica = 0;
    porcentajeGrasaVisceral = 0.0;
    cintura = 0.0;
    cadera = 0.0;
    pecho = 0.0;
    muslo = 0.0;
    imc = 0.0;
    clasificacion = "";
    altoRiesgo = false;
    vasosAgua = 0;
    proteina = 0.0;
}

Medicion::Medicion(cliente* cli, instructor* inst, fecha* fecha, double peso, double estatura, double pGrasa, double pMusculo, int edadMet, double grasaVisc, double cintura, double cadera, double pecho, double muslo) {
    this->clienteRef = cli;
    this->instructorRef = inst;
    this->fechaMedicion = fecha;
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = pGrasa;
    this->porcentajeMusculo = pMusculo;
    this->edadMetabolica = edadMet;
    this->porcentajeGrasaVisceral = grasaVisc;
    this->cintura = cintura;
    this->cadera = cadera;
    this->pecho = pecho;
    this->muslo = muslo;

    // Realizar todos los cálculos automáticamente
    calcularIMC();
    determinarClasificacion();
    calcularVasosAgua();
    calcularProteina();
}

Medicion::~Medicion() {
    delete fechaMedicion;
}

// Métodos privados para cálculos
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
        altoRiesgo = false;
    }
    else if (imc <= 16.99) {
        clasificacion = "Delgadez moderada";
        altoRiesgo = false;
    }
    else if (imc <= 18.49) {
        clasificacion = "Delgadez leve";
        altoRiesgo = false;
    }
    else if (imc <= 24.99) {
        clasificacion = "Normal";
        altoRiesgo = false;
    }
    else if (imc <= 29.99) {
        clasificacion = "Pre-obesidad";
        altoRiesgo = false;
    }
    else if (imc <= 34.99) {
        clasificacion = "Obesidad leve";
        altoRiesgo = true;
    }
    else if (imc <= 39.99) {
        clasificacion = "Obesidad media";
        altoRiesgo = true;
    }
    else {
        clasificacion = "Obesidad mórbida";
        altoRiesgo = true;
    }
}

void Medicion::calcularVasosAgua() {
    vasosAgua = (int)(peso / 7.0);
}

void Medicion::calcularProteina() {
    if (clienteRef != nullptr) {
        char sexo = clienteRef->getSexo();
        if (sexo == 'M' || sexo == 'm') {
            // Hombre que hace ejercicio: entre 1.7 - 2.5 (usamos promedio 2.1)
            proteina = peso * 2.1;
        }
        else if (sexo == 'F' || sexo == 'f') {
            // Mujer que hace ejercicio: entre 1.6 - 1.8 (usamos promedio 1.7)
            proteina = peso * 1.7;
        }
        else {
            // Base general según OMS: 0.8 gramos por kg
            proteina = peso * 0.8;
        }
    }
    else {
        // Si no hay referencia al cliente, usar valor base
        proteina = peso * 0.8;
    }
}

// Getters para obtener información del cliente e instructor
string Medicion::getNombreCliente() const {
    if (clienteRef != nullptr) {
        return clienteRef->getNombre();
    }
    return "Cliente no asignado";
}

string Medicion::getIdCliente() const {
    if (clienteRef != nullptr) {
        return clienteRef->getCedula();
    }
    return "ID no disponible";
}

string Medicion::getNombreInstructor() const {
    if (instructorRef != nullptr) {
        return instructorRef->getNombre();
    }
    return "Instructor no asignado";
}

char Medicion::getSexoCliente() const {
    if (clienteRef != nullptr) {
        return clienteRef->getSexo();
    }
    return 'M'; // Valor por defecto
}

// Getters para datos de medición ingresados
fecha* Medicion::getFechaMedicion() const {
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

int Medicion::getEdadMetabolica() const {
    return edadMetabolica;
}

double Medicion::getPorcentajeGrasaVisceral() const {
    return porcentajeGrasaVisceral;
}

// Getters para medidas corporales
double Medicion::getCintura() const {
    return cintura;
}

double Medicion::getCadera() const {
    return cadera;
}

double Medicion::getPecho() const {
    return pecho;
}

double Medicion::getMuslo() const {
    return muslo;
}

// Getters para datos calculados
double Medicion::getIMC() const {
    return imc;
}

string Medicion::getClasificacion() const {
    return clasificacion;
}

bool Medicion::esAltoRiesgo() const {
    return altoRiesgo;
}

int Medicion::getVasosAgua() const {
    return vasosAgua;
}

double Medicion::getProteina() const {
    return proteina;
}

// Getters para referencias
cliente* Medicion::getCliente() const {
    return clienteRef;
}

instructor* Medicion::getInstructor() const {
    return instructorRef;
}

// Setters para datos de medición
void Medicion::setFechaMedicion(fecha* fecha) {
    delete fechaMedicion;
    fechaMedicion = fecha;
}

void Medicion::setPeso(double peso) {
    this->peso = peso;
    calcularIMC();
    determinarClasificacion();
    calcularVasosAgua();
    calcularProteina();
}

void Medicion::setEstatura(double estatura) {
    this->estatura = estatura;
    calcularIMC();
    determinarClasificacion();
}

void Medicion::setPorcentajeGrasa(double pGrasa) {
    this->porcentajeGrasa = pGrasa;
}

void Medicion::setPorcentajeMusculo(double pMusculo) {
    this->porcentajeMusculo = pMusculo;
}

void Medicion::setEdadMetabolica(int edad) {
    this->edadMetabolica = edad;
}

void Medicion::setPorcentajeGrasaVisceral(double grasaVisc) {
    this->porcentajeGrasaVisceral = grasaVisc;
}

// Setters para medidas corporales
void Medicion::setCintura(double cintura) {
    this->cintura = cintura;
}

void Medicion::setCadera(double cadera) {
    this->cadera = cadera;
}

void Medicion::setPecho(double pecho) {
    this->pecho = pecho;
}

void Medicion::setMuslo(double muslo) {
    this->muslo = muslo;
}

void Medicion::actualizarCalculos() {
    calcularIMC();
    determinarClasificacion();
    calcularVasosAgua();
    calcularProteina();
}