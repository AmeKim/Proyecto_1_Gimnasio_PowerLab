#include "vecClasesGrupales.h"
#include "utiles.h"

vecClasesGrupales::vecClasesGrupales() {
    tam = 8; // requisito: máximo 8 clases por sucursal
    cant = 0;
    clases = new ClaseGrupal * [tam];
    for (int i = 0; i < tam; i++) clases[i] = nullptr;
}

vecClasesGrupales::~vecClasesGrupales() {
    for (int i = 0; i < cant; i++) {
        delete clases[i];
    }
    delete[] clases;
}

bool vecClasesGrupales::agregar(ClaseGrupal* c) {
    if (cant < tam) {
        clases[cant] = c;
        cant++;
        return true;
    }
    return false;
}

ClaseGrupal* vecClasesGrupales::obtener(int indice) {
    if (indice >= 0 && indice < cant) return clases[indice];
    return nullptr;
}

ClaseGrupal* vecClasesGrupales::buscarPorCodigo(string codigo) {
    for (int i = 0; i < cant; i++) {
        if (clases[i] != nullptr && clases[i]->getCodigo() == codigo) {
            return clases[i];
        }
    }
    return nullptr;
}

int vecClasesGrupales::getCantidad() const {
    return cant;
}

void vecClasesGrupales::mostrarLista() const {
    print("Lista de clases grupales de la sucursal:\n");
    for (int i = 0; i < cant; i++) {
        if (clases[i] != nullptr) {
            print(to_string(i + 1) + "- " + clases[i]->toString() + "\n");
        }
    }
}