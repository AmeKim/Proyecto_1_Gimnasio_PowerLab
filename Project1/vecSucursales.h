#pragma once
#include "Sucursal.h"

class vecSucursales {
private:
    Sucursal** datos;
    int tam;
    int cant;
    void expandir();

public:
    vecSucursales(int capacidadInicial = 10);
    ~vecSucursales();

    bool insertar(Sucursal* s); // false si codigo duplicado
    Sucursal* buscarPorCodigo(const string& codigo) const;
    int indicePorCodigo(const string& codigo) const;
    Sucursal* obtener(string cod) const;
    int cantidad() const;
    void listarTodos() const;
    bool eliminarPorCodigo(const string& codigo);
	string listarInstructoresPorSucursal(string codigo);
};