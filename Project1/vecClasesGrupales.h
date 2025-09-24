#pragma once
#include "ClaseGrupal.h"
#include <string>
using namespace std;

class vecClasesGrupales {
private:
    ClaseGrupal** clases;
    int tam;
    int cant;

public:
    vecClasesGrupales();
    ~vecClasesGrupales();

    bool agregar(ClaseGrupal* c);            // agrega si hay espacio
    ClaseGrupal* obtener(int indice);        // devuelve puntero o nullptr
    ClaseGrupal* buscarPorCodigo(int codigo); // busca por codigo
    int getCantidad() const;
   
    void mostrarLista() const;
	string mostrarTipos() const;
};