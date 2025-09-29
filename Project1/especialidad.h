#pragma once
#include <string>

using namespace std;

class Especialidad {
public:
    Especialidad() = default;
    Especialidad(const string& nombre) : nombre(nombre) {}
    string getNombre() const { return nombre; }
    void setNombre(const string& n) { nombre = n; }

    // Nombres estáticos disponibles
    static const string CROSSFIT;
    static const string HIIT;
    static const string TRX;
    static const string PESAS;
    static const string SPINNING;
    static const string CARDIO;
    static const string YOGA;
    static const string ZUMBA;

private:
    string nombre;
};
