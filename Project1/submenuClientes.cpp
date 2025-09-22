#include "submenuClientes.h"

submenuClientes::submenuClientes(vecClientes* vClientes, vecSucursales* vSucursales){
	this->vClientes = vClientes;
	this->vSucursales = vSucursales;
	continuacion = new char('s');
}

submenuClientes::~submenuClientes(){
	delete continuacion;
}

int submenuClientes::iniciar(){
	*continuacion = 's';
	do{
		limpiar();
		opcion = imprimirMenu();
		switch(opcion){
			case '1':
				incluirCliente();
				break;
			case '2':
				asignarInstructorCliente();
				break;
			case '3':
				ClientePorSucursal();
				break;
			case '4':
				mostrarCliente();
				break;
			case '0':
				print("Saliendo...\n");
				return 0;
				break;
			default:
				cout << "Opci" << char(162) << "n no v" << char(160) << "lida\n";
		}
		if(opcion != '4'){
			cout<< "Desea continuar en el submen" << char(163) << " de Clientes ? (s / n) : ";
			cin >> *continuacion;
			cin.ignore();
		}
	}while(*continuacion == 's' || *continuacion == 'S');
	cin.get();
	limpiar();
	return 0;
}

char submenuClientes::imprimirMenu(){
	char opcion;
	print("\n----------------------------------------------------\n");
	cout<< "\n-------SubMen" << char(163)<< "de Clientes-------\n";
	cout<<"Por favor escoja una opci" << char(162) << "n: \n";
	print("1. Ingresar un Cliente\n");
	print("2. Asignar Instructor a un Cliente\n");
	print("3. Mostrar Clientes por Sucursal\n");
	print("4. Mostrar detalle de un Cliente\n");
	print("0. Regresar al menu inicial\n\n");
	char num;
	cout<< "Ingrese la opci" << char(162) << "n (Ejm: 1): "; cin >> num;
	return num;
}

void submenuClientes::incluirCliente(){
	limpiar();
	print("-------------------Lista de Sucursales-------------------");
	vSucursales->mostrarTodas();
	cout<< "Ingrese el c" << char(162) << "digo de la Sucursal a mostrar: ";
	int cod = digNum();

	print("Ingrese el nombre del cliente: ");
	string nombre = digPalabra();

	print("Ingrese el ID del cliente: ");
	string cedula = digPalabra();
	if(vClientes->getCliente(cedula) != nullptr){
		cout<<"Ya existe un cliente con esa c" << char(162) << "dula\n";
		return;
	}

	print("Ingrese el telefono del cliente: ");
	string telefono = digPalabra();

	print("Ingrese el correo del cliente: ");
	string correo = digPalabra();

	print("Ingrese la fecha de nacimiento del cliente (dd/mm/aaaa): ");
	string fechaNacimiento = digPalabra();

	print("Ingrese el sexo del cliente (M/F): ");
	string sexo = digPalabra();

	print("Ingrese la fecha de inscripcion del cliente (dd/mm/aaaa): ");
	string fechaInscrip = digPalabra();

	cliente* nuevoCliente = new cliente(nombre, cedula, telefono, correo, fechaNacimiento, sexo, fechaInscrip);
	vClientes->agregarCliente(nuevoCliente);
	print("Cliente agregado exitosamente\n");
}

void submenuClientes::asignarInstructorCliente(){
	limpiar();
	print("-------------------Lista de Clientes-------------------");
	vClientes->mostrarTodos();
	cout<< "Ingrese la c" << char(162) << "dula del cliente a asignar instructor: ";
	string cedulaCli = digPalabra();
	cliente* cli = vClientes->getCliente(cedulaCli);
	if(cli == nullptr){
		cout<< "No existe un cliente con esa c" << char(162) << "dula\n";
		return;
	}
	print("-------------------Lista de Sucursales-------------------");
	vSucursales->mostrarTodas();
	cout<< "Ingrese el c" << char(162) << "digo de la Sucursal donde se encuentra el instructor: ";
	int cod = digNum();
	Sucursal* suc = vSucursales->getSucursal(cod);
	if(suc == nullptr){
		cout<< "No existe una sucursal con ese c" << char(162) << "digo\n";
		return;
	}
	print("-------------------Lista de Instructores-------------------");
	suc->getInstructores()->mostrarTodos();
	cout <<"Ingrese la c" << char(162) << "dula del instructor a asignar: ";
	string cedulaInst = digPalabra();
	instructor* inst = suc->getInstructores()->getInstructor(cedulaInst);
	if(inst == nullptr){
		cout<< "No existe un instructor con esa c" << char(162) << "dula en esa sucursal\n";
		return;
	}
	cli->setCedulaInstructorAsignado(cedulaInst);
	print("Instructor asignado exitosamente\n");
}

void submenuClientes::ClientePorSucursal(){
	limpiar();
	print("-------------------Lista de Sucursales-------------------");
	vSucursales->mostrarTodas();
	cout<< "Ingrese el c" << char(162) << "digo de la Sucursal a mostrar: ";
	int cod = digNum();
	Sucursal* suc = vSucursales->getSucursal(cod);
	if(suc == nullptr){
		cout<< "No existe una sucursal con ese c" << char(162) << "digo\n";
		return;
	}
	print("-------------------Lista de Clientes en la Sucursal-------------------");
	suc->getClientes()->mostrarTodos();
}

void submenuClientes::mostrarCliente(){
	limpiar();
	print("-------------------Lista de Clientes-------------------");
	vClientes->mostrarTodos();
	cout<< "Ingrese la c" << char(162) << "dula del cliente a mostrar: ";
	string cedulaCli = digPalabra();
	cliente* cli = vClientes->getCliente(cedulaCli);
	if(cli == nullptr){
		cout<< "No existe un cliente con esa c" << char(162) << "dula\n";
		return;
	}
	print("-------------------Detalle del Cliente-------------------\n");
	print(cli->toStringDetallado());
	print("--------------------------------------------------------\n");
	print("Desea ver el historial de mediciones del cliente? (s/n): ");
	char resp;
	cin >> resp;
	cin.ignore();
	if(resp == 's' || resp == 'S'){
		cli->mostrarHistorialMediciones();
	}
}


