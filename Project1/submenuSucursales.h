#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "vecSucursales.h"
#include "Medicion.h"
using namespace std;

class submenuClaseGrup {

private:
	char opcion;
	char* continuacion;
	vecSucursales* vSucursales;
	char imprimirMenu();
	void addSucursal();
	void MostrarSucursales();
	void reporteIMC();


};