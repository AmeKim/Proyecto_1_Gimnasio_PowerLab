#include "vecSucursales.h"

vecSucursales::vecSucursales() {
    can = 0;
    vSucursales = new Sucursal * [tam];
    for (int i = 0; i < tam; i++) {
        vSucursales[i] = nullptr;
    }
}

vecSucursales::~vecSucursales() {
    for (int i = 0; i < can; i++) {
        delete vSucursales[i];
    }
    delete[] vSucursales;
}

void vecSucursales::agregarSucursal(Sucursal* sucursal) {
    if (can < tam && sucursal) {
        vSucursales[can] = sucursal;
        can++;
    }
}

void vecSucursales::eliminarSucursal(int codigo) {
    for (int i = 0; i < can; i++) {
        if (vSucursales[i]->getCodigo() == codigo) {
            delete vSucursales[i];
            for (int j = i; j < can - 1; j++) {
                vSucursales[j] = vSucursales[j + 1];
            }
            vSucursales[can - 1] = nullptr;
            can--;
            return;
        }
    }
}

Sucursal* vecSucursales::getSucursal(int codigo) {
    for (int i = 0; i < can; i++) {
        if (vSucursales[i] && vSucursales[i]->getCodigo() == codigo) {
            return vSucursales[i];
        }
    }
    return nullptr;
}

Sucursal* vecSucursales::getSucursalPorIndice(int idx) {
    if (idx >= 0 && idx < can) {
        return vSucursales[idx];
    }
    return nullptr;
}

int vecSucursales::getCan() {
    return can;
}

string vecSucursales::toString() {
    stringstream s;
    for (int i = 0; i < can; i++) {
        s << vSucursales[i]->toString() << endl;
    }
    return s.str();
}

void vecSucursales::mostrarTodas() {
    for (int i = 0; i < can; i++) {
        if (vSucursales[i]) {
            cout << vSucursales[i]->toString() << endl;
        }
    }
}

void vecSucursales::inicializarDatos() {
    // Crear sucursales de ejemplo
    Sucursal* suc1 = new Sucursal(101, "San José", "Escazú", "powerlab.escazu@gmail.com", "2222-3344");
    Sucursal* suc2 = new Sucursal(102, "Heredia", "Belén", "powerlab.belen@gmail.com", "2233-4455");
    Sucursal* suc3 = new Sucursal(103, "Alajuela", "Centro", "powerlab.centro@gmail.com", "2244-5566");

    agregarSucursal(suc1);
    agregarSucursal(suc2);
    agregarSucursal(suc3);

    // Crear especialidades básicas
    vecEspecialidades* especialidades1 = new vecEspecialidades();
    especialidades1->agregarEspecialidad(new especialidad(1, "Yoga"));
    especialidades1->agregarEspecialidad(new especialidad(2, "Zumba"));
    especialidades1->agregarEspecialidad(new especialidad(3, "TRX"));

    vecEspecialidades* especialidades2 = new vecEspecialidades();
    especialidades2->agregarEspecialidad(new especialidad(4, "CrossFit"));
    especialidades2->agregarEspecialidad(new especialidad(5, "Pesas"));

    // Crear instructores de ejemplo
    instructor* inst1 = new instructor("María Gómez", "115670111", 22334455, "maria@gmail.com",
        Fecha(20, 3, 1985), especialidades1);
    instructor* inst2 = new instructor("Juan Rodríguez", "116780222", 23344556, "juan@gmail.com",
        Fecha(15, 7, 1988), especialidades2);

    suc1->agregarInstructor(inst1);
    suc1->agregarInstructor(inst2);

    // Crear clientes de ejemplo
    cliente* cli1 = new cliente("Carlos Pérez", "118990123", 88881111, "carlos@gmail.com",
        Fecha(1, 1, 1990), 'M', Fecha(15, 7, 2025), inst1);
    cliente* cli2 = new cliente("Laura Jiménez", "119880456", 88882222, "laura@gmail.com",
        Fecha(10, 5, 1992), 'F', Fecha(20, 6, 2025), inst2);

    suc1->agregarCliente(cli1);
    suc1->agregarCliente(cli2);
}