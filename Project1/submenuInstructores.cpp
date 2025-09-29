#include "submenuInstructores.h"
#include "utiles.h"
#include "Medicion.h"
#include "fecha.h"
#include "especialidad.h"

void submenuInstructores::mostrar(vecSucursales* sucursales, BateriaEjercicios* bateria) {
    int opcion = -1;
    while (opcion != 0) {
        limpiar();
        print("========================================\n");
        print("3- SubMenu Instructores\n");
        print("========================================\n");
        print("(1) Incluir Instructor\n");
        print("(2) Lista de Instructores por Sucursal\n");
        print("(3) Detalle de Instructor\n");
        print("(4) Instructores por Especialidad\n");
        print("(5) Clientes por Instructor\n");
        print("(6) Generar Medicion a Cliente\n");
        print("(7) Historial de Mediciones\n");
        print("(8) Ingresar Ejercicio a la Bateria\n");
        print("(9) Generar rutina\n");
        print("(10) Visualizacion de Rutina\n");
        print("(0) Regresar al Menu Principal\n");
        print("Digite la opcion deseada: ");
        opcion = digNum();

        switch (opcion) {
        case 1: incluirInstructor(sucursales); break;
        case 2: listaInstructoresPorSucursal(sucursales); break;
        case 3: detalleInstructor(sucursales); break;
        case 4: instructoresPorEspecialidad(sucursales); break;
        case 5: clientesPorInstructor(sucursales); break;
        case 6: generarMedicion(sucursales); break;
        case 7: historialMediciones(sucursales); break;
        case 8: ingresarEjercicio(bateria); break;
        case 9: generarRutina(sucursales, bateria); break;
        case 10: visualizarRutina(sucursales); break;
        case 0: break;
        default:
            print("Opcion invalida\n");
            limpiarEnter();
        }
    }
}

