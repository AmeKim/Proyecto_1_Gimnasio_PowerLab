#include "vecClasesGrupales.h"

vecClasesGrupales::vecClasesGrupales(int capacidad) {
    tam = capacidad;
    can = 0;
    clases = new claseGrupal * [tam];
    for (int i = 0; i < tam; i++) {
        clases[i] = nullptr;
    }
}

vecClasesGrupales::~vecClasesGrupales() {
    for (int i = 0; i < can; i++) {
        delete clases[i];
    }
    delete[] clases;
}

bool vecClasesGrupales::agregarClase(claseGrupal* clase) {
    if (can < tam && clase != nullptr) {
        clases[can] = clase;
        can++;
        return true;
    }
    return false;
}

claseGrupal* vecClasesGrupales::buscarPorCodigo(int codigo) const {
    for (int i = 0; i < can; i++) {
        if (clases[i] && clases[i]->getCodigo() == codigo) {
            return clases[i];
        }
    }
    return nullptr;
}

void vecClasesGrupales::mostrarTodas() const {
    cout << "Lista de clases existentes en la sucursal:" << endl;
    for (int i = 0; i < can; i++) {
        if (clases[i]) {
            cout << clases[i]->toString() << endl;
        }
    }
}

bool vecClasesGrupales::matricularClienteEnClase(int codigoClase, cliente* cli) {
    claseGrupal* clase = buscarPorCodigo(codigoClase);
    if (clase && cli) {
        return clase->matricularCliente(cli);
    }
    return false;
}

void vecClasesGrupales::mostrarClientesDeClase(int codigoClase) const {
    claseGrupal* clase = buscarPorCodigo(codigoClase);
    if (clase) {
        clase->mostrarClientesMatriculados();
    }
    else {
        cout << "Clase no encontrada." << endl;
    }
}

int vecClasesGrupales::getCan() const {
    return can;
}