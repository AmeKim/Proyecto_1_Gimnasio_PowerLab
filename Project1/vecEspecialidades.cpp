#include "vecEspecialidades.h"

vecEspecialidades::vecEspecialidades() {
    tam = 10;
    cant = 0;
    especialidades = new especialidad * [tam];
    for (int i = 0; i < tam; i++) {
        especialidades[i] = nullptr;
    }
}

vecEspecialidades::~vecEspecialidades() {
    for (int i = 0; i < cant; i++) {
        delete especialidades[i];
    }
    delete[] especialidades;
}

void vecEspecialidades::agregar(especialidad* esp) {
    if (cant < tam) {
        especialidades[cant] = esp;
        cant++;
    }
}

especialidad* vecEspecialidades::obtener(int indice) {
    if (indice >= 0 && indice < cant) {
        return especialidades[indice];
    }
    return nullptr;
}

int vecEspecialidades::getCantidad() const {
    return cant;
}

bool vecEspecialidades::buscar(string nombre) {
    for (int i = 0; i < cant; i++) {
        if (especialidades[i]->getNombre() == nombre) {
            return true;
        }
    }
    return false;
}

string vecEspecialidades::toString() const {
    string result = "";
    for (int i = 0; i < cant; i++) {
        if (i > 0) result += ", ";
        result += especialidades[i]->getNombre();
    }
    return result;
}
