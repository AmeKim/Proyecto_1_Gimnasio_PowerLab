#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Ejercicio.h"
using namespace std;

class Rutina {
private:
    string cedulaCliente;
    Ejercicio** ejercicios;
    int can;
    int tam;

public:
    Rutina(string cedulaCliente, int capacidad = 15);
    ~Rutina();

    bool agregarEjercicio(Ejercicio* ejercicio);
    void limpiarRutina();

    string getCedulaCliente() const;
    int getCan() const;

    string toString() const;
    void mostrarRutina() const;
    void mostrarPorZona(int zona) const;
    int contarEjerciciosPorZona(int zona) const;
};