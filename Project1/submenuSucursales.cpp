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
		case '1': addSucursal();
			break;
		case '2': MostrarSucursal();
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
	print("\n-----------------------------------------\n");
	cout<< "\n-------SubMen" << char(163)<< " de Sucursales-------\n";
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
	cin.ignore();
	limpiarEnter();
	print("-------------------Creando una nueva Sucursal-------------------\n");
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal: ";
	string codigo = digPalabra();
	print("Ingrese la provincia donde se ubica la Sucursal: ");
	string provincia = digPalabra();
	cout<< "Ingrese el cant" << char(162) << "n donde se ubica la Sucursal: ";
	string canton = digPalabra();
	print("Ingrese el correo de la Sucursal: ");
	string correo = digPalabra();
	cout<< "Ingrese el tel" << char(130) << "fono de la Sucursal: ";
	string telefono = digPalabra();
	Sucursal* nuevaSucursal = new Sucursal(codigo, provincia, canton, correo, telefono);
	if(vSucursales->insertar(nuevaSucursal)){
		print("Sucursal agregada exitosamente.\n");
		print("<Digite enter para regresar>\n");
		cin.get(); // Espera a que el usuario presione Enter
	}else{
		cout <<"Error: No se pudo agregar la sucursal. M"<< char(160) <<"ximo de sucursales alcanzado.\n";
		delete nuevaSucursal;
		print("<Digite enter para regresar>\n");
		cin.get();
	}
}

void submenuSucursales::MostrarSucursal(){
	cin.get();
	limpiarEnter();
	print("-------------------Mostrando una Sucursal-------------------\n");
	if(vSucursales->cantidad() == 0){
		print("No hay sucursales registradas.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
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
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}else{
		print("Sucursal no encontrada.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
	}
}

void submenuSucursales::reporteIMC() {
	cin.get();
	limpiarEnter();
	print("-------------------Reporte de IMC por Sucursal-------------------\n");
	if(vSucursales->cantidad() == 0){
		print("No hay sucursales registradas.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vSucursales->listarTodos();
	string codigo;
	cout<< "Ingrese el c" << char(162) << "digo de la Sucursal para generar el reporte de IMC: ";
	codigo = digPalabra();
	Sucursal* s = vSucursales->buscarPorCodigo(codigo);
	if(s){
		s->generarReporteIMC();
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}else{
		print("Sucursal no encontrada.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
	}
}