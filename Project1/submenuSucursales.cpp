#include "submenuSucursales.h"
#include "utiles.h"
#include "reporteM.h"

void submenuSucursales::mostrar(vecSucursales* sucursales) {
    int opcion = -1;
    while (opcion != 0) {
        limpiar();
        print("========================================\n");
        print("1- Submenu Sucursales\n");
        print("========================================\n");
        print("(1) Ingresar Sucursal\n");
        print("(2) Mostrar Sucursales\n");
        print("(3) Reporte de IMC por sucursal\n");
        print("(0) Regresar Menu Principal\n");
        print("Digite la opcion deseada: ");
        opcion = digNum();

        switch (opcion) {
        case 1:
            ingresarSucursal(sucursales);
            break;
        case 2:
            mostrarSucursales(sucursales);
            break;
        case 3:
            reporteIMC(sucursales);
            break;
        case 0:
            break;
        default:
            print("Opcion invalida\n");
            limpiarEnter();
        }
    }
}

void submenuSucursales::ingresarSucursal(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (1) Submenu Sucursales >> (1) Incluir Sucursal\n\n");

    print("Digite Codigo: ");
    string codigo = digPalabra();

    if (sucursales->buscarPorCodigo(codigo) != nullptr) {
        print("Error: Ya existe una sucursal con ese codigo.\n");
        limpiarEnter();
        return;
    }

    print("Digite provincia: ");
    string provincia = digPalabra();

    print("Digite canton: ");
    string canton = digPalabra();

    print("Digite correo: ");
    string correo = digPalabra();

    print("Digite telefono: ");
    string telefono = digPalabra();

    Sucursal* nuevaSucursal = new Sucursal(codigo, provincia, canton, correo, telefono);

    if (sucursales->insertar(nuevaSucursal)) {
        print("\nSucursal registrada correctamente!!!!\n");
    }
    else {
        delete nuevaSucursal;
        print("\nError al registrar la sucursal.\n");
    }

    limpiarEnter();
}

void submenuSucursales::mostrarSucursales(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (1) Submenu Sucursales >> (2) Mostrar Sucursal\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales:\n");
    sucursales->listarTodos();

    print("\nDigite el codigo de la sucursal que desea visualizar: ");
    string codigo = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigo);
    if (suc == nullptr) {
        print("\nSucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\n");
    print(suc->toStringDetallado());

    limpiarEnter();
}

void submenuSucursales::reporteIMC(vecSucursales* sucursales) {
    limpiar();
    print("Menu principal>> (1) Submenu Sucursales >> (3) Reporte IMC por sucursal\n\n");

    if (sucursales->getCantidad() == 0) {
        print("No hay sucursales registradas.\n");
        limpiarEnter();
        return;
    }

    print("Lista de sucursales existentes:\n");
    sucursales->listarTodos();

    print("\nDigite codigo de la sucursal a consultar: ");
    string codigo = digPalabra();

    Sucursal* suc = sucursales->buscarPorCodigo(codigo);
    if (suc == nullptr) {
        print("\nSucursal no encontrada.\n");
        limpiarEnter();
        return;
    }

    print("\n");
    string nombreCompleto = suc->getProvincia() + " - " + suc->getCanton();
    reporteM reporte;
    reporte.generarReporteIMCporSucursal(suc->getClientes(), nombreCompleto);

    limpiarEnter();
}