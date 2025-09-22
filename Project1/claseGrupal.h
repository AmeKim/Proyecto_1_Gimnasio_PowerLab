#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "cliente.h"
using namespace std;

// Forward declaration para evitar dependencias circulares
class cliente;
class instructor;

class claseGrupal {
private:
    int codigo;
    string tipoClase; // CrossFit, HIIT, TRX, Pesas, Spinning, Cardio, Yoga, Zumba
    int capacidadMaxima;
    string salon;
    string horario;
    string cedulaInstructor;
    cliente** clientesMatriculados;
    int cantidadMatriculados;

public:
    claseGrupal();
    claseGrupal(int codigo, const string& tipoClase, int capacidadMaxima,
        const string& salon, const string& horario, const string& cedulaInstructor);
    ~claseGrupal();

    // Getters
    int getCodigo() const;
    string getTipoClase() const;
    int getCapacidadMaxima() const;
    string getSalon() const;
    string getHorario() const;
    string getCedulaInstructor() const;
    int getCantidadMatriculados() const;
    int getCuposDisponibles() const;

    // Setters
    void setCodigo(int codigo);
    void setTipoClase(const string& tipoClase);
    void setCapacidadMaxima(int capacidad);
    void setSalon(const string& salon);
    void setHorario(const string& horario);
    void setCedulaInstructor(const string& cedula);

    // Métodos para gestionar clientes
    bool matricularCliente(cliente* cli);
    bool desmatricularCliente(const string& cedula);
    bool estaMatriculado(const string& cedula) const;
    void mostrarClientesMatriculados() const;
    string getClientesMatriculados() const;

    // Métodos de utilidad
    void mostrar() const;
    string toString() const;
    string toStringCompleto() const;
    bool tieneCupo() const;
};