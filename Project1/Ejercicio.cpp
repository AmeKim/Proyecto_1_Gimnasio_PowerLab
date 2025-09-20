#include "Ejercicio.h"

Ejercicio::Ejercicio() {
    this->zonaMuscular = 0;
    this->nombre = "";
    this->descripcion = "";
    this->series = 0;
    this->repeticiones = 0;
}

Ejercicio::Ejercicio(int zona, string nombre, string descripcion) {
    this->zonaMuscular = zona;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->series = 0;
    this->repeticiones = 0;
}

Ejercicio::Ejercicio(int zona, string nombre, string descripcion, int series, int repeticiones) {
    this->zonaMuscular = zona;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->series = series;
    this->repeticiones = repeticiones;
}

Ejercicio::~Ejercicio() {
    // Destructor vacío ya que no hay memoria dinámica
}

// Getters
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

// Setters
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

// Métodos adicionales
string Ejercicio::getNombreZona() const {
    switch (zonaMuscular) {
    case 1: return "Pecho";
    case 2: return "Tríceps";
    case 3: return "Bíceps";
    case 4: return "Piernas";
    case 5: return "Espalda";
    default: return "Desconocida";
    }
}

string Ejercicio::toString() const {
    stringstream s;
    s << nombre << ", series: " << series << ", repeticiones: " << repeticiones;
    return s.str();
}

void Ejercicio::mostrar() const {
    cout << "Zona: " << getNombreZona() << endl;
    cout << "Ejercicio: " << nombre << endl;
    cout << "Descripción: " << descripcion << endl;
    if (series > 0 && repeticiones > 0) {
        cout << "Series: " << series << " - Repeticiones: " << repeticiones << endl;
    }
}