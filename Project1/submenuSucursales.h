#include <iostream>
#include <string>
#include <sstream>
#include "utiles.h"
#include "vecSucursales.h"
#include "Medicion.h"
using namespace std;

class submenuSucursales {

private:
	char opcion;
	char* continuacion;
	vecSucursales* vSucursales;
	char imprimirMenu();
	void addSucursal();
	void MostrarSucursal();
	void reporteIMC();

	public:
		submenuSucursales(vecSucursales* vSucursales);
		~submenuSucursales();
		int iniciar();
};