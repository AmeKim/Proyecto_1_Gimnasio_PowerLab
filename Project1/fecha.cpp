#include "fecha.h"

fecha::fecha() {
    dia = 1;
    mes = 1;
    anio = 2025;
}

fecha::fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

fecha::fecha(const string& fechaStr) {
    // Parsear formato "dd/mm/yyyy"
    int pos1 = fechaStr.find('/');
    int pos2 = fechaStr.find('/', pos1 + 1);

    if (pos1 != string::npos && pos2 != string::npos) {
        dia = stoi(fechaStr.substr(0, pos1));
        mes = stoi(fechaStr.substr(pos1 + 1, pos2 - pos1 - 1));
        anio = stoi(fechaStr.substr(pos2 + 1));
    }
    else {
        dia = 1;
        mes = 1;
        anio = 2025;
    }
}

fecha::~fecha() {}

int fecha::getDia() const { return dia; }
int fecha::getMes() const { return mes; }
int fecha::getAnio() const { return anio; }

void fecha::setDia(int dia) { this->dia = dia; }
void fecha::setMes(int mes) { this->mes = mes; }
void fecha::setAnio(int anio) { this->anio = anio; }

void fecha::setFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

void fecha::setFecha(const string& fechaStr) {
    int pos1 = fechaStr.find('/');
    int pos2 = fechaStr.find('/', pos1 + 1);

    if (pos1 != string::npos && pos2 != string::npos) {
        dia = stoi(fechaStr.substr(0, pos1));
        mes = stoi(fechaStr.substr(pos1 + 1, pos2 - pos1 - 1));
        anio = stoi(fechaStr.substr(pos2 + 1));
    }
}

bool fecha::esValida() const {
    if (mes < 1 || mes > 12) return false;
    if (dia < 1) return false;

    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Año bisiesto
    if (mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))) {
        diasPorMes[1] = 29;
    }

    return dia <= diasPorMes[mes - 1];
}

int fecha::calcularEdad() const {
    // Año actual aproximado para el cálculo
    int anioActual = 2025;
    int mesActual = 9;
    int diaActual = 21;

    int edad = anioActual - anio;

    if (mes > mesActual || (mes == mesActual && dia > diaActual)) {
        edad--;
    }

    return edad;
}

string fecha::toString() const {
    stringstream s;
    if (dia < 10) s << "0";
    s << dia << "/";
    if (mes < 10) s << "0";
    s << mes << "/" << anio;
    return s.str();
}

void fecha::mostrar() const {
    cout << toString() << endl;
}

bool fecha::operator==(const fecha& otra) const {
    return (dia == otra.dia && mes == otra.mes && anio == otra.anio);
}

bool fecha::operator<(const fecha& otra) const {
    if (anio < otra.anio) return true;
    if (anio > otra.anio) return false;
    if (mes < otra.mes) return true;
    if (mes > otra.mes) return false;
    return dia < otra.dia;
}

bool fecha::operator>(const fecha& otra) const {
    return !(*this < otra || *this == otra);
}