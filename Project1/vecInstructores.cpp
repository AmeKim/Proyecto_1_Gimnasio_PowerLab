#include "vecInstructores.h"

vecInstructores::vecInstructores() {
    can = 0;
    vInstructores = new instructor * [tam];
    for (int i = 0; i < tam; i++) {
        vInstructores[i] = nullptr;
    }
}

vecInstructores::~vecInstructores() {
    for (int i = 0; i < can; i++) {
        delete vInstructores[i];
    }
    delete[] vInstructores;
}

void vecInstructores::agregarInstructor(instructor* inst) {
    if (can < tam && inst) {
        vInstructores[can] = inst;
        can++;
    }
    else {
        print("No se pueden agregar más instructores\n");
    }
}

void vecInstructores::eliminarInstructor(string cedula) {
    for (int i = 0; i < can; i++) {
        if (vInstructores[i]->getCedula() == cedula) {
            delete vInstructores[i];
            for (int j = i; j < can - 1; j++) {
                vInstructores[j] = vInstructores[j + 1];
            }
            vInstructores[can - 1] = nullptr;
            can--;
            print("Instructor eliminado\n");
            return;
        }
    }
    print("No se encontró el instructor\n");
}

instructor* vecInstructores::getInstructor(string cedula) {
    for (int i = 0; i < can; i++) {
        if (vInstructores[i] && vInstructores[i]->getCedula() == cedula) {
            return vInstructores[i];
        }
    }
    return nullptr;
}

instructor* vecInstructores::getInstructorPorIndice(int idx) {
    if (idx >= 0 && idx < can) {
        return vInstructores[idx];
    }
    return nullptr;
}

int vecInstructores::getCan() {
    return can;
}

string vecInstructores::toString() {
    stringstream s;
    for (int i = 0; i < can; i++) {
        if (vInstructores[i]) {
            s << vInstructores[i]->toString() << endl;
        }
    }
    return s.str();
}

string vecInstructores::toStringDetallado() {
    stringstream s;
    for (int i = 0; i < can; i++) {
        if (vInstructores[i]) {
            s << "Instructor: " << vInstructores[i]->getNombre() << endl;
            s << "Cédula: " << vInstructores[i]->getCedula() << endl;
            s << "Especialidades: " << vInstructores[i]->getEspecialidades()->toString() << endl;
            s << "------------------------" << endl;
        }
    }
    return s.str();
}

void vecInstructores::mostrarInstructoresPorEspecialidad(const string& especialidad) {
    bool encontrado = false;
    for (int i = 0; i < can; i++) {
        if (vInstructores[i] && vInstructores[i]->tieneEspecialidad(especialidad)) {
            cout << vInstructores[i]->getCedula() << " " << vInstructores[i]->getNombre() << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay instructores con esa especialidad" << endl;
    }
}

void vecInstructores::mostrarClientesPorInstructor(const string& cedulaInstructor) {
    // Esta funcionalidad requiere acceso a los clientes, se implementaría en la sucursal
    print("Funcionalidad pendiente de implementar\n");
}