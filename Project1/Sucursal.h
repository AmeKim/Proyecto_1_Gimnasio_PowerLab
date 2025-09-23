#pragma once
#include "vecClientes.h"
#include "vecInstructores.h"
#include "vecClasesGrupales.h"
#include <string>

using namespace std;

class Sucursal {
private:
    int codigo; // <-- AÑADIR ESTA LÍNEA
    string nombre;
    string ubicacion;
    vecClientes* clientes;
    vecInstructores* instructores;
    vecClasesGrupales* clasesGrupales;

public:
    Sucursal(int cod, string nom, string ubi); // <-- MODIFICAR CONSTRUCTOR
    ~Sucursal();

    // ===== MÉTODOS AÑADIDOS PARA CORREGIR ERRORES =====
    int getCodigo() const;
    string toString() const;
    void mostrar() const;
    // =================================================

    // Métodos para Clientes
    bool agregarCliente(cliente* cli);
    bool eliminarCliente(string cedula);
    cliente* buscarCliente(string cedula);
    string mostrarTodosLosClientes() const;

    // Métodos para Instructores
    bool contratarInstructor(instructor* ins);
    bool despedirInstructor(string cedula);
    instructor* buscarInstructor(string cedula);
    string mostrarTodosLosInstructores() const;

    // Métodos para Clases Grupales
    bool agregarClaseGrupal(claseGrupal* clase);
    bool matricularClienteEnClase(int codigoClase, string cedulaCliente);
    string mostrarTodasLasClases() const;
    void mostrarClientesDeClase(int codigoClase) const;
};