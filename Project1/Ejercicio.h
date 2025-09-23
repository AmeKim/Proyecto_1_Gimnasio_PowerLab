#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ejercicio {
private:
    string nombre;
    string descripcion;
    int zonaMuscular; // 1-Pecho, 2-Tr�ceps, 3-B�ceps, 4-Piernas, 5-Espalda

public:
    Ejercicio();
    Ejercicio(string nombre, string descripcion, int zona);
    ~Ejercicio();

    string getNombre() const;
    string getDescripcion() const;
    int getZonaMuscular() const;
    string getZonaString() const;

    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setZonaMuscular(int zona);

    string toString() const;
};