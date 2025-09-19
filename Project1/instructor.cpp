#include "instructor.h"

// Constructores
instructor::instructor(string nombre, string cedula, int telefono, string correo,
    int dia, int mes, int anio, vecEspecialidades* esp)
    : Persona(nombre, cedula, telefono, correo, dia, mes, anio), especialidades(esp) {
}

instructor::instructor(string nombre, string cedula, int telefono, string correo,
    const Fecha& fechaNac, vecEspecialidades* esp)
    : Persona(nombre, cedula, telefono, correo, fechaNac), especialidades(esp) {
}

instructor::instructor(string nombre, string cedula, int telefono, string correo,
    const string& fechaNacStr, vecEspecialidades* esp)
    : Persona(nombre, cedula, telefono, correo, fechaNacStr), especialidades(esp) {
}

instructor::~instructor() {
    delete especialidades;
}

// Getters
vecEspecialidades* instructor::getEspecialidades() const {
    return especialidades;
}

// Setters
void instructor::setEspecialidades(vecEspecialidades* esp) {
    if (especialidades) {
        delete especialidades; // Liberar memoria anterior
    }
    this->especialidades = esp;
}

// Utility methods
string instructor::toString() {
    stringstream s;
    s << "=== INFORMACIÓN DEL INSTRUCTOR ===" << endl;
    s << "Cedula: " << getCedula() << endl;
    s << "Nombre: " << getNombre() << endl;
    s << "Correo: " << getCorreo() << endl;
    s << "Telefono: " << getNumeroT() << endl;
    s << "Fecha de Nacimiento: " << getFechaNacimiento().toString() << endl;

    if (getFechaNacimiento().esFechaInicializada() && getFechaNacimiento().esFechaValida()) {
        s << "Edad: " << getEdad() << " años" << endl;
    }

    s << "Especialidades (" << getCantidadEspecialidades() << "):" << endl;
    if (especialidades && especialidades->getCan() > 0) {
        s << especialidades->toString();
    }
    else {
        s << "  - Sin especialidades asignadas" << endl;
    }
    s << "=================================" << endl;
    return s.str();
}

bool instructor::tieneEspecialidad(const string& nombreEsp) const {
    if (!especialidades) {
        return false;
    }

    for (int i = 0; i < especialidades->getCan(); i++) {
        // Este método necesitaría ser implementado en vecEspecialidades
        // para acceder a especialidades por índice
        // Por ahora, usamos el método existente
        if (especialidades->getEspecialidad(nombreEsp) != nullptr) {
            return true;
        }
    }
    return false;
}

int instructor::getCantidadEspecialidades() const {
    if (!especialidades) {
        return 0;
    }
    return especialidades->getCan();
}