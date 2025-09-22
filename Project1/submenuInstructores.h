#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "vecInstructores.h"
#include "vecEspecialidades.h"
#include "vecSucursales.h"

class submenuInstructores{
	private: 
	char opcion;
	char* continuacion;
	vecInstructores* vInstructores;
	vecEspecialidades* vEspecialidades;
	vecSucursales* vSucursales;
	char imprimirMenu();
	void incluirInstructor();
	void mostrarInstructorPorSucursal();
	void mostrarInstructor();
	void mostrarInstructorPorEspecialidad();
	void mostrarClientesPorInstructor();
	void generarMedicion();
	void historialMedicionesInstructor();
	void ingresarEjecicioBateria();
	void generarRutina();
	void visualizarRutina();

public:
	submenuInstructores(vecInstructores* vInstructores, vecEspecialidades* vEspecialidades, vecSucursales* vSucursales);
	~submenuInstructores();
	int iniciar();
};

