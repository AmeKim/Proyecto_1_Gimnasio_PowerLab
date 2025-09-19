#include "reporteM.h"
#include <iomanip>
#include <cmath>

reporteM::reporteM() {
    clienteRef = nullptr;
    instructorRef = nullptr;
    fechaMedicion = Fecha();
    peso = 0.0;
    estatura = 0.0;
    porcentajeGrasa = 0.0;
    porcentajeMusculo = 0.0;
    edadMetabolica = 0;
    porcentajeGrasaVisceral = 0.0;
    medidaCintura = 0.0;
    medidaCadera = 0.0;
    medidaPecho = 0.0;
    medidaMuslo = 0.0;
    imc = 0.0;
    clasificacionIMC = "";
    altoRiesgo = false;
    vasosAgua = 0;
    proteinaRecomendada = 0.0;
}

reporteM::reporteM(cliente* cli, instructor* inst, const Fecha& fecha, double peso, double estatura,
    double pGrasa, double pMusculo, int edadMet, double grasaVisc,
    double cintura, double cadera, double pecho, double muslo) {
    this->clienteRef = cli;
    this->instructorRef = inst;
    this->fechaMedicion = fecha;
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = pGrasa;
    this->porcentajeMusculo = pMusculo;
    this->edadMetabolica = edadMet;
    this->porcentajeGrasaVisceral = grasaVisc;
    this->medidaCintura = cintura;
    this->medidaCadera = cadera;
    this->medidaPecho = pecho;
    this->medidaMuslo = muslo;

    // Calcular valores automáticos
    calcularTodosLosValores();
}

reporteM::~reporteM() {
    // No eliminamos las referencias porque son manejadas por otros contenedores
    clienteRef = nullptr;
    instructorRef = nullptr;
}

void reporteM::calcularIMC() {
    if (estatura > 0) {
        imc = peso / (estatura * estatura);
    }
    else {
        imc = 0.0;
    }
}

void reporteM::determinarClasificacionIMC() {
    if (imc < 16.00) {
        clasificacionIMC = "Delgadez severa";
    }
    else if (imc >= 16.00 && imc <= 16.99) {
        clasificacionIMC = "Delgadez moderada";
    }
    else if (imc >= 17.00 && imc <= 18.49) {
        clasificacionIMC = "Delgadez leve";
    }
    else if (imc >= 18.50 && imc <= 24.99) {
        clasificacionIMC = "Normal";
    }
    else if (imc >= 25.00 && imc <= 29.99) {
        clasificacionIMC = "Pre-obesidad";
    }
    else if (imc >= 30.00 && imc <= 34.99) {
        clasificacionIMC = "Obesidad leve";
    }
    else if (imc >= 35.00 && imc <= 39.99) {
        clasificacionIMC = "Obesidad media";
    }
    else if (imc >= 40.00) {
        clasificacionIMC = "Obesidad mórbida";
    }
}

void reporteM::determinarAltoRiesgo() {
    // Alto riesgo si tiene obesidad leve, media o mórbida
    altoRiesgo = (imc >= 30.00);
}

void reporteM::calcularVasosAgua() {
    // Dividir peso en kilos entre 7 para vasos de 250ml
    vasosAgua = static_cast<int>(ceil(peso / 7.0));
}

void reporteM::calcularProteinaRecomendada() {
    if (!clienteRef) {
        proteinaRecomendada = 0.0;
        return;
    }

    // Proteína base: 0.8g por kg de peso
    double proteinaBase = peso * 0.8;

    // Si hace ejercicio, aumentar según el sexo
    // Asumimos que todos los clientes del gimnasio hacen ejercicio
    char sexo = clienteRef->getSexo();
    if (sexo == 'M' || sexo == 'm') {
        // Hombre que hace ejercicio: 1.7 - 2.5g por kg (usamos 2.1 como promedio)
        proteinaRecomendada = peso * 2.1;
    }
    else if (sexo == 'F' || sexo == 'f') {
        // Mujer que hace ejercicio: 1.6 - 1.8g por kg (usamos 1.7 como promedio)
        proteinaRecomendada = peso * 1.7;
    }
    else {
        // Si no se especifica el sexo, usar valor base
        proteinaRecomendada = proteinaBase;
    }
}

void reporteM::calcularTodosLosValores() {
    calcularIMC();
    determinarClasificacionIMC();
    determinarAltoRiesgo();
    calcularVasosAgua();
    calcularProteinaRecomendada();
}

