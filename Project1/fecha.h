#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    // Constructores
    Fecha(int dia, int mes, int anio);
    Fecha(const string& fechaStr); // formato: "dd/mm/aaaa"
    Fecha(const Fecha& otra);
    Fecha(); // Fecha actual

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Setters
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setFecha(int dia, int mes, int anio);
    void setFecha(const string& fechaStr);

    // Utilidades
    string toString() const;
    bool esValida() const;
    int calcularEdad(const Fecha& fechaActual) const;
    int diasTranscurridos(const Fecha& otraFecha) const;
    bool esMayor(const Fecha& otraFecha) const;
    bool esMenor(const Fecha& otraFecha) const;
    bool esIgual(const Fecha& otraFecha) const;

    // Métodos estáticos
    static Fecha fechaActual();
    static bool esBisiesto(int anio);
    static int diasEnMes(int mes, int anio);
};