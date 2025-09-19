#include "claseGrupal.h"
#include <iostream>

claseGrupal::claseGrupal(int codigo, especialidad* esp, int capacidadMax, string salon, string horario)
    : codigo(codigo), especialidadPtr(esp), capacidadMax(capacidadMax > 0 ? capacidadMax : 1), cantidadActual(0), salon(salon), horario(horario), instructorPtr(nullptr) {
    tipo = esp ? esp->getNombre() : "";
    clientes = new cliente*[this->capacidadMax];
    for (int i = 0; i < this->capacidadMax; ++i) {
        clientes[i] = nullptr;
    }
}

claseGrupal::~claseGrupal() {
    delete[] clientes;
}

bool claseGrupal::setInstructor(instructor* inst) {
    if (!inst || !especialidadPtr) return false;
    // Validar que el instructor tenga la especialidad
    if (inst->tieneEspecialidad(especialidadPtr->getNombre())) {
        instructorPtr = inst;
        return true;
    }
    return false;
}

bool claseGrupal::matricularCliente(cliente* cli) {
    if (!cli) return false;
    if (cantidadActual >= capacidadMax) return false;
    for (int i = 0; i < cantidadActual; ++i) {
        if (clientes[i] == cli) return false;
    }
    clientes[cantidadActual++] = cli;
    return true;
}

void claseGrupal::mostrarDetalle() const {
    std::cout << "\n=== DETALLE DE CLASE GRUPAL ===" << std::endl;
    std::cout << "Código: " << codigo << std::endl;
    if (especialidadPtr) {
        std::cout << "Especialidad: ";
        especialidadPtr->mostrar();
    }
    std::cout << "Salón: " << salon << std::endl;
    std::cout << "Horario: " << horario << std::endl;
    std::cout << "Capacidad máxima: " << capacidadMax << std::endl;
    std::cout << "Cantidad actual: " << cantidadActual << std::endl;
    if (instructorPtr) {
        std::cout << "Instructor: " << instructorPtr->getNombre() << std::endl;
    } else {
        std::cout << "Instructor: No asignado" << std::endl;
    }
    mostrarClientes();
}

void claseGrupal::mostrarClientes() const {
    std::cout << "\n--- CLIENTES MATRICULADOS ---" << std::endl;
    if (cantidadActual == 0) {
        std::cout << "No hay clientes inscritos." << std::endl;
        return;
    }
    for (int i = 0; i < cantidadActual; ++i) {
        if (clientes[i]) {
            std::cout << clientes[i]->getNombre() << " (" << clientes[i]->getCedula() << ")" << std::endl;
        }
    }
}

int claseGrupal::getCodigo() const { return codigo; }
string claseGrupal::getTipo() const { return tipo; }
int claseGrupal::getCapacidadMax() const { return capacidadMax; }
int claseGrupal::getCantidadActual() const { return cantidadActual; }
string claseGrupal::getSalon() const { return salon; }
string claseGrupal::getHorario() const { return horario; }
especialidad* claseGrupal::getEspecialidad() const { return especialidadPtr; }
instructor* claseGrupal::getInstructor() const { return instructorPtr; }
