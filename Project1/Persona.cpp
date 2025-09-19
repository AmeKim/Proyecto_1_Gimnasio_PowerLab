#include "Persona.h"

// Constructores
Persona::Persona(string nom, string ced, int numT, string cor, int dia, int mes, int anio)
    : nombre(nom), cedula(ced), numeroT(numT), correo(cor), fechaNacimiento(dia, mes, anio) {
}

Persona::Persona(string nom, string ced, int numT, string cor, const Fecha& fecha)
    : nombre(nom), cedula(ced), numeroT(numT), correo(cor), fechaNacimiento(fecha) {
}

Persona::Persona(string nom, string ced, int numT, string cor, const string& fechaStr)
    : nombre(nom), cedula(ced), numeroT(numT), correo(cor), fechaNacimiento(fechaStr) {
}

// Setters
void Persona::setNombre(string nom) {
    this->nombre = nom;
}

void Persona::setCedula(string ced) {
    this->cedula = ced;
}

void Persona::setNumeroT(int numT) {
    this->numeroT = numT;
}

void Persona::setCorreo(string cor) {
    this->correo = cor;
}

void Persona::setFechaNacimiento(int dia, int mes, int anio) {
    fechaNacimiento.setFecha(dia, mes, anio);
}

void Persona::setFechaNacimiento(const Fecha& fecha) {
    this->fechaNacimiento = fecha;
}

void Persona::setFechaNacimiento(const string& fechaStr) {
    fechaNacimiento.parsearFecha(fechaStr);
}

// Getters
string Persona::getNombre() const {
    return nombre;
}

string Persona::getCedula() const {
    return cedula;
}

int Persona::getNumeroT() const {
    return numeroT;
}

string Persona::getCorreo() const {
    return correo;
}

Fecha Persona::getFechaNacimiento() const {
    return fechaNacimiento;
}

int Persona::getEdad() const {
    return fechaNacimiento.calcularEdad(Fecha::fechaActual());
}

// Getters específicos de fecha
int Persona::getDia() const {
    return fechaNacimiento.getDia();
}

int Persona::getMes() const {
    return fechaNacimiento.getMes();
}

int Persona::getAnio() const {
    return fechaNacimiento.getAnio();
}

void Persona::mostrarDatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Numero de Telefono: " << numeroT << endl;
    cout << "Correo Electronico: " << correo << endl;
    cout << "Fecha de Nacimiento: " << fechaNacimiento.toString() << endl;
    if (fechaNacimiento.esFechaInicializada() && fechaNacimiento.esFechaValida()) {
        cout << "Edad: " << getEdad() << " años" << endl;
    }
}

string Persona::toString() {
    stringstream s;
    s << "Nombre: " << nombre << endl;
    s << "Cedula: " << cedula << endl;
    s << "Telefono: " << numeroT << endl;
    s << "Correo: " << correo << endl;
    s << "Fecha de Nacimiento: " << fechaNacimiento.toString() << endl;
    if (fechaNacimiento.esFechaInicializada() && fechaNacimiento.esFechaValida()) {
        s << "Edad: " << getEdad() << " años" << endl;
    }
    return s.str();
}

Persona::~Persona() {
}