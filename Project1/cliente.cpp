#include "cliente.h"

// Constructores
cliente::cliente(string nombre, string cedula, int telefono, string correo, int dia, int mes, int anio,
    char sexo, const Fecha& fechaIns, instructor* inst)
    : Persona(nombre, cedula, telefono, correo, dia, mes, anio), sexo(sexo), fechaInscripcion(fechaIns), inst(inst) {
}

cliente::cliente(string nombre, string cedula, int telefono, string correo, const Fecha& fechaNac,
    char sexo, const Fecha& fechaIns, instructor* inst)
    : Persona(nombre, cedula, telefono, correo, fechaNac), sexo(sexo), fechaInscripcion(fechaIns), inst(inst) {
}

cliente::cliente(string nombre, string cedula, int telefono, string correo, const string& fechaNacStr,
    char sexo, const string& fechaInsStr, instructor* inst)
    : Persona(nombre, cedula, telefono, correo, fechaNacStr), sexo(sexo), fechaInscripcion(fechaInsStr), inst(inst) {
}

cliente::~cliente() {
    // Note: Don't delete inst here as it's managed elsewhere
    // delete inst; // Commented out to avoid double deletion
    // delete r; // Commented out until rutina class is implemented
}

// Getters
char cliente::getSexo() const {
    return sexo;
}

Fecha cliente::getFechaInscripcion() const {
    return fechaInscripcion;
}

instructor* cliente::getInstructor() const {
    return inst;
}

//rutina* cliente::getRutina() {
//    return r;
//}

// Setters
void cliente::setSexo(char sexo) {
    this->sexo = sexo;
}

void cliente::setFechaInscripcion(const Fecha& fecha) {
    this->fechaInscripcion = fecha;
}

void cliente::setFechaInscripcion(const string& fechaStr) {
    fechaInscripcion.parsearFecha(fechaStr);
}

void cliente::setInstructor(instructor* inst) {
    this->inst = inst;
}

//void cliente::setRutina(rutina* r) {
//    this->r = r;
//}

// Utility methods
string cliente::toString() {
    stringstream s;
    s << "=== INFORMACIÓN DEL CLIENTE ===" << endl;
    s << "Nombre: " << getNombre() << endl;
    s << "Cedula: " << getCedula() << endl;
    s << "Telefono: " << getNumeroT() << endl;
    s << "Correo: " << getCorreo() << endl;
    s << "Fecha de Nacimiento: " << getFechaNacimiento().toString() << endl;

    if (getFechaNacimiento().esFechaInicializada() && getFechaNacimiento().esFechaValida()) {
        s << "Edad: " << getEdad() << " años" << endl;
    }

    s << "Sexo: " << sexo << endl;
    s << "Fecha de Inscripcion: " << fechaInscripcion.toString() << endl;

    if (fechaInscripcion.esFechaInicializada() && fechaInscripcion.esFechaValida()) {
        s << "Antiguedad: " << getAntiguedad() << " años" << endl;
    }

    if (inst) {
        s << "Instructor: " << inst->getNombre() << " (Ced: " << inst->getCedula() << ")" << endl;
    }
    else {
        s << "Instructor: No asignado" << endl;
    }

    //if (r)
    //    s << "Rutina: " << r->toString() << endl;
    s << "===============================" << endl;
    return s.str();
}

int cliente::getAntiguedad() const {
    if (!fechaInscripcion.esFechaInicializada() || !fechaInscripcion.esFechaValida()) {
        return -1; // Indica error
    }
    return fechaInscripcion.calcularEdad(Fecha::fechaActual());
}
