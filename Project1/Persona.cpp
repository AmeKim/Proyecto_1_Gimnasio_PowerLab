#include "Persona.h"

Persona::Persona(string nombre, string cedula, string telefono, string correo, int dia, int mes, int anio) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = new Fecha(dia, mes, anio);
}

Persona::Persona(string nombre, string cedula, string telefono, string correo, const Fecha& fecha) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = new Fecha(fecha);
}

Persona::Persona(string nombre, string cedula, string telefono, string correo, const string& fechaStr) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = new Fecha(fechaStr);
}

Persona::Persona() {
    this->nombre = "";
    this->cedula = "";
    this->telefono = "";
    this->correo = "";
    this->fechaNacimiento = new Fecha();
}

Persona::~Persona() {
    delete fechaNacimiento;
}

// Getters
string Persona::getNombre() const { return nombre; }
string Persona::getCedula() const { return cedula; }
string Persona::getTelefono() const { return telefono; }
string Persona::getCorreo() const { return correo; }
Fecha* Persona::getFechaNacimiento() const { return fechaNacimiento; }

int Persona::getEdad() const {
    if (fechaNacimiento) {
        Fecha hoy; // Asumir que el constructor por defecto crea fecha actual
        return fechaNacimiento->calcularEdad(hoy);
    }
    return 0;
}

// Setters
void Persona::setNombre(string nombre) { this->nombre = nombre; }
void Persona::setCedula(string cedula) { this->cedula = cedula; }
void Persona::setTelefono(string telefono) { this->telefono = telefono; }
void Persona::setCorreo(string correo) { this->correo = correo; }

void Persona::setFechaNacimiento(const Fecha& fecha) {
    if (fechaNacimiento) delete fechaNacimiento;
    fechaNacimiento = new Fecha(fecha);
}

void Persona::setFechaNacimiento(int dia, int mes, int anio) {
    if (fechaNacimiento) delete fechaNacimiento;
    fechaNacimiento = new Fecha(dia, mes, anio);
}

void Persona::setFechaNacimiento(const string& fechaStr) {
    if (fechaNacimiento) delete fechaNacimiento;
    fechaNacimiento = new Fecha(fechaStr);
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