#include "Sucursal.h"
#include "Medicion.h"

Sucursal::Sucursal() {
    codigo = 0;
    provincia = "";
    canton = "";
    correo = "";
    telefono = "";
    clientes = new vecClientes();
    instructores = new vecInstructores();
    clasesGrupales = new vecClasesGrupales();
}

Sucursal::Sucursal(int codigo, const string& provincia, const string& canton,
    const string& correo, const string& telefono) {
    this->codigo = codigo;
    this->provincia = provincia;
    this->canton = canton;
    this->correo = correo;
    this->telefono = telefono;
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
int Sucursal::getCodigo() const {
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

vecClientes* Sucursal::getClientes() const {
    return clientes;
}

vecInstructores* Sucursal::getInstructores() const {
    return instructores;
}

vecClasesGrupales* Sucursal::getClasesGrupales() const {
    return clasesGrupales;
}

// Setters
void Sucursal::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Sucursal::setProvincia(const string& provincia) {
    this->provincia = provincia;
}

void Sucursal::setCanton(const string& canton) {
    this->canton = canton;
}

void Sucursal::setCorreo(const string& correo) {
    this->correo = correo;
}

void Sucursal::setTelefono(const string& telefono) {
    this->telefono = telefono;
}

// Métodos para gestionar clientes
bool Sucursal::agregarCliente(cliente* cli) {
    if (cli != nullptr) {
        clientes->agregarCliente(cli);
        return true;
    }
    return false;
}

cliente* Sucursal::buscarCliente(const string& cedula) {
    return clientes->getCliente(cedula);
}

// Métodos para gestionar instructores
bool Sucursal::agregarInstructor(instructor* inst) {
    return instructores->agregarInstructor(inst);
}

instructor* Sucursal::buscarInstructor(const string& cedula) {
    return instructores->buscarInstructor(cedula);
}

// Métodos para gestionar clases grupales
bool Sucursal::agregarClaseGrupal(claseGrupal* clase) {
    return clasesGrupales->agregarClase(clase);
}

// Función auxiliar para determinar categoría de IMC
int determinarCategoriaIMC(double imc) {
    if (imc < 16.00) return 1;
    if (imc >= 16.00 && imc <= 16.99) return 2;
    if (imc >= 17.00 && imc <= 18.49) return 3;
    if (imc >= 18.50 && imc <= 24.99) return 4;
    if (imc >= 25.00 && imc <= 29.99) return 5;
    if (imc >= 30.00 && imc <= 34.99) return 6;
    if (imc >= 35.00 && imc <= 39.99) return 7;
    if (imc >= 40.00) return 8;
    return 0; // Valor inválido
}

// Reportes
void Sucursal::reporteIMC() const {
    cout << "REPORTE DE IMC – SUCURSAL " << provincia << " – " << canton << endl;
    cout << endl;

    // Procesar cada categoría de IMC usando switch
    for (int categoria = 1; categoria <= 8; categoria++) {
        string nombreCategoria;
        string rangoCategoria;

        switch (categoria) {
        case 1:
            nombreCategoria = "Delgadez severa";
            rangoCategoria = "(<16.00)";
            break;
        case 2:
            nombreCategoria = "Delgadez moderada";
            rangoCategoria = "(16.00 - 16.99)";
            break;
        case 3:
            nombreCategoria = "Delgadez leve";
            rangoCategoria = "(17.00 - 18.49)";
            break;
        case 4:
            nombreCategoria = "Normal";
            rangoCategoria = "(18.50 - 24.99)";
            break;
        case 5:
            nombreCategoria = "Pre-obesidad";
            rangoCategoria = "(25.00 - 29.99)";
            break;
        case 6:
            nombreCategoria = "Obesidad leve";
            rangoCategoria = "(30.00 - 34.99)";
            break;
        case 7:
            nombreCategoria = "Obesidad media";
            rangoCategoria = "(35.00 - 39.99)";
            break;
        case 8:
            nombreCategoria = "Obesidad mórbida";
            rangoCategoria = "(≥40.00)";
            break;
        default:
            nombreCategoria = "Desconocido";
            rangoCategoria = "";
            break;
        }

        cout << nombreCategoria << " " << rangoCategoria << ":" << endl;

        bool hayClientesEnCategoria = false;
        int contadorCategoria = 0;

        for (int i = 0; i < clientes->getCan(); i++) {
            cliente* cli = clientes->getClientePorIndice(i);
            if (cli && cli->getCanMediciones() > 0) {
                reporteM* ultimaMedicion = cli->getMedicion(cli->getCanMediciones() - 1);
                if (ultimaMedicion && determinarCategoriaIMC(ultimaMedicion->getIMC()) == categoria) {
                    contadorCategoria++;
                    cout << contadorCategoria << "- " << cli->getCedula() << " " << cli->getNombre()
                        << " IMC: " << ultimaMedicion->getIMC() << endl;
                    hayClientesEnCategoria = true;
                }
            }
        }

        switch (hayClientesEnCategoria) {
        case false:
            switch (categoria) {
            case 1: // Delgadez severa - muestra "Ninguno" según el PDF
                cout << "Ninguno" << endl;
                break;
            default:
                cout << "(Cantidad 0)" << endl;
                break;
            }
            break;
        case true:
            if (categoria != 1) { // Solo mostrar cantidad si no es delgadez severa
                cout << "(Cantidad " << contadorCategoria << ")" << endl;
            }
            break;
        }
    }
}

void Sucursal::mostrarClientesPorIMC() const {
    reporteIMC();
}

// Métodos de utilidad
void Sucursal::mostrar() const {
    cout << "=== DETALLE DE SUCURSAL ===" << endl;
    cout << "Código: " << codigo << endl;
    cout << "Provincia: " << provincia << endl;
    cout << "Cantón: " << canton << endl;
    cout << "Correo: " << correo << endl;
    cout << "Teléfono: " << telefono << endl;
    cout << "Clientes registrados: " << clientes->getCan() << endl;
    cout << "Instructores: " << instructores->getCan() << endl;
    cout << "Clases grupales: " << clasesGrupales->getCan() << endl;
}

string Sucursal::toString() const {
    stringstream s;
    s << codigo << " " << provincia << " - " << canton;
    return s.str();
}

string Sucursal::toStringCompleto() const {
    stringstream s;
    s << "Código: " << codigo << endl;
    s << "Provincia: " << provincia << endl;
    s << "Cantón: " << canton << endl;
    s << "Correo: " << correo << endl;
    s << "Teléfono: " << telefono << endl;
    return s.str();
}