#include "submenuSucursales.h"

submenuSucursales::submenuSucursales(vecSucursales* vSucursales){
	this->vSucursales = vSucursales;
	continuacion = new char('s');
}

submenuSucursales::~submenuSucursales(){
	delete continuacion;
}

int submenuSucursales::iniciar(){
	*continuacion = 's';
	do{
		limpiar();
		opcion = imprimirMenu();
		switch(opcion){
			case '1':
				addSucursal();
				break;
			case '2':
				MostrarSucursal();
				break;
			case '3':
				reporteIMC();
				break;
			case '4':
				print("Saliendo...\n");
				return 0;
			default:
				cout<< "Opci" << char(162) << "n no v" << char(160)<< "lida\n";
		}
		if(opcion != '4'){
			cout<< "Desea continuar en el submen" << char(163) << " de Sucursales ? (s / n) : ";
			cin >> *continuacion;
			cin.ignore();
		}
	}while(*continuacion == 's' || *continuacion == 'S');
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
	print("4. Regresar al menu inicial\n\n");
	char num;
	cout<< "Ingrese la opci" << char(162) << "n (Ejm: 1): "; cin >> num;
	return num;
	
}

void submenuSucursales::addSucursal(){
	limpiar();
	cout<< "Ingrese el c" << char(162) << "digo de la Sucursal : ";
	int cod = digNum();
	print("Ingrese la provincia donde se ubica la Sucursal: ");
	string prov = digPalabra();
	cout<< "Ingrese el cant" << char(162) << "n donde se ubica la Sucursal : ";
	string canton = digPalabra();
	print("Ingrese el correo de la Sucursal: ");
	string correo = digPalabra();
	cout<< "Ingrese el tel" << char(130)<< "fono de la Sucursal : ";
	string telefono = digPalabra();
	if(vSucursales->agregarSucursal(new Sucursal(cod, prov, canton, correo, telefono))){
		print("Sucursal agregada exitosamente\n");
	}
	else{
		cout<< "No se pudo agregar la Sucursal (posiblemente el c" << char(162) << "digo ya existe o se alcanz" << char(162) << " el l" << char(161) << "mite)\n";
	}
}

void submenuSucursales::MostrarSucursal(){
	cin.ignore();
	limpiarEnter();
	print("-------------------Lista de Sucursales-------------------");
	vSucursales->mostrarTodas();
	cout<< "Ingrese el c" << char(162) << "digo de la Sucursal a mostrar: ";
	int cod = digNum();
	if(vSucursales->existeCodigo((cod))){
		vSucursales->mostrarSucursal((cod));
	}
	else{
		cout<<"No se encontr" << char(162) << " la Sucursal con ese c" << char(162) << "digo\n";
	}
	limpiarEnter();
}

void submenuSucursales::reporteIMC(){
	limpiar();
	print("-------------------Lista de Sucursales-------------------");
	vSucursales->mostrarTodas();
	cout<<"Ingrese el c" << char(162) << "digo de la Sucursal para generar el reporte de IMC: ";
	int cod = digNum();
	Sucursal* suc = vSucursales->buscarPorCodigo(cod);
	if(suc){
		suc->reporteIMC();
	}
	else{
		cout<<"No se encontr" << char(162) << " la Sucursal con ese c" << char(162) << "digo\n";
	}
	limpiarEnter();
}


