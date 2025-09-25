#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class ClaseGrupal {
private:
    string tipo;              // 1..8 (crossFit, HIIT, TRX , pesas, spinning , cardio, yoga, zumba)
    int codigo;         // Identificador interno (ej: "1")
    int capacidad;         // cupo máximo
    int cantMatriculados;  // cantidad actual matriculados
    string salon;
    string horario;
    string cedulaInstructor; // cedula del instructor asignado

    // lista de cedulas de clientes matriculados (propietario)
    string* matriculados;
    int tamMatriculados; // tamaño del arreglo matriculados

public:
    ClaseGrupal();
    ClaseGrupal(string tipo, int codigo, int capacidad, string salon, string horario, string cedulaInstructor);
    ~ClaseGrupal();

    // Getters
    string getTipo() const;
    int getCodigo() const;
    int getCapacidad() const;
    int getCantMatriculados() const;
    string getSalon() const;
    string getHorario() const;
    string getCedulaInstructor() const;

    // Setters/Modificadores
    bool matricularCliente(string cedulaCliente); // devuelve true si matricula ok
    bool estaMatriculado(string cedulaCliente) const;
    bool removerMatricula(string cedulaCliente);  // remueve si existe

    string toString() const;
    string detalleClase() const;
	string mostrarTipos() const;
};