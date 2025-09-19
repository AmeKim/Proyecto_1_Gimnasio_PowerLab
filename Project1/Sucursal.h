#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "vecClientes.h"
#include "vecInstructores.h"
#include "vecClasesGrupales.h"
using namespace std;

class Sucursal {
private:
    int codigo;
    string provincia;
    string canton;
    string correo;
    string telefono;
    vecClientes* clientes;
    vecInstructores* instructores;
    vecClasesGrupales* clasesGrupales;

public:
    // Constructores y destructor
    Sucursal();
    Sucursal(int codigo, string provincia, string canton, string correo, string telefono);
    ~Sucursal();

    // Getters
    int getCodigo() const;
    string getProvincia() const;
    string getCanton() const;
    string getCorreo() const;
    string getTelefono() const;
    vecClientes* getClientes() const;
    vecInstructores* getInstructores() const;
    vecClasesGrupales* getClasesGrupales() const;

    // Setters
    void setCodigo(int codigo);
    void setProvincia(const string& provincia);
    void setCanton(const string& canton);
    void setCorreo(const string& correo);
    void setTelefono(const string& telefono);

    // M�todos para gestionar clientes
    bool agregarCliente(cliente* cli);
    cliente* buscarCliente(const string& cedula);
    void mostrarClientes() const;
    void reporteIMC() const;
    cliente* getClientePorIndice(int indice) const;

    // M�todos para gestionar instructores
    bool agregarInstructor(instructor* inst);
    instructor* buscarInstructor(const string& cedula);
    void mostrarInstructores() const;
    instructor* getInstructorPorIndice(int indice) const;

    // M�todos para gestionar clases grupales
    bool agregarClaseGrupal(claseGrupal* clase);
    void mostrarClasesGrupales() const;

    // M�todos de utilidad
    string toString() const;
    void mostrarDetalle() const;
};