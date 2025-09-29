#include "submenuClaseGrup.h"
#include "utiles.h"
#include "ClaseGrupal.h"
#include "especialidad.h"

void submenuClaseGrup::mostrar(vecSucursales* sucursales) {
    int opcion = -1;
    while (opcion != 0) {
        limpiar();
        print("========================================\n");
        print("4- Submenu Clases Grupales\n");
        print("========================================\n");
        print("(1) Crear Clase Grupal\n");
        print("(2) Mostrar Clases Grupales\n");
        print("(3) Matricular Cliente en Clase Grupal\n");
        print("(4) Clases Matriculadas por Cliente\n");
        print("(0) Regresar al Menu Principal\n");
        print("Digite la opcion deseada: ");
        opcion = digNum();

        switch (opcion) {
        case 1:
            crearClaseGrupal(sucursales);
            break;
        case 2:
            mostrarClasesGrupales(sucursales);
            break;
        case 3:
            matricularCliente(sucursales);
            break;
        case 4:
            clasesMatriculadas(sucursales);
            break;
        case 0:
            break;
        default:
            print("Opcion invalida\n");
            limpiarEnter();
        }
    }
}

void submenuClaseGrup::crearClaseGrupal(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (4) Submenu Clases Grupales >> (1) Crear Clase Grupal\n\n");

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

    print("\nTipos de clases disponibles:\n");
    print("1. CrossFit\n");
    print("2. HIIT\n");
    print("3. TRX\n");
    print("4. Pesas\n");
    print("5. Spinning\n");
    print("6. Cardio\n");
    print("7. Yoga\n");
    print("8. Zumba\n");

    print("\nDigite codigo de la clase: ");
    int tipoClase = digNum();

    string nombreClase;
    switch (tipoClase) {
    case 1: nombreClase = Especialidad::CROSSFIT; break;
    case 2: nombreClase = Especialidad::HIIT; break;
    case 3: nombreClase = Especialidad::TRX; break;
    case 4: nombreClase = Especialidad::PESAS; break;
    case 5: nombreClase = Especialidad::SPINNING; break;
    case 6: nombreClase = Especialidad::CARDIO; break;
    case 7: nombreClase = Especialidad::YOGA; break;
    case 8: nombreClase = Especialidad::ZUMBA; break;
    default:
        print("Opcion invalida.\n");
        limpiarEnter();
        return;
    }

    print("\nClase de " + nombreClase + " seleccionada!!!\n");

    print("Digite capacidad maxima: ");
    int capacidad = digNum();

    print("Digite salon: ");
    string salon = digPalabra();

    print("Digite horario: ");
    string horario = digPalabra();

    vecInstructores& instructores = suc->obtenerVecInstructores();
    print("\nLista de instructores existentes con la especialidad:\n");

    bool hayInstructores = false;
    for (int i = 0; i < instructores.tamanio(); i++) {
        instructor& ins = instructores.obtener(i);
        for (int j = 0; j < ins.obtenerCantidadEspecialidades(); j++) {
            if (ins.obtenerEspecialidad(j).getNombre() == nombreClase) {
                print(ins.toString() + "\n");
                hayInstructores = true;
                break;
            }
        }
    }

    if (!hayInstructores) {
        print("No hay instructores con esa especialidad.\n");
        limpiarEnter();
        return;
    }

    print("\nDigite instructor (cedula): ");
    int cedulaIns = digNum();

    instructor* ins = suc->buscarInstructorPorCedula(cedulaIns);
    if (ins == nullptr) {
        print("Instructor no encontrado.\n");
        limpiarEnter();
        return;
    }

    bool tieneEspecialidad = false;
    for (int i = 0; i < ins->obtenerCantidadEspecialidades(); i++) {
        if (ins->obtenerEspecialidad(i).getNombre() == nombreClase) {
            tieneEspecialidad = true;
            break;
        }
    }

    if (!tieneEspecialidad) {
        print("El instructor no tiene la especialidad requerida.\n");
        limpiarEnter();
        return;
    }

    print("\nInstructor seleccionado!!\n");

    static int codigoClase = 1000;
    ClaseGrupal* nuevaClase = new ClaseGrupal(codigoClase++, nombreClase, capacidad, salon, horario, ins);

    if (suc->agregarClaseGrupal(nuevaClase)) {
        print("\nClase grupal registrada correctamente!!!!!!!!\n");
    }
    else {
        delete nuevaClase;
        print("\nError al registrar clase grupal.\n");
    }

    limpiarEnter();
}

