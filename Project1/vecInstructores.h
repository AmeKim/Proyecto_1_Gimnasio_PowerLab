#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "instructor.h"
#include "utiles.h"
using namespace std;

class vecInstructores {
private:
    instructor** vInstructores;
    int can;
    int tam = 30;
public:
    vecInstructores();
    ~vecInstructores();
    void agregarInstructor(instructor* inst);
    void eliminarInstructor(string cedula);
    instructor* getInstructor(const string& cedula);
    instructor* getInstructorPorIndice(int idx);
    int getCan() const;
    string toString() const;
    string toStringEspecifico(string cedula) const;
    // Métodos adicionales para búsqueda por especialidad
    string getInstructoresPorEspecialidad(const string& especialidad) const;
};