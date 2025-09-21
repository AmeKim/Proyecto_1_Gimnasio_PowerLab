#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "instructor.h"
using namespace std;

class vecInstructores {
private:
    instructor** vInstructores;
    int can;
    int tam;

public:
    vecInstructores(int capacidad = 50);
    ~vecInstructores();

    // Métodos principales
    bool agregarInstructor(instructor* inst);
    void eliminarInstructor(const string& cedula);
    instructor* buscarInstructor(const string& cedula);
    instructor* getInstructor(const string& cedula);

    // Getters
    int getCan() const;
    int getTam() const;
    instructor* getInstructorPorIndice(int indice) const;

    // Búsquedas específicas
    string getInstructoresPorEspecialidad(const string& especialidad) const;
    string mostrarInstructoresPorEspecialidad(const string& especialidad) const;

    // Funciones requeridas por el compilador
    instructor* getInstructor(const string& cedula) const;
    string toStringEspecifico(const string& cedula) const;
    void mostrarTodos() const;
    void mostrarInstructor(const string& cedula) const;

    // Métodos de cadena
    string toString() const;
    string toStringEspecifico(const string& cedula) const;

    // Métodos de visualización
    void mostrarTodos() const;
    void mostrarInstructor(const string& cedula) const;
};