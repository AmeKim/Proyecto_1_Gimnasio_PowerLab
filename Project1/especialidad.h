#pragma once
#include <iostream>
#include <string>
using namespace std;

class especialidad {
private:
    string nombre;

public:
    especialidad();
    especialidad(string nombre);
    ~especialidad();

    string getNombre() const;
    void setNombre(string nombre);
    string toString() const;
};
