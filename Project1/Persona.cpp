#include "Persona.h"

Persona::Persona(string nombre, string cedula, string telefono, string correo, int dia, int mes, int anio) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = new fecha(dia, mes, anio);
}

Persona::Persona(string nombre, string cedula, string telefono, string correo, fecha* fecha) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
	this->fechaNacimiento = fecha;
}

Persona::Persona(string nombre, string cedula, string telefono, string correo, string fechaStr) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = new fecha(fechaStr);
}

Persona::Persona() {
    this->nombre = "";
    this->cedula = "";
    this->telefono = "";
    this->correo = "";
    this->fechaNacimiento = new fecha();
}

Persona::~Persona() {
    delete fechaNacimiento;
}

// Getters
string Persona::getNombre() const { return nombre; }
string Persona::getCedula() const { return cedula; }
string Persona::getTelefono() const { return telefono; }
string Persona::getCorreo() const { return correo; }
fecha* Persona::getFechaNacimiento() const { return fechaNacimiento; }

int Persona::getEdad() const {
    if (fechaNacimiento) {
       return fechaNacimiento->calcularEdad();
    }
    return 0;
}

// Setters
void Persona::setNombre(string nombre) { this->nombre = nombre; }
void Persona::setCedula(string cedula) { this->cedula = cedula; }
void Persona::setTelefono(string telefono) { this->telefono = telefono; }
void Persona::setCorreo(string correo) { this->correo = correo; }

void Persona::setFechaNacimiento(fecha* fecha) {
    if (fechaNacimiento) delete fechaNacimiento;
	fechaNacimiento = fecha;
}

void Persona::setFechaNacimiento(int dia, int mes, int anio) {
    if (fechaNacimiento) delete fechaNacimiento;
    fechaNacimiento = new fecha(dia, mes, anio);
}

void Persona::setFechaNacimiento(string fechaStr) {
    if (fechaNacimiento) delete fechaNacimiento;
    fechaNacimiento = new fecha(fechaStr);
}

string Persona::toString() {
    stringstream s;
    s << "Nombre: " << nombre << "\n";
    s << "Cedula: " << cedula << "\n";
    s << "Telefono: " << telefono << "\n";
    s << "Correo: " << correo << "\n";
    if (fechaNacimiento) {
        s << "Fecha de nacimiento: " << fechaNacimiento->toString() << "\n";
        s << "Edad: " << getEdad() << " años\n";
    }
    return s.str();
}