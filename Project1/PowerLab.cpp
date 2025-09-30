#include "PowerLab.h"
#include "submenuSucursales.h"
#include "submenuClientes.h"
#include "submenuInstructores.h"
#include "submenuClaseGrup.h"
#include "utiles.h"
#include "Ejercicio.h"
#include "instructor.h"
#include "cliente.h"
#include "ClaseGrupal.h"
#include "Medicion.h"
#include "especialidad.h"
#include "fecha.h"

PowerLab::PowerLab() {
    sucursales = new vecSucursales(30);
    bateria = new BateriaEjercicios();
    cargarDatosIniciales();
}

PowerLab::~PowerLab() {
    if (sucursales) {
        delete sucursales;
        sucursales = nullptr;
    }
    if (bateria) {
        delete bateria;
        bateria = nullptr;
    }
}

void PowerLab::cargarDatosIniciales() {
    Sucursal* suc1 = new Sucursal("101", "San Jose", "Escazu", "powerlab.escazu@gmail.com", "2222-3344");
    Sucursal* suc2 = new Sucursal("102", "Heredia", "Belen", "powerlab.belen@gmail.com", "2233-4455");
    Sucursal* suc3 = new Sucursal("103", "Alajuela", "Centro", "powerlab.alajuela@gmail.com", "2244-5566");

    if (!sucursales->insertar(suc1)) delete suc1;
    if (!sucursales->insertar(suc2)) delete suc2;
    if (!sucursales->insertar(suc3)) delete suc3;

    instructor ins1("115670111", "Maria Gomez", "2233-4455", "maria@gmail.com", fecha("20/03/1985"));
    ins1.agregarEspecialidad(Especialidad(Especialidad::YOGA));
    ins1.agregarEspecialidad(Especialidad(Especialidad::ZUMBA));
    ins1.agregarEspecialidad(Especialidad(Especialidad::TRX));
    suc1->agregarInstructor(ins1);

    instructor ins2("116780222", "Juan Rodriguez", "2244-5566", "juan@gmail.com", fecha("15/07/1988"));
    ins2.agregarEspecialidad(Especialidad(Especialidad::CROSSFIT));
    ins2.agregarEspecialidad(Especialidad(Especialidad::PESAS));
    suc1->agregarInstructor(ins2);

    instructor ins3("117890333", "Ana Lopez", "2255-6677", "ana@gmail.com", fecha("10/11/1990"));
    ins3.agregarEspecialidad(Especialidad(Especialidad::SPINNING));
    ins3.agregarEspecialidad(Especialidad(Especialidad::CARDIO));
    suc1->agregarInstructor(ins3);

    instructor ins4("118900444", "Miguel Lopez", "2266-7788", "miguel@gmail.com", fecha("05/09/1987"));
    ins4.agregarEspecialidad(Especialidad(Especialidad::HIIT));
    ins4.agregarEspecialidad(Especialidad(Especialidad::TRX));
    suc2->agregarInstructor(ins4);

    cliente* cli1 = new cliente("118990123", "Carlos Perez", "8888-1111", "carlos@gmail.com",
        fecha("01/01/1990"), fecha("15/07/2025"), "m");
    cli1->setInstructor(&suc1->obtenerVecInstructores().obtener(0));
    if (!suc1->agregarCliente(cli1)) delete cli1;
    else {
        Medicion* med1 = new Medicion(fecha("01/02/2025"), 80, 1.73, 20, 40);
        cli1->agregarMedicion(med1);
        Medicion* med2 = new Medicion(fecha("01/03/2025"), 78, 1.73, 19, 41);
        cli1->agregarMedicion(med2);
        Medicion* med3 = new Medicion(fecha("12/06/2025"), 76.5, 1.73, 18, 42);
        cli1->agregarMedicion(med3);
    }

    cliente* cli2 = new cliente("119880456", "Laura Jimenez", "8888-2222", "laura@gmail.com",
        fecha("12/05/1992"), fecha("20/08/2025"), "f");
    cli2->setInstructor(&suc1->obtenerVecInstructores().obtener(1));
    if (!suc1->agregarCliente(cli2)) delete cli2;
    else {
        Medicion* med4 = new Medicion(fecha("20/08/2025"), 70, 1.60, 28, 35);
        cli2->agregarMedicion(med4);
    }

    cliente* cli3 = new cliente("120770789", "Andres Ramirez", "8888-3333", "andres@gmail.com",
        fecha("08/12/1988"), fecha("10/09/2025"), "m");
    cli3->setInstructor(&suc1->obtenerVecInstructores().obtener(2));
    if (!suc1->agregarCliente(cli3)) delete cli3;
    else {
        Medicion* med5 = new Medicion(fecha("10/09/2025"), 75, 1.78, 15, 45);
        cli3->agregarMedicion(med5);
    }

    cliente* cli4 = new cliente("118233423", "Maria Calas", "8888-4444", "mcalas@gmail.com",
        fecha("15/03/1995"), fecha("05/08/2025"), "f");
    cli4->setInstructor(&suc1->obtenerVecInstructores().obtener(0));
    if (!suc1->agregarCliente(cli4)) delete cli4;
    else {
        Medicion* med6 = new Medicion(fecha("05/08/2025"), 52, 1.75, 25, 30);
        cli4->agregarMedicion(med6);
    }

    cliente* cli5 = new cliente("145990123", "Flora Mora", "8888-5555", "flora@gmail.com",
        fecha("22/07/1993"), fecha("12/07/2025"), "f");
    cli5->setInstructor(&suc1->obtenerVecInstructores().obtener(1));
    if (!suc1->agregarCliente(cli5)) delete cli5;
    else {
        Medicion* med7 = new Medicion(fecha("12/07/2025"), 50, 1.71, 22, 32);
        cli5->agregarMedicion(med7);
    }

    cliente* cli6 = new cliente("678990123", "Juan Perez", "8888-6666", "jperez@gmail.com",
        fecha("30/11/1991"), fecha("18/06/2025"), "m");
    cli6->setInstructor(&suc1->obtenerVecInstructores().obtener(2));
    if (!suc1->agregarCliente(cli6)) delete cli6;
    else {
        Medicion* med8 = new Medicion(fecha("18/06/2025"), 48, 1.70, 20, 35);
        cli6->agregarMedicion(med8);
    }

    Ejercicio* ej1 = new Ejercicio("Press de banca plano con barra", "Ejercicio basico de pecho", 1);
    if (!bateria->agregar(ej1)) delete ej1;
    Ejercicio* ej2 = new Ejercicio("Press inclinado con barra", "Pecho superior", 1);
    if (!bateria->agregar(ej2)) delete ej2;
    Ejercicio* ej3 = new Ejercicio("Press declinado con barra", "Pecho inferior", 1);
    if (!bateria->agregar(ej3)) delete ej3;

    Ejercicio* ej4 = new Ejercicio("Fondos en paralelas", "Triceps completo", 2);
    if (!bateria->agregar(ej4)) delete ej4;
    Ejercicio* ej5 = new Ejercicio("Press frances", "Triceps", 2);
    if (!bateria->agregar(ej5)) delete ej5;

    Ejercicio* ej6 = new Ejercicio("Curl con barra", "Biceps basico", 3);
    if (!bateria->agregar(ej6)) delete ej6;
    Ejercicio* ej7 = new Ejercicio("Curl martillo", "Biceps y antebrazo", 3);
    if (!bateria->agregar(ej7)) delete ej7;

    Ejercicio* ej8 = new Ejercicio("Sentadillas", "Ejercicio de fuerza con barra en la espalda", 4);
    if (!bateria->agregar(ej8)) delete ej8;
    Ejercicio* ej9 = new Ejercicio("Prensa de piernas", "Cuadriceps y gluteos", 4);
    if (!bateria->agregar(ej9)) delete ej9;
    Ejercicio* ej10 = new Ejercicio("Zancadas", "Piernas completas", 4);
    if (!bateria->agregar(ej10)) delete ej10;
    Ejercicio* ej11 = new Ejercicio("Extensiones de pierna en maquina", "Cuadriceps", 4);
    if (!bateria->agregar(ej11)) delete ej11;
    Ejercicio* ej12 = new Ejercicio("Peso muerto rumano", "Femoral y gluteos", 4);
    if (!bateria->agregar(ej12)) delete ej12;
    Ejercicio* ej13 = new Ejercicio("Hip thrust", "Gluteos", 4);
    if (!bateria->agregar(ej13)) delete ej13;
    Ejercicio* ej14 = new Ejercicio("Curl de femorales en maquina", "Femoral", 4);
    if (!bateria->agregar(ej14)) delete ej14;
    Ejercicio* ej15 = new Ejercicio("Buenos dias", "Espalda baja y femorales", 4);
    if (!bateria->agregar(ej15)) delete ej15;
    Ejercicio* ej16 = new Ejercicio("Aductores y abductores", "Parte interna y externa del muslo", 4);
    if (!bateria->agregar(ej16)) delete ej16;
    Ejercicio* ej17 = new Ejercicio("Maquina de abductores", "Abrir piernas contra resistencia", 4);
    if (!bateria->agregar(ej17)) delete ej17;

    Ejercicio* ej18 = new Ejercicio("Dominadas", "Espalda completa", 5);
    if (!bateria->agregar(ej18)) delete ej18;
    Ejercicio* ej19 = new Ejercicio("Remo con barra", "Espalda media", 5);
    if (!bateria->agregar(ej19)) delete ej19;
    Ejercicio* ej20 = new Ejercicio("Peso muerto", "Espalda baja", 5);
    if (!bateria->agregar(ej20)) delete ej20;

    ClaseGrupal* clase1 = new ClaseGrupal(1001, Especialidad::CROSSFIT, 20, "A1", "Lunes 6pm",
        &suc1->obtenerVecInstructores().obtener(1));
    if (!suc1->agregarClaseGrupal(clase1)) delete clase1;

    ClaseGrupal* clase2 = new ClaseGrupal(1002, Especialidad::YOGA, 15, "B2", "Martes 7am",
        &suc1->obtenerVecInstructores().obtener(0));
    if (!suc1->agregarClaseGrupal(clase2)) delete clase2;

    ClaseGrupal* clase3 = new ClaseGrupal(1003, Especialidad::SPINNING, 25, "C1", "Miercoles 5pm",
        &suc1->obtenerVecInstructores().obtener(2));
    if (!suc1->agregarClaseGrupal(clase3)) delete clase3;

    if (suc1->getClasesGrupales() && suc1->getClasesGrupales()->getCantidad() > 0) {
        ClaseGrupal* cg1 = suc1->getClasesGrupales()->buscarPorCodigo(1001);
        ClaseGrupal* cg2 = suc1->getClasesGrupales()->buscarPorCodigo(1002);
        ClaseGrupal* cg3 = suc1->getClasesGrupales()->buscarPorCodigo(1003);

        cliente* c1 = suc1->buscarClientePorCedula("118990123");
        cliente* c2 = suc1->buscarClientePorCedula("119880456");
        cliente* c3 = suc1->buscarClientePorCedula("120770789");

        if (cg1 && c1) cg1->matricularCliente(c1);
        if (cg2 && c2) cg2->matricularCliente(c2);
        if (cg3 && c3) cg3->matricularCliente(c3);
    }
}

void PowerLab::ejecutar() {
    int opcion = -1;
    while (opcion != 0) {
        mostrarMenuPrincipal();
        opcion = digNum();

        switch (opcion) {
        case 1:
            submenuSucursales::mostrar(sucursales);
            break;
        case 2:
            submenuClientes::mostrar(sucursales);
            break;
        case 3:
            submenuInstructores::mostrar(sucursales, bateria);
            break;
        case 4:
            submenuClaseGrup::mostrar(sucursales);
            break;
        case 0:
            print("\nGracias por usar el sistema PowerLab!\n");
            break;
        default:
            print("Opcion invalida. Por favor seleccione una opcion del menu.\n");
            limpiarEnter();
        }
    }
}

void PowerLab::mostrarMenuPrincipal() {
    limpiar();
    print("========================================\n");
    print("   GESTION DE GIMNASIOS POWERLAB\n");
    print("========================================\n");
    print("Menu Principal\n");
    print("========================================\n");
    print("(1) Submenu de Sucursales\n");
    print("(2) Submenu de Clientes\n");
    print("(3) Submenu de Instructores\n");
    print("(4) Submenu de Clases Grupales\n");
    print("(0) Salir\n");
    print("========================================\n");
    print("Digite la opcion deseada: ");
}