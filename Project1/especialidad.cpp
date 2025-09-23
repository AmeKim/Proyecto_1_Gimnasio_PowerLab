#include "especialidad.h"

especialidad::especialidad() {
    nombre = "";
}

especialidad::especialidad(string nombre) {
    this->nombre = nombre;
}

especialidad::~especialidad() {}

string especialidad::getNombre() const {
    return nombre;
}

void especialidad::setNombre(string nombre) {
    this->nombre = nombre;
}

string especialidad::toString() const {
    return nombre;
}