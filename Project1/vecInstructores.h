#pragma once
#include "instructor.h"
#include <string>

using namespace std;

class vecInstructores {
public:
    vecInstructores(int capacidadInicial = 8);
    ~vecInstructores();

    int getCantidad();
    void agregar(const instructor& ins);
    int tamanio() const;
    const instructor& obtener(int idx) const;
    instructor& obtener(int idx);
    int indicePorCedula(string cedula) const;
    void limpiar();

private:
    void asegurarCapacidad(int nuevaCapacidad);
    instructor* datos;
    int capacidad;
    int cantidad;
};