#include "instructor.h"

instructor::instructor(): Persona(), especialidades(8), telefono(), correo(), fechaNacimiento() {
}

instructor::instructor(int cedula, const string& nombre, const string& telefono,const string& correo, const fecha& fechaNac): Persona(nombre, to_string(cedula), telefono, correo, fechaNac.getDia(), fechaNac.getMes(), fechaNac.getAnio()),especialidades(8), telefono(telefono), correo(correo), fechaNacimiento(fechaNac) {
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
    return especialidades.tamanio();
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
    string resultado = "Instructor: " + nombre + "\n";
    resultado += "C" + string(130, 100) + "dula: " + cedula + "\n";
    resultado += "Tel" + string(130, 102) + "fono: " + telefono + "\n";
    resultado += "Correo: " + correo + "\n";
    resultado += "Fecha de Nacimiento: " + fechaNacimiento.toString() + "\n";
    resultado += "Edad: " + to_string(getEdad()) + " a" + string(164, 241) + "os\n";
    resultado += "Especialidades: ";
    if (especialidades.tamanio() == 0) {
        resultado += "Ninguna\n";
    } else {
        for (int i = 0; i < especialidades.tamanio(); ++i) {
            resultado += especialidades.obtener(i).getNombre();
            if (i < especialidades.tamanio() - 1) {
                resultado += ", ";
            }
        }
        resultado += "\n";
    }
	return resultado;
}
