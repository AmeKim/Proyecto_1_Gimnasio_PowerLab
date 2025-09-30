#include "instructor.h"

instructor::instructor(): Persona(), especialidades(8), telefono(), correo(), fechaNacimiento() {
}

instructor::instructor(const string& cedula, const string& nombre, const string& telefono,const string& correo, const fecha& fechaNac): Persona(nombre, cedula, telefono, correo, fechaNac.getDia(), fechaNac.getMes(), fechaNac.getAnio()),especialidades(8), telefono(telefono), correo(correo), fechaNacimiento(fechaNac) {
}

instructor::instructor(const instructor& other): Persona(other),especialidades(other.especialidades),telefono(other.telefono),correo(other.correo),fechaNacimiento(other.fechaNacimiento) {
}

instructor& instructor::operator=(const instructor& other) {
    if (this == &other) return *this;
    Persona::operator=(other);
    especialidades = other.especialidades;
    telefono = other.telefono;
    correo = other.correo;
    fechaNacimiento = other.fechaNacimiento;
    return *this;
}

instructor::~instructor() {
    // VecEspecialidades gestionará su propia memoria en su destructor
}

void instructor::agregarEspecialidad(const Especialidad& esp) {
    especialidades.agregar(esp);
}

int instructor::obtenerCantidadEspecialidades() const {
    return especialidades.getCantidad();
}

const Especialidad& instructor::obtenerEspecialidad(int indice) const {
    return especialidades.obtener(indice);
}

void instructor::limpiarEspecialidades() {
    especialidades.limpiar();
}

void instructor::setTelefono(const string& t) { telefono = t; }
void instructor::setCorreo(const string& c) { correo = c; }
void instructor::setFechaNacimiento(const fecha& f) { fechaNacimiento = f; }

string instructor::getTelefono() const { return telefono; }
string instructor::getCorreo() const { return correo; }
fecha instructor::getFechaNacimiento() const { return fechaNacimiento; }

string instructor::toString() const {
    stringstream s;
    s << "Instructor: " << nombre << "\n";
    s << "C" << char(130) << "dula: " << cedula << "\n";
    s << "Telefono: " << telefono << "\n";
    s << "Correo: " << correo << "\n";
    s << "Fecha de Nacimiento: " << fechaNacimiento.toString() << "\n";
    s << "Especialidades: ";
    int tam = especialidades.getCantidad();

    if (tam == 0) {
        s << "Ninguna";
    }
    else {
        for (int i = 0; i < tam; i++) {
            s << especialidades.obtener(i).getNombre();
            if (i < tam - 1) {
                s << ", ";
            }
        }
    }
    s << "\n";

    return s.str();
}
