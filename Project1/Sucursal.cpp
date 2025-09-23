#include "Sucursal.h"

Sucursal::Sucursal() {
    this->codigo = "";
    this->provincia = "";
    this->canton = "";
    this->correo = "";
    this->telefono = "";
}

Sucursal::Sucursal(string codigo, string provincia, string canton, string correo, string telefono) {
    this->codigo = codigo;
    this->provincia = provincia;
    this->canton = canton;
    this->correo = correo;
    this->telefono = telefono;
}

Sucursal::~Sucursal() {}

// Getters
string Sucursal::getCodigo() const { return codigo; }
string Sucursal::getProvincia() const { return provincia; }
string Sucursal::getCanton() const { return canton; }
string Sucursal::getCorreo() const { return correo; }
string Sucursal::getTelefono() const { return telefono; }

// Setters
void Sucursal::setCodigo(string codigo) { this->codigo = codigo; }
void Sucursal::setProvincia(string provincia) { this->provincia = provincia; }
void Sucursal::setCanton(string canton) { this->canton = canton; }
void Sucursal::setCorreo(string correo) { this->correo = correo; }
void Sucursal::setTelefono(string telefono) { this->telefono = telefono; }

string Sucursal::toString() const {
    stringstream s;
    s << "Codigo: " << codigo << "\n";
    s << "Provincia: " << provincia << "\n";
    s << "Canton: " << canton << "\n";
    s << "Correo: " << correo << "\n";
    s << "Telefono: " << telefono << "\n";
    return s.str();
}

void Sucursal::mostrar() const {
    cout << toString();
}