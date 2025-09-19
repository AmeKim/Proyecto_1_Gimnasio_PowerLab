#include "claseGrupal.h"

claseGrupal::claseGrupal() {
    codigo = 0;
    tipo = "";
    capacidad = 0;
    cantidadActual = 0;
    salon = "";
    horario = "";
    instructorAsignado = nullptr;
    clientesMatriculados = nullptr;
}

claseGrupal::claseGrupal(int codigo, string tipo, int capacidad, string salon, string horario, instructor* inst) {
    this->codigo = codigo;
    this->tipo = tipo;
    this->capacidad = capacidad;
    this->cantidadActual = 0;
    this->salon = salon;
    this->horario = horario;
    this->instructorAsignado = inst;

    // Inicializar array de clientes matriculados
    this->clientesMatriculados = new cliente * [capacidad];
    for (int i = 0; i < capacidad; i++) {
        clientesMatriculados[i] = nullptr;
    }
}

claseGrupal::~claseGrupal() {
    if (clientesMatriculados) {
        delete[] clientesMatriculados;
    }
}

// Getters
int claseGrupal::getCodigo() const { return codigo; }
string claseGrupal::getTipo() const { return tipo; }
int claseGrupal::getCapacidad() const { return capacidad; }
int claseGrupal::getCantidadActual() const { return cantidadActual; }
string claseGrupal::getSalon() const { return salon; }
string claseGrupal::getHorario() const { return horario; }
instructor* claseGrupal::getInstructor() const { return instructorAsignado; }
int claseGrupal::getCuposDisponibles() const { return capacidad - cantidadActual; }

// Setters
void claseGrupal::setCodigo(int codigo) { this->codigo = codigo; }
void claseGrupal::setTipo(const string& tipo) { this->tipo = tipo; }
void claseGrupal::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
    // Redimensionar array si es necesario
    if (clientesMatriculados) {
        delete[] clientesMatriculados;
    }
    clientesMatriculados = new cliente * [capacidad];
    for (int i = 0; i < capacidad; i++) {
        clientesMatriculados[i] = nullptr;
    }
}
void claseGrupal::setSalon(const string& salon) { this->salon = salon; }
void claseGrupal::setHorario(const string& horario) { this->horario = horario; }
void claseGrupal::setInstructor(instructor* inst) { this->instructorAsignado = inst; }

// Métodos para manejo de clientes
bool claseGrupal::matricularCliente(cliente* cli) {
    if (!cli || cantidadActual >= capacidad) {
        return false;
    }

    // Verificar si ya está matriculado
    if (tieneClienteMatriculado(cli)) {
        return false;
    }

    // Encontrar primera posición libre
    for (int i = 0; i < capacidad; i++) {
        if (clientesMatriculados[i] == nullptr) {
            clientesMatriculados[i] = cli;
            cantidadActual++;
            return true;
        }
    }

    return false;
}

bool claseGrupal::desmatricularCliente(cliente* cli) {
    if (!cli) return false;

    for (int i = 0; i < capacidad; i++) {
        if (clientesMatriculados[i] == cli) {
            clientesMatriculados[i] = nullptr;
            cantidadActual--;

            // Compactar array (opcional)
            for (int j = i; j < capacidad - 1; j++) {
                clientesMatriculados[j] = clientesMatriculados[j + 1];
            }
            clientesMatriculados[capacidad - 1] = nullptr;

            return true;
        }
    }

    return false;
}

bool claseGrupal::tieneClienteMatriculado(cliente* cli) const {
    if (!cli) return false;

    for (int i = 0; i < cantidadActual && i < capacidad; i++) {
        if (clientesMatriculados[i] == cli) {
            return true;
        }
    }

    return false;
}

cliente* claseGrupal::getClientePorIndice(int indice) const {
    if (indice >= 0 && indice < cantidadActual && indice < capacidad) {
        return clientesMatriculados[indice];
    }
    return nullptr;
}

string claseGrupal::toString() const {
    stringstream s;
    s << "Código: " << codigo << endl;
    s << "Tipo: " << tipo << endl;
    s << "Capacidad: " << capacidad << endl;
    s << "Matriculados: " << cantidadActual << endl;
    s << "Cupos disponibles: " << getCuposDisponibles() << endl;
    s << "Salón: " << salon << endl;
    s << "Horario: " << horario << endl;
    if (instructorAsignado) {
        s << "Instructor: " << instructorAsignado->getNombre() << endl;
    }
    return s.str();
}

string claseGrupal::getClientesMatriculadosStr() const {
    stringstream s;
    s << "Clientes matriculados:" << endl;
    for (int i = 0; i < cantidadActual && i < capacidad; i++) {
        if (clientesMatriculados[i]) {
            s << (i + 1) << ". " << clientesMatriculados[i]->getCedula()
                << " " << clientesMatriculados[i]->getNombre() << endl;
        }
    }
    return s.str();
}

void claseGrupal::mostrarDetalle() const {
    cout << toString();
    cout << getClientesMatriculadosStr();
}
