#include "instructor.h"

instructor::instructor(string nombre, string cedula, int telefono, string correo,
                       int dia, int mes, int anio, vecEspecialidades* v)
    : Persona(nombre, cedula, telefono, correo, dia, mes, anio) {
    this->v = v;
}

instructor::~instructor() {
    delete v;
}

vecEspecialidades* instructor::getEspecialidades() {
    return v;
}

string instructor::toString() {
    stringstream s;
    s << "Cedula: " << getCedula() << endl;
    s << "Nombre: " << getNombre() << endl;
    s << "Correo: " << getCorreo() << endl;
    s << "Telefono: " << getNumeroT() << endl;
    s << "Fecha de Nacimiento: " << getDia() << "/" << getMes() << "/" << getAnnio() << endl;
    s << "Especialidades: " << endl;
    s << v->toString() << endl;
    return s.str();
}

