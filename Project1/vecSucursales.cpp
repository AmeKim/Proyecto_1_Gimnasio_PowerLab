#include "vecSucursales.h"

vecSucursales::vecSucursales(int capacidad) {
    tam = capacidad;
    can = 0;
    sucursales = new Sucursal * [tam];
    for (int i = 0; i < tam; i++) {
        sucursales[i] = nullptr;
    }
}

vecSucursales::~vecSucursales() {
    for (int i = 0; i < can; i++) {
        delete sucursales[i];
    }
    delete[] sucursales;
}

bool vecSucursales::agregarSucursal(Sucursal* sucursal) {
    if (can < tam && sucursal != nullptr) {
        // Verificar que no existe una sucursal con el mismo código
        if (!existeCodigo(sucursal->getCodigo())) {
            sucursales[can] = sucursal;
            can++;
            return true;
        }
    }
    return false;
}

void vecSucursales::eliminarSucursal(int codigo) {
    for (int i = 0; i < can; i++) {
        if (sucursales[i] && sucursales[i]->getCodigo() == codigo) {
            delete sucursales[i];
            for (int j = i; j < can - 1; j++) {
                sucursales[j] = sucursales[j + 1];
            }
            sucursales[can - 1] = nullptr;
            can--;
            return;
        }
    }
}

Sucursal* vecSucursales::buscarPorCodigo(int codigo) const {
    for (int i = 0; i < can; i++) {
        if (sucursales[i] && sucursales[i]->getCodigo() == codigo) {
            return sucursales[i];
        }
    }
    return nullptr;
}

bool vecSucursales::existeCodigo(int codigo) const {
    return buscarPorCodigo(codigo) != nullptr;
}

int vecSucursales::getCan() const {
    return can;
}

int vecSucursales::getTam() const {
    return tam;
}

void vecSucursales::mostrarTodas() const {
    cout << "Lista de sucursales:" << endl;
    for (int i = 0; i < can; i++) {
        if (sucursales[i]) {
            cout << sucursales[i]->toString() << endl;
        }
    }
}

void vecSucursales::mostrarSucursal(int codigo) const {
    Sucursal* suc = buscarPorCodigo(codigo);
    if (suc) {
        suc->mostrar();
    }
    else {
        cout << "Sucursal no encontrada." << endl;
    }
}

string vecSucursales::toString() const {
    stringstream s;
    for (int i = 0; i < can; i++) {
        if (sucursales[i]) {
            s << sucursales[i]->toString() << endl;
        }
    }
    return s.str();
}

Sucursal* vecSucursales::getSucursalPorIndice(int indice) const {
    if (indice >= 0 && indice < can) {
        return sucursales[indice];
    }
    return nullptr;
}

Sucursal* vecSucursales::getSucursal(int codigo) const {
    return buscarPorCodigo(codigo);
}