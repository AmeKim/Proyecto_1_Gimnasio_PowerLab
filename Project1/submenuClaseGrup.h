#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "vecClasesGrupales.h"
#include "vecClientes.h"
#include "vecSucursales.h"
#include "vecEspecialidades.h"
using namespace std;

class submenuClaseGrup{
private: 
	char opcion;
	char* continuacion;
	vecClasesGrupales* vClasesGrupales;
	vecClientes* vClientes;
	vecSucursales* vSucursales;
	vecEspecialidades* vEspecialidades;
	char imprimirMenu();
	void crearClaseGrupal();
	void mostrarClasesPorSucursal();
	void inscribirClienteClase();
	void mostrarClasePorCliente();

public:
	submenuClaseGrup(vecClasesGrupales* vClasesGrupales, vecClientes* vClientes, vecSucursales* vSucursales, vecEspecialidades* vEspecialidades);
	~submenuClaseGrup();
	int iniciar();

};

