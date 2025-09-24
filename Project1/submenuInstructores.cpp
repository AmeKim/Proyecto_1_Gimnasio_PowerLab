#include "submenuInstructores.h"

submenuInstructores::submenuInstructores(vecInstructores* vInstructores, vecEspecialidades* vEspecialidafes, vecSucursales* vSucursales){
	this->vInstructores = vInstructores;
	this->vEspecialidades = vEspecialidades;
	this->vSucursales = vSucursales;
	continuacion = new char('s');
}
submenuInstructores::~submenuInstructores(){
	delete continuacion;
}

int submenuInstructores::iniciar(){
	*continuacion = 's';
	do{
		limpiar();
		opcion = imprimirMenu();
		switch(opcion){
			case '1':
				incluirInstructor();
				break;
			case '2':
				mostrarInstructoresPorSucursal();
				break;
			case '3':
				mostrarInstructorDetalle();
				break;
			case '4':
				mostrarInstructorPorEspecialidad();
				break;
			case '5':
				mostrarClientesPorInstructor();
				break;
			case '6':
				generarMedicion();
				break;
			case '7':
				historialMediciones();
				break;
			case '8':
				ingresarEjecicioBateria();
				break;
			case '9':
				generarRutina();
				break;
			case '10':
				visualizarRutina();
				break;
			case '0':
				print("Saliendo...\n");
				return 0;
				break;
			default:
				cout << "Opci" << char(162) << "n no v" << char(160) << "lida\n";
		}
		if(opcion != '10'){
			cout<< "Desea continuar en el submen" << char(163) << " de Instructores ? (s / n) : ";
			cin >> *continuacion;
			cin.ignore();
		}
	}while(*continuacion == 's' || *continuacion == 'S');
	cin.get();
	limpiar();
	return 0;
}

char submenuInstructores::imprimirMenu(){
	char opcion;
	print("\n----------------------------------------------------\n");
	cout<< "\n-------SubMen" << char(163)<< "de Instructores-------\n";
	cout<<"Por favor escoja una opci" << char(162) << "n: \n";
	print("1. Ingresar un Instructor\n");
	print("2. Mostrar Instructores por Sucursal\n");
	print("3. Mostrar detalle de un Instructor\n");
	print("4. Mostrar Instructores por Especialidad\n");
	print("5. Mostrar Clientes por Instructor\n");
	cout << "6. Generar Medici"<< char(162) << "n para un Cliente\n";
	print("7. Historial de Mediciones por Instructor\n");
	print("8. Ingresar Ejercicio a Bateria de Ejercicios\n");
	print("9. Generar Rutina para un Cliente\n");
	print("10. Visualizar Rutina de un Cliente\n");
	print("0. Regresar al menu inicial\n\n");
	char num;
	cout<< "Ingrese la opci" << char(162) << "n (Ejm: 1): "; cin >> num;
	return num;	
}

