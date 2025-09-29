#include "Rutina.h"
#include <iostream>

EjercicioRutina::EjercicioRutina(Ejercicio* ej, int ser, int rep)
    : ejercicio(ej), series(ser), repeticiones(rep) {
}

EjercicioRutina::~EjercicioRutina() {}

Ejercicio* EjercicioRutina::getEjercicio() const { return ejercicio; }
int EjercicioRutina::getSeries() const { return series; }
int EjercicioRutina::getRepeticiones() const { return repeticiones; }

string EjercicioRutina::toString() const {
    return ejercicio->getNombre() + ", serie: " + to_string(series) +
        ", repeticiones: " + to_string(repeticiones);
}

Rutina::Rutina() : tam(50), cant(0) {
    ejerciciosRutina = new EjercicioRutina * [tam];
    for (int i = 0; i < tam; i++) {
        ejerciciosRutina[i] = nullptr;
    }
}

Rutina::~Rutina() {
    limpiarRutina();
    delete[] ejerciciosRutina;
}

void Rutina::agregarEjercicio(Ejercicio* ejercicio, int series, int repeticiones) {
    if (!ejercicio || cant >= tam) return;
    ejerciciosRutina[cant++] = new EjercicioRutina(ejercicio, series, repeticiones);
}

void Rutina::mostrarRutina(string nombreCliente) {
    if (cant == 0) {
        cout << "No hay ejercicios en la rutina.\n";
        return;
    }

    cout << "Pecho:\n";
    bool encontrado = false;
    for (int i = 0; i < cant; i++) {
        if (ejerciciosRutina[i] && ejerciciosRutina[i]->getEjercicio()->getZonaMuscular() == 1) {
            cout << ejerciciosRutina[i]->toString() << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Ninguno\n";

    cout << "\nTriceps:\n";
    encontrado = false;
    for (int i = 0; i < cant; i++) {
        if (ejerciciosRutina[i] && ejerciciosRutina[i]->getEjercicio()->getZonaMuscular() == 2) {
            cout << ejerciciosRutina[i]->toString() << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Ninguno\n";

    cout << "\nBiceps:\n";
    encontrado = false;
    for (int i = 0; i < cant; i++) {
        if (ejerciciosRutina[i] && ejerciciosRutina[i]->getEjercicio()->getZonaMuscular() == 3) {
            cout << ejerciciosRutina[i]->toString() << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Ninguno\n";

    std::cout << "\nPiernas:\n";
    encontrado = false;
    for (int i = 0; i < cant; i++) {
        if (ejerciciosRutina[i] && ejerciciosRutina[i]->getEjercicio()->getZonaMuscular() == 4) {
            cout << ejerciciosRutina[i]->toString() << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Ninguno\n";

    cout << "\nEspalda:\n";
    encontrado = false;
    for (int i = 0; i < cant; i++) {
        if (ejerciciosRutina[i] && ejerciciosRutina[i]->getEjercicio()->getZonaMuscular() == 5) {
            cout << ejerciciosRutina[i]->toString() << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Ninguno\n";
}

void Rutina::limpiarRutina() {
    for (int i = 0; i < cant; i++) {
        if (ejerciciosRutina[i]) {
            delete ejerciciosRutina[i];
            ejerciciosRutina[i] = nullptr;
        }
    }
    cant = 0;
}

int Rutina::getCantidad() const {
    return cant;
}