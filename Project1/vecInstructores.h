#pragma once
#include "instructor.h"

class vecInstructores {
private:
    Instructor** datos;
    int tam;
    int cant;

    void expandir();

public:
    vecInstructores(int capacidadInicial = 10);
    ~vecInstructores();

    bool insertar(Instructor* i); // falso si cedula duplicada
    Instructor* buscarPorCedula(const string& cedula) const;
	especialidad* obtenerEspecialidad(const string& nombre) const;
    int indicePorCedula(const string& cedula) const;
    Instructor* obtener(string ced) const;
    int getcantidad() const;
    void listarTodos() const;
    bool eliminarPorCedula(const string& cedula);
};
