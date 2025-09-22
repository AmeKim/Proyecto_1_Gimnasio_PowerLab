#include "Ejercicio.h"

Ejercicio::Ejercicio() {
    zonaMuscular = 1;
    nombre = "";
    descripcion = "";
    series = 0;
    repeticiones = 0;
}

Ejercicio::Ejercicio(int zona, const string& nombre, const string& descripcion) {
    this->zonaMuscular = zona;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->series = 0;
    this->repeticiones = 0;
}

Ejercicio::Ejercicio(int zona, const string& nombre, const string& descripcion, int series, int repeticiones) {
    this->zonaMuscular = zona;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->series = series;
    this->repeticiones = repeticiones;
}

Ejercicio::~Ejercicio() {
    // No hay memoria dinámica que liberar
}

int Ejercicio::getZonaMuscular() const {
    return zonaMuscular;
}

string Ejercicio::getNombre() const {
    return nombre;
}

string Ejercicio::getDescripcion() const {
    return descripcion;
}

int Ejercicio::getSeries() const {
    return series;
}

int Ejercicio::getRepeticiones() const {
    return repeticiones;
}

string Ejercicio::getNombreZona() const {
    switch (zonaMuscular) {
    case 1: return "Pecho";
    case 2: return "Tríceps";
    case 3: return "Bíceps";
    case 4: return "Piernas";
    case 5: return "Espalda";
    default: return "Desconocido";
    }
}

void Ejercicio::setZonaMuscular(int zona) {
    this->zonaMuscular = zona;
}

void Ejercicio::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Ejercicio::setDescripcion(const string& descripcion) {
    this->descripcion = descripcion;
}

void Ejercicio::setSeries(int series) {
    this->series = series;
}

void Ejercicio::setRepeticiones(int repeticiones) {
    this->repeticiones = repeticiones;
}

void Ejercicio::mostrar() const {
    cout << "Ejercicio: " << nombre << endl;
    cout << "Zona muscular: " << getNombreZona() << endl;
    cout << "Descripción: " << descripcion << endl;
    if (series > 0 && repeticiones > 0) {
        cout << "Series: " << series << ", Repeticiones: " << repeticiones << endl;
    }
}

string Ejercicio::toString() const {
    if (series > 0 && repeticiones > 0) {
        return nombre + ", serie: " + to_string(series) + ", repeticiones: " + to_string(repeticiones);
    }
    else {
        return nombre;
    }
}

string Ejercicio::toStringCompleto() const {
    stringstream s;
    s << "Ejercicio: " << nombre << endl;
    s << "Zona: " << getNombreZona() << endl;
    s << "Descripción: " << descripcion << endl;
    if (series > 0 && repeticiones > 0) {
        s << "Series: " << series << ", Repeticiones: " << repeticiones << endl;
    }
    return s.str();
}

Ejercicio* Ejercicio::crearCopia() const {
    return new Ejercicio(zonaMuscular, nombre, descripcion, series, repeticiones);
}