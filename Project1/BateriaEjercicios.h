#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Ejercicio.h"
using namespace std;

class BateriaEjercicios {
private:
    Ejercicio** ejercicios;
    int can;
    int tam;

public:
    BateriaEjercicios(int capacidad = 50);
    ~BateriaEjercicios();

    bool agregarEjercicio(Ejercicio* ejercicio);
    void eliminarEjercicio(const string& nombre);
    Ejercicio* buscarEjercicio(const string& nombre);

    void mostrarEjerciciosPorZona(int zona) const;
    string getEjerciciosPorZona(int zona) const;
    Ejercicio* obtenerEjercicioPorIndice(int indice, int zona) const;

    int getCan() const;
    int getTam() const;
    void mostrarTodos() const;
    string toString() const;

    // Métodos para obtener ejercicios de una zona específica
    int contarEjerciciosPorZona(int zona) const;
    void inicializarEjerciciosBasicos();
};

