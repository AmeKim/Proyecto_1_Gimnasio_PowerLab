#include "BateriaEjercicios.h"
#include "utiles.h"

BateriaEjercicios::BateriaEjercicios() {
    tam = 100;
    cant = 0;
    ejercicios = new Ejercicio * [tam];
    for (int i = 0; i < tam; i++) {
        ejercicios[i] = nullptr;
    }
}

BateriaEjercicios::~BateriaEjercicios() {
    for (int i = 0; i < cant; i++) {
        delete ejercicios[i];
    }
    delete[] ejercicios;
}

void BateriaEjercicios::agregar(Ejercicio* ejercicio) {
    if (cant < tam) {
        ejercicios[cant] = ejercicio;
        cant++;
    }
}

Ejercicio* BateriaEjercicios::obtener(int indice) {
    if (indice >= 0 && indice < cant) {
        return ejercicios[indice];
    }
    return nullptr;
}

int BateriaEjercicios::getCantidad() const {
    return cant;
}

void BateriaEjercicios::mostrarPorZona(int zona) {
    print("BATERÍA DE EJERCICIOS DISPONIBLES PARA ZONA MUSCULAR ");
    switch (zona) {
    case 1: print("PECHO\n"); break;
    case 2: print("TRÍCEPS\n"); break;
    case 3: print("BÍCEPS\n"); break;
    case 4: print("PIERNAS\n"); break;
    case 5: print("ESPALDA\n"); break;
    }
    print("===========================================\n");

    int contador = 1;
    for (int i = 0; i < cant; i++) {
        if (ejercicios[i]->getZonaMuscular() == zona) {
            print(to_string(contador) + ". " + ejercicios[i]->getNombre() + "\n");
            contador++;
        }
    }
}

Ejercicio* BateriaEjercicios::obtenerPorZona(int zona, int indiceZona) {
    int contador = 0;
    for (int i = 0; i < cant; i++) {
        if (ejercicios[i]->getZonaMuscular() == zona) {
            if (contador == indiceZona) {
                return ejercicios[i];
            }
            contador++;
        }
    }
    return nullptr;
}

int BateriaEjercicios::getCantidadPorZona(int zona) {
    int contador = 0;
    for (int i = 0; i < cant; i++) {
        if (ejercicios[i]->getZonaMuscular() == zona) {
            contador++;
        }
    }
    return contador;
}

string BateriaEjercicios::toString() const {
    string result = "";
    for (int i = 0; i < cant; i++) {
        result += to_string(i + 1) + ". " + ejercicios[i]->toString() + "\n";
    }
    return result;
}
