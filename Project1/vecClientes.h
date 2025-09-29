#pragma once
#include "cliente.h"
#include <string>
using namespace std;

class vecClientes {
private:
    cliente** clientes;
    int tam;
    int cant;
    void expandir();

public:
    vecClientes();
    ~vecClientes();

    bool agregar(cliente* cli);
    cliente* obtener(int indice);
    cliente* buscarPorCedula(const string& cedula);
    int getCantidad() const;
    string listarSimple() const;
};