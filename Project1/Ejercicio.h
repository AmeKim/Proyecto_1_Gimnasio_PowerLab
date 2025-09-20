#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Ejercicio {
private:
    int zonaMuscular; // 1-Pecho, 2-Tríceps, 3-Bíceps, 4-Piernas, 5-Espalda
    string nombre;
    string descripcion;
    int series;
    int repeticiones;

public:
    Ejercicio();
    Ejercicio(int zona, string nombre, string descripcion);
    Ejercicio(int zona, string nombre, string descripcion, int series, int repeticiones);
    ~Ejercicio();

    // Getters
    int getZonaMuscular() const;
    string getNombre() const;
    string getDescripcion() const;
    int getSeries() const;
    int getRepeticiones() const;

    // Setters
    void setZonaMuscular(int zona);
    void setNombre(const string& nombre);
    void setDescripcion(const string& descripcion);
    void setSeries(int series);
    void setRepeticiones(int repeticiones);

    // Métodos adicionales
    string getNombreZona() const;
    string toString() const;
    void mostrar() const;
};