#pragma once
#include "cliente.h"

class vecClientes {
private:
    cliente** clientes;
    int tam;
    int cant;

public:
    vecClientes();
    ~vecClientes();

    bool agregar(cliente* cli);

    // Acceso no-const (permite modificar cliente o colecci�n)
    cliente* obtener(int indice);
    cliente* buscarPorCedula(string cedula);

    // Acceso const (permite llamar desde objetos const)
    cliente* obtener(string ced) const;
    cliente* buscarPorCedula(string cedula) const;

    int getCantidad() const;
    void mostrarLista() const;
    void generarReporteIMC() const;
};
