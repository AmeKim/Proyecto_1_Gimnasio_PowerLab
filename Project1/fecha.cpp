#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::Fecha(const string& fechaStr) {
    // Parsear fecha del formato "dd/mm/aaaa"
    size_t pos1 = fechaStr.find('/');
    size_t pos2 = fechaStr.find('/', pos1 + 1);

    if (pos1 != string::npos && pos2 != string::npos) {
        dia = stoi(fechaStr.substr(0, pos1));
        mes = stoi(fechaStr.substr(pos1 + 1, pos2 - pos1 - 1));
        anio = stoi(fechaStr.substr(pos2 + 1));
    }
    else {
        dia = 1;
        mes = 1;
        anio = 2000;
    }
}

Fecha::Fecha(const Fecha& otra) {
    this->dia = otra.dia;
    this->mes = otra.mes;
    this->anio = otra.anio;
}

Fecha::Fecha() {
    // Obtener fecha actual
    time_t t = time(0);
    tm now_tm;
    localtime_s(&now_tm, &t);
    dia = now_tm.tm_mday;
    mes = now_tm.tm_mon + 1;
    anio = now_tm.tm_year + 1900;
}

// Getters
int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAnio() const { return anio; }

// Setters
void Fecha::setDia(int dia) {
    if (dia >= 1 && dia <= 31) this->dia = dia;
}

void Fecha::setMes(int mes) {
    if (mes >= 1 && mes <= 12) this->mes = mes;
}

void Fecha::setAnio(int anio) {
    if (anio >= 1900 && anio <= 2100) this->anio = anio;
}

void Fecha::setFecha(int dia, int mes, int anio) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

void Fecha::setFecha(const string& fechaStr) {
    size_t pos1 = fechaStr.find('/');
    size_t pos2 = fechaStr.find('/', pos1 + 1);

    if (pos1 != string::npos && pos2 != string::npos) {
        setDia(stoi(fechaStr.substr(0, pos1)));
        setMes(stoi(fechaStr.substr(pos1 + 1, pos2 - pos1 - 1)));
        setAnio(stoi(fechaStr.substr(pos2 + 1)));
    }
}

string Fecha::toString() const {
    stringstream s;
    s << (dia < 10 ? "0" : "") << dia << "/";
    s << (mes < 10 ? "0" : "") << mes << "/";
    s << anio;
    return s.str();
}

bool Fecha::esValida() const {
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > diasEnMes(mes, anio)) return false;
    if (anio < 1900 || anio > 2100) return false;
    return true;
}

int Fecha::calcularEdad(const Fecha& fechaActual) const {
    int edad = fechaActual.anio - anio;
    if (fechaActual.mes < mes || (fechaActual.mes == mes && fechaActual.dia < dia)) {
        edad--;
    }
    return edad;
}

int Fecha::diasTranscurridos(const Fecha& otraFecha) const {
    // Implementación simplificada
    int dias = (otraFecha.anio - anio) * 365;
    dias += (otraFecha.mes - mes) * 30;
    dias += (otraFecha.dia - dia);
    return abs(dias);
}

bool Fecha::esMayor(const Fecha& otraFecha) const {
    if (anio > otraFecha.anio) return true;
    if (anio < otraFecha.anio) return false;
    if (mes > otraFecha.mes) return true;
    if (mes < otraFecha.mes) return false;
    return dia > otraFecha.dia;
}

bool Fecha::esMenor(const Fecha& otraFecha) const {
    return !esMayor(otraFecha) && !esIgual(otraFecha);
}

bool Fecha::esIgual(const Fecha& otraFecha) const {
    return dia == otraFecha.dia && mes == otraFecha.mes && anio == otraFecha.anio;
}

Fecha Fecha::fechaActual() {
    return Fecha();
}

bool Fecha::esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int Fecha::diasEnMes(int mes, int anio) {
    int dias[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mes == 2 && esBisiesto(anio)) return 29;
    return dias[mes - 1];
}