#include "claseGrupal.h"

claseGrupal::claseGrupal() {
    codigo = 0;
    tipoClase = "";
    capacidadMaxima = 20;
    salon = "";
    horario = "";
    cedulaInstructor = "";
    cantidadMatriculados = 0;
    clientesMatriculados = new cliente * [capacidadMaxima];
    for (int i = 0; i < capacidadMaxima; i++) {
        clientesMatriculados[i] = nullptr;
    }
}

claseGrupal::claseGrupal(int codigo, const string& tipoClase, int capacidadMaxima,
    const string& salon, const string& horario, const string& cedulaInstructor) {
    this->codigo = codigo;
    this->tipoClase = tipoClase;
    this->capacidadMaxima = capacidadMaxima;
    this->salon = salon;
    this->horario = horario;
    this->cedulaInstructor = cedulaInstructor;
    this->cantidadMatriculados = 0;
    this->clientesMatriculados = new cliente * [capacidadMaxima];
    for (int i = 0; i < capacidadMaxima; i++) {
        clientesMatriculados[i] = nullptr;
    }
}

claseGrupal::~claseGrupal() {
    delete[] clientesMatriculados;
}

// Getters
int claseGrupal::getCodigo() const {
    return codigo;
}

string claseGrupal::getTipoClase() const {
    return tipoClase;
}

int claseGrupal::getCapacidadMaxima() const {
    return capacidadMaxima;
}

string claseGrupal::getSalon() const {
    return salon;
}

string claseGrupal::getHorario() const {
    return horario;
}

string claseGrupal::getCedulaInstructor() const {
    return cedulaInstructor;
}

int claseGrupal::getCantidadMatriculados() const {
    return cantidadMatriculados;
}

int claseGrupal::getCuposDisponibles() const {
    return capacidadMaxima - cantidadMatriculados;
}

// Setters
void claseGrupal::setCodigo(int codigo) {
    this->codigo = codigo;
}

void claseGrupal::setTipoClase(const string& tipoClase) {
    this->tipoClase = tipoClase;
}

void claseGrupal::setCapacidadMaxima(int capacidad) {
    this->capacidadMaxima = capacidad;
}

void claseGrupal::setSalon(const string& salon) {
    this->salon = salon;
}

void claseGrupal::setHorario(const string& horario) {
    this->horario = horario;
}

void claseGrupal::setCedulaInstructor(const string& cedula) {
    this->cedulaInstructor = cedula;
}

// Métodos para gestionar clientes
bool claseGrupal::matricularCliente(cliente* cli) {
    if (cantidadMatriculados < capacidadMaxima && cli != nullptr) {
        // Verificar que no esté ya matriculado
        if (!estaMatriculado(cli->getCedula())) {
            clientesMatriculados[cantidadMatriculados] = cli;
            cantidadMatriculados++;
            return true;
        }
    }
    return false;
}

bool claseGrupal::desmatricularCliente(const string& cedula) {
    for (int i = 0; i < cantidadMatriculados; i++) {
        if (clientesMatriculados[i] && clientesMatriculados[i]->getCedula() == cedula) {
            // Mover todos los elementos hacia atrás
            for (int j = i; j < cantidadMatriculados - 1; j++) {
                clientesMatriculados[j] = clientesMatriculados[j + 1];
            }
            clientesMatriculados[cantidadMatriculados - 1] = nullptr;
            cantidadMatriculados--;
            return true;
        }
    }
    return false;
}

bool claseGrupal::estaMatriculado(const string& cedula) const {
    for (int i = 0; i < cantidadMatriculados; i++) {
        if (clientesMatriculados[i] && clientesMatriculados[i]->getCedula() == cedula) {
            return true;
        }
    }
    return false;
}

void claseGrupal::mostrarClientesMatriculados() const {
    cout << "Lista de clientes matriculados en la clase:" << endl;
    for (int i = 0; i < cantidadMatriculados; i++) {
        if (clientesMatriculados[i]) {
            cout << clientesMatriculados[i]->toString() << endl;
        }
    }
}

string claseGrupal::getClientesMatriculados() const {
    stringstream s;
    for (int i = 0; i < cantidadMatriculados; i++) {
        if (clientesMatriculados[i]) {
            s << clientesMatriculados[i]->toString() << endl;
        }
    }
    return s.str();
}

// Métodos de utilidad
void claseGrupal::mostrar() const {
    cout << "=== DETALLE DE CLASE GRUPAL ===" << endl;
    cout << "Código: " << codigo << endl;
    cout << "Clase: " << tipoClase << endl;
    cout << "Capacidad: " << capacidadMaxima << endl;
    cout << "Matriculados: " << cantidadMatriculados << endl;
    cout << "Cupos disponibles: " << getCuposDisponibles() << endl;
    cout << "Salón: " << salon << endl;
    cout << "Horario: " << horario << endl;
    cout << "Instructor: " << cedulaInstructor << endl;
}

string claseGrupal::toString() const {
    return to_string(codigo) + ". " + tipoClase;
}

string claseGrupal::toStringCompleto() const {
    stringstream s;
    s << "Clase: " << tipoClase << endl;
    s << "Capacidad: " << capacidadMaxima << endl;
    s << "Matriculados: " << cantidadMatriculados << endl;
    s << "Cupos disponibles: " << getCuposDisponibles() << endl;
    s << "Salón: " << salon << endl;
    s << "Horario: " << horario << endl;
    return s.str();
}

bool claseGrupal::tieneCupo() const {
    return cantidadMatriculados < capacidadMaxima;
}
