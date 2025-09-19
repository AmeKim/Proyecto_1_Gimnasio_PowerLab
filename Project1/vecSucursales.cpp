#include "vecSucursales.h"

vecSucursales::vecSucursales() {
    this->can = 0;
    this->vSucursales = new Sucursal * [tam];
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
        // Verificar que no exista una sucursal con el mismo código
        if (!existeCodigo(sucursal->getCodigo())) {
            vSucursales[can] = sucursal;
            can++;
            print("Sucursal registrada correctamente!!!!\n");
        }
        else {
            print("Error: Ya existe una sucursal con ese código\n");
            delete sucursal; // Liberar memoria si no se puede agregar
        }
    }
    else {
        print("No se pueden agregar más sucursales\n");
    }
}

void vecSucursales::eliminarSucursal(int codigo) {
    for (int i = 0; i < can; i++) {
        if (vSucursales[i]->getCodigo() == codigo) {
            delete vSucursales[i];
            // Mover todos los elementos hacia atrás
            for (int j = i; j < can - 1; j++) {
                vSucursales[j] = vSucursales[j + 1];
            }
            vSucursales[can - 1] = nullptr;
            can--;
            print("Sucursal eliminada correctamente\n");
            return;
        }
    }
    print("No se encontró la sucursal\n");
}

Sucursal* vecSucursales::buscarSucursal(int codigo) {
    for (int i = 0; i < can; i++) {
        if (vSucursales[i] && vSucursales[i]->getCodigo() == codigo) {
            return vSucursales[i];
        }
    }
    return nullptr;
}

int vecSucursales::getCan() const {
    return can;
}

string vecSucursales::toString() const {
    stringstream s;
    s << "Lista de sucursales:\n";
    for (int i = 0; i < can; i++) {
        if (vSucursales[i]) {
            s << vSucursales[i]->getCodigo() << " "
                << vSucursales[i]->getProvincia() << " - "
                << vSucursales[i]->getCanton() << "\n";
        }
    }
    return s.str();
}

string vecSucursales::toStringEspecifica(int codigo) const {
    for (int i = 0; i < can; i++) {
        if (vSucursales[i] && vSucursales[i]->getCodigo() == codigo) {
            return vSucursales[i]->toString();
        }
    }
    return "Sucursal no encontrada\n";
}

void vecSucursales::mostrarTodas() const {
    print(toString());
}

bool vecSucursales::existeCodigo(int codigo) const {
    return buscarSucursal(codigo) != nullptr;
}

Sucursal* vecSucursales::getSucursalPorIndice(int idx) {
    return (idx >= 0 && idx < can) ? vSucursales[idx] : nullptr;
}