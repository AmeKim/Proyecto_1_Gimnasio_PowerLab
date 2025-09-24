#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "vecClientes.h"
#include "vecClasesGrupales.h"
#include "vecInstructores.h"
#include "BateriaEjercicios.h"
#include "reporteM.h"
#include "utiles.h"

using namespace std;

class Sucursal {
private:
    string codigo;
    string provincia;
    string canton;
    string correo;
    string telefono;

    // Colecciones propias de la sucursal (propietarias)
    vecClientes* clientes;
    vecClasesGrupales* clases;
	vecInstructores* instructores;
    BateriaEjercicios* bateria;

public:
    Sucursal();
    Sucursal(string codigo, string provincia, string canton, string correo, string telefono);
    ~Sucursal();

    // Getters
    string getCodigo() const;
    string getProvincia() const;
    string getCanton() const;
    string getCorreo() const;
    string getTelefono() const;

    // Setters
    void setProvincia(string provincia);
    void setCanton(string canton);
    void setCorreo(string correo);
    void setTelefono(string telefono);

    // Operaciones solicitadas por el enunciado / interfaz
    bool agregarCliente(cliente* cli);               // valida duplicados por cedula en la sucursal
    cliente* buscarClientePorCedula(string cedula) const;

    bool agregarClaseGrupal(ClaseGrupal* c);        // valida límite de 8 clases (vecClasesGrupales ya tiene tam=8)
    ClaseGrupal* buscarClasePorCodigo(int codigo) const;

    BateriaEjercicios* getBateria();                // acceso a la batería de ejercicios
    vecClientes* getVecClientes();   
    vecInstructores* getVecInstructores();
	vecClasesGrupales* getVecClasesGrupales();

    // Reportes
    void generarReporteIMC() const;                  // usa reporteM para imprimir reporte por sucursal

    // Representación
    string toString() const;
};