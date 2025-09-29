#include "ClaseGrupal.h"
#include "instructor.h"
#include "cliente.h"

ClaseGrupal::ClaseGrupal() : codigo(0), tipo(""), capacidad(0), salon(""),
horario(""), instructorAsignado(nullptr), tamClientes(50), cantMatriculados(0) {
    clientesMatriculados = new cliente * [tamClientes];
    for (int i = 0; i < tamClientes; i++) {
        clientesMatriculados[i] = nullptr;
    }
}

ClaseGrupal::ClaseGrupal(int cod, const string& tip, int cap, const string& sal,
    const string& hor, instructor* ins)
    : codigo(cod), tipo(tip), capacidad(cap), salon(sal), horario(hor),
    instructorAsignado(ins), tamClientes(50), cantMatriculados(0) {
    clientesMatriculados = new cliente * [tamClientes];
    for (int i = 0; i < tamClientes; i++) {
        clientesMatriculados[i] = nullptr;
    }
}

ClaseGrupal::~ClaseGrupal() {
    if (clientesMatriculados) {
        delete[] clientesMatriculados;
        clientesMatriculados = nullptr;
    }
}

int ClaseGrupal::getCodigo() const { return codigo; }
string ClaseGrupal::getTipo() const { return tipo; }
int ClaseGrupal::getCapacidad() const { return capacidad; }
string ClaseGrupal::getSalon() const { return salon; }
string ClaseGrupal::getHorario() const { return horario; }
instructor* ClaseGrupal::getInstructor() const { return instructorAsignado; }
int ClaseGrupal::getCantidadMatriculados() const { return cantMatriculados; }

int ClaseGrupal::getCuposDisponibles() const {
    return capacidad - cantMatriculados;
}

bool ClaseGrupal::matricularCliente(cliente* cli) {
    if (!cli || cantMatriculados >= capacidad) return false;

    for (int i = 0; i < cantMatriculados; i++) {
        if (clientesMatriculados[i] == cli) return false;
    }

    clientesMatriculados[cantMatriculados++] = cli;
    cli->matricularClase(this);
    return true;
}

string ClaseGrupal::listarClientesMatriculados() const {
    if (cantMatriculados == 0) {
        return "No hay clientes matriculados en esta clase.\n";
    }

    stringstream ss;
    for (int i = 0; i < cantMatriculados; i++) {
        if (clientesMatriculados[i]) {
            ss << clientesMatriculados[i]->getCedula() << " "
                << clientesMatriculados[i]->getNombreCompleto() << "\n";
        }
    }
    return ss.str();
}

string ClaseGrupal::toString() const {
    stringstream ss;
    ss << "Clase: " << tipo << "\n";
    ss << "Capacidad: " << capacidad << "\n";
    ss << "Matriculados: " << cantMatriculados << "\n";
    ss << "Cupos disponibles: " << getCuposDisponibles() << "\n";
    ss << "Salon: " << salon << "\n";
    ss << "Horario: " << horario << "\n";

    if (instructorAsignado) {
        ss << "Instructor asignado: " << instructorAsignado->getNombre() << "\n";
    }
    else {
		ss << "Instructor asignado: Ninguno\n";
    }

    ss << "\nLista de clientes matriculados en la clase:\n";
    ss << listarClientesMatriculados();

    return ss.str();
}