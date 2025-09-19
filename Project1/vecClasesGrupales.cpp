#include "vecClasesGrupales.h"
#include "utiles.h"

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
        if (clases[i]) {
            delete clases[i];
        }
    }
    delete[] clases;
}

bool vecClasesGrupales::agregarClase(claseGrupal* clase) {
    if (can < tam && clase) {
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
    for (int i = 0; i < can; i++) {
        if (clases[i]) {
            print("=================================\n");
            print(clases[i]->toString());
            print("=================================\n");
        }
    }
}

bool vecClasesGrupales::matricularClienteEnClase(int codigoClase, cliente* cli) {
    if (!cli) return false;

    int contador = 0;

    // Contar en cuántas clases ya está matriculado el cliente
    for (int i = 0; i < can; ++i) {
        if (clases[i] && clases[i]->tieneClienteMatriculado(cli)) {
            contador++;
        }
    }

    // Verificar límite de 3 clases por cliente
    if (contador >= 3) {
        print("El cliente ya está matriculado en 3 clases (máximo permitido)\n");
        return false;
    }

    // Buscar la clase específica y matricular
    claseGrupal* clase = buscarPorCodigo(codigoClase);
    if (clase) {
        if (clase->matricularCliente(cli)) {
            print("Cliente matriculado correctamente en la clase\n");
            return true;
        }
        else {
            print("No se pudo matricular el cliente (clase llena o ya matriculado)\n");
            return false;
        }
    }

    print("No se encontró la clase especificada\n");
    return false;
}

void vecClasesGrupales::mostrarClientesDeClase(int codigoClase) const {
    claseGrupal* clase = buscarPorCodigo(codigoClase);
    if (clase) {
        print("=== CLIENTES MATRICULADOS ===\n");
        print(clase->getClientesMatriculadosStr());
    }
    else {
        print("No se encontró la clase especificada\n");
    }
}

int vecClasesGrupales::getCan() const {
    return can;
}