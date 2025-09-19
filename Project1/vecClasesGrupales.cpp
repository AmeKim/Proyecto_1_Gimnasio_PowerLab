#include "vecClasesGrupales.h"
#include <iostream>

vecClasesGrupales::vecClasesGrupales(int capacidad) : can(0), tam(capacidad) {
    clases = new claseGrupal*[tam];
    for (int i = 0; i < tam; ++i) clases[i] = nullptr;
}

vecClasesGrupales::~vecClasesGrupales() {
    for (int i = 0; i < can; ++i) {
        delete clases[i];
    }
    delete[] clases;
}

bool vecClasesGrupales::agregarClase(claseGrupal* clase) {
    if (can < tam && clase) {
        clases[can++] = clase;
        return true;
    }
    return false;
}

claseGrupal* vecClasesGrupales::buscarPorCodigo(int codigo) const {
    for (int i = 0; i < can; ++i) {
        if (clases[i] && clases[i]->getCodigo() == codigo) {
            return clases[i];
        }
    }
    return nullptr;
}

void vecClasesGrupales::mostrarTodas() const {
    for (int i = 0; i < can; ++i) {
        if (clases[i]) {
            clases[i]->mostrarDetalle();
            std::cout << "----------------------" << std::endl;
        }
    }
}

bool vecClasesGrupales::matricularClienteEnClase(int codigoClase, cliente* cli) {
    if (!cli) return false;
    // Validar máximo 3 clases por cliente
    int contador = 0;
    for (int i = 0; i < can; ++i) {
        if (clases[i]) {
            for (int j = 0; j < clases[i]->getCantidadActual(); ++j) {
                // Comparar por puntero
                if (clases[i]->getCantidadActual() > 0 && clases[i]->getInstructor() == cli) {
                    contador++;
                }
            }
        }
    }
    if (contador >= 3) return false;
    claseGrupal* clase = buscarPorCodigo(codigoClase);
    if (clase) {
        return clase->matricularCliente(cli);
    }
    return false;
}

void vecClasesGrupales::mostrarClientesDeClase(int codigoClase) const {
    claseGrupal* clase = buscarPorCodigo(codigoClase);
    if (clase) {
        clase->mostrarClientes();
    } else {
        std::cout << "Clase grupal no encontrada." << std::endl;
    }
}

int vecClasesGrupales::getCan() const {
    return can;
}
