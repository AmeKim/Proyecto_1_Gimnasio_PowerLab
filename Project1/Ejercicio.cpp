#include "Ejercicio.h"

Ejercicio::Ejercicio(string nombre, string descripcion, int zonaMuscular) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->zonaMuscular = zonaMuscular;
}

Ejercicio::Ejercicio() {
    nombre = "";
    descripcion = "";
    zonaMuscular = 0;
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

void Ejercicio::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Ejercicio::setDescripcion(const string& descripcion) {
    this->descripcion = descripcion;
}

void Ejercicio::setZonaMuscular(int zonaMuscular) {
    this->zonaMuscular = zonaMuscular;
}

string Ejercicio::mostrarEjercicio() const {
    stringstream s;
    s << "Ejercicio: " << nombre << "\n";
    s << "Descripción: " << descripcion << "\n";
    s << "Zona Muscular: ";
    switch(zonaMuscular) {
        case PECHO: s << "Pecho"; break;
        case TRICEPS: s << "Tríceps"; break;
        case BICEPS: s << "Bíceps"; break;
        case PIERNAS: s << "Piernas"; break;
        case ESPALDA: s << "Espalda"; break;
        default: s << "Desconocida"; break;
    }
    s << "\n";
    return s.str();
}
