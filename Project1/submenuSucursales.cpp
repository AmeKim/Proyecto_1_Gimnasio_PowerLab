#include "submenuSucursales.h"

submenuSucursales::submenuSucursales(vecSucursales* vSucursales){
	this->vSucursales = vSucursales;
	continuacion = new char('s');
}

submenuSucursales::~submenuSucursales(){
	delete continuacion;
}

int submenuSucursales::iniciar() {
	*continuacion = 's';
	while (*continuacion == 's' || *continuacion == 'S') {
		limpiar();
		opcion = imprimirMenu();
		switch (opcion) {
		case '1': MostrarSucursal();
			break;
		case '2': addSucursal();
			break;
		case '3': reporteIMC();
			break;
		case '0':
			print("Saliendo...\n");
			*continuacion = 'n';
			break;
		default:
			cout << "Error: Por favor digite una opci" << char(162) << "n v" << char(160) << "lida\n";
			print("\n------------------------------------\n");
			limpiarEnter();
			continue;
		}
	}
	cin.get();
	limpiar();
	return 0;
}

char submenuSucursales::imprimirMenu(){
	char opcion;
	print("\n----------------------------------------------------\n");
	cout<< "\n-------SubMen" << char(163)<< "de Sucursales-------\n";
	cout<< "Por favor escoja una opci"<< char(162) <<"n: \n";
	print("1. Ingresar una Sucursal\n");
	print("2. Muestre una Sucursal\n");
	print("3. Mostrar reporte de IMC por Sucursal\n");
	cout<< "0. Regresar al men" << char(163)<< "u principal\n\n";
	char num;
	cout<< "Ingrese la opci" << char(162) << "n (Ejm: 1): "; cin >> num;
	return num;
	
}

void submenuSucursales::addSucursal(){
	limpiar();
	print("-------------------Creando una nueva Sucursal-------------------\n");
	string codigo, provincia, canton, correo, telefono;
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal: ";
	codigo = digPalabra();
	print("Ingrese la provincia donde se ubica la Sucursal: ");
	provincia = digPalabra();
	cout<< "Ingrese el cant" << char(162) << "n donde se ubica la Sucursal: ";
	canton = digPalabra();
	print("Ingrese el correo de la Sucursal: ");
	correo = digPalabra();
	cout<< "Ingrese el tel" << char(130) << "fono de la Sucursal: ";
	telefono = digPalabra();
	Sucursal* nuevaSucursal = new Sucursal(codigo, provincia, canton, correo, telefono);
	if(vSucursales->insertar(nuevaSucursal)){
		print("Sucursal agregada exitosamente.\n");
	}else{
		cout <<"Error: No se pudo agregar la sucursal. M"<< char(160) <<"ximo de sucursales alcanzado.\n";
		delete nuevaSucursal;
	}
}

void submenuSucursales::MostrarSucursal(){
	limpiar();
	print("-------------------Mostrando una Sucursal-------------------\n");
	if(vSucursales->cantidad() == 0){
		print("No hay sucursales registradas.\n");
		return;
	}
	vSucursales->listarTodos();
	string codigo;
	cout<< "Ingrese el c" << char(162) << "digo de la Sucursal a mostrar: ";
	codigo = digPalabra();
	Sucursal* s = vSucursales->buscarPorCodigo(codigo);
	if(s){
		print("Detalles de la Sucursal:\n");
		s->toString();
	}else{
		print("Sucursal no encontrada.\n");
	}
}

void submenuSucursales::reporteIMC() {
	limpiar();
	print("-------------------Reporte de IMC por Sucursal-------------------\n");
	if(vSucursales->cantidad() == 0){
		print("No hay sucursales registradas.\n");
		return;
	}
	vSucursales->listarTodos();
	string codigo;
	cout<< "Ingrese el c" << char(162) << "digo de la Sucursal para generar el reporte de IMC: ";
	codigo = digPalabra();
	Sucursal* s = vSucursales->buscarPorCodigo(codigo);
	if(s){
		s->generarReporteIMC();
	}else{
		print("Sucursal no encontrada.\n");
	}
}

