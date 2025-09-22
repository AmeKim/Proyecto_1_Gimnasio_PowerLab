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

    bool agregarInstructor(instructor* inst);
    void eliminarInstructor(const string& cedula);
    instructor* buscarInstructor(const string& cedula) const; // Corregido para ser const
    instructor* getInstructor(const string& cedula);

    int getCan() const;
    int getTam() const;
    instructor* getInstructorPorIndice(int indice) const;

    string getInstructoresPorEspecialidad(const string& especialidad) const;
    string mostrarInstructoresPorEspecialidad(const string& especialidad) const;

    string toString() const;
    string toStringEspecifico(const string& cedula) const;
    void mostrarTodos() const;
    void mostrarInstructor(const string& cedula) const;
};