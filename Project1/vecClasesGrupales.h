#pragma once
#include "claseGrupal.h"
#include <string>
using namespace std;

class vecClasesGrupales {
private:
    claseGrupal** clases;
    int can;
    int tam;
public:
    vecClasesGrupales(int capacidad = 8);
    ~vecClasesGrupales();
    bool agregarClase(claseGrupal* clase);
    claseGrupal* buscarPorCodigo(int codigo) const;
    void mostrarTodas() const;
    string toString() const; // <-- A�ADIR ESTA L�NEA
    bool matricularClienteEnClase(int codigoClase, cliente* cli);
    void mostrarClientesDeClase(int codigoClase) const;
    int getCan() const;
};