#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Ejercicio.h"
using namespace std;

class Rutina {
private:
    Ejercicio** ejercicios;
    int can;
    int tam;
    string cedulaCliente;

public:
    Rutina(string cedulaCliente, int capacidad = 50);
    ~Rutina();

    // Métodos principales
    bool agregarEjercicio(Ejercicio* ejercicio);
    void limpiarRutina();

    // Getters
    string getCedulaCliente() const;
    int getCan() const;

    // Métodos de visualización
    string toString() const;
    void mostrarRutina() const;
    void mostrarPorZona(int zona) const;

    // Método para obtener ejercicios por zona
    int contarEjerciciosPorZona(int zona) const;
};