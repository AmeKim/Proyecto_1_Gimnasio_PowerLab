#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "instructor.h"
#include "cliente.h"
using namespace std;

class claseGrupal {
private:
    int codigo;
    string tipo;
    int capacidad;
    int cantidadActual;
    string salon;
    string horario;
    instructor* instructorAsignado;
    cliente** clientesMatriculados; // Array dinámico de punteros a clientes

public:
    claseGrupal();
    claseGrupal(int codigo, string tipo, int capacidad, string salon, string horario, instructor* inst);
    ~claseGrupal();

    // Getters
    int getCodigo() const;
    string getTipo() const;
    int getCapacidad() const;
    int getCantidadActual() const;
    string getSalon() const;
    string getHorario() const;
    instructor* getInstructor() const;
    int getCuposDisponibles() const;

    // Setters
    void setCodigo(int codigo);
    void setTipo(const string& tipo);
    void setCapacidad(int capacidad);
    void setSalon(const string& salon);
    void setHorario(const string& horario);
    void setInstructor(instructor* inst);

    // Métodos para manejo de clientes
    bool matricularCliente(cliente* cli);
    bool desmatricularCliente(cliente* cli);
    bool tieneClienteMatriculado(cliente* cli) const;
    cliente* getClientePorIndice(int indice) const;

    // Métodos de visualización
    string toString() const;
    string getClientesMatriculadosStr() const;
    void mostrarDetalle() const;
};