#include "Medición.h"

Medicion::Medicion(const Fecha& fecha, double peso, double estatura,
    double porcGrasa, double porcMusculo) {
    this->fecha = new Fecha(fecha);
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = porcGrasa;
    this->porcentajeMusculo = porcMusculo;
    this->cintura = 0;
    this->cadera = 0;
    this->pecho = 0;
    this->muslo = 0;

    calcularIMC();
    calcularClasificacion();
}

Medicion::Medicion() {
    this->fecha = new Fecha();
    this->peso = 0;
    this->estatura = 0;
    this->porcentajeGrasa = 0;
    this->porcentajeMusculo = 0;
    this->imc = 0;
    this->clasificacion = "";
    this->altoRiesgo = false;
    this->vasosAgua = 0;
    this->proteinaRecomendada = 0;
    this->cintura = 0;
    this->cadera = 0;
    this->pecho = 0;
    this->muslo = 0;
}

Medicion::~Medicion() {
    delete fecha;
}

// Getters
Fecha* Medicion::getFecha() const { return fecha; }
double Medicion::getPeso() const { return peso; }
double Medicion::getEstatura() const { return estatura; }
double Medicion::getPorcentajeGrasa() const { return porcentajeGrasa; }
double Medicion::getPorcentajeMusculo() const { return porcentajeMusculo; }
double Medicion::getIMC() const { return imc; }
string Medicion::getClasificacion() const { return clasificacion; }
bool Medicion::getAltoRiesgo() const { return altoRiesgo; }
int Medicion::getVasosAgua() const { return vasosAgua; }
double Medicion::getProteinaRecomendada() const { return proteinaRecomendada; }

// Setters
void Medicion::setPeso(double peso) {
    this->peso = peso;
    calcularIMC();
    calcularClasificacion();
}

void Medicion::setEstatura(double estatura) {
    this->estatura = estatura;
    calcularIMC();
    calcularClasificacion();
}

void Medicion::setPorcentajeGrasa(double porc) {
    this->porcentajeGrasa = porc;
}

void Medicion::setPorcentajeMusculo(double porc) {
    this->porcentajeMusculo = porc;
}

void Medicion::setMedidasCorporales(double cintura, double cadera, double pecho, double muslo) {
    this->cintura = cintura;
    this->cadera = cadera;
    this->pecho = pecho;
    this->muslo = muslo;
}

// Cálculos
void Medicion::calcularIMC() {
    if (estatura > 0) {
        imc = peso / (estatura * estatura);
    }
    else {
        imc = 0;
    }
}

void Medicion::calcularClasificacion() {
    if (imc < 18.5) {
        clasificacion = "Bajo peso";
        altoRiesgo = true;
    }
    else if (imc < 25) {
        clasificacion = "Peso normal";
        altoRiesgo = false;
    }
    else if (imc < 30) {
        clasificacion = "Sobrepeso";
        altoRiesgo = true;
    }
    else {
        clasificacion = "Obesidad";
        altoRiesgo = true;
    }
}

void Medicion::calcularRecomendaciones(char sexo, bool haceEjercicio) {
    // Cálculo de vasos de agua recomendados (basado en el peso)
    vasosAgua = static_cast<int>(peso * 0.033); // 33ml por kg de peso
    if (haceEjercicio) vasosAgua += 2; // 2 vasos extra si hace ejercicio

    // Cálculo de proteína recomendada
    if (haceEjercicio) {
        proteinaRecomendada = peso * 1.6; // 1.6g por kg si hace ejercicio
    }
    else {
        proteinaRecomendada = peso * 0.8; // 0.8g por kg si no hace ejercicio
    }

    // Ajuste por sexo
    if (sexo == 'F' || sexo == 'f') {
        proteinaRecomendada *= 0.9; // Ajuste para mujeres
    }
}

// Utilidades
string Medicion::toString() const {
    stringstream s;
    s << "Fecha: " << fecha->toString() << endl;
    s << "Peso: " << endl;
    s<<
   
}

string Medicion::toStringDetallado() const {
    stringstream ss;
    ss << toString()
        << "Porcentaje de grasa: " << fixed << setprecision(1) << porcentajeGrasa << "%" << endl
        << "Porcentaje muscular: " << porcentajeMusculo << "%" << endl
        << "Recomendaciones:" << endl
        << "- Vasos de agua: " << vasosAgua << " vasos al día" << endl
        << "- Proteína: " << fixed << setprecision(1) << proteinaRecomendada << " g al día" << endl;

    if (cintura > 0) {
        ss << "Medidas corporales:" << endl
            << "- Cintura: " << cintura << " cm" << endl
            << "- Cadera: " << cadera << " cm" << endl
            << "- Pecho: " << pecho << " cm" << endl
            << "- Muslo: " << muslo << " cm" << endl;
    }

    return ss.str();
}

string Medicion::toStringResumen() const {
    stringstream ss;
    ss << fecha->toString() << " | "
        << fixed << setprecision(1) << peso << "kg | "
        << "IMC: " << imc << " | "
        << clasificacion;
    return ss.str();
}