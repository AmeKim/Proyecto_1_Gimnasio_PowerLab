#include "cliente.h"

cliente::cliente(string nombre, string cedula, int telefono, string correo, int dia, int mes, int anio,
                 char sexo, string fecha_Inscripcion, instructor* inst)
    : Persona(nombre, cedula, telefono, correo, dia, mes, anio) {
    this->sexo = sexo;
    this->fecha_Inscripcion = fecha_Inscripcion;
    this->inst = inst;
    this->r = r;
}

cliente::~cliente() {
    delete inst;
    delete r;
}

char cliente::getSexo() {
    return sexo;
}

string cliente::getFechaInscripcion() {
    return fecha_Inscripcion;
}

instructor* cliente::getInstructor() {
    return inst;
}

//rutina* cliente::getRutina() {
//return r;
//}

void cliente::setSexo(char sexo) {
    this->sexo = sexo;
}

void cliente::setFechaInscripcion(string fecha_Inscripcion) {
    this->fecha_Inscripcion = fecha_Inscripcion;
}

void cliente::setInstructor(instructor* inst) {
    this->inst = inst;
}

//void cliente::setRutina(rutina* r) {
//this->r = r;
//}

string cliente::toString() {
    stringstream s;
    s << "Nombre: " << getNombre() << endl;
    s << "Cedula: " << getCedula() << endl;
    s << "Telefono: " << getNumeroT() << endl;
    s << "Correo: " << getCorreo() << endl;
    s << "Fecha de Nacimiento: " << getDia() << "/" << getMes() << "/" << getAnnio() << endl;
    s << "Sexo: " << sexo << endl;
    s << "Fecha de Inscripcion: " << fecha_Inscripcion << endl;
    if (inst)
        s << "Instructor: " << inst->getNombre() << endl;
   //if (r)
    //s << "Rutina: " << r->toString() << endl;
    //return s.str();
}
