#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Ejercicio {
private:
    int zonaMuscular; // 1=Pecho, 2=Tríceps, 3=Bíceps, 4=Piernas, 5=Espalda
    string nombre;
    string descripcion;
    int series;
    int repeticiones;

public:
    // Constructores
    Ejercicio();
    Ejercicio(int zona, const string& nombre, const string& descripcion);
    Ejercicio(int zona, const string& nombre, const string& descripcion, int series, int repeticiones);

    // Destructor
    ~Ejercicio();

    // Getters
    int getZonaMuscular() const;
    string getNombre() const;
    string getDescripcion() const;
    int getSeries() const;
    int getRepeticiones() const;
    string getNombreZona() const;

    // Setters
    void setZonaMuscular(int zona);
    void setNombre(const string& nombre);
    void setDescripcion(const string& descripcion);
    void setSeries(int series);
    void setRepeticiones(int repeticiones);

    // Métodos de utilidad
    void mostrar() const;
    string toString() const;
    string toStringCompleto() const;

    // Crear copia para rutina
    Ejercicio* crearCopia() const;
};