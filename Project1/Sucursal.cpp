#include "Sucursal.h"
#include <sstream>
#include <iostream> // Necesario para 'cout' en el método mostrar()

// MODIFICAR CONSTRUCTOR para que acepte y asigne el código
Sucursal::Sucursal(int cod, string nom, string ubi) : codigo(cod), nombre(nom), ubicacion(ubi) {
    clientes = new vecClientes();
    instructores = new vecInstructores();
    clasesGrupales = new vecClasesGrupales();
}

Sucursal::~Sucursal() {
    delete clientes;
    delete instructores;
    delete clasesGrupales;
}

// ===== IMPLEMENTACIÓN DE MÉTODOS AÑADIDOS =====

int Sucursal::getCodigo() const {
    return codigo;
}

string Sucursal::toString() const {
    stringstream s;
    s << "Sucursal [" << codigo << "] - " << nombre << " (" << ubicacion << ")";
    return s.str();
}

void Sucursal::mostrar() const {
    cout << toString() << endl;
}

// =================================================

// (Aquí va el resto del código de Sucursal.cpp que ya tenías, sin cambios)

// Métodos para Clientes
bool Sucursal::agregarCliente(cliente* cli) {
    clientes->agregarCliente(cli);
    return true;
}

bool Sucursal::eliminarCliente(string cedula) {
    if (clientes->getCliente(cedula) != nullptr) {
        clientes->eliminarCliente(cedula);
        return true;
    }
    return false;
}

cliente* Sucursal::buscarCliente(string cedula) {
    return clientes->getCliente(cedula);
}

string Sucursal::mostrarTodosLosClientes() const {
    return clientes->mostrarTodos();
}

// Métodos para Instructores
bool Sucursal::contratarInstructor(instructor* ins) {
    return instructores->agregarInstructor(ins);
}

bool Sucursal::despedirInstructor(string cedula) {
    if (instructores->buscarInstructor(cedula) != nullptr) {
        instructores->eliminarInstructor(cedula);
        return true;
    }
    return false;
}

instructor* Sucursal::buscarInstructor(string cedula) {
    return instructores->buscarInstructor(cedula);
}

string Sucursal::mostrarTodosLosInstructores() const {
    return instructores->toString();
}

// Métodos para Clases Grupales
bool Sucursal::agregarClaseGrupal(claseGrupal* clase) {
    return clasesGrupales->agregarClase(clase);
}

bool Sucursal::matricularClienteEnClase(int codigoClase, string cedulaCliente) {
    cliente* cli = clientes->getCliente(cedulaCliente);
    if (cli) {
        return clasesGrupales->matricularClienteEnClase(codigoClase, cli);
    }
    return false;
}

string Sucursal::mostrarTodasLasClases() const {
    return clasesGrupales->toString();
}

void Sucursal::mostrarClientesDeClase(int codigoClase) const {
    clasesGrupales->mostrarClientesDeClase(codigoClase);
}