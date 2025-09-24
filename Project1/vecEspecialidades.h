#pragma once
#include <string>
#include <sstream>
#include "especialidad.h"
#include "utiles.h"

class vecEspecialidades {
private:
    especialidad** especialidades;
    int tam;
    int cant;

public:
    vecEspecialidades();
    ~vecEspecialidades();

    void agregar(especialidad* esp);
    especialidad* obtener(int indice);
    int getCantidad() const;
    bool buscar(string nombre);
    string toString() const;
	void listarTodas() const;
	bool existeEspecialidad(string nombre) const;
    int getCantidad();
};
