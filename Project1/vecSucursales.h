#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Sucursal.h"
using namespace std;

class vecSucursales {
private:
    Sucursal** sucursales;
    int can;
    int tam;

public:
    vecSucursales(int capacidad = 30);
    ~vecSucursales();

    bool agregarSucursal(Sucursal* sucursal);
    void eliminarSucursal(int codigo);
    Sucursal* buscarPorCodigo(int codigo) const;
    bool existeCodigo(int codigo) const;

    int getCan() const;
    int getTam() const;

    void mostrarTodas() const;
    void mostrarSucursal(int codigo) const;

    string toString() const;
    Sucursal* getSucursalPorIndice(int indice) const;
	Sucursal* getSucursal(int codigo) const;
};