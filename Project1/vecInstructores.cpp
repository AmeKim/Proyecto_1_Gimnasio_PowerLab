#include "vecInstructores.h"

vecInstructores::vecInstructores(int capacidadInicial) : datos(nullptr), capacidad(0), cantidad(0) {
    if (capacidadInicial < 1) capacidadInicial = 8;
    datos = new instructor[capacidadInicial];
    capacidad = capacidadInicial;
}

vecInstructores::~vecInstructores() {
    delete[] datos;
    datos = nullptr;
    capacidad = 0;
    cantidad = 0;
}

void vecInstructores::asegurarCapacidad(int nuevaCapacidad) {
    if (nuevaCapacidad <= capacidad) return;
    instructor* nuevo = new instructor[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) nuevo[i] = datos[i];
    delete[] datos;
    datos = nuevo;
    capacidad = nuevaCapacidad;
}

void vecInstructores::agregar(const instructor& ins) {
    if (cantidad >= capacidad) asegurarCapacidad((capacidad == 0) ? 4 : capacidad * 2);
    datos[cantidad++] = ins;
}

int vecInstructores::tamanio() const { return cantidad; }

const instructor& vecInstructores::obtener(int idx) const {
    if (idx < 0) idx = 0;
    if (idx >= cantidad) idx = cantidad - 1;
    return datos[idx];
}

instructor& vecInstructores::obtener(int idx) {
    if (idx < 0) idx = 0;
    if (idx >= cantidad) idx = cantidad - 1;
    return datos[idx];
}

int vecInstructores::indicePorCedula(int cedula) const {
        string cedulaStr = to_string(cedula);
    for (int i = 0; i < cantidad; ++i) {
        if (datos[i].getCedula() == cedulaStr) return i;
    }
	return -1;
}

void vecInstructores::limpiar() { cantidad = 0; }