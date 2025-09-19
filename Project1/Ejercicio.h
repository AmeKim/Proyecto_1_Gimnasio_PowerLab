#pragma once
#include <string>
#include <sstream>
using namespace std;

enum ZonaMuscular {
    PECHO = 1,
    TRICEPS = 2,
    BICEPS = 3,
    PIERNAS = 4,
    ESPALDA = 5
};

class Ejercicio {
private:
    string nombre;
    string descripcion;
    int zonaMuscular; // Usa el enum ZonaMuscular
public:
    Ejercicio(string nombre, string descripcion, int zonaMuscular);
    Ejercicio();
    ~Ejercicio();

    // Getters
    string getNombre() const;
    string getDescripcion() const;
    int getZonaMuscular() const;

    // Setters
    void setNombre(const string& nombre);
    void setDescripcion(const string& descripcion);
    void setZonaMuscular(int zonaMuscular);

    // Mostrar información
    string mostrarEjercicio() const;
};
