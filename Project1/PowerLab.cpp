#include "PowerLab.h"

PowerLab::PowerLab(){
	continuacion = new char('s');
	menuSucursales = new submenuSucursales(sucursales);
	menuClientes = new submenuClientes(clientes, sucursales);
	menuInstructores = new submenuInstructores(instructores, especialidades, sucursales);
	menuClasesGrupales = new submenuClaseGrup(clasesGrupales, clientes, sucursales, especialidades);

}

PowerLab::~PowerLab(){
	delete continuacion;
	delete menuSucursales;
	delete menuClientes;
	delete menuInstructores;
	delete menuClasesGrupales;
	delete especialidades;
	delete sucursales;
	delete clientes;
	delete instructores;
	delete clasesGrupales;
}

int PowerLab::iniciar(){
	*continuacion = 's';
	while (*continuacion == 's' || *continuacion == 'S') {
		limpiar();
		opcion = imprimirMenu();
		switch (opcion) {
		case '1': gestionarSucursales();
			break;
		case '2': gestionarClientes();
			break;
		case '3': gestionarInstructores();
			break;
		case '4': gestionarClasesGrupales();
			break;
		case '5':
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

char PowerLab::imprimirMenu() {
	print("---------------------------------------------------------------\n");
	cout << "---------Bienvenido a la Gesti" << char(162) << "n de Gimnasios PowerLab---------\n";
	print("---------------------------------------------------------------\n");	
	cout << "1. Ir a men" << char(163) << " de Sucursales\n";
	cout << "2. Ir a men" << char(163) << " de Clientes\n";
	cout << "3. Ir a men" << char(163) << " de Instructores\n";
	cout << "4. Ir a men" << char(163) << " de Clases Grupales\n";
	cout << "5. Salir\n";
	print("---------------------------------------------------------------\n");	
	print("---------------------------------------------------------------\n");
	char num;
	cout << "Por favor seleccione una opci" << (char)162 << "n:\n"; cin >> num;
	return num;
}

void PowerLab::gestionarSucursales(){ 	menuSucursales->iniciar(); }

void PowerLab::gestionarClientes() { menuClientes->iniciar(); }

void PowerLab::gestionarInstructores() { menuInstructores->iniciar(); }

void PowerLab::gestionarClasesGrupales() { menuClasesGrupales->iniciar(); }