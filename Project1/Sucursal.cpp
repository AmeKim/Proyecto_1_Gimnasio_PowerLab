#include "Sucursal.h"
#include "utiles.h"
#include <iostream>

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

Sucursal::Sucursal(int codigo, string provincia, string canton, string correo, string telefono) {
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
int Sucursal::getCodigo() const { return codigo; }
string Sucursal::getProvincia() const { return provincia; }
string Sucursal::getCanton() const { return canton; }
string Sucursal::getCorreo() const { return correo; }
string Sucursal::getTelefono() const { return telefono; }
vecClientes* Sucursal::getClientes() const { return clientes; }
vecInstructores* Sucursal::getInstructores() const { return instructores; }
vecClasesGrupales* Sucursal::getClasesGrupales() const { return clasesGrupales; }

// Setters
void Sucursal::setCodigo(int codigo) { this->codigo = codigo; }
void Sucursal::setProvincia(const string& provincia) { this->provincia = provincia; }
void Sucursal::setCanton(const string& canton) { this->canton = canton; }
void Sucursal::setCorreo(const string& correo) { this->correo = correo; }
void Sucursal::setTelefono(const string& telefono) { this->telefono = telefono; }

// Métodos para gestionar clientes
bool Sucursal::agregarCliente(cliente* cli) {
    if (cli && !buscarCliente(cli->getCedula())) {
        clientes->agregarCliente(cli);
        return true;
    }
    return false;
}

cliente* Sucursal::buscarCliente(const string& cedula) {
    return clientes->getCliente(cedula);
}

void Sucursal::mostrarClientes() const {
    if (clientes->getCan() == 0) {
        print("No hay clientes registrados en esta sucursal\n");
        return;
    }

    print("Lista de clientes de la sucursal:\n");
    for (int i = 0; i < clientes->getCan(); i++) {
        cliente* cli = clientes->getClientePorIndice(i);
        if (cli) {
            print(to_string(i + 1) + "- " + cli->getCedula() + " " + cli->getNombre() + "\n");
        }
    }
}

cliente* Sucursal::getClientePorIndice(int indice) const {
    return clientes->getClientePorIndice(indice);
}

void Sucursal::reporteIMC() const {
    print("REPORTE DE IMC – SUCURSAL " + provincia + " – " + canton + "\n\n");

    // Contadores para cada categoría
    int contadores[8] = { 0 }; // 8 categorías de IMC

    // Arreglos para almacenar clientes por categoría
    const int MAX_CLIENTES_CAT = 50;
    cliente* categorias[8][MAX_CLIENTES_CAT];

    // Inicializar arreglos
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < MAX_CLIENTES_CAT; j++) {
            categorias[i][j] = nullptr;
        }
    }

    // Clasificar clientes según su última medición
    for (int i = 0; i < clientes->getCan(); i++) {
        cliente* cli = clientes->getClientePorIndice(i);
        if (cli && cli->getUltimaMedicion()) {
            double imc = cli->getUltimaMedicion()->getIMC();
            int categoria = 0;

            if (imc < 16.00) categoria = 0;
            else if (imc <= 16.99) categoria = 1;
            else if (imc <= 18.49) categoria = 2;
            else if (imc <= 24.99) categoria = 3;
            else if (imc <= 29.99) categoria = 4;
            else if (imc <= 34.99) categoria = 5;
            else if (imc <= 39.99) categoria = 6;
            else categoria = 7;

            if (contadores[categoria] < MAX_CLIENTES_CAT) {
                categorias[categoria][contadores[categoria]] = cli;
                contadores[categoria]++;
            }
        }
    }

    // Mostrar resultados
    string nombres[8] = {
        "Delgadez severa (<16.00)",
        "Delgadez moderada (16.00 - 16.99)",
        "Delgadez leve (17.00 - 18.49)",
        "Normal (18.50 - 24.99)",
        "Pre-obesidad (25.00 - 29.99)",
        "Obesidad leve (30.00 - 34.99)",
        "Obesidad media (35.00 - 39.99)",
        "Obesidad mórbida (?40.00)"
    };

    for (int i = 0; i < 8; i++) {
        print(nombres[i] + ":\n");
        if (contadores[i] == 0) {
            print("Ninguno\n\n");
        }
        else {
            print("(Cantidad " + to_string(contadores[i]) + ")\n");
            for (int j = 0; j < contadores[i]; j++) {
                cliente* cli = categorias[i][j];
                if (cli && cli->getUltimaMedicion()) {
                    print(to_string(j + 1) + "- " + cli->getCedula() + " " +
                        cli->getNombre() + " IMC: " +
                        to_string(cli->getUltimaMedicion()->getIMC()) + "\n");
                }
            }
            print("\n");
        }
    }
}

// Métodos para gestionar instructores
bool Sucursal::agregarInstructor(instructor* inst) {
    if (inst && !buscarInstructor(inst->getCedula())) {
        instructores->agregarInstructor(inst);
        return true;
    }
    return false;
}

instructor* Sucursal::buscarInstructor(const string& cedula) {
    return instructores->getInstructor(cedula);
}

void Sucursal::mostrarInstructores() const {
    if (instructores->getCan() == 0) {
        print("No hay instructores registrados en esta sucursal\n");
        print("3- Sin instructor por el momento\n");
        return;
    }

    for (int i = 0; i < instructores->getCan(); i++) {
        instructor* inst = instructores->getInstructorPorIndice(i);
        if (inst) {
            print(to_string(i + 1) + "- " + inst->getCedula() + " " + inst->getNombre() + "\n");
        }
    }
    print(to_string(instructores->getCan() + 1) + "- Sin instructor por el momento\n");
}

instructor* Sucursal::getInstructorPorIndice(int indice) const {
    return instructores->getInstructorPorIndice(indice);
}

// Métodos para gestionar clases grupales
bool Sucursal::agregarClaseGrupal(claseGrupal* clase) {
    if (clase) {
        return clasesGrupales->agregarClase(clase);
    }
    return false;
}

void Sucursal::mostrarClasesGrupales() const {
    clasesGrupales->mostrarTodas();
}

// Métodos de utilidad
string Sucursal::toString() const {
    stringstream s;
    s << "Código: " << codigo << "\n";
    s << "Provincia: " << provincia << "\n";
    s << "Cantón: " << canton << "\n";
    s << "Correo: " << correo << "\n";
    s << "Teléfono: " << telefono << "\n";
    return s.str();
}

void Sucursal::mostrarDetalle() const {
    print("========== DETALLE SUCURSAL ==========\n");
    print("Código: " + to_string(codigo) + "\n");
    print("Provincia: " + provincia + "\n");
    print("Cantón: " + canton + "\n");
    print("Correo: " + correo + "\n");
    print("Teléfono: " + telefono + "\n");
    print("Clientes registrados: " + to_string(clientes->getCan()) + "\n");
    print("Instructores registrados: " + to_string(instructores->getCan()) + "\n");
    print("Clases grupales disponibles: " + to_string(clasesGrupales->getCan()) + "\n");
}