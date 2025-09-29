#include "vecClasesGrupales.h"
#include <sstream>

vecClasesGrupales::vecClasesGrupales() : tam(8), cant(0) {
    clases = new ClaseGrupal * [tam];
    for (int i = 0; i < tam; i++) {
        clases[i] = nullptr;
    }
}

vecClasesGrupales::~vecClasesGrupales() {
    for (int i = 0; i < cant; i++) {
        if (clases[i]) {
            delete clases[i];
        }
    }
    delete[] clases;
}

bool vecClasesGrupales::agregar(ClaseGrupal* c) {
    if (!c || cant >= tam) return false;

    for (int i = 0; i < cant; i++) {
        if (clases[i] && clases[i]->getCodigo() == c->getCodigo()) {
            return false;
        }
    }

    clases[cant++] = c;
    return true;
}

ClaseGrupal* vecClasesGrupales::obtener(int cod) {
    for (int i = 0; i < cant; i++) {
        if (clases[i] && clases[i]->getCodigo() == cod) {
            return clases[i];
        }
    }
    return nullptr;
}

ClaseGrupal* vecClasesGrupales::buscarPorCodigo(int codigo) {
    return obtener(codigo);
}

int vecClasesGrupales::getCantidad() const {
    return cant;
}

void vecClasesGrupales::mostrarLista() const {
    if (cant == 0) {
        cout << "No hay clases grupales registradas.\n";
        return;
    }

    for (int i = 0; i < cant; i++) {
        if (clases[i]) {
            cout << (i + 1) << ". " << clases[i]->getTipo() << "\n";
        }
    }
}

string vecClasesGrupales::mostrarTipos() const {
    if (cant == 0) {
        return "No hay clases grupales registradas.\n";
    }

    stringstream ss;
    for (int i = 0; i < cant; i++) {
        if (clases[i]) {
            ss << clases[i]->getCodigo() << ". " << clases[i]->getTipo() << "\n";
        }
    }
    return ss.str();
}