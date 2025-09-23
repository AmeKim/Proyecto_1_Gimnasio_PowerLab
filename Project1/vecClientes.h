#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "cliente.h"
using namespace std;

class vecClientes {
private:
    cliente** vClientes;
    int can;
    int tam = 30;
public:
    vecClientes();
    ~vecClientes();
    void agregarCliente(cliente*);
    void eliminarCliente(string);
    cliente* getCliente(string) const; 
    int getCan() const; 
    string toString() const; 
    string toStringEspecifico(string) const; 
    cliente* getClientePorIndice(int idx) const; 
    string mostrarTodos() const; 
};