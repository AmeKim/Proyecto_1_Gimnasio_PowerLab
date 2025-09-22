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
				mostrarInstructorPorSucursal();
				break;
			case '3':
				mostrarInstructor();
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
				historialMedicionesInstructor();
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

void submenuInstructores::incluirInstructor() {
	limpiar();
	print("Ingrese el nombre del instructor: ");
	string nombre = digPalabra();

	cout << "Ingrese la c" << char(162) << "dula del instructor: ";
	string cedula = digPalabra();


	cout << "Ingrese el tel" << char(130) << "fono del instructor: ";
	string telefono = digPalabra();

	print("Ingrese el correo del instructor: ");
	string correo = digPalabra();

	print("Ingrese la fecha de nacimiento del instructor (dd/mm/aaaa): ");
	string fechaNacimiento = digPalabra();

	print("Especialidades disponibles:\n");
	cout << vEspecialidades->toString();
	print("Ingrese el ID de la especailidad del instructor: ");
	int idEspecialidad = digNum();

	instructor* nuevoInstructor = new instructor(cedula, nombre, telefono, correo, fechaNacimiento);
	if (vInstructores->agregarInstructor(nuevoInstructor)) {
		especialidad* esp = vEspecialidades->buscarPorId(idEspecialidad);
		print("Instructor agregado exitosamente.\n");
		if (esp) {
			if (nuevoInstructor->agregarEspecialidad(esp)) {
				print("Especialidad agregada exitosamente.\n");
			}
			else {
				print("El instructor ya tiene esta especialidad.\n");
			}
		}
		else {
			print("Especialidad no encontrada.\n");
		}
		// Agregar especialidades
		char agregarOtra;
		do {
			print("Desea agregar una especialidad al instructor? (s/n): ");
			cin >> agregarOtra;
			cin.ignore();
			if (agregarOtra == 's' || agregarOtra == 'S') {
				vEspecialidades->mostrarTodas();
				print("Ingrese el ID de la especialidad a agregar: ");
				int idEspecialidad;
				cin >> idEspecialidad;
				cin.ignore();
				especialidad* esp = vEspecialidades->buscarPorId(idEspecialidad);
				if (esp) {
					if (nuevoInstructor->agregarEspecialidad(esp)) {
						print("Especialidad agregada exitosamente.\n");
					} else {
						print("El instructor ya tiene esta especialidad.\n");
					}
				} else {
					print("Especialidad no encontrada.\n");
				}
			}
		} while (agregarOtra == 's' || agregarOtra == 'S');
	} else {
		cout<<"Error: No se pudo agregar el instructor. Puede que ya exista o se haya alcanzado el l" << char(161) << "mite m" << char(160) << "ximo.\n";
		delete nuevoInstructor; // Liberar memoria si no se agrega
	}
}

void submenuInstructores::mostrarInstructorPorSucursal() {
	limpiar();
	print("Sucursales disponibles:\n");
	cout << vSucursales->toString();
	print("Ingrese el ID de la sucursal para ver sus instructores: ");
	int idSucursal = digNum();
	Sucursal* suc = vSucursales->buscarPorCodigo(idSucursal);
	if (suc) {
		cout << "Instructores en la sucursal " << suc->getCodigo() << ":\n";
		cout<< vInstructores->getInstructoresPorSucursal(idSucursal);
	} else {
		print("Sucursal no encontrada.\n");
	}
}