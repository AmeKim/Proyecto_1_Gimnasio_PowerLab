#pragma once
#include "especialidad.h"

using namespace std;

class vecEspecialidades {
public:
    vecEspecialidades(int capacidadInicial = 8);
    vecEspecialidades(const vecEspecialidades& otro);
    ~vecEspecialidades();
    vecEspecialidades& operator=(const vecEspecialidades& otro);
    // Inicialización
    void cargarEspecialidadesPorDefecto();

    // Operaciones básicas
    void agregar(const Especialidad& e);
    void limpiar();
    int getCantidad() const;
    const Especialidad& obtener(int indice) const;
    Especialidad& obtener(int indice);

    // Búsqueda
    int indicePorNombre(const string& nombre) const;
    bool existe(const string& nombre) const;

private:
    void asegurarCapacidad(int nuevaCapacidad);
    Especialidad* datos;
    int capacidad;
    int cantidad;
};