void submenuInstructores::incluirInstructor(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (1) Ingresar Instructor\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite Codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\nIngrese los datos del nuevo instructor:\n");

    print("Digite cedula: ");
    int cedula = digNum();

    if (suc->buscarInstructorPorCedula(cedula) != nullptr) {
        print("Error: Ya existe un instructor con esa cedula en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("Digite nombre completo: ");
    string nombre = digPalabra();

    print("Digite telefono: ");
    string telefono = digPalabra();

    print("Digite correo: ");
    string correo = digPalabra();

    print("Digite fecha de nacimiento (dd/mm/aaaa): ");
    string fechaStr = digPalabra();
    fecha fechaNac(fechaStr);

    instructor nuevoIns(cedula, nombre, telefono, correo, fechaNac);

    print("\nCuantas especialidades tiene el instructor: ");
    int cantEsp = digNum();

    print("\nEspecialidades disponibles:\n");
    print("1. CrossFit\n2. HIIT\n3. TRX\n4. Pesas\n5. Spinning\n6. Cardio\n7. Yoga\n8. Zumba\n\n");

    for (int i = 0; i < cantEsp; i++) {
        print("Digite especialidad #" + to_string(i + 1) + " (numero): ");
        int opEsp = digNum();

        Especialidad esp;
        switch (opEsp) {
        case 1: esp = Especialidad(Especialidad::CROSSFIT); break;
        case 2: esp = Especialidad(Especialidad::HIIT); break;
        case 3: esp = Especialidad(Especialidad::TRX); break;
        case 4: esp = Especialidad(Especialidad::PESAS); break;
        case 5: esp = Especialidad(Especialidad::SPINNING); break;
        case 6: esp = Especialidad(Especialidad::CARDIO); break;
        case 7: esp = Especialidad(Especialidad::YOGA); break;
        case 8: esp = Especialidad(Especialidad::ZUMBA); break;
        default:
            print("Opcion invalida, se omite.\n");
            continue;
        }
        nuevoIns.agregarEspecialidad(esp);
    }

    suc->agregarInstructor(nuevoIns);
    print("\nInstructor registrado correctamente!!!!!\n");

    limpiarEnter();
}

void submenuInstructores::listaInstructoresPorSucursal(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (2) Lista de Instructores por Sucursal\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    vecInstructores& instructores = suc->obtenerVecInstructores();
    if (instructores.tamanio() == 0) {
        print("\nNo hay instructores en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("\nLista de instructores existentes en la sucursal:\n");
    for (int i = 0; i < instructores.tamanio(); i++) {
        print(instructores.obtener(i).toString() + "\n");
    }

    limpiarEnter();
}

void submenuInstructores::detalleInstructor(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (3) Detalle de instructor\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite Codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    vecInstructores& instructores = suc->obtenerVecInstructores();
    if (instructores.tamanio() == 0) {
        print("\nNo hay instructores en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("\nLista de instructores existentes:\n");
    for (int i = 0; i < instructores.tamanio(); i++) {
        print(instructores.obtener(i).toString() + "\n");
    }

    print("\nDigite el ID del instructor que desea visualizar: ");
    int cedula = digNum();

    instructor* ins = suc->buscarInstructorPorCedula(cedula);
    if (ins == nullptr) {
        print("Instructor no encontrado.\n");
        limpiarEnter();
        return;
    }

    print("\nDetalle del instructor:\n");
    print("Nombre: " + ins->getNombreCompleto() + "\n");
    print("Cedula: " + ins->getCedula() + "\n");
    print("Telefono: " + ins->getTelefono() + "\n");
    print("Correo: " + ins->getCorreo() + "\n");
    print("Fecha de nacimiento: " + ins->getFechaNacimiento().toString() + "\n");

    print("Especialidades: ");
    for (int i = 0; i < ins->obtenerCantidadEspecialidades(); i++) {
        if (i > 0) print(", ");
        print(ins->obtenerEspecialidad(i).getNombre());
    }
    print("\n");
    print("Sucursal: " + suc->getProvincia() + " - " + suc->getCanton() + "\n");

    limpiarEnter();
}

void submenuInstructores::instructoresPorEspecialidad(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (4) Instructores por Especialidad\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite Codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\nEspecialidad:\n");
    print("1. CrossFit\n");
    print("2. HIIT\n");
    print("3. TRX\n");
    print("4. Pesas\n");
    print("5. Spinning\n");
    print("6. Cardio\n");
    print("7. Yoga\n");
    print("8. Zumba\n");

    print("\nDigite la especialidad deseada: ");
    int opEsp = digNum();

    string nombreEsp;
    switch (opEsp) {
    case 1: nombreEsp = Especialidad::CROSSFIT; break;
    case 2: nombreEsp = Especialidad::HIIT; break;
    case 3: nombreEsp = Especialidad::TRX; break;
    case 4: nombreEsp = Especialidad::PESAS; break;
    case 5: nombreEsp = Especialidad::SPINNING; break;
    case 6: nombreEsp = Especialidad::CARDIO; break;
    case 7: nombreEsp = Especialidad::YOGA; break;
    case 8: nombreEsp = Especialidad::ZUMBA; break;
    default:
        print("Opcion invalida.\n");
        limpiarEnter();
        return;
    }

    vecInstructores& instructores = suc->obtenerVecInstructores();
    print("\nInstructores de " + nombreEsp + ":\n");

    bool encontrado = false;
    for (int i = 0; i < instructores.tamanio(); i++) {
        instructor& ins = instructores.obtener(i);
        for (int j = 0; j < ins.obtenerCantidadEspecialidades(); j++) {
            if (ins.obtenerEspecialidad(j).getNombre() == nombreEsp) {
                print(ins.toString() + "\n");
                encontrado = true;
                break;
            }
        }
    }

    if (!encontrado) {
        print("No hay instructores con esa especialidad.\n");
    }

    limpiarEnter();
}

void submenuInstructores::clientesPorInstructor(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (5) Clientes por Instructor\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite Codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    vecInstructores& instructores = suc->obtenerVecInstructores();
    if (instructores.tamanio() == 0) {
        print("\nNo hay instructores en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("\nLista de instructores existentes:\n");
    for (int i = 0; i < instructores.tamanio(); i++) {
        print(instructores.obtener(i).toString() + "\n");
    }

    print("\nDigite ID del instructor deseado: ");
    int cedula = digNum();

    instructor* ins = suc->buscarInstructorPorCedula(cedula);
    if (ins == nullptr) {
        print("Instructor no encontrado.\n");
        limpiarEnter();
        return;
    }

    print("\nClientes a cargo del instructor:\n");
    vecClientes* clientes = suc->getClientes();

    if (clientes == nullptr || clientes->getCantidad() == 0) {
        print("No hay clientes registrados.\n");
        limpiarEnter();
        return;
    }

    bool encontrado = false;
    for (int i = 0; i < clientes->getCantidad(); i++) {
        cliente* cli = clientes->obtener(i);
        if (cli && cli->getInstructor() && cli->getInstructor()->getCedula() == ins->getCedula()) {
            print(cli->getCedula() + " " + cli->getNombreCompleto() + "\n");
            encontrado = true;
        }
    }

    if (!encontrado) {
        print("Este instructor no tiene clientes asignados.\n");
    }

    limpiarEnter();
}

void submenuInstructores::generarMedicion(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (6) Generar Medicion a Cliente\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite Codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\nIngrese el ID del cliente: ");
    string cedula = digPalabra();

    cliente* cli = suc->buscarClientePorCedula(cedula);
    if (cli == nullptr) {
        print("Cliente no encontrado.\n");
        limpiarEnter();
        return;
    }

    print("\nCliente Encontrado:\n");
    print(cli->getCedula() + " " + cli->getNombreCompleto() + "\n");

    print("\nGeneracion de Medicion:\n");
    print("Digite Fecha (dd/mm/aaaa): ");
    string fechaStr = digPalabra();
    fecha fechaMed(fechaStr);

    print("Digite peso (kg): ");
    double peso = digDouble();

    print("Digite estatura (m): ");
    double estatura = digDouble();

    print("Digite % de grasa: ");
    double grasa = digDouble();

    print("Digite % de musculo: ");
    double musculo = digDouble();

    Medicion* med = new Medicion(fechaMed, peso, estatura, grasa, musculo);

    print("\n");
    print("IMC: " + to_string(med->getImc()) + "\n");
    print("Clasificacion: " + med->getClasificacion() + "\n");
    print("Alto Riesgo: " + string(med->esAltoRiesgo() ? "SI" : "NO") + "\n");
    print("Cantidad de vasos recomendados: " + to_string(med->calcularVasos()) + "\n");

    double proteina = med->calcularProteina(cli->getSexo() == "m" || cli->getSexo() == "M");
    print("Cantidad de proteina recomendada: " + to_string(proteina) + " gramos\n");

    cli->agregarMedicion(med);
    print("\nMedicion registrada correctamente!!!!\n");

    limpiarEnter();
}

void submenuInstructores::historialMediciones(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (7) Historial de Mediciones\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite Codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\nDigite ID del Cliente: ");
    string cedula = digPalabra();

    cliente* cli = suc->buscarClientePorCedula(cedula);
    if (cli == nullptr) {
        print("Cliente no encontrado.\n");
        limpiarEnter();
        return;
    }

    print("\nCliente Encontrado!!!\n");
    print(cli->getCedula() + " " + cli->getNombreCompleto() + "\n");

    vecReportesM* mediciones = cli->getMediciones();
    if (mediciones == nullptr || mediciones->getCantidad() == 0) {
        print("\nNo hay mediciones registradas para este cliente.\n");
        limpiarEnter();
        return;
    }

    print("\nHISTORIAL DE MEDICIONES\n");
    mediciones->mostrarHistorial();

    print("\nDigite el numero de la medicion a consultar: ");
    int opcion = digNum();

    if (opcion < 1 || opcion > mediciones->getCantidad()) {
        print("Opcion invalida.\n");
        limpiarEnter();
        return;
    }

    Medicion* med = mediciones->obtener(opcion - 1);
    if (med == nullptr) {
        print("Error al obtener medicion.\n");
        limpiarEnter();
        return;
    }

    print("\n=============== Detalle Medicion ===============\n");
    print(med->toString());
    print("Cantidad de vasos recomendados: " + to_string(med->calcularVasosAgua()) + "\n");
    double proteina = med->calcularProteina(cli->getSexo() == "m" || cli->getSexo() == "M");
    print("Cantidad de proteina recomendada: " + to_string(proteina) + " gramos\n");

    limpiarEnter();
}

void submenuInstructores::ingresarEjercicio(BateriaEjercicios* bateria) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (8) Ingresar Ejercicio a la Bateria\n\n");

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        print("Zona Muscular\n");
        print("1-Pecho\n");
        print("2-Triceps\n");
        print("3-Biceps\n");
        print("4-Piernas\n");
        print("5-Espalda\n");

        print("\nDigite zona muscular: ");
        int zona = digNum();

        if (zona < 1 || zona > 5) {
            print("Zona invalida.\n");
            limpiarEnter();
            return;
        }

        print("Digite el nombre del ejercicio: ");
        string nombre = digPalabra();

        print("Digite la descripcion: ");
        string descripcion = digPalabra();

        Ejercicio* ej = new Ejercicio(nombre, descripcion, zona);

        if (bateria->agregar(ej)) {
            print("\nEjercicio agregado correctamente a la bateria!!!!\n");
        }
        else {
            delete ej;
            print("\nError al agregar ejercicio.\n");
        }

        print("\nDesea ingresar otro ejercicio (S/N): ");
        string resp = digPalabra();
        if (resp.length() > 0) {
            continuar = resp[0];
        }
        else {
            continuar = 'n';
        }
    }

    limpiarEnter();
}

void submenuInstructores::generarRutina(vecSucursales* sucursales, BateriaEjercicios* bateria) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (9) Generar Rutina\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite el codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\nDigite cedula del cliente: ");
    string cedula = digPalabra();

    cliente* cli = suc->buscarClientePorCedula(cedula);
    if (cli == nullptr) {
        print("Cliente no encontrado.\n");
        limpiarEnter();
        return;
    }

    print("\nCliente encontrado: " + cli->getNombreCompleto() + "\n");

    instructor* ins = cli->getInstructor();
    if (ins != nullptr) {
        print("Instructor asignado: " + ins->getNombreCompleto() + "\n");
    }
    else {
        print("Sin instructor asignado\n");
    }

    Rutina* rutina = cli->getRutina();
    if (rutina == nullptr) {
        print("Error: Cliente no tiene rutina inicializada.\n");
        limpiarEnter();
        return;
    }

    rutina->limpiarRutina();

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        print("\nZona Muscular\n");
        print("1-Pecho\n");
        print("2-Triceps\n");
        print("3-Biceps\n");
        print("4-Piernas\n");
        print("5-Espalda\n");

        print("\nDigite zona muscular: ");
        int zona = digNum();

        if (zona < 1 || zona > 5) {
            print("Zona invalida.\n");
            continue;
        }

        int cantEjZona = bateria->getCantidadPorZona(zona);
        if (cantEjZona == 0) {
            print("\nNo hay ejercicios disponibles para esta zona.\n");
            continue;
        }

        print("\nBATERIA DE EJERCICIOS DISPONIBLES PARA ZONA MUSCULAR\n");
        print("===========================================\n");
        bateria->mostrarPorZona(zona);

        print("\nDigite el ejercicio: ");
        int opEj = digNum();

        if (opEj < 1 || opEj > cantEjZona) {
            print("Opcion invalida.\n");
            continue;
        }

        Ejercicio* ej = bateria->obtenerPorZona(zona, opEj - 1);
        if (ej == nullptr) {
            print("Error al obtener ejercicio.\n");
            continue;
        }

        print("Digite las series: ");
        int series = digNum();

        print("Digite las repeticiones: ");
        int repeticiones = digNum();

        rutina->agregarEjercicio(ej, series, repeticiones);
        print("\nEjercicio seleccionado!!!\n");

        print("\nDesea Ingresar otro ejercicio(S/N): ");
        string resp = digPalabra();
        if (resp.length() > 0) {
            continuar = resp[0];
        }
        else {
            continuar = 'n';
        }
    }

    print("\n==================================================================\n");
    print("RUTINA GENERADA PARA " + cli->getNombreCompleto() + "\n");
    print("==================================================================\n");
    rutina->mostrarRutina(cli->getNombreCompleto());

    limpiarEnter();
}

void submenuInstructores::visualizarRutina(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (3) Submenu Instructores >> (10) Visualizacion de Rutina\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite el codigo de sucursal: ");
    string codigoSuc = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigoSuc);
    if (suc == nullptr) {
        print("Sucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\nDigite cedula del cliente: ");
    string cedula = digPalabra();

    cliente* cli = suc->buscarClientePorCedula(cedula);
    if (cli == nullptr) {
        print("Cliente no encontrado.\n");
        limpiarEnter();
        return;
    }

    Rutina* rutina = cli->getRutina();
    if (rutina == nullptr || rutina->getCantidad() == 0) {
        print("\nEste cliente no tiene rutina asignada.\n");
        limpiarEnter();
        return;
    }

    print("\n==================================================================\n");
    print("RUTINA DE " + cli->getNombreCompleto() + "\n");
    print("==================================================================\n");
    rutina->mostrarRutina(cli->getNombreCompleto());

    limpiarEnter();
}