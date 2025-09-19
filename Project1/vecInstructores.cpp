#include "vecInstructores.h"

vecInstructores::vecInstructores() {
    this->can = 0;
    this->vInstructores = new instructor * [tam];
    for (int i = 0; i < tam; i++) {
        vInstructores[i] = nullptr;
    }
}

vecInstructores::~vecInstructores() {
    for (int i = 0; i < can; i++) {
        if (vInstructores[i]) {
            delete vInstructores[i];
        }
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
        if (vInstructores[i] && vInstructores[i]->getCedula() == cedula) {
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

instructor* vecInstructores::getInstructor(const string& cedula) {
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

int vecInstructores::getCan() const {
    return can;
}

string vecInstructores::toString() const {
    stringstream s;
    for (int i = 0; i < can; i++) {
        if (vInstructores[i]) {
            s << vInstructores[i]->toString() << endl;
        }
    }
    return s.str();
}

string vecInstructores::toStringEspecifico(string cedula) const {
    for (int i = 0; i < can; i++) {
        if (vInstructores[i] && vInstructores[i]->getCedula() == cedula) {
            return vInstructores[i]->toString();
        }
    }
    return "No se encontró el instructor\n";
}

string vecInstructores::getInstructoresPorEspecialidad(const string& especialidad) const {
    stringstream s;
    for (int i = 0; i < can; i++) {
        if (vInstructores[i] && vInstructores[i]->tieneEspecialidad(especialidad)) {
            s << vInstructores[i]->getCedula() << " " << vInstructores[i]->getNombre() << endl;
        }
    }
    return s.str();
}