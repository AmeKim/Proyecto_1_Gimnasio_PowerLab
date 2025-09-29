#include "sucursal.h"

Sucursal::Sucursal(): codigo(), provincia(), canton(), correo(), telefono(),instructores(8), clases(8) {
}

Sucursal::Sucursal(const string& codigo, const string& provincia, const string& canton,const string& correo, const string& telefono): codigo(codigo), provincia(provincia), canton(canton), correo(correo), telefono(telefono), instructores(8), clases(8) {
}

Sucursal::~Sucursal() {}

// Accesores
void Sucursal::setCodigo(const string& c) { codigo = c; }
string Sucursal::getCodigo() const { return codigo; }
void Sucursal::setProvincia(const string& p) { provincia = p; }
string Sucursal::getProvincia() const { return provincia; }
void Sucursal::setCanton(const string& ca) { canton = ca; }
string Sucursal::getCanton() const { return canton; }
void Sucursal::setCorreo(const string& co) { correo = co; }
string Sucursal::getCorreo() const { return correo; }
void Sucursal::setTelefono(const string& t) { telefono = t; }
string Sucursal::getTelefono() const { return telefono; }

// Instructores
bool Sucursal::agregarInstructor(const instructor& ins) {
    // Validar que no exista instructor con misma cédula en esta sucursal
    int cedula = stoi(ins.getCedula());
    if (instructores.indicePorCedula(cedula) != -1) {
        return false; // Ya existe un instructor con esa cédula
    }
    instructores.agregar(ins);
    return true;
}

int Sucursal::contarInstructores() const {
    return instructores.tamanio();
}

const vecInstructores& Sucursal::obtenerVecInstructores() const {
    return instructores;
}

vecInstructores& Sucursal::obtenerVecInstructores() {
    return instructores;
}

// Clases
void Sucursal::agregarClase(const ClaseGrupal& c) {
    clases.agregar(c);
}

int Sucursal::contarClases() const {
    return clases.tamanio();
}

const vecClasesGrupales& Sucursal::obtenerVecClases() const {
    return clases;
}

vecClasesGrupales& Sucursal:: obtenerVecClases() {
	return clases;
}