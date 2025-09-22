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
    Sucursal();
    Sucursal(int codigo, const string& provincia, const string& canton,
        const string& correo, const string& telefono);
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

    // Métodos para gestionar clientes
    bool agregarCliente(cliente* cli);
    cliente* buscarCliente(const string& cedula);

    // Métodos para gestionar instructores
    bool agregarInstructor(instructor* inst);
    instructor* buscarInstructor(const string& cedula);

    // Métodos para gestionar clases grupales
    bool agregarClaseGrupal(claseGrupal* clase);

    // Reportes
    void reporteIMC() const;
    void mostrarClientesPorIMC() const;

    // Métodos de utilidad
    void mostrar() const;
    string toString() const;
    string toStringCompleto() const;
};