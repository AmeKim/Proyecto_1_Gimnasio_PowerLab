#include "instructor.h"

instructor::instructor() {
    cedula = "";
    nombre = "";
    telefono = "";
    correo = "";
    fechaNacimiento = "";
    especialidades = new vecEspecialidades();
}

instructor::instructor(const string& cedula, const string& nombre, const string& telefono,
    const string& correo, const string& fechaNacimiento) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = fechaNacimiento;
    this->especialidades = new vecEspecialidades();
}

instructor::~instructor() {
    delete especialidades;
}

// Getters
string instructor::getCedula() const {
    return cedula;
}

string instructor::getNombre() const {
    return nombre;
}

string instructor::getTelefono() const {
    return telefono;
}

string instructor::getCorreo() const {
    return correo;
}

string instructor::getFechaNacimiento() const {
    return fechaNacimiento;
}

vecEspecialidades* instructor::getEspecialidades() const {
    return especialidades;
}

// Setters
void instructor::setCedula(const string& cedula) {
    this->cedula = cedula;
}

void instructor::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void instructor::setTelefono(const string& telefono) {
    this->telefono = telefono;
}

void instructor::setCorreo(const string& correo) {
    this->correo = correo;
}

void instructor::setFechaNacimiento(const string& fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}

// Métodos para especialidades
bool instructor::agregarEspecialidad(especialidad* esp) {
    if (esp != nullptr) {
        especialidades->agregarEspecialidad(esp);
        return true;
    }
    return false;
}

bool instructor::tieneEspecialidad(const string& nombreEspecialidad) const {
    return especialidades->buscarPorNombre(nombreEspecialidad) != nullptr;
}

bool instructor::tieneEspecialidad(int idEspecialidad) const {
    return especialidades->buscarPorId(idEspecialidad) != nullptr;
}

string instructor::getEspecialidadesString() const {
    stringstream s;
    for (int i = 0; i < especialidades->getCan(); i++) {
        // Accedemos a las especialidades de forma directa
        if (i > 0) s << ", ";
        // Aquí necesitaremos agregar un método para obtener especialidades por índice
    }
    return s.str();
}

void instructor::mostrarEspecialidades() const {
    cout << "Especialidades:" << endl;
    especialidades->mostrarTodas();
}

// Métodos de utilidad
void instructor::mostrar() const {
    cout << "=== DETALLE DEL INSTRUCTOR ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
    cout << "Fecha de nacimiento: " << fechaNacimiento << endl;
    cout << "Especialidades: " << getEspecialidadesString() << endl;
}

string instructor::toString() const {
    return cedula + " " + nombre;
}

string instructor::toStringCompleto() const {
    stringstream s;
    s << "Nombre: " << nombre << endl;
    s << "Cedula: " << cedula << endl;
    s << "Telefono: " << telefono << endl;
    s << "Correo: " << correo << endl;
    s << "Fecha de nacimiento: " << fechaNacimiento << endl;
    s << "Especialidades: " << getEspecialidadesString() << endl;
    return s.str();
}