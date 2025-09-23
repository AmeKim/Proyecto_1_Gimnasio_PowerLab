#include "instructor.h"

Instructor::Instructor() : Persona() {
    maxEspecialidades = 8;
    cantEspecialidades = 0;
    especialidades = new string[maxEspecialidades];
    codigoSucursal = "";
}

Instructor::Instructor(string nombre, string cedula, string telefono, string correo, const string& fechaNacimientoStr)
    : Persona(nombre, cedula, telefono, correo, fechaNacimientoStr) {
    maxEspecialidades = 8;
    cantEspecialidades = 0;
    especialidades = new string[maxEspecialidades];
    codigoSucursal = "";
}

Instructor::~Instructor() {
    delete[] especialidades;
}

bool Instructor::agregarEspecialidad(const string& esp) {
    if (esp.empty()) return false;
    for (int i = 0; i < cantEspecialidades; ++i) if (especialidades[i] == esp) return false;
    if (cantEspecialidades >= maxEspecialidades) return false;
    especialidades[cantEspecialidades++] = esp;
    return true;
}

bool Instructor::tieneEspecialidad(const string& esp) const {
    for (int i = 0; i < cantEspecialidades; ++i) if (especialidades[i] == esp) return true;
    return false;
}

int Instructor::getCantEspecialidades() const { return cantEspecialidades; }

string Instructor::getEspecialidad(int idx) const {
    if (idx < 0 || idx >= cantEspecialidades) return "";
    return especialidades[idx];
}

void Instructor::setCodigoSucursal(const string& codigo) { codigoSucursal = codigo; }
string Instructor::getCodigoSucursal() const { return codigoSucursal; }

string Instructor::toString() {
    stringstream s;
    s << Persona::toString();
    s << "Sucursal: " << (codigoSucursal.empty() ? "Sin sucursal" : codigoSucursal) << "\n";
    s << "Especialidades: ";
    if (cantEspecialidades == 0) s << "Ninguna\n";
    else {
        for (int i = 0; i < cantEspecialidades; ++i) {
            s << especialidades[i];
            if (i < cantEspecialidades - 1) s << ", ";
        }
        s << "\n";
    }
    return s.str();
}
