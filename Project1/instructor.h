#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"
#include "vecEspecialidades.h"
using namespace std;

// Forward declarations
class cliente;
class Rutina;
class BateriaEjercicios;
class Ejercicio;
class reporteM;

class instructor : public Persona {
private:
    vecEspecialidades* especialidades;

public:
    instructor(string nombre, string cedula, int telefono, string correo,
        int dia, int mes, int anio, vecEspecialidades* esp);
    instructor(string nombre, string cedula, int telefono, string correo,
        const Fecha& fechaNac, vecEspecialidades* esp);
    instructor(string nombre, string cedula, int telefono, string correo,
        const string& fechaNacStr, vecEspecialidades* esp);
    ~instructor();

    // Getters
    vecEspecialidades* getEspecialidades() const;
    int getCantidadEspecialidades() const;

    // Setters
    void setEspecialidades(vecEspecialidades* esp);

    // M�todos de especialidades
    bool tieneEspecialidad(const string& nombreEsp) const;

    // *** M�TODOS PRINCIPALES PARA CREAR RUTINAS ***
    // El instructor crea la rutina completa y se la da al cliente
    Rutina* crearRutinaCompleta(cliente* cli, BateriaEjercicios* bateria);
    bool generarRutinaParaCliente(cliente* cli, BateriaEjercicios* bateria);

    // El instructor puede agregar ejercicios espec�ficos a una rutina
    bool agregarEjercicioARutina(Rutina* rutina, BateriaEjercicios* bateria,
        int zona, int indiceEjercicio, int series, int repeticiones);

    // El instructor entrega la rutina terminada al cliente
    bool entregarRutinaACliente(cliente* cli, Rutina* rutina);

    // Visualizaci�n de rutinas
    void mostrarRutinaDeCliente(cliente* cli) const;
    void mostrarBateriaEjerciciosPorZona(BateriaEjercicios* bateria, int zona) const;

    // *** M�TODOS PARA MEDICIONES ***
    reporteM* crearMedicionParaCliente(cliente* cli, const Fecha& fecha, double peso,
        double estatura, double pGrasa, double pMusculo);
    bool asignarMedicionACliente(cliente* cli, reporteM* medicion);

    // M�todos de visualizaci�n
    string toString() override;
    string toStringDetallado() const;
    void mostrarEspecialidades() const;
};