#pragma once
#include <string>
#include <sstream>
#include "vecInstructores.h"
#include "vecClientes.h"
#include "vecClasesGrupales.h"

using namespace std;

class Sucursal {
private:
    string codigo;
    string provincia;
    string canton;
    string correo;
    string telefono;

    vecInstructores instructores;
    vecClientes* clientes;
    vecClasesGrupales* clasesGrupales;

public:
    // Constructores y destructor
    Sucursal();
    Sucursal(const string& cod, const string& prov, const string& cant,
        const string& corr, const string& tel);
    ~Sucursal();

    // Getters
    string getCodigo() const;
    string getProvincia() const;
    string getCanton() const;
    string getCorreo() const;
    string getTelefono() const;

    // Setters
    void setCodigo(const string& cod);
    void setProvincia(const string& prov);
    void setCanton(const string& cant);
    void setCorreo(const string& corr);
    void setTelefono(const string& tel);

    // Gestión de instructores
    void agregarInstructor(const instructor& ins);
    vecInstructores& obtenerVecInstructores();
    const vecInstructores& obtenerVecInstructores() const;
    instructor* buscarInstructorPorCedula(string cedula);
    const instructor* buscarInstructorPorCedula(string cedula) const;

    // Gestión de clientes
    vecClientes* getClientes();
    const vecClientes* getClientes() const;
    bool agregarCliente(cliente* cliente);
    cliente* buscarClientePorCedula(const string& cedula);

    // Gestión de clases grupales
    vecClasesGrupales* getClasesGrupales();
    const vecClasesGrupales* getClasesGrupales() const;
    bool agregarClaseGrupal(ClaseGrupal* clase);
    ClaseGrupal* buscarClasePorCodigo(int codigo);

    // Utilidades
    string toString() const;
    string toStringDetallado() const;
};