void submenuInstructores::incluirInstructor(){
	limpiar();
	print("-------------------Creando un nuevo Instructor-------------------\n");
	if(vSucursales->cantidad() == 0){
		print("No hay sucursales registradas. No se puede agregar un instructor.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal a la que se asociar" << char(160) << " el Instructor: ";
		int cod = digNum();
		if (vSucursales->obtener(cod) == nullptr) {
			cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
			return;
		}
	print("-------------Ingresando datos de un nuevo Instructor-------------\n");
	cout << "Ingrese la c" << char(130) << "dula del Instructor: ";
	string cedula = digPalabra();

	print("Ingrese el nombre del Instructor: ");
	string nombre = digPalabra();

	print("Ingrese el correo del Instructor: ");
	string correo = digPalabra();

	cout << "Ingrese el tel" << char(130) << "fono del Instructor: ";
	string telefono = digPalabra();

	print("Ingrese la fecha de nacimiento del Instructor (dd/mm/aaaa): ");
	string fechaStr = digPalabra();
	fecha* fechaNac = new fecha(fechaStr);

	print("-------------Lista de Especialidades Disponibles-------------\n");
	vEspecialidades->listarTodas();

	print("Ingrese la cantidad de especialidades a asignar al Instructor: ");
	int cantEsp = digNum();
	if(cantEsp <= 0){
		print("Error: La cantidad de especialidades debe ser mayor a cero.\n");
		return;
	}
	especialidad** especialidades = new especialidad * [cantEsp];
	for(int i = 0; i < cantEsp; ++i){
		cout << "Ingrese el nombre de la especialidad " << (i + 1) << ": ";
		string nombreEsp = digPalabra();
		if(!vEspecialidades->existeEspecialidad(nombreEsp)){
			cout << "Error: No existe una especialidad con ese nombre.\n";
			--i; // repetir iteracion
			continue;
		}
		especialidades[i] = new especialidad(nombreEsp);
	}
	Instructor* nuevoInstructor = new Instructor(nombre, cedula, telefono, correo, fechaStr);
	for(int i = 0; i < cantEsp; ++i){
		nuevoInstructor->agregarEspecialidad(especialidades[i]->getNombre());
	}
	nuevoInstructor->setCodigoSucursal(vSucursales->obtener(cod)->getCodigo());
	if (vInstructores->insertar(nuevoInstructor)) {
		vSucursales->obtener(cod)->getVecInstructores()->insertar(nuevoInstructor);
		print("Instructor agregado exitosamente.\n");
	} else {
		cout << "Error: No se pudo agregar el instructor. M" << char(160) << "ximo de instructores alcanzado o c" << char(162) << "dula duplicada.\n";
		delete nuevoInstructor;
	}
	for(int i = 0; i < cantEsp; ++i){
		delete especialidades[i];
	}
	delete[] especialidades;
}

void submenuInstructores::mostrarInstructoresPorSucursal(){
	limpiar();
	print("-------------------Mostrando Instructores por Sucursal-------------------\n");
	if(vSucursales->cantidad() == 0){
		print("No hay sucursales registradas.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal para listar sus Instructores: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	string codigoSucursal = vSucursales->obtener(cod)->getCodigo();
	string ins = vSucursales->listarInstructoresPorSucursal(codigoSucursal);
	print(ins);
}

void submenuInstructores::mostrarInstructorDetalle(){
	limpiar();
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas. No se puede agregar un instructor.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal a la que se asociar" << char(160) << " el Instructor: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	print("-------------------Mostrando detalle de un Instructor-------------------\n");
	if(vInstructores->getcantidad() == 0){
		print("No hay instructores registrados.\n");
		return;
	}
	vInstructores->listarTodos();
	cout << "Ingrese la c" << char(130) << "dula del Instructor a mostrar: ";
	string cedula = digPalabra();
	Instructor* inst = vInstructores->buscarPorCedula(cedula);
	if(inst){
		print("Detalles del Instructor:\n");
		print(inst->toString());
	}else{
		print("Instructor no encontrado.\n");
	}
}

void submenuInstructores::mostrarInstructorPorEspecialidad(){
	limpiar();
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas. No se puede agregar un instructor.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal a la que se asociar" << char(160) << " el Instructor: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	print("-------------------Mostrando Instructores por Especialidad-------------------\n");
	if(vEspecialidades->getCantidad() == 0){
		print("No hay especialidades registradas.\n");
		return;
	}
	vEspecialidades->listarTodas();
	cout << "Ingrese el nombre de la Especialidad para listar sus Instructores: ";
	string nombreEsp = digPalabra();
	if(!vEspecialidades->existeEspecialidad(nombreEsp)){
		cout << "Error: No existe una especialidad con ese nombre.\n";
		return;
	}
	bool encontrado = false;
	for(int i = 0; i < vInstructores->getcantidad(); ++i){
		Instructor* inst = vInstructores->obtener(i);
		if(inst && inst->tieneEspecialidad(nombreEsp)){
			if(!encontrado){
				print("Instructores con la especialidad " + nombreEsp + ":\n");
				encontrado = true;
			}
			print(inst->toString() + "\n");
		}
	}
	if(!encontrado){
		print("No hay instructores con esa especialidad.\n");
	}
}

void submenuInstructores::mostrarClientesPorInstructor(){
	limpiar();
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas. No se puede agregar un instructor.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal a la que se asociar" << char(160) << " el Instructor: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	print("-------------------Mostrando Clientes por Instructor-------------------\n");
	if(vInstructores->getcantidad() == 0){
		print("No hay instructores registrados.\n");
		return;
	}
	vInstructores->listarTodos();
	cout << "Ingrese la c" << char(130) << "dula del Instructor para listar sus Clientes: ";
	string cedula = digPalabra();
	Instructor* inst = vInstructores->buscarPorCedula(cedula);
	if(!inst){
		cout << "Error: No existe un instructor con esa c" << char(162) << "dula.\n";
		return;
	}
	bool encontrado = false;
	for(int i = 0; i < vSucursales->cantidad(); ++i){
		vecClientes* vCli = vSucursales->obtener(i)->getVecClientes();
		if(vCli && vCli->getCantidad() > 0){
			for(int j = 0; j < vCli->getCantidad(); ++j){
				cliente* cli = vCli->obtener(j);
				if(cli && cli->getCedulaInstructor() == cedula){
					if(!encontrado){
						print("Clientes asignados al Instructor " + inst->getNombre() + ":\n");
						encontrado = true;
					}
					print(cli->toString() + "\n");
				}
			}
		}
	}
	if(!encontrado){
		print("No hay clientes asignados a este instructor.\n");
	}
}

void submenuInstructores::generarMedicion(){
	limpiar();
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas. No se puede agregar un instructor.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal a la que se asociar" << char(160) << " el Instructor: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	cout << "-------------------Generando Medici"<< char(162) << "n para un Cliente-------------------\n";
	if(vInstructores->getcantidad() == 0){
		print("No hay instructores registrados.\n");
		return;
	}
	vInstructores->listarTodos();
	cout << "Ingrese la c" << char(130) << "dula del Instructor que realiza la medici"<< char(162) << "n: ";
	string cedulaInst = digPalabra();
	Instructor* inst = vInstructores->buscarPorCedula(cedulaInst);
	if(!inst){
		cout << "Error: No existe un instructor con esa c" << char(162) << "dula.\n";
		return;
	}
	bool encontrado = false;
	for(int i = 0; i < vSucursales->cantidad(); ++i){
		vecClientes* vCli = vSucursales->obtener(i)->getVecClientes();
		if(vCli && vCli->getCantidad() > 0){
			for(int j = 0; j < vCli->getCantidad(); ++j){
				cliente* cli = vCli->obtener(j);
				if(cli && cli->getCedulaInstructor() == cedulaInst){
					if(!encontrado){
						print("Clientes asignados al Instructor " + inst->getNombre() + ":\n");
						encontrado = true;
					}
					print(cli->toString() + "\n");
				}
			}
		}
	}
	if(!encontrado){
		print("No hay clientes asignados a este instructor.\n");
		return;
	}
	cout << "Ingrese la c" << char(130) << "dula del Cliente al que se le va a realizar la medici"<< char(162) << "n: ";
	string cedulaCli = digPalabra();
	cliente* cli = nullptr;
	for(int i = 0; i < vSucursales->cantidad(); ++i){
		vecClientes* vCli = vSucursales->obtener(i)->getVecClientes();
		if(vCli){
			cli = vCli->buscarPorCedula(cedulaCli);
			if(cli != nullptr) break;
		}
	}
	if (!cli) {
		cout << "Error: No existe un cliente con esa c" << char(162) << "dula.\n";
		return;
	}
	cout << "Ingrese la fecha de la medici" << char(162) << "n (dd/mm/aaaa): ";
	string fechaStr = digPalabra();
	fecha* fechaMed = new fecha(fechaStr);
	if(!fechaMed->esValida()){
		cout << "Error: La fecha ingresada no es v" << char(160) << "lida.\n";
		delete fechaMed;
		return;
	}
	print("Ingrese el peso (kg): ");
	double peso = digDouble();

	print("Ingrese la estatura (m): ");
	double estatura = digDouble();

	print("Ingrese el porcentaje de grasa corporal (%): ");
	double grasaCorporal = digDouble();

	cout << "Ingrese el porcentaje de m" << char(163) << "sculo (%): ";
	double porcentajeMusculo = digDouble();

	Medicion* medicion = new Medicion(fechaStr, peso, estatura, grasaCorporal, porcentajeMusculo);
	medicion->calcularTodo(cli->getSexo());
	cli->getInstructor()->realizarMedicionCliente(medicion, cli->getNombre());
	cout << "Medici" << char(162) << "n agregada exitosamente al historial del Cliente.\n";
	delete fechaMed;
}

void submenuInstructores::historialMediciones() {
	limpiar();
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		return;
	}
	vSucursales->listarTodos();
	cout <<"Ingrese el c" << char(162) << "digo de la Sucursal: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	vecClientes* vCli = vSucursales->obtener(cod)->getVecClientes();
	if (vCli->getCantidad() == 0) {
		print("No hay clientes registrados en esta sucursal.\n");
		return;
	}
	vCli->mostrarLista();
	cout << "Ingrese la c" << char(130) << "dula del Cliente para ver su historial de mediciones: ";
	string cedulaCli = digPalabra();
	cliente* cli = vCli->buscarPorCedula(cedulaCli);
	if (!cli) {
		cout << "Error: No existe un cliente con esa c" << char(162) << "dula en esta sucursal.\n";
		return;
	}
	vecReportesM* historial = cli->getHistorialMediciones();
	if (historial->getCantidad() == 0) {
		print("El cliente no tiene mediciones registradas.\n");
		return;
	}
	print("Historial de Mediciones del Cliente " + cli->getNombre() + ":\n");
	historial->mostrarHistorial();
}

void submenuInstructores::ingresarEjecicioBateria(){
	limpiar();
	print("-------------------Ingresando Ejercicio a Bateria de Ejercicios-------------------\n");
	if(vSucursales->cantidad() == 0){
		print("No hay sucursales registradas.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal para agregar un ejercicio a su bater"<< char(161) << "a: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	BateriaEjercicios* bateria = vSucursales->obtener(cod)->getBateria();
	print("-------------Ingresando datos de un nuevo Ejercicio-------------\n");
	cout << "Ingrese el nombre del Ejercicio: ";
	string nombre = digPalabra();

	cout << "Ingrese la descripci" << char(162) << "n del Ejercicio (en que consiste): ";
	string descripcion = digPalabra();

	cout<< "Ingrese el m" << char(130) << "sculo objetivo del Ejercicio: ";
	cout << " (1-Pecho, 2-Tr" << char(161) << "ceps, 3-B" << char(161) << "ceps, 4-Piernas, 5-Espalda): ";
	int musculoObjetivo = digNum();
	if (musculoObjetivo < 1 || musculoObjetivo > 5) {
		cout << "Error: M" << char(130) << "sculo objetivo inv" << char(160) << "lido.\n";
		return;
	}
	Ejercicio* nuevoEjercicio = new Ejercicio(nombre, descripcion, musculoObjetivo);
	if (bateria->agregar(nuevoEjercicio)) {
		cout << "Ejercicio agregado exitosamente a la bater"<< char(161) << "a de ejercicios de la sucursal.\n";
	} else {
		cout << "Error: No se pudo agregar el ejercicio. M" << char(160) << "ximo de ejercicios alcanzado o ejercicio duplicado.\n";
		delete nuevoEjercicio;
	}
}

void submenuInstructores::generarRutina(){
	limpiar();
	print("-------------------Generando Rutina para un Cliente-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal para generar una rutina a un cliente: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	vecClientes* vCli = vSucursales->obtener(cod)->getVecClientes();
	if (vCli->getCantidad() == 0) {
		print("No hay clientes registrados en esta sucursal.\n");
		return;
	}
	vCli->mostrarLista();
	cout << "Ingrese la c" << char(130) << "dula del Cliente para generar su rutina: ";
	string cedulaCli = digPalabra();
	cliente* cli = vCli->buscarPorCedula(cedulaCli);
	if (!cli) {
		cout << "Error: No existe un cliente con esa c" << char(162) << "dula en esta sucursal.\n";
		return;
	}
	BateriaEjercicios* bateria = vSucursales->obtener(cod)->getBateria();
	if (bateria->getCantidad() == 0) {
		cout << "La bater"<< char(161) << "a de ejercicios de esta sucursal est"<< char(160) << " vac"<< char(161) << ". No se puede generar una rutina.\n";
		return;
	}
	Rutina* rutina = new Rutina();
	for (int zona = 1; zona <= 5; zona++) {
		int cantPorZona = bateria->getCantidadPorZona(zona);
		if (cantPorZona == 0) continue;
		bateria->mostrarPorZona(zona);
		cout << "Ingrese la cantidad de ejercicios a seleccionar para esta zona(m"<< char(160) << "ximo " << to_string(cantPorZona) << ") : ";
		int cantSeleccionar = digNum();
		if (cantSeleccionar <= 0 || cantSeleccionar > cantPorZona) {
			cout << "Error: Cantidad inv" << char(160) << "lida.\n";
			delete rutina;
			return;
		}
		for (int i = 0; i < cantSeleccionar; i++) {
			cout << "Ingrese el n" << char(163) << "mero del ejercicio " << (i + 1) << " para esta zona: ";
			int numEjercicio = digNum();
			Ejercicio* ej = bateria->obtenerPorZona(zona, numEjercicio - 1);
			if (!ej) {
				cout << "Error: Ejercicio inv" << char(160) << "lido.\n";
				--i; // repetir iteracion
				continue;
			}
			print("Ingrese la cantidad de series para este ejercicio: ");
			int series = digNum();
			if (series <= 0) {
				cout << "Error: La cantidad de series debe ser mayor a cero.\n";
				--i; // repetir iteracion
				continue;
			}
			print("Ingrese la cantidad de repeticiones por serie para este ejercicio: ");
			int repeticiones = digNum();
			if (repeticiones <= 0) {
				cout << "Error: La cantidad de repeticiones debe ser mayor a cero.\n";
				--i; // repetir iteracion
				continue;
			}
			rutina->agregarEjercicio(ej, series, repeticiones);
		}
	}
	cli->getInstructor()->agregarRutinaCliente(rutina, cedulaCli);
	cout << "Rutina generada exitosamente para el Cliente " << cli->getNombre() << ".\n";
}

void submenuInstructores::visualizarRutina(){
	limpiar();
	print("-------------------Visualizando Rutina de un Cliente-------------------\n");
	if (vSucursales->cantidad() == 0) {
		print("No hay sucursales registradas.\n");
		return;
	}
	vSucursales->listarTodos();
	cout << "Ingrese el c" << char(162) << "digo de la Sucursal para ver la rutina de un cliente: ";
	int cod = digNum();
	if (vSucursales->obtener(cod) == nullptr) {
		cout << "Error: No existe una sucursal con ese c" << char(162) << "digo.\n";
		return;
	}
	vecClientes* vCli = vSucursales->obtener(cod)->getVecClientes();
	if (vCli->getCantidad() == 0) {
		print("No hay clientes registrados en esta sucursal.\n");
		return;
	}
	vCli->mostrarLista();
	cout << "Ingrese la c" << char(130) << "dula del Cliente para ver su rutina: ";
	string cedulaCli = digPalabra();
	cliente* cli = vCli->buscarPorCedula(cedulaCli);
	if (!cli) {
		cout << "Error: No existe un cliente con esa c" << char(162) << "dula en esta sucursal.\n";
		return;
	}
	Rutina* rutina = cli->getRutinaActual();
	if (!rutina || rutina->getCantidad() == 0) {
		print("El cliente no tiene una rutina asignada.\n");
		return;
	}
	rutina->mostrarRutina(cli->getNombre());
}