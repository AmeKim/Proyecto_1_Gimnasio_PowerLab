#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

    bool esAnioBisiesto(int anio) const;
    int diasEnMes(int mes, int anio) const;

public:
    // Constructores
    Fecha(); // Constructor por defecto sin inicializaci�n
    Fecha(int d, int m, int a);
    Fecha(const string& fechaStr);

    // Destructor
    ~Fecha();

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Setters con validaci�n
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    void setFecha(int d, int m, int a);

    // Validaci�n de fecha
    bool validarFecha();
    bool esFechaValida() const; // Verifica si la fecha actual es v�lida
    bool esFechaInicializada() const; // Verifica si la fecha ha sido inicializada

    // Parsear fecha desde string (formato: dd/mm/aaaa o dd-mm-aaaa)
    bool parsearFecha(const string& fechaStr);

    // Convertir a string
    string toString() const;
    string toStringLargo() const;

    // Calcular edad (�til para clientes e instructores)
    int calcularEdad(const Fecha& fechaActual) const;

    // Comparar fechas
    bool esAnterior(const Fecha& otra) const;
    bool esPosterior(const Fecha& otra) const;
    bool esIgual(const Fecha& otra) const;

    // Operadores
    bool operator<(const Fecha& otra) const;
    bool operator>(const Fecha& otra) const;
    bool operator==(const Fecha& otra) const;
    bool operator!=(const Fecha& otra) const;

    // M�todos est�ticos
    static Fecha fechaActual();
    static bool esFechaValida(int d, int m, int a);
};