#include "especialidad.h"

especialidad::especialidad() {
    this->id = 0;
    this->nombre = "";
    this->descripcion = "";
}

especialidad::especialidad(int id, string nombre, string descripcion) {
    this->id = id;
    this->nombre = nombre;
    this->descripcion = descripcion;
}

especialidad::~especialidad() {
    // Destructor vacío
}

// Getters
int especialidad::getId() const {
    return id;
}

string especialidad::getNombre() const {
    return nombre;
}

string especialidad::getDescripcion() const {
    return descripcion;
}

// Setters
void especialidad::setId(int id) {
    this->id = id;
}

void especialidad::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void especialidad::setDescripcion(const string& descripcion) {
    this->descripcion = descripcion;
}

void especialidad::mostrar() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    if (!descripcion.empty()) {
        cout << "Descripción: " << descripcion << endl;
    }
}

string especialidad::toString() const {
    return nombre;
}
