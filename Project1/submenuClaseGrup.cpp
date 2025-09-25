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
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el código de la Sucursal para la nueva clase grupal: ";
	string cod = digPalabra();
	Sucursal* sucursal = vSucursales->obtener(cod);
	if (sucursal == nullptr) {
		cout << "Error: No existe una sucursal con ese código.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	print("-------------Ingresando datos de la nueva Clase Grupal-------------\n");
	cout << "Ingrese el código de la nueva clase grupal (número entero): ";
	int codigo = digNum();
	if (vClasesGrupales->buscarPorCodigo(codigo) != nullptr) {
		cout << "Error: Ya existe una clase grupal con ese código.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	print("Ingrese el nombre de la clase grupal: ");
	string tipo = digPalabra();
	print("-------------Lista de Especialidades Disponibles-------------\n");
	vEspecialidades->listarTodas();
	print("Ingrese el nombre de la especialidad para esta clase grupal: ");
	string nombreEsp = digPalabra();
	if (!vEspecialidades->existeEspecialidad(nombreEsp)) {
		cout << "Error: No existe una especialidad con ese nombre.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	cout << "Ingrese el horario de la clase grupal (Ejem: Martes 10am): ";
	string horario = digPalabra();

	cout << "Ingrese el salón donde se realizará la clase grupal: ";
	string salon = digPalabra();

	cout << "Ingrese la capacidad máxima de la clase grupal (número entero): ";
	int capacidad = digNum();
	if (capacidad <= 0) {
		cout << "Error: Capacidad inválida.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}

	// Buscar instructores con la especialidad igual al tipo de la clase grupal
	vecInstructores* vInstructores = sucursal->getVecInstructores();
	if (vInstructores->getcantidad() == 0) {
		print("No hay instructores registrados en esta sucursal. No se puede asignar un instructor a la clase grupal.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	bool encontrado = false;
	for (int i = 0; i < vInstructores->getcantidad(); ++i) {
		Instructor* inst = vInstructores->obtener(cod);
		if (inst && inst->tieneEspecialidad(nombreEsp)) {
			if (!encontrado) {
				print("Instructores con la especialidad " + nombreEsp + ":\n");
				encontrado = true;
			}
			print(inst->toString() + "\n");
		}
	}
	if (!encontrado) {
		print("No hay instructores con esa especialidad en esta sucursal. No se puede asignar un instructor a la clase grupal.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	cout << "Ingrese la cédula del Instructor para esta clase grupal: ";
	string cedulaInst = digPalabra();
	Instructor* inst = vInstructores->buscarPorCedula(cedulaInst);
	if (!inst) {
		cout << "Error: No existe un instructor con esa cédula en esta sucursal.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	ClaseGrupal* nuevaClase = new ClaseGrupal(tipo, codigo,capacidad, salon, horario, cedulaInst);
	if (vClasesGrupales->agregar(nuevaClase)) {
		sucursal->getVecClasesGrupales()->agregar(nuevaClase);
		print("Clase grupal agregada exitosamente a la sucursal.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
	}
	else {
		cout << "Error: No se pudo agregar la clase grupal. Máximo de clases alcanzado o código duplicado.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		delete nuevaClase;
	}
}

void submenuClaseGrup::mostrarClasesPorSucursal(){
	limpiar();
	print("-------------------Mostrando Clases Grupales por Sucursal-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el código de la Sucursal para ver sus clases grupales: ";
	string cod = digPalabra();
	Sucursal* sucursal = vSucursales->obtener(cod);
	if (sucursal == nullptr) {
		cout << "Error: No existe una sucursal con ese código.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vecClasesGrupales* vClases = sucursal->getVecClasesGrupales();
	if (vClases->getCantidad() == 0) {
		print("No hay clases grupales registradas en esta sucursal.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vClases->mostrarLista();
}

void submenuClaseGrup::inscribirClienteClase(){
	limpiar();
	print("-------------------Inscribiendo Cliente a una Clase Grupal-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el código de la Sucursal para inscribir un cliente a una clase grupal: ";
	string cod = digPalabra();
	Sucursal* sucursal = vSucursales->obtener(cod);
	if (sucursal == nullptr) {
		cout << "Error: No existe una sucursal con ese código.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vecClientes* vCli = sucursal->getVecClientes();
	if (vCli->getCantidad() == 0) {
		print("No hay clientes registrados en esta sucursal.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vCli->mostrarLista();
	cout << "Ingrese la cédula del Cliente a inscribir en una clase grupal: ";
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
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vClases->mostrarLista();
	cout << "Ingrese el código de la Clase Grupal para inscribir al cliente: ";
	int codigoClase = digNum();
	ClaseGrupal* clase = vClases->buscarPorCodigo(codigoClase);
	if (!clase) {
		cout << "Error: No existe una clase grupal con ese código en esta sucursal.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	if (clase->matricularCliente(cedulaCli)) {
		print("Cliente inscrito exitosamente en la clase grupal.\n");
		print("<Digite enter para regresar>\n");
		cin.get();
	}
	else {
		cout << "Error: No se pudo inscribir al cliente. Puede que la clase esté llena o el cliente ya esté inscrito.\n";
		print("<Digite enter para regresar>\n");
		cin.get();
	}

}

void submenuClaseGrup::mostrarClasePorCliente(){
	limpiar();
	print("-------------------Mostrando Clases Grupales por Cliente-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
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
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
	vecClientes* vCli = sucursal->getVecClientes();
	if (vCli->getCantidad() == 0) {
		print("No hay clientes registrados en esta sucursal.\n");
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
		print("<Digite enter para regresar>\n");
		cin.get();
		return;
	}
}