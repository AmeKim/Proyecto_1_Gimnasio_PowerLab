#include "especialidad.h"
#include <iostream>
especialidad::especialidad() : id(0), nombre(""), descripcion("") {}
especialidad::especialidad(int id, string nombre, string descripcion)
    : id(id), nombre(nombre), descripcion(descripcion) {}
especialidad::~especialidad() {}
int especialidad::getId() const { return id; }
string especialidad::getNombre() const { return nombre; }
string especialidad::getDescripcion() const { return descripcion; }
void especialidad::setId(int id) { this->id = id; }
void especialidad::setNombre(const string& nombre) { this->nombre = nombre; }
void especialidad::setDescripcion(const string& descripcion) { this->descripcion = descripcion; }
void especialidad::mostrar() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    if (!descripcion.empty())
        cout << "Descripción: " << descripcion << endl;
}
string especialidad::toString() const {
    stringstream s;
    s << "ID: " << id << "\n";
    s << "Nombre: " << nombre << "\n";
    if (!descripcion.empty())
        s << "Descripción: " << descripcion << "\n";
    return s.str();
}
