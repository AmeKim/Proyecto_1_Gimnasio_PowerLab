#include "submenuClientes.h"
#include "utiles.h"
#include "cliente.h"
#include "fecha.h"

void submenuClientes::mostrar(vecSucursales* sucursales) {
    int opcion = -1;
    while (opcion != 0) {
        limpiar();
        print("========================================\n");
        print("2- Submenu Clientes\n");
        print("========================================\n");
        print("(1) Incluir Cliente\n");
        print("(2) Asignar Instructor a Cliente\n");
        print("(3) Lista de Clientes por Sucursal\n");
        print("(4) Detalle de Cliente\n");
        print("(0) Regresar al Menu Principal\n");
        print("Digite la opcion deseada: ");
        opcion = digNum();

        switch (opcion) {
        case 1:
            incluirCliente(sucursales);
            break;
        case 2:
            asignarInstructor(sucursales);
            break;
        case 3:
            listaClientesPorSucursal(sucursales);
            break;
        case 4:
            detalleCliente(sucursales);
            break;
        case 0:
            break;
        default:
            print("Opcion invalida\n");
            limpiarEnter();
        }
    }
}

void submenuClientes::incluirCliente(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (2) Submenu Clientes >> (1) Incluir Cliente\n\n");

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

    print("\nIngresar datos del cliente:\n");

    print("Digite nombre completo: ");
    string nombre = digPalabra();

    print("Digite cedula: ");
    string cedula = digPalabra();

    if (suc->buscarClientePorCedula(cedula) != nullptr) {
        print("Error: Ya existe un cliente con esa cedula en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("Digite telefono: ");
    string telefono = digPalabra();

    print("Digite correo: ");
    string correo = digPalabra();

    print("Digite fecha de nacimiento (dd/mm/aaaa): ");
    string fechaNacStr = digPalabra();
    fecha fechaNac(fechaNacStr);

    print("Digite fecha de inscripcion (dd/mm/aaaa): ");
    string fechaInscStr = digPalabra();
    fecha fechaInsc(fechaInscStr);

    print("Digite sexo: ");
    string sexo = digPalabra();

    cliente* nuevoCliente = new cliente(cedula, nombre, telefono, correo, fechaNac, fechaInsc, sexo);

    vecInstructores& instructores = suc->obtenerVecInstructores();
    if (instructores.tamanio() > 0) {
        print("\nLista de instructores Existentes:\n");
        for (int i = 0; i < instructores.tamanio(); i++) {
            print(to_string(i + 1) + "- " + instructores.obtener(i).toString() + "\n");
        }
        print(to_string(instructores.tamanio() + 1) + "- Sin instructor por el momento\n");

        print("\nDigite instructor asignado: ");
        int opcionIns = digNum();

        if (opcionIns > 0 && opcionIns <= instructores.tamanio()) {
            nuevoCliente->setInstructor(&instructores.obtener(opcionIns - 1));
        }
    }
    else {
        print("\nNo hay instructores disponibles. Cliente sin instructor.\n");
    }

    if (suc->agregarCliente(nuevoCliente)) {
        print("\nCliente registrado correctamente!!!!!!\n");
    }
    else {
        delete nuevoCliente;
        print("\nError al registrar cliente.\n");
    }

    limpiarEnter();
}

void submenuClientes::asignarInstructor(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (2) Submenu Clientes >> (2) Asignar Instructor a Cliente\n\n");

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
    print("Nombre del cliente: " + cli->getNombreCompleto() + "\n");

    instructor* insActual = cli->getInstructor();
    if (insActual != nullptr) {
        print("Instructor actual asignado al cliente: " + insActual->getNombreCompleto() + "\n");
    }
    else {
        print("Instructor actual: Sin instructor\n");
    }

    vecInstructores& instructores = suc->obtenerVecInstructores();
    if (instructores.tamanio() == 0) {
        print("\nNo hay instructores disponibles en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("\nLista de instructores de la sucursal:\n");
    for (int i = 0; i < instructores.tamanio(); i++) {
        print(to_string(i + 1) + "- " + instructores.obtener(i).toString() + "\n");
    }
    print(to_string(instructores.tamanio() + 1) + "- Sin instructor por el momento\n");

    print("\nDigite instructor a asignar: ");
    int opcionIns = digNum();

    if (opcionIns == instructores.tamanio() + 1) {
        cli->setInstructor(nullptr);
        print("\nSe ha removido el instructor del cliente.\n");
    }
    else if (opcionIns > 0 && opcionIns <= instructores.tamanio()) {
        cli->setInstructor(&instructores.obtener(opcionIns - 1));
        print("\nEl instructor fue asignado al cliente!!!!!!!\n");
    }
    else {
        print("\nOpcion invalida.\n");
    }

    limpiarEnter();
}

void submenuClientes::listaClientesPorSucursal(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (2) Submenu Clientes >> (3) Lista de Clientes por Sucursal\n\n");

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

    vecClientes* clientes = suc->getClientes();
    if (clientes == nullptr || clientes->getCantidad() == 0) {
        print("\nNo hay clientes registrados en esta sucursal.\n");
        limpiarEnter();
        return;
    }

    print("\nLista de clientes de la sucursal:\n");
    print(clientes->listarSimple());

    limpiarEnter();
}

void submenuClientes::detalleCliente(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (2) Submenu Clientes >> (4) Detalle de Cliente\n\n");

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

    print("\nDigite el ID del cliente que desea visualizar: ");
    string cedula = digPalabra();

    cliente* cli = suc->buscarClientePorCedula(cedula);
    if (cli == nullptr) {
        print("Cliente no encontrado.\n");
        limpiarEnter();
        return;
    }

    print("\nDetalle de cliente:\n");
    print(cli->toString());
    print("Sucursal: " + suc->getProvincia() + " - " + suc->getCanton() + "\n");

    instructor* ins = cli->getInstructor();
    if (ins != nullptr) {
        print("Instructor: " + ins->getNombreCompleto() + "\n");
    }
    else {
        print("Instructor: Sin instructor asignado\n");
    }

    limpiarEnter();
}