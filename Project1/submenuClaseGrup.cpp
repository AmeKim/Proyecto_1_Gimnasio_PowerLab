#include "submenuClaseGrup.h"

submenuClaseGrup::submenuClaseGrup(vecClasesGrupales* vClasesGrupales, vecClientes* vClientes, vecSucursales* vSucursales, vecEspecialidades* vEspecialidades) {
	this->vClasesGrupales = vClasesGrupales;
	this->vClientes = vClientes;
	this->vSucursales = vSucursales;
	this->vEspecialidades = vEspecialidades;
	continuacion =  new char('s');
}

submenuClaseGrup::~submenuClaseGrup() {
	delete continuacion;
}

int submenuClaseGrup::iniciar() {
	*continuacion = 's';
	while (*continuacion == 's' || *continuacion == 'S') {
		limpiar();
		opcion = imprimirMenu();
		switch (opcion) {
		case '1': crearClaseGrupal();
			break;
		case '2': mostrarClasesPorSucursal();
			break;
		case '3': inscribirClienteClase();
			break;
		case '4': mostrarClasePorCliente();
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

char submenuClaseGrup::imprimirMenu() {
	cout << "---------------Submen"<< char(163) << " de Clases Grupales---------------\n";
	print("1. Crear Clase Grupal\n");
	print("2. Mostrar Clases por Sucursal\n");
	print("3. Inscribir Cliente a Clase\n");
	print("4. Mostrar Clases por Cliente\n");
	print("0. Salir\n");
	char num;
	print("Ingrese la opcion: "); cin >> num;
	return num;
}

void submenuClaseGrup::crearClaseGrupal() {
	limpiar();
	print("-------------------Creando una nueva Clase Grupal-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas. No se puede agregar una clase grupal.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	if (vEspecialidades->getCantidad() == 0) {
		print("No hay especialidades registradas. No se puede crear una clase grupal. \n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el código de la Sucursal para la nueva clase grupal: ";
	cin.ignore();
	string cod = digPalabra();
	Sucursal* sucursal = vSucursales->obtener(cod);
	if (sucursal == nullptr) {
		cout << "Error: No existe una sucursal con ese código.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vecInstructores* vInstructoresSucursal = vSucursales->buscarPorCodigo(cod)->getVecInstructores();
	if (vInstructoresSucursal == nullptr || vInstructoresSucursal->getcantidad() == 0) {
		print("No hay instructores registrados en esta sucursal. No se puede crear una clase grupal.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	print("-------------Ingresando datos de la nueva Clase Grupal-------------\n");
	cout << "Ingrese el c" << char(162) << "digo de la nueva Clase Grupal(Ejemplo: 01): ";
	int codigo = digNum();
	cout << "Ingrese la el horario en que se va a impartir la Clase Grupal (Ejemplo: Lunes de 13 a 15): ";
	string horario = digPalabra();

	cout << "Ingrese el numero de Sal" << char(162) << "n donde se impartir" << char(160) << " la Clase Grupal: ";
	string salon = digPalabra();

	cout << "Ingrese la capacidad m" << char(160) << "xima de participantes: ";
	int capacidadMaxima = digNum();
	if (capacidadMaxima <= 0) {
		cout << "Error: La capacidad m" << char(160) << "xima debe ser mayor a cero.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	print("-------------------Lista de Especialidades-------------------\n");
	vEspecialidades->listarTodas();
	cout << "Ingrese el nombre de la especialidad de la clase: ";
	string tipo = digPalabra();
	if (!vEspecialidades->existeEspecialidad(tipo)) {
		cout << "Error: No existe una especialidad con ese nombre.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	print("-------------------Lista de Instructores-------------------\n");
	vInstructoresSucursal->listarTodos();
	cout << "Ingrese la c" << char(130) << "dula del Instructor que impartir" << char(160) << " la clase: ";
	string cedulaInstructor = digPalabra();
	Instructor* instructor = vInstructoresSucursal->buscarPorCedula(cedulaInstructor);
	if (instructor == nullptr) {
		cout << "Error: No existe un instructor con esa c" << char(162) << "dula en esta sucursal.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	// Verificar que el instructor tiene la especialidad requerida
	if (!instructor->tieneEspecialidad(tipo)) {
		cout << "Error: El instructor seleccionado no tiene la especialidad requerida para esta clase.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	ClaseGrupal* nuevaClase = new ClaseGrupal(tipo, codigo, capacidadMaxima, salon, horario, cedulaInstructor);

	if (vClasesGrupales->agregar(nuevaClase)) {
		cout << "Clase grupal creada exitosamente.\n";
	}
	else {
		cout << "Error: No se pudo crear la clase grupal.\n";
		delete nuevaClase;
	}

	cout << endl << endl;
	print("<Digite enter para regresar>\n");
	cin.get();
}

void submenuClaseGrup::mostrarClasesPorSucursal(){
	limpiar();
	print("-------------------Mostrando Clases Grupales por Sucursal-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el código de la Sucursal para ver sus clases grupales: ";
	cin.ignore();
	string cod = digPalabra();

	Sucursal* sucursal = vSucursales->buscarPorCodigo(cod);
	if (sucursal == nullptr) {
		cout << "Error: No existe una sucursal con ese código.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	bool hayClases = false;
	print("Clases Grupales en la sucursal " + sucursal->getProvincia() + " - " + sucursal->getCanton() + ":\n");
	vecClasesGrupales* vClases = sucursal->getVecClasesGrupales();
	if (vClases->getCantidad() == 0) {
		print("No hay clases grupales registradas en esta sucursal.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vClases->mostrarLista();
}

void submenuClaseGrup::inscribirClienteClase(){
	limpiar();
	print("-------------------Inscribiendo Cliente a Clase Grupal-------------------\n");

	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	if (vClasesGrupales->getCantidad() == 0) {
		print("No hay clases grupales registradas.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	if (vClientes->getCantidad() == 0) {
		print("No hay clientes registrados.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal: ";
	cin.ignore();
	string cod = digPalabra();

	Sucursal* sucursal = vSucursales->buscarPorCodigo(cod);
	if (sucursal == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	// Mostrar clases disponibles de esta sucursal	
	bool hayClases = false;
	print("Clases grupales disponibles:\n");
	for (int i = 0; i < vClasesGrupales->getCantidad(); ++i) {
		ClaseGrupal* clase = vClasesGrupales->obtener(i);
		if (clase && clase->getCodigoSucursal() == cod) {
			if (!hayClases) {
				hayClases = true;
			}
			cout << "ID: " << clase->getCodigo() << " - " << clase->toString() << "\n";
		}
	}

	if (!hayClases) {
		print("No hay clases grupales disponibles en esta sucursal.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	cout << "Ingrese el ID de la clase a la que desea inscribir el cliente: ";
	int idClase = digNum();
	ClaseGrupal* claseSeleccionada = nullptr;

	// Buscar la clase por ID y verificar que pertenezca a la sucursal
	for (int i = 0; i < vClasesGrupales->getCantidad(); ++i) {
		ClaseGrupal* clase = vClasesGrupales->obtener(i);
		if (clase && clase->getCodigo() == idClase && clase->getCodigoSucursal() == cod) {
			claseSeleccionada = clase;
			break;
		}
	}

	if (claseSeleccionada == nullptr) {
		cout << "Error: No existe una clase con ese ID en esta sucursal.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	// Verificar capacidad
	if (claseSeleccionada->capacidadSuperada()) {
		cout << "Error: La clase seleccionada ya alcanz" << char(162) << " su capacidad m" << char(160) << "xima.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	// Mostrar clientes de la sucursal
	vecClientes* vCliSucursal = sucursal->getVecClientes();
	if (vCliSucursal == nullptr || vCliSucursal->getCantidad() == 0) {
		print("No hay clientes registrados en esta sucursal.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	print("Clientes disponibles en esta sucursal:\n");
	vCliSucursal->mostrarLista();

	cout << "Ingrese la c" << char(130) << "dula del cliente a inscribir: ";
	string cedulaCliente = digPalabra();

	cliente* clienteSeleccionado = vCliSucursal->buscarPorCedula(cedulaCliente);
	if (clienteSeleccionado == nullptr) {
		cout << "Error: No existe un cliente con esa c" << char(162) << "dula en esta sucursal.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	// Verificar si el cliente ya está inscrito
	if (claseSeleccionada->estaMatriculado(cedulaCliente)) {
		cout << "Error: El cliente ya est" << char(160) << " inscrito en esta clase.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	// Inscribir cliente
	if (claseSeleccionada->matricularCliente(cedulaCliente)) {
		cout << "Cliente inscrito exitosamente en la clase grupal.\n";
	}
	else {
		cout << "Error: No se pudo inscribir el cliente en la clase.\n";
	}

	cout << endl << endl;
	print("<Digite enter para regresar>\n");
	cin.get();
}

void submenuClaseGrup::mostrarClasePorCliente(){
	limpiar();
	print("-------------------Mostrando Clases Grupales por Cliente-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el código de la Sucursal para ver las clases grupales de un cliente: ";
	string cod = digPalabra();
	Sucursal* sucursal = vSucursales->obtener(cod);
	if (sucursal == nullptr) {
		cout << "Error: No existe una sucursal con ese código.\n";
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vecClientes* vCli = sucursal->getVecClientes();
	if (vCli->getCantidad() == 0) {
		print("No hay clientes registrados en esta sucursal.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vCli->mostrarLista();
	cout << "Ingrese la cédula del Cliente para ver sus clases grupales: ";
	string cedulaCli = digPalabra();
	cliente* cli = vCli->buscarPorCedula(cedulaCli);
	if (!cli) {
		cout << "Error: No existe un cliente con esa cédula en esta sucursal.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vecClasesGrupales* vClases = sucursal->getVecClasesGrupales();
	if (vClases->getCantidad() == 0) {
		print("No hay clases grupales registradas en esta sucursal.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	bool encontrado = false;
	for (int i = 0; i < vClases->getCantidad(); ++i) {
		ClaseGrupal* clase = vClases->obtener(i);
		if (clase && clase->estaMatriculado(cedulaCli)) {
			if (!encontrado) {
				print("Clases grupales en las que está inscrito el cliente " + cli->getNombre() + ":\n");
				encontrado = true;
			}
			print(clase->toString() + "\n");
		}
	}
	if (!encontrado) {
		print("El cliente no está inscrito en ninguna clase grupal.\n");
		cout << endl << endl;
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
}