#pragma once
#include "instructor.h"
#include "claseGrupal.h"
#include "vecInstructores.h"
#include "vecClasesGrupales.h"
#include <string>
#include <sstream>

using namespace std;

class Sucursal {
public:
    Sucursal();
    Sucursal(const string& codigo, const string& provincia, const string& canton,const string& correo, const string& telefono);
    ~Sucursal();

    // Accesores básicos
    void setCodigo(const string& c);
    string getCodigo() const;
    void setProvincia(const string& p);
    string getProvincia() const;
    void setCanton(const string& ca);
    string getCanton() const;
    void setCorreo(const string& co);
    string getCorreo() const;
    void setTelefono(const string& t);
    string getTelefono() const;

    // Operaciones sobre instructores
    bool agregarInstructor(const instructor& ins); // retorna false si ya existe cedula
    int contarInstructores() const;
    const vecInstructores& obtenerVecInstructores() const;
    vecInstructores& obtenerVecInstructores();

    // Operaciones sobre clases (interfaz mínima requerida)
    void agregarClase(const ClaseGrupal& c);
    int contarClases() const;
    const vecClasesGrupales& obtenerVecClases() const;
    vecClasesGrupales& obtenerVecClases();

private:
    string codigo;
    string provincia;
    string canton;
    string correo;
    string telefono;

    vecInstructores instructores;
    vecClasesGrupales clases;
};