#pragma once
#include "Ejercicio.h"

class BateriaEjercicios {
private:
    Ejercicio** ejercicios;
    int tam;
    int cant;

public:
    BateriaEjercicios();
    ~BateriaEjercicios();

    bool agregar(Ejercicio* ejercicio);
    Ejercicio* obtener(int indice);
    int getCantidad() const;
    void mostrarPorZona(int zona);
    Ejercicio* obtenerPorZona(int zona, int indiceZona);
    int getCantidadPorZona(int zona);
    string toString() const;
};