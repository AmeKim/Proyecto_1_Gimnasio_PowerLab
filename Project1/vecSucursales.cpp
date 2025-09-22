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
        // Verificar que no exista el código
        if (!existeCodigo(sucursal->getCodigo())) {
            sucursales[can] = sucursal;
            can++;
            return true;
        }
    }
    return false;
}

bool vecSucursales::agregarSucursal(int codigo, const string provincia, const string canton, const string correo, const string telefono) {
    if (can < tam && !existeCodigo(codigo)) {
        Sucursal* nuevaSucursal = new Sucursal(codigo, provincia, canton, correo, telefono);
        sucursales[can] = nuevaSucursal;
        can++;
        return true;
    }
    return false;
}

Sucursal* vecSucursales::buscarPorCodigo(int codigo) const {
    for (int i = 0; i < can; i++) {
        if (sucursales[i] != nullptr && sucursales[i]->getCodigo() == codigo) {
            return sucursales[i];
        }
    }
    return nullptr;
}

int vecSucursales::buscarIndicePorCodigo(int codigo) const {
    for (int i = 0; i < can; i++) {
        if (sucursales[i] != nullptr && sucursales[i]->getCodigo() == codigo) {
            return i;
        }
    }
    return -1;
}

bool vecSucursales::eliminarSucursal(int codigo) {
    int indice = buscarIndicePorCodigo(codigo);
    if (indice != -1) {
        delete sucursales[indice];

        // Desplazar elementos hacia la izquierda
        for (int i = indice; i < can - 1; i++) {
            sucursales[i] = sucursales[i + 1];
        }

        sucursales[can - 1] = nullptr;
        can--;
        return true;
    }
    return false;
}

Sucursal* vecSucursales::getSucursalPorIndice(int indice) const {
    if (indice >= 0 && indice < can) {
        return sucursales[indice];
    }
    return nullptr;
}

int vecSucursales::getCan() const {
    return can;
}

int vecSucursales::getTam() const {
    return tam;
}

bool vecSucursales::estaLlena() const {
    return can >= tam;
}

bool vecSucursales::estaVacia() const {
    return can == 0;
}

bool vecSucursales::existeCodigo(int codigo) const {
    return buscarPorCodigo(codigo) != nullptr;
}

void vecSucursales::mostrarTodas() const {
    if (estaVacia()) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    cout << "Lista de sucursales:" << endl;
    for (int i = 0; i < can; i++) {
        if (sucursales[i] != nullptr) {
            cout << sucursales[i]->getCodigo() << " "
                << sucursales[i]->getProvincia() << " - "
                << sucursales[i]->getCanton() << endl;
        }
    }
}

void vecSucursales::mostrarSucursal(int codigo) const {
    Sucursal* sucursal = buscarPorCodigo(codigo);
    if (sucursal != nullptr) {
        cout << "Codigo: " << sucursal->getCodigo() << endl;
        cout << "Provincia: " << sucursal->getProvincia() << endl;
        cout << "Canton: " << sucursal->getCanton() << endl;
        cout << "Correo: " << sucursal->getCorreo() << endl;
        cout << "Telefono: " << sucursal->getTelefono() << endl;
    }
    else {
        cout << "Sucursal no encontrada." << endl;
    }
}

string vecSucursales::toString() const {
    stringstream s;
    if (estaVacia()) {
        s << "No hay sucursales registradas." << endl;
        return s.str();
    }

    s << "Lista de sucursales:" << endl;
    for (int i = 0; i < can; i++) {
        if (sucursales[i] != nullptr) {
            s << sucursales[i]->toString() << endl;
            s << "-------------------" << endl;
        }
    }
    return s.str();
}

string vecSucursales::mostrarListaSimple() const {
    stringstream s;
    if (estaVacia()) {
        s << "No hay sucursales registradas." << endl;
        return s.str();
    }

    s << "Lista de sucursales existentes:" << endl;
    for (int i = 0; i < can; i++) {
        if (sucursales[i] != nullptr) {
            s << sucursales[i]->getCodigo() << " "
                << sucursales[i]->getProvincia() << " - "
                << sucursales[i]->getCanton() << endl;
        }
    }
    return s.str();
}