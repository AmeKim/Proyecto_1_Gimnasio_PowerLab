#include "Sucursal.h"

// Constructor por defecto
Sucursal::Sucursal()
    : codigo(""), provincia(""), canton(""), correo(""), telefono(""),
    instructores(8) {
    clientes = new vecClientes();
    clasesGrupales = new vecClasesGrupales();
}

// Constructor con parámetros
Sucursal::Sucursal(const string& cod, const string& prov, const string& cant,
    const string& corr, const string& tel)
    : codigo(cod), provincia(prov), canton(cant), correo(corr), telefono(tel),
    instructores(8) {
    clientes = new vecClientes();
    clasesGrupales = new vecClasesGrupales();
}

// Destructor
Sucursal::~Sucursal() {
    if (clientes) {
        delete clientes;
        clientes = nullptr;
    }
    if (clasesGrupales) {
        delete clasesGrupales;
        clasesGrupales = nullptr;
    }
}

// Getters
string Sucursal::getCodigo() const {
    return codigo;
}

string Sucursal::getProvincia() const {
    return provincia;
}

string Sucursal::getCanton() const {
    return canton;
}

string Sucursal::getCorreo() const {
    return correo;
}

string Sucursal::getTelefono() const {
    return telefono;
}

// Setters
void Sucursal::setCodigo(const string& cod) {
    codigo = cod;
}

void Sucursal::setProvincia(const string& prov) {
    provincia = prov;
}

void Sucursal::setCanton(const string& cant) {
    canton = cant;
}

void Sucursal::setCorreo(const string& corr) {
    correo = corr;
}

void Sucursal::setTelefono(const string& tel) {
    telefono = tel;
}

// Gestión de instructores
void Sucursal::agregarInstructor(const instructor& ins) {
    instructores.agregar(ins);
}

vecInstructores& Sucursal::obtenerVecInstructores() {
    return instructores;
}

const vecInstructores& Sucursal::obtenerVecInstructores() const {
    return instructores;
}

instructor* Sucursal::buscarInstructorPorCedula(int cedula) {
    int indice = instructores.indicePorCedula(cedula);
    if (indice == -1) return nullptr;
    return &instructores.obtener(indice);
}

const instructor* Sucursal::buscarInstructorPorCedula(int cedula) const {
    int indice = instructores.indicePorCedula(cedula);
    if (indice == -1) return nullptr;
    return &instructores.obtener(indice);
}

// Gestión de clientes
vecClientes* Sucursal::getClientes() {
    return clientes;
}

const vecClientes* Sucursal::getClientes() const {
    return clientes;
}

bool Sucursal::agregarCliente(cliente* cliente) {
    if (!clientes || !cliente) return false;
    return clientes->agregar(cliente);
}

cliente* Sucursal::buscarClientePorCedula(const string& cedula) {
    if (!clientes) return nullptr;
    return clientes->buscarPorCedula(cedula);
}

// Gestión de clases grupales
vecClasesGrupales* Sucursal::getClasesGrupales() {
    return clasesGrupales;
}

const vecClasesGrupales* Sucursal::getClasesGrupales() const {
    return clasesGrupales;
}

bool Sucursal::agregarClaseGrupal(ClaseGrupal* clase) {
    if (!clasesGrupales || !clase) return false;
    return clasesGrupales->agregar(clase);
}

ClaseGrupal* Sucursal::buscarClasePorCodigo(int codigo) {
    if (!clasesGrupales) return nullptr;
    return clasesGrupales->buscarPorCodigo(codigo);
}

// Utilidades
string Sucursal::toString() const {
    stringstream s;
    s << codigo << " " << provincia << " - " << canton;
    return s.str();
}

string Sucursal::toStringDetallado() const {
    stringstream s;
    s << "Codigo: " << codigo << "\n";
    s << "Provincia: " << provincia << "\n";
    s << "Canton: " << canton << "\n";
    s << "Correo: " << correo << "\n";
    s << "Telefono: " << telefono << "\n";
    s << "Instructores: " << instructores.tamanio() << "\n";
    if (clientes) {
        s << "Clientes: " << clientes->getCantidad() << "\n";
    }
    if (clasesGrupales) {
        s << "Clases Grupales: " << clasesGrupales->getCantidad() << "\n";
    }
    return s.str();
}