void submenuClaseGrup::mostrarClasesGrupales(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (4) Submenu Clases Grupales >> (2) Mostrar Clases Grupales\n\n");

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

    vecClasesGrupales* clases = suc->getClasesGrupales();
    if (clases == nullptr || clases->getCantidad() == 0) {
        print("\nNo hay clases grupales en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("\nLista de clases existentes en la sucursal:\n");
    print(clases->mostrarTipos());

    print("\nDigite codigo de la clase: ");
    int codigo = digNum();

    ClaseGrupal* clase = clases->buscarPorCodigo(codigo);
    if (clase == nullptr) {
        print("Clase no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\nDetalle de la clase Grupal:\n");
    print(clase->toString());

    limpiarEnter();
}

void submenuClaseGrup::matricularCliente(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (4) Submenu Clases Grupales >> (3) Matricular Cliente en Clase Grupal\n\n");

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

    print("\nDigite cedula del cliente: ");
    string cedula = digPalabra();

    cliente* cli = suc->buscarClientePorCedula(cedula);
    if (cli == nullptr) {
        print("Cliente no encontrado.\n");
        limpiarEnter();
        return;
    }

    print("\nCliente encontrado:\n");
    print(cli->getCedula() + " " + cli->getNombreCompleto() + "\n");

    if (cli->getCantidadClasesMatriculadas() >= 3) {
        print("\nEl cliente ya tiene el maximo de 3 clases matriculadas.\n");
        limpiarEnter();
        return;
    }

    vecClasesGrupales* clases = suc->getClasesGrupales();
    if (clases == nullptr || clases->getCantidad() == 0) {
        print("\nNo hay clases grupales en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("\nLista de clases existentes en la sucursal:\n");
    print(clases->mostrarTipos());

    print("\nDigite codigo de la clase: ");
    int codigo = digNum();

    ClaseGrupal* clase = clases->buscarPorCodigo(codigo);
    if (clase == nullptr) {
        print("Clase no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\nClase: " + clase->getTipo() + "\n");
    print("Capacidad: " + to_string(clase->getCapacidad()) + "\n");
    print("Matriculados: " + to_string(clase->getCantidadMatriculados()) + "\n");
    print("Cupos disponibles: " + to_string(clase->getCuposDisponibles()) + "\n");
    print("Salon: " + clase->getSalon() + "\n");
    print("Horario: " + clase->getHorario() + "\n");

    if (clase->getCuposDisponibles() <= 0) {
        print("\nNo hay cupos disponibles en esta clase.\n");
        limpiarEnter();
        return;
    }

    print("\nDesea matricular al cliente (S/N): ");
    string resp = digPalabra();

    if (resp.length() > 0 && (resp[0] == 'S' || resp[0] == 's')) {
        if (clase->matricularCliente(cli)) {
            print("\nCliente matriculado correctamente en " + clase->getTipo() + " !!!\n");
        }
        else {
            print("\nError al matricular cliente.\n");
        }
    }
    else {
        print("\nMatricula cancelada.\n");
    }

    limpiarEnter();
}

void submenuClaseGrup::clasesMatriculadas(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (4) Submenu Clases Grupales >> (4) Clases Matriculadas por Cliente\n\n");

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

    print("\nDigite cedula del cliente: ");
    string cedula = digPalabra();

    cliente* cli = suc->buscarClientePorCedula(cedula);
    if (cli == nullptr) {
        print("Cliente no encontrado.\n");
        limpiarEnter();
        return;
    }

    print("\nCliente encontrado:\n");
    print(cli->getCedula() + " " + cli->getNombreCompleto() + "\n");

    print("\nClases matriculadas por el cliente:\n");
    print(cli->mostrarClasesMatriculadas());
    print("Total de clases matriculadas: " + to_string(cli->getCantidadClasesMatriculadas()) + "\n");

    limpiarEnter();
}