// Getters
cliente* reporteM::getCliente() const { return clienteRef; }
instructor* reporteM::getInstructor() const { return instructorRef; }
Fecha reporteM::getFechaMedicion() const { return fechaMedicion; }
double reporteM::getPeso() const { return peso; }
double reporteM::getEstatura() const { return estatura; }
double reporteM::getPorcentajeGrasa() const { return porcentajeGrasa; }
double reporteM::getPorcentajeMusculo() const { return porcentajeMusculo; }
int reporteM::getEdadMetabolica() const { return edadMetabolica; }
double reporteM::getPorcentajeGrasaVisceral() const { return porcentajeGrasaVisceral; }
double reporteM::getMedidaCintura() const { return medidaCintura; }
double reporteM::getMedidaCadera() const { return medidaCadera; }
double reporteM::getMedidaPecho() const { return medidaPecho; }
double reporteM::getMedidaMuslo() const { return medidaMuslo; }
double reporteM::getIMC() const { return imc; }
string reporteM::getClasificacionIMC() const { return clasificacionIMC; }
bool reporteM::getAltoRiesgo() const { return altoRiesgo; }
int reporteM::getVasosAgua() const { return vasosAgua; }
double reporteM::getProteinaRecomendada() const { return proteinaRecomendada; }

// Setters
void reporteM::setCliente(cliente* cli) {
    clienteRef = cli;
    calcularProteinaRecomendada(); // Recalcular porque depende del sexo del cliente
}

void reporteM::setInstructor(instructor* inst) { instructorRef = inst; }
void reporteM::setFechaMedicion(const Fecha& fecha) { fechaMedicion = fecha; }

void reporteM::setPeso(double peso) {
    this->peso = peso;
    calcularIMC();
    determinarClasificacionIMC();
    determinarAltoRiesgo();
    calcularVasosAgua();
    calcularProteinaRecomendada();
}

void reporteM::setEstatura(double estatura) {
    this->estatura = estatura;
    calcularIMC();
    determinarClasificacionIMC();
    determinarAltoRiesgo();
}

void reporteM::setPorcentajeGrasa(double pGrasa) { porcentajeGrasa = pGrasa; }
void reporteM::setPorcentajeMusculo(double pMusculo) { porcentajeMusculo = pMusculo; }
void reporteM::setEdadMetabolica(int edadMet) { edadMetabolica = edadMet; }
void reporteM::setPorcentajeGrasaVisceral(double grasaVisc) { porcentajeGrasaVisceral = grasaVisc; }
void reporteM::setMedidaCintura(double cintura) { medidaCintura = cintura; }
void reporteM::setMedidaCadera(double cadera) { medidaCadera = cadera; }
void reporteM::setMedidaPecho(double pecho) { medidaPecho = pecho; }
void reporteM::setMedidaMuslo(double muslo) { medidaMuslo = muslo; }

string reporteM::toString() const {
    stringstream s;
    s << fixed << setprecision(2);
    s << "Fecha: " << fechaMedicion.toString() << " | ";
    s << "Peso: " << peso << " kg | ";
    s << "IMC: " << imc;
    return s.str();
}

string reporteM::toStringDetallado() const {
    stringstream s;
    s << fixed << setprecision(2);
    s << "=============== Detalle Medición ===============\n";
    s << "Fecha: " << fechaMedicion.toString() << "\n";
    s << "Peso (kg): " << peso << "\n";
    s << "Estatura (m): " << estatura << "\n";
    s << "% de grasa: " << porcentajeGrasa << "\n";
    s << "% de músculo: " << porcentajeMusculo << "\n";
    if (edadMetabolica > 0) {
        s << "Edad metabólica: " << edadMetabolica << " años\n";
    }
    if (porcentajeGrasaVisceral > 0) {
        s << "% de grasa visceral: " << porcentajeGrasaVisceral << "\n";
    }
    if (medidaCintura > 0) {
        s << "Medida cintura: " << medidaCintura << " cm\n";
    }
    if (medidaCadera > 0) {
        s << "Medida cadera: " << medidaCadera << " cm\n";
    }
    if (medidaPecho > 0) {
        s << "Medida pecho: " << medidaPecho << " cm\n";
    }
    if (medidaMuslo > 0) {
        s << "Medida muslo: " << medidaMuslo << " cm\n";
    }
    s << "IMC: " << imc << "\n";
    s << "Clasificación: " << clasificacionIMC << "\n";
    s << "Alto Riesgo: " << (altoRiesgo ? "SÍ" : "NO") << "\n";
    s << "Cantidad de vasos recomendados: " << vasosAgua << "\n";
    s << "Cantidad de proteína recomendada: " << proteinaRecomendada << " gramos\n";
    return s.str();
}

void reporteM::mostrar() const {
    cout << toString() << endl;
}

void reporteM::mostrarDetallado() const {
    cout << toStringDetallado() << endl;
}