#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    fecha();
    fecha(int dia, int mes, int anio);
    fecha(const string fechaStr); // Constructor para formato "dd/mm/yyyy"
    ~fecha();

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Setters
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setFecha(int dia, int mes, int anio);
    void setFecha(const string fechaStr);

    // Métodos
    bool esValida() const;
    int calcularEdad() const;
    string toString() const;
    void mostrar() const;

    // Operadores
    bool operator == (const fecha& otra) const;
    bool operator<(const fecha& otra) const;
    bool operator>(const fecha& otra) const;
};