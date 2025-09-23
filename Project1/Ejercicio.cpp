#include "Ejercicio.h"

Ejercicio::Ejercicio() {
    nombre = "";
    descripcion = "";
    zonaMuscular = 1;
}

Ejercicio::Ejercicio(string nombre, string descripcion, int zona) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->zonaMuscular = zona;
}

Ejercicio::~Ejercicio() {}

string Ejercicio::getNombre() const {
    return nombre;
}

string Ejercicio::getDescripcion() const {
    return descripcion;
}

int Ejercicio::getZonaMuscular() const {
    return zonaMuscular;
}

string Ejercicio::getZonaString() const {
    switch (zonaMuscular) {
    case 1: return "Pecho";
    case 2: return "Tríceps";
    case 3: return "Bíceps";
    case 4: return "Piernas";
    case 5: return "Espalda";
    default: return "Desconocida";
    }
}

void Ejercicio::setNombre(string nombre) {
    this->nombre = nombre;
}

void Ejercicio::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Ejercicio::setZonaMuscular(int zona) {
    this->zonaMuscular = zona;
}

string Ejercicio::toString() const {
    return nombre + " - " + descripcion + " (Zona: " + getZonaString() + ")";
}