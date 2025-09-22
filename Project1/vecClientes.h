#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "cliente.h"
using namespace std;

class vecClientes{
	private:
	cliente** vClientes;
	int can;
	int tam = 30;
public:
	vecClientes();
	~vecClientes();
	void agregarCliente(cliente*);
	void eliminarCliente(string);
	cliente* getCliente(string);
	int getCan();
	string toString();
	string toStringEspecifico(string);
	cliente* getClientePorIndice(int idx);
	string mostrarTodos();
};

