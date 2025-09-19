#include "Sucursal.h"

Sucursal::Sucursal(string codigo, string provincia, string canton, string correo, string telefono) {
    this->codigo = codigo;
    this->provincia = provincia;
    this->canton = canton;
    this->correo = correo;
    this->telefono = telefono;
    this->clientes = new vecClientes();
    this->instructores = new vecInstructores();
    this->clasesGrupales = new vecClasesGrupales();
}

Sucursal::Sucursal() {
    this->codigo = "";
    this->provincia = "";
    this->canton = "";
    this->correo = "";
    this->telefono = "";
    this->clientes = new vecClientes();
    this->instructores = new vecInstructores();
    this->clasesGrupales = new vecClasesGrupales();
}

Sucursal::~Sucursal() {
    delete clientes;
    delete instructores;
    delete clasesGrupales;
}

// Getters
string Sucursal::getCodigo() const { return codigo; }
string Sucursal::getProvincia() const { return provincia; }
string Sucursal::getCanton() const { return canton; }
string Sucursal::getCorreo() const { return correo; }
string Sucursal::getTelefono() const { return telefono; }
vecClientes* Sucursal::getClientes() const { return clientes; }
vecInstructores* Sucursal::getInstructores() const { return instructores; }
vecClasesGrupales* Sucursal::getClasesGrupales() const { return clasesGrupales; }

// Setters
void Sucursal::setCodigo(string codigo) { this->codigo = codigo; }
void Sucursal::setProvincia(string provincia) { this->provincia = provincia; }
void Sucursal::setCanton(string canton) { this->canton = canton; }
void Sucursal::setCorreo(string correo) { this->correo = correo; }
void Sucursal::setTelefono(string telefono) { this->telefono = telefono; }

// Métodos de gestión
bool Sucursal::agregarCliente(cliente* cli) {
    if (clientes && cli) {
        clientes->agregarCliente(cli);
        return true;
    }
    return false;
}

bool Sucursal::agregarInstructor(instructor* inst) {
    if (instructores && inst) {
        instructores->agregarInstructor(inst);
        return true;
    }
    return false;
}

bool Sucursal::agregarClaseGrupal(claseGrupal* clase) {
    if (clasesGrupales && clase) {
        clasesGrupales->agregarClase(clase);
        return true;
    }
    return false;
}

cliente* Sucursal::buscarCliente(string cedula) {
    if (clientes) {
        return clientes->getCliente(cedula);
    }
    return nullptr;
}

instructor* Sucursal::buscarInstructor(string cedula) {
    if (instructores) {
        return instructores->getInstructor(cedula);
    }
    return nullptr;
}

string Sucursal::reporteIMC() {
    stringstream s;
    s << "\n========= REPORTE DE IMC - SUCURSAL " << provincia << " - " << canton << " =========\n\n";

    // Arrays para contar clientes por categoría
    int delgadezSevera = 0, delgadezModerada = 0, delgadezLeve = 0;
    int normal = 0, preObesidad = 0;
    int obesidadLeve = 0, obesidadMedia = 0, obesidadMorbida = 0;

    stringstream sDelgadezSevera, sDelgadezModerada, sDelgadezLeve;
    stringstream sNormal, sPreObesidad;
    stringstream sObesidadLeve, sObesidadMedia, sObesidadMorbida;

    // Aquí se implementaría la lógica para categorizar clientes por IMC
    // usando las mediciones más recientes de cada cliente

    s << "Delgadez severa (<16.00):\n";
    if (delgadezSevera == 0) {
        s << "  Ninguno\n";
    }
    else {
        s << "  (Cantidad " << delgadezSevera << ")\n" << sDelgadezSevera.str();
    }

    s << "\nDelgadez moderada (16.00 - 16.99):\n";
    if (delgadezModerada == 0) {
        s << "  Ninguno\n";
    }
    else {
        s << "  (Cantidad " << delgadezModerada << ")\n" << sDelgadezModerada.str();
    }

    s << "\nDelgadez leve (17.00 - 18.49):\n";
    if (delgadezLeve == 0) {
        s << "  Ninguno\n";
    }
    else {
        s << "  (Cantidad " << delgadezLeve << ")\n" << sDelgadezLeve.str();
    }

    s << "\nNormal (18.50 - 24.99):\n";
    if (normal == 0) {
        s << "  Ninguno\n";
    }
    else {
        s << "  (Cantidad " << normal << ")\n" << sNormal.str();
    }

    s << "\nPre-obesidad (25.00 - 29.99):\n";
    if (preObesidad == 0) {
        s << "  Ninguno\n";
    }
    else {
        s << "  (Cantidad " << preObesidad << ")\n" << sPreObesidad.str();
    }

    s << "\nObesidad leve (30.00 - 34.99):\n";
    if (obesidadLeve == 0) {
        s << "  Ninguno\n";
    }
    else {
        s << "  (Cantidad " << obesidadLeve << ")\n" << sObesidadLeve.str();
    }

    s << "\nObesidad media (35.00 - 39.99):\n";
    if (obesidadMedia == 0) {
        s << "  Ninguno\n";
    }
    else {
        s << "  (Cantidad " << obesidadMedia << ")\n" << sObesidadMedia.str();
    }

    s << "\nObesidad mórbida (?40.00):\n";
    if (obesidadMorbida == 0) {
        s << "  Ninguno\n";
    }
    else {
        s << "  (Cantidad " << obesidadMorbida << ")\n" << sObesidadMorbida.str();
    }

    return s.str();
}

string Sucursal::listaClientesPorInstructor(string cedulaInstructor) {
    stringstream s;
    instructor* inst = buscarInstructor(cedulaInstructor);

    if (!inst) {
        return "Instructor no encontrado\n";
    }

    s << "Clientes a cargo del instructor " << inst->getNombre() << ":\n";

    int contador = 0;
    for (int i = 0; i < clientes->getCan(); i++) {
        cliente* cli = clientes->getClientePorIndice(i);
        if (cli && cli->getInstructor() == inst) {
            contador++;
            s << contador << ". " << cli->getCedula() << " " << cli->getNombre() << "\n";
        }
    }

    if (contador == 0) {
        s << "Este instructor no tiene clientes asignados\n";
    }

    return s.str();
}

string Sucursal::toString() {
    stringstream s;
    s << "========== SUCURSAL ==========\n";
    s << "Codigo: " << codigo << "\n";
    s << "Provincia: " << provincia << "\n";
    s << "Canton: " << canton << "\n";
    s << "Correo: " << correo << "\n";
    s << "Telefono: " << telefono << "\n";
    s << "Total clientes: " << (clientes ? clientes->getCan() : 0) << "\n";
    s << "Total instructores: " << (instructores ? instructores->getCan() : 0) << "\n";
    s << "Total clases grupales: " << (clasesGrupales ? clasesGrupales->getCan() : 0) << "\n";
    return s.str();
}

string Sucursal::toStringSimple() {
    stringstream s;
    s << codigo << " " << provincia << " - " << canton;
    return s.str();
}