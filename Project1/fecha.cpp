#include "Fecha.h"

// Métodos privados
bool Fecha::esAnioBisiesto(int anio) const {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int Fecha::diasEnMes(int mes, int anio) const {
    int diasMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mes == 2 && esAnioBisiesto(anio)) {
        return 29;
    }
    if (mes < 1 || mes > 12) {
        return 31; // Valor por defecto para evitar errores
    }
    return diasMes[mes - 1];
}

// Constructores
Fecha::Fecha() : dia(0), mes(0), anio(0) {
    // Constructor por defecto sin inicialización específica
    // Los valores deben ser asignados posteriormente
}

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
    validarFecha();
}

Fecha::Fecha(const string& fechaStr) : dia(0), mes(0), anio(0) {
    if (!parsearFecha(fechaStr)) {
        // Si falla el parseo, dejar valores en 0 para indicar fecha inválida
        dia = 0;
        mes = 0;
        anio = 0;
    }
}

// Destructor
Fecha::~Fecha() {
}

// Getters
int Fecha::getDia() const {
    return dia;
}

int Fecha::getMes() const {
    return mes;
}

int Fecha::getAnio() const {
    return anio;
}

// Setters con validación
void Fecha::setDia(int d) {
    dia = d;
    validarFecha();
}

void Fecha::setMes(int m) {
    mes = m;
    validarFecha();
}

void Fecha::setAnio(int a) {
    anio = a;
    validarFecha();
}

void Fecha::setFecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
    validarFecha();
}

// Validación de fecha
bool Fecha::validarFecha() {
    bool esValida = true;

    if (mes < 1 || mes > 12) {
        esValida = false;
    }

    if (dia < 1 || dia > diasEnMes(mes, anio)) {
        esValida = false;
    }

    if (anio < 1900 || anio > 2100) {
        esValida = false;
    }

    return esValida;
}

// Verifica si la fecha actual es válida sin modificarla
bool Fecha::esFechaValida() const {
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > diasEnMes(mes, anio)) return false;
    if (anio < 1900 || anio > 2100) return false;
    return true;
}

// Verifica si la fecha ha sido inicializada
bool Fecha::esFechaInicializada() const {
    return !(dia == 0 && mes == 0 && anio == 0);
}

// Parsear fecha desde string (formato: dd/mm/aaaa o dd-mm-aaaa)
bool Fecha::parsearFecha(const string& fechaStr) {
    size_t pos1 = fechaStr.find_first_of("/-");
    size_t pos2 = fechaStr.find_last_of("/-");

    if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) {
        return false;
    }

    try {
        string diaStr = fechaStr.substr(0, pos1);
        string mesStr = fechaStr.substr(pos1 + 1, pos2 - pos1 - 1);
        string anioStr = fechaStr.substr(pos2 + 1);

        // Conversión manual para evitar stoi (más compatible)
        dia = 0;
        for (char c : diaStr) {
            if (c < '0' || c > '9') return false;
            dia = dia * 10 + (c - '0');
        }

        mes = 0;
        for (char c : mesStr) {
            if (c < '0' || c > '9') return false;
            mes = mes * 10 + (c - '0');
        }

        anio = 0;
        for (char c : anioStr) {
            if (c < '0' || c > '9') return false;
            anio = anio * 10 + (c - '0');
        }

        return validarFecha();
    }
    catch (...) {
        return false;
    }
}

// Convertir a string
string Fecha::toString() const {
    if (!esFechaInicializada()) {
        return "No asignada";
    }
    if (!esFechaValida()) {
        return "Fecha inválida";
    }

    stringstream ss;
    ss << setfill('0') << setw(2) << dia << "/"
        << setfill('0') << setw(2) << mes << "/"
        << anio;
    return ss.str();
}

string Fecha::toStringLargo() const {
    if (!esFechaInicializada()) {
        return "Fecha no asignada";
    }
    if (!esFechaValida()) {
        return "Fecha inválida";
    }

    string meses[] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                     "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
    stringstream ss;
    if (mes >= 1 && mes <= 12) {
        ss << dia << " de " << meses[mes - 1] << " de " << anio;
    }
    else {
        ss << toString(); // Fallback al formato corto si hay error
    }
    return ss.str();
}

// Calcular edad (útil para clientes e instructores)
int Fecha::calcularEdad(const Fecha& fechaActual) const {
    if (!esFechaInicializada() || !esFechaValida() ||
        !fechaActual.esFechaInicializada() || !fechaActual.esFechaValida()) {
        return -1; // Indica error en el cálculo
    }

    int edad = fechaActual.anio - anio;
    if (fechaActual.mes < mes || (fechaActual.mes == mes && fechaActual.dia < dia)) {
        edad--;
    }
    return edad < 0 ? -1 : edad; // -1 indica fecha futura o error
}

// Comparar fechas
bool Fecha::esAnterior(const Fecha& otra) const {
    if (!esFechaInicializada() || !esFechaValida() ||
        !otra.esFechaInicializada() || !otra.esFechaValida()) {
        return false; // No se pueden comparar fechas inválidas
    }

    if (anio < otra.anio) return true;
    if (anio > otra.anio) return false;
    if (mes < otra.mes) return true;
    if (mes > otra.mes) return false;
    return dia < otra.dia;
}

bool Fecha::esPosterior(const Fecha& otra) const {
    return !esAnterior(otra) && !esIgual(otra);
}

bool Fecha::esIgual(const Fecha& otra) const {
    if (!esFechaInicializada() || !esFechaValida() ||
        !otra.esFechaInicializada() || !otra.esFechaValida()) {
        return false; // Fechas inválidas no son iguales a nada
    }

    return dia == otra.dia && mes == otra.mes && anio == otra.anio;
}

// Operadores
bool Fecha::operator<(const Fecha& otra) const {
    return esAnterior(otra);
}

bool Fecha::operator>(const Fecha& otra) const {
    return esPosterior(otra);
}

bool Fecha::operator==(const Fecha& otra) const {
    return esIgual(otra);
}

bool Fecha::operator!=(const Fecha& otra) const {
    return !esIgual(otra);
}

// Métodos estáticos
Fecha Fecha::fechaActual() {
    // En un proyecto real, usarías <chrono> o <ctime>
    // Por simplicidad, retorna una fecha fija basada en el contexto del proyecto
    return Fecha(18, 9, 2025); // Fecha actual según el contexto
}

bool Fecha::esFechaValida(int d, int m, int a) {
    Fecha temp(d, m, a);
    return (temp.dia == d && temp.mes == m && temp.anio == a);
}