#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Sucursal.h"
#include "utiles.h"
using namespace std;

class vecSucursales {
private:
    Sucursal** sucursales;
    int can;
    int tam;

public:
    vecSucursales(int capacidad = 30);
    ~vecSucursales();

    // M�todos para agregar sucursales
    bool agregarSucursal(Sucursal* sucursal);
    bool agregarSucursal(int codigo, const string& provincia, const string& canton,
        const string& correo, const string& telefono);

    // B�squeda de sucursales
    Sucursal* buscarPorCodigo(int codigo) const;
    int buscarIndicePorCodigo(int codigo) const;

    // Eliminaci�n
    bool eliminarSucursal(int codigo);

    // Getters
    Sucursal* getSucursalPorIndice(int indice) const;
    int getCan() const;
    int getTam() const;
    bool estaLlena() const;
    bool estaVacia() const;

    // Validaciones
    bool existeCodigo(int codigo) const;

    // M�todos de presentaci�n
    void mostrarTodas() const;
    void mostrarSucursal(int codigo) const;
    string toString() const;
    string mostrarListaSimple() const; // Para mostrar lista en men�s
};