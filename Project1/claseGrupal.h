#pragma once
#include <string>
#include <sstream>
using namespace std;

class instructor;
class cliente;

class ClaseGrupal {
private:
    int codigo;
    string tipo;
    int capacidad;
    string salon;
    string horario;
    instructor* instructorAsignado;
    cliente** clientesMatriculados;
    int tamClientes;
    int cantMatriculados;

public:
    ClaseGrupal();
    ClaseGrupal(int cod, const string& tip, int cap, const string& sal,
        const string& hor, instructor* ins);
    ~ClaseGrupal();

    // Getters
    int getCodigo() const;
    string getTipo() const;
    int getCapacidad() const;
    string getSalon() const;
    string getHorario() const;
    instructor* getInstructor() const;
    int getCantidadMatriculados() const;
    int getCuposDisponibles() const;

    // Matriculación
    bool matricularCliente(cliente* cli);
    string listarClientesMatriculados() const;

    // Utilidades
    string toString() const;
};