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
	while (*continuacion == 's' || *continuacion == 'S') {
		limpiar();
		opcion = imprimirMenu();
		switch (opcion) {
		case '1': incluirCliente();
			break;
		case '2': asignarInstructorCliente();
			break;
		case '3': ClientePorSucursal();
			break;
		case '4': mostrarClienteDetalle();
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

void submenuClientes::incluirCliente() {
	limpiar();
	print("-------------------Creando un nuevo Cliente-------------------\n");
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal a la que se asociar" << char(160) << " el Cliente: ";
		int cod = digNum();
		if (vSucursales->obtener(cod) == nullptr) {
			cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
			print("<Digite enter para regresar>\n");
			cin.get();
			return;
		}
	print("-------------Ingresando datos de un nuevo Cliente-------------\n");
	cout << "Ingrese la c" << char(130) << "dula del Cliente: ";
	string cedula = digPalabra();

	print("Ingrese el nombre del Cliente: ");
	string nombre = digPalabra();

	print("Ingrese el correo del Cliente: ");
	string correo = digPalabra();

	cout << "Ingrese el tel" << char(130) << "fono del Cliente: ";
	string telefono = digPalabra();

	print("Ingrese el sexo del Cliente (M/F): ");
	char sexo;
	cin >> sexo;
	cin.ignore();

	print("Ingrese la fecha de nacimiento del Cliente (dd/mm/aaaa): ");
	string fechaStr = digPalabra();
	fecha* fechaNac = new fecha(fechaStr);

	cout << "Ingrese la fecha de inscripci" << char(162) << "n del Cliente (dd/mm/aaaa): ";
	string fechaInscStr = digPalabra();
	fecha* fechaInsc = new fecha(fechaInscStr);

	print("-------------------Lista de Instructores-------------------\n");
	vSucursales->obtener(cod)->getVecInstructores()->listarTodos();
	cout << "Ingrese la c" << char(130) << "dula del Instructor que desea asignar al Cliente: ";
	string cedulaInst = digPalabra();

	cliente* nuevoCliente = new cliente(nombre, cedula, telefono, correo, fechaStr, sexo, fechaInscStr, cedulaInst);
	if (vClientes->agregar(nuevoCliente)) {
		if (vSucursales->obtener(cod)->agregarCliente(nuevoCliente)) {
			print("Cliente agregado exitosamente.\n");
			print("<Digite enter para regresar>\n");
			cin.get();
		}
		else {
			cout << "Error: No se pudo agregar el cliente a la sucursal. C" << char(162) << "dula duplicada en la sucursal.\n";
			delete nuevoCliente;
			print("<Digite enter para regresar>\n");
			cin.get();
		}
	}
	else {
		cout << "Error: No se pudo agregar el cliente. C" << char(162) << "dula duplicada en el sistema.\n";
		delete nuevoCliente;
		print("<Digite enter para regresar>\n");
		cin.get();
	}
}

void submenuClientes::asignarInstructorCliente() {
	limpiar();
	print("-------------------Asignando Instructor a un Cliente-------------------\n");
	if (vClientes->getCantidad() == 0) {
		print("No hay clientes registrados.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vClientes->mostrarLista();
	cout << "Ingrese la c" << char(130) << "dula del Cliente al que desea asignar un Instructor: ";
	string cedulaCli = digPalabra();
	cliente* cli = vClientes->buscarPorCedula(cedulaCli);
	if (cli == nullptr) {
		cout << "Error: No existe un cliente con esa c" << char(162) << "dula.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	print("-------------------Lista de Instructores-------------------\n");
	bool encontrado = false;
	for (int i = 0; i < vSucursales->cantidad(); ++i) {
		vecInstructores* vInstructores = vSucursales->obtener(i)->getVecInstructores();
		if (vInstructores && vInstructores->getcantidad() > 0) {
			vInstructores->listarTodos();
			encontrado = true;
		}
	}
	if (!encontrado) {
		print("No hay instructores registrados en ninguna sucursal.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	cout << "Ingrese la c" << char(130) << "dula del Instructor que desea asignar al Cliente: ";
	string cedulaInst = digPalabra();
	Instructor* inst = nullptr;
	for (int i = 0; i < vSucursales->cantidad(); ++i) {
		vecInstructores* vInstructores = vSucursales->obtener(i)->getVecInstructores();
		if (vInstructores) {
			inst = vInstructores->buscarPorCedula(cedulaInst);
			if (inst != nullptr) break;
		}
	}
	if (inst == nullptr) {
		cout << "Error: No existe un instructor con esa c" << char(162) << "dula.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	cli->setCedulaInstructor(cedulaInst);
	print("Instructor asignado exitosamente al Cliente.\n");
	print("<Digite enter para regresar>\n");
	cin.get();
}

void submenuClientes::ClientePorSucursal() {
	limpiar();
	print("-------------------Mostrando Clientes por Sucursal-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal para listar sus Clientes: ";
	int cod = digNum();
	Sucursal* suc = vSucursales->obtener(cod);
	if (suc == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vecClientes* vCli = suc->getVecClientes();
	if (vCli == nullptr || vCli->getCantidad() == 0) {
		print("No hay clientes registrados en esta sucursal.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vCli->mostrarLista();
}

void submenuClientes::mostrarClienteDetalle() {
	limpiar();
	print("-------------------Mostrando detalle de un Cliente-------------------\n");
	if (vClientes->getCantidad() == 0) {
		print("No hay clientes registrados.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vClientes->mostrarLista();
	cout << "Ingrese la c" << char(130) << "dula del Cliente para ver su detalle: ";
	string cedulaCli = digPalabra();
	cliente* cli = vClientes->buscarPorCedula(cedulaCli);
	if (cli == nullptr) {
		cout << "Error: No existe un cliente con esa c" << char(162) << "dula.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	// Buscar nombre del instructor asignado
	string nombreInstructor = "No asignado";
	string cedulaInst = cli->getCedulaInstructor();
	if (!cedulaInst.empty()) {
		for (int i = 0; i < vSucursales->cantidad(); ++i) {
			vecInstructores* vInstructores = vSucursales->obtener(i)->getVecInstructores();
			if (vInstructores) {
				Instructor* inst = vInstructores->buscarPorCedula(cedulaInst);
				if (inst != nullptr) {
					nombreInstructor = inst->getNombre();
					break;
				}
			}
		}
	}
	// Buscar nombre de la sucursal del cliente
	string nombreSucursal = "No asignada";
	for (int i = 0; i < vSucursales->cantidad(); ++i) {
		vecClientes* vCli = vSucursales->obtener(i)->getVecClientes();
		if (vCli && vCli->buscarPorCedula(cedulaCli) != nullptr) {
			nombreSucursal = vSucursales->obtener(i)->getProvincia() + " - " + vSucursales->obtener(i)->getCanton();
			break;
		}
	}
	print(cli->toStringDetalle(nombreInstructor, nombreSucursal));
}
