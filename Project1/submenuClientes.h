#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "vecClientes.h"
#include "vecSucursales.h"
using namespace std;

class submenuClientes{
private: 
	char opcion;
	char* continuacion;
	vecClientes* vClientes;
	vecSucursales* vSucursales;
	char imprimirMenu();
	void incluirCliente();
	void asignarInstructorCliente();
	void ClientePorSucursal();
	void mostrarClienteDetalle();
public:
	submenuClientes(vecClientes* vClientes, vecSucursales* vSucursales);
	~submenuClientes();
	int iniciar();
};

