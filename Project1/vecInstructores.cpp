#include "vecInstructores.h"

vecInstructores::vecInstructores(int capacidad) {
    tam = capacidad;
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

bool vecInstructores::agregarInstructor(instructor* inst) {
    if (can < tam && inst != nullptr) {
        vInstructores[can] = inst;
        can++;
        return true;
    }
    return false;
}

void vecInstructores::eliminarInstructor(const string& cedula) {
    for (int i = 0; i < can; i++) {
        if (vInstructores[i] && vInstructores[i]->getCedula() == cedula) {
            delete vInstructores[i];
            for (int j = i; j < can - 1; j++) {
                vInstructores[j] = vInstructores[j + 1];
            }
            vInstructores[can - 1] = nullptr;
            can--;
            return;
        }
    }
}

instructor* vecInstructores::buscarInstructor(const string& cedula) {
    for (int i = 0; i < can; i++) {
        if (vInstructores[i] && vInstructores[i]->getCedula() == cedula) {
            return vInstructores[i];
        }
    }
    return nullptr;
}

instructor* vecInstructores::getInstructor(const string& cedula) {
    return buscarInstructor(cedula);
}

int vecInstructores::getCan() const {
    return can;
}

int vecInstructores::getTam() const {
    return tam;
}

instructor* vecInstructores::getInstructorPorIndice(int indice) const {
    if (indice >= 0 && indice < can) {
        return vInstructores[indice];
    }
    return nullptr;
}

string vecInstructores::getInstructoresPorEspecialidad(const string& especialidad) const {
    stringstream s;
    bool encontrado = false;

    for (int i = 0; i < can; i++) {
        if (vInstructores[i] && vInstructores[i]->tieneEspecialidad(especialidad)) {
            s << vInstructores[i]->toString() << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        s << "No hay instructores con esa especialidad." << endl;
    }

    return s.str();
}

string vecInstructores::mostrarInstructoresPorEspecialidad(const string& especialidad) const {
    return getInstructoresPorEspecialidad(especialidad);
}

string vecInstructores::toString() const {
    stringstream s;
    for (int i = 0; i < can; i++) {
        if (vInstructores[i]) {
            s << (i + 1) << "- " << vInstructores[i]->toString() << endl;
        }
    }
    return s.str();
}

string vecInstructores::toStringEspecifico(const string& cedula) const {
    instructor* inst = buscarInstructor(cedula);
    if (inst) {
        return inst->toString();
    }
    return "Instructor no encontrado";
}

void vecInstructores::mostrarTodos() const {
    cout << toString();
}

void vecInstructores::mostrarInstructor(const string& cedula) const {
    instructor* inst = buscarInstructor(cedula);
    if (inst) {
        inst->mostrar();
    }
    else {
        cout << "Instructor no encontrado" << endl;
    }
}