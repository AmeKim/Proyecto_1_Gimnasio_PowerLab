#pragma once
#include "Ejercicio.h"
#include <string>
using namespace std;

class EjercicioRutina {
private:
    Ejercicio* ejercicio;
    int series;
    int repeticiones;

public:
    EjercicioRutina(Ejercicio* ej, int ser, int rep);
    ~EjercicioRutina();

    Ejercicio* getEjercicio() const;
    int getSeries() const;
    int getRepeticiones() const;
    string toString() const;
};

class Rutina {
private:
    EjercicioRutina** ejerciciosRutina;
    int tam;
    int cant;

public:
    Rutina();
    ~Rutina();

    void agregarEjercicio(Ejercicio* ejercicio, int series, int repeticiones);
    void mostrarRutina(string nombreCliente);
    void limpiarRutina();
    int getCantidad() const;
};