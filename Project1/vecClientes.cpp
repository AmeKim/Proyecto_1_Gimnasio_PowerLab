#include "vecClientes.h"
#include <sstream>

vecClientes::vecClientes() : tam(50), cant(0) {
    clientes = new cliente * [tam];
    for (int i = 0; i < tam; i++) {
        clientes[i] = nullptr;
    }
}

vecClientes::~vecClientes() {
    for (int i = 0; i < cant; i++) {
        if (clientes[i]) {
            delete clientes[i];
        }
    }
    delete[] clientes;
}

void vecClientes::expandir() {
    int nuevoTam = tam * 2;
    cliente** nuevo = new cliente * [nuevoTam];

    for (int i = 0; i < nuevoTam; i++) {
        nuevo[i] = nullptr;
    }

    for (int i = 0; i < cant; i++) {
        nuevo[i] = clientes[i];
    }

    delete[] clientes;
    clientes = nuevo;
    tam = nuevoTam;
}

bool vecClientes::agregar(cliente* cli) {
    if (!cli) return false;

    if (buscarPorCedula(cli->getCedula()) != nullptr) {
        return false;
    }

    if (cant >= tam) {
        expandir();
    }

    clientes[cant++] = cli;
    return true;
}

cliente* vecClientes::obtener(int indice) {
    if (indice < 0 || indice >= cant) return nullptr;
    return clientes[indice];
}

cliente* vecClientes::buscarPorCedula(const string& cedula) {
    for (int i = 0; i < cant; i++) {
        if (clientes[i] && clientes[i]->getCedula() == cedula) {
            return clientes[i];
        }
    }
    return nullptr;
}

int vecClientes::getCantidad() const {
    return cant;
}

string vecClientes::listarSimple() const {
    if (cant == 0) {
        return "No hay clientes registrados.\n";
    }

    stringstream ss;
    for (int i = 0; i < cant; i++) {
        if (clientes[i]) {
            ss << (i + 1) << "- " << clientes[i]->getCedula() << " "
                << clientes[i]->getNombreCompleto() << "\n";
        }
    }
    return ss.str();
}