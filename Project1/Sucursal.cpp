#include "Sucursal.h"

Sucursal::Sucursal() {
    codigo = "";
    provincia = "";
    canton = "";
    correo = "";
    telefono = "";
    clientes = new vecClientes();
    clases = new vecClasesGrupales();
    bateria = new BateriaEjercicios();
	instructores = new vecInstructores();
}

Sucursal::Sucursal(string codigo, string provincia, string canton, string correo, string telefono) {
    this->codigo = codigo;
    this->provincia = provincia;
    this->canton = canton;
    this->correo = correo;
    this->telefono = telefono;
    clientes = new vecClientes();
    clases = new vecClasesGrupales();
    bateria = new BateriaEjercicios();
	instructores = new vecInstructores();
}

Sucursal::~Sucursal() {
    delete clientes;
    delete clases;
    delete bateria;
	delete instructores;
}

// Getters
string Sucursal::getCodigo() const { return codigo; }
string Sucursal::getProvincia() const { return provincia; }
string Sucursal::getCanton() const { return canton; }
string Sucursal::getCorreo() const { return correo; }
string Sucursal::getTelefono() const { return telefono; }

// Setters
void Sucursal::setProvincia(string provincia) { this->provincia = provincia; }
void Sucursal::setCanton(string canton) { this->canton = canton; }
void Sucursal::setCorreo(string correo) { this->correo = correo; }
void Sucursal::setTelefono(string telefono) { this->telefono = telefono; }

// Agregar cliente con validación de duplicado en la misma sucursal
bool Sucursal::agregarCliente(cliente* cli) {
    if (cli == nullptr) return false;
    string ced = cli->getCedula();
    // buscar por cédula en esta sucursal
    cliente* existente = clientes->buscarPorCedula(ced);
    if (existente != nullptr) {
        // Ya existe un cliente con misma cédula en la sucursal
        return false;
    }
    clientes->agregar(cli);
    return true;
}

cliente* Sucursal::buscarClientePorCedula(string cedula) const {
    // vecClientes tiene versión const de buscarPorCedula
    return clientes->buscarPorCedula(cedula);
}

// Agregar clase grupal: vecClasesGrupales::agregar devuelve false si ya está lleno
bool Sucursal::agregarClaseGrupal(ClaseGrupal* c) {
    if (c == nullptr) return false;
    // Verificar que no exista clase con mismo código
    ClaseGrupal* existente = clases->buscarPorCodigo(c->getCodigo());
    if (existente != nullptr) {
        return false; // duplicado por código
    }
    return clases->agregar(c);
}

ClaseGrupal* Sucursal::buscarClasePorCodigo(int codigo) const {
    return clases->buscarPorCodigo(codigo);
}

BateriaEjercicios* Sucursal::getBateria() {
    return bateria;
}

vecClientes* Sucursal::getVecClientes() {
    return clientes;
}

vecInstructores* Sucursal::getVecInstructores() {
    return instructores;
}

vecClasesGrupales* Sucursal::getVecClasesGrupales(){
	return clases;
}

// Genera reporte IMC por sucursal (usa reporteM: imprime por consola)
void Sucursal::generarReporteIMC() const {
    reporteM rep;
    // Construir nombre para encabezado: provincia - canton
    string nombreSucursal = provincia + " - " + canton;
    rep.generarReporteIMCporSucursal(clientes, nombreSucursal);
}

string Sucursal::toString() const {
    stringstream s;
    s << "Codigo : " << codigo << "\n";
    s << "Provincia: " << provincia << "\n";
    s << "Canton: " << canton << "\n";
    s << "Correo: " << correo << "\n";
    s << "Telefono: " << telefono << "\n";
    s << "Clientes registrados: " << clientes->getCantidad() << "\n";
    s << "Clases registradas: " << clases->getCantidad() << "\n";
    return s.str();
}