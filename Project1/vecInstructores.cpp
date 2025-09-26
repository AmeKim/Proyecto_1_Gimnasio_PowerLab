#include "vecInstructores.h"
#include "utiles.h"
#include <sstream>

vecInstructores::vecInstructores(int capacidadInicial) {
    if (capacidadInicial < 1) capacidadInicial = 10;
    tam = capacidadInicial;
    cant = 0;
    datos = new Instructor * [tam];
    for (int i = 0; i < tam; ++i) datos[i] = nullptr;
}

vecInstructores::~vecInstructores() {
    for (int i = 0; i < cant; ++i) if (datos[i]) delete datos[i];
    delete[] datos;
}

void vecInstructores::expandir() {
    int nuevo = tam * 2;
    Instructor** aux = new Instructor * [nuevo];
    for (int i = 0; i < nuevo; ++i) aux[i] = nullptr;
    for (int i = 0; i < cant; ++i) aux[i] = datos[i];
    delete[] datos;
    datos = aux;
    tam = nuevo;
}

bool vecInstructores::insertar(Instructor* i) {
    if (!i) return false;
    if (buscarPorCedula(i->getCedula()) != nullptr) return false;
    if (cant >= tam) expandir();
    datos[cant++] = i;
    return true;
}

Instructor* vecInstructores::buscarPorCedula(const string& cedula) const {
    for (int i = 0; i < cant; ++i) if (datos[i] && datos[i]->getCedula() == cedula) return datos[i];
    return nullptr;
}

especialidad* vecInstructores::obtenerEspecialidad(const string& nombre) const
{
    return nullptr;
}

int vecInstructores::indicePorCedula(const string& cedula) const {
    for (int i = 0; i < cant; ++i) if (datos[i] && datos[i]->getCedula() == cedula) return i;
    return -1;
}

Instructor* vecInstructores::obtener(string idx) const {
    for (int i = 0 ; i< cant; i++){
        if (datos[i]->getCedula() == idx)
            return datos[i];
    }
	return nullptr;
}

Instructor* vecInstructores::obtener(int idx) const{
    if (idx >= 0 && idx < cant) {
        return datos[idx];
    }
}

int vecInstructores::getcantidad() const { return cant; }

void vecInstructores::listarTodos() const {
    if (cant == 0) { print("No hay instructores registrados\n"); return; }
    for (int i = 0; i < cant; ++i) {
        if (datos[i]) {
            stringstream s;
            s << (i + 1) << "- " << datos[i]->getCedula() << " " << datos[i]->getNombre() << "\n";
            print(s.str());
        }
    }
}

bool vecInstructores::eliminarPorCedula(const string& cedula) {
    int idx = indicePorCedula(cedula);
    if (idx == -1) return false;
    if (datos[idx]) delete datos[idx];
    for (int i = idx; i < cant - 1; ++i) datos[i] = datos[i + 1];
    datos[cant - 1] = nullptr;
    --cant;
    return true;
}