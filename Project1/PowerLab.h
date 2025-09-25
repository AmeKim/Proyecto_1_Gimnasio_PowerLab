#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "vecEspecialidades.h"
#include "submenuSucursales.h"
#include "vecSucursales.h"
#include "submenuClientes.h"
#include "vecClientes.h"
#include "submenuInstructores.h"
#include "vecInstructores.h"
#include "submenuClaseGrup.h"
#include "vecClasesGrupales.h"
using namespace std;


class PowerLab{
	private: 
		char opcion;
		char* continuacion;
		vecEspecialidades* especialidades = new vecEspecialidades;
		submenuSucursales* menuSucursales;
		vecSucursales* sucursales = new vecSucursales;
		submenuClientes* menuClientes;
		vecClientes* clientes = new vecClientes;
		submenuInstructores* menuInstructores;
		vecInstructores* instructores = new vecInstructores;
		submenuClaseGrup* menuClasesGrupales;
		vecClasesGrupales* clasesGrupales = new vecClasesGrupales;
		char imprimirMenu();
		void gestionarSucursales();
		void gestionarClientes();
		void gestionarInstructores();
		void gestionarClasesGrupales();
public:
	PowerLab();
	~PowerLab();
	int iniciar();
};