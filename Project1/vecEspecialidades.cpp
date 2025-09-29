#include "vecEspecialidades.h"
#include "especialidad.h"

vecEspecialidades::vecEspecialidades(int capacidadInicial)
    : datos(nullptr), capacidad(0), cantidad(0) {
    if (capacidadInicial < 1) capacidadInicial = 8;
    datos = new Especialidad[capacidadInicial];
    capacidad = capacidadInicial;
    // No llamamos a cargarEspecialidadesPorDefecto aquí por si el programa necesita control sobre el momento de carga
}

vecEspecialidades::~vecEspecialidades() {
    delete[] datos;
    datos = nullptr;
    capacidad = 0;
    cantidad = 0;
}

void vecEspecialidades::asegurarCapacidad(int nuevaCapacidad) {
    if (nuevaCapacidad <= capacidad) return;
    Especialidad* nuevo = new Especialidad[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevo[i] = datos[i];
    }
    delete[] datos;
    datos = nuevo;
    capacidad = nuevaCapacidad;
}

void vecEspecialidades::agregar(const Especialidad& e) {
    if (cantidad >= capacidad) {
        asegurarCapacidad(capacidad * 2);
    }
    datos[cantidad++] = e;
}

void vecEspecialidades::limpiar() {
    // Resetea el conteo; mantiene el buffer para futuras inserciones
    cantidad = 0;
}

int vecEspecialidades::tamanio() const {
    return cantidad;
}

const Especialidad& vecEspecialidades::obtener(int indice) const {
    if (indice < 0) indice = 0;
    if (indice >= cantidad) indice = cantidad - 1;
    return datos[indice];
}

Especialidad& vecEspecialidades::obtener(int indice) {
    if (indice < 0) indice = 0;
    if (indice >= cantidad) indice = cantidad - 1;
    return datos[indice];
}

int vecEspecialidades::indicePorNombre(const string& nombre) const {
    for (int i = 0; i < cantidad; ++i) {
        if (datos[i].getNombre() == nombre) return i;
    }
    return -1;
}

bool vecEspecialidades::existe(const string& nombre) const {
    return indicePorNombre(nombre) != -1;
}

void vecEspecialidades::cargarEspecialidadesPorDefecto() {
    limpiar();
    agregar(Especialidad(Especialidad::CROSSFIT));
    agregar(Especialidad(Especialidad::HIIT));
    agregar(Especialidad(Especialidad::TRX));
    agregar(Especialidad(Especialidad::PESAS));
    agregar(Especialidad(Especialidad::SPINNING));
    agregar(Especialidad(Especialidad::CARDIO));
    agregar(Especialidad(Especialidad::YOGA));
    agregar(Especialidad(Especialidad::ZUMBA));
}