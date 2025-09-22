#include "cliente.h"

cliente::cliente() {
    nombre = "";
    cedula = "";
    telefono = "";
    correo = "";
    fechaNacimiento = "";
    sexo = "";
    fechaInscripcion = "";
    cedulaInstructor = "";
    maxMediciones = 10;
    canMediciones = 0;
    mediciones = new reporteM * [maxMediciones];
    for (int i = 0; i < maxMediciones; i++) {
        mediciones[i] = nullptr;
    }
    rutinaActual = nullptr;
}

cliente::cliente(const string& nombre, const string& cedula, const string& telefono,
    const string& correo, const string& fechaNacimiento,
    const string& sexo, const string& fechaInscripcion) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = fechaNacimiento;
    this->sexo = sexo;
    this->fechaInscripcion = fechaInscripcion;
    this->cedulaInstructor = "";
    this->maxMediciones = 10;
    this->canMediciones = 0;
    this->mediciones = new reporteM * [maxMediciones];
    for (int i = 0; i < maxMediciones; i++) {
        mediciones[i] = nullptr;
    }
    this->rutinaActual = nullptr;
}

cliente::~cliente() {
    for (int i = 0; i < canMediciones; i++) {
        delete mediciones[i];
    }
    delete[] mediciones;
    delete rutinaActual;
}

// Getters
string cliente::getNombre() const {
    return nombre;
}

string cliente::getCedula() const {
    return cedula;
}

string cliente::getTelefono() const {
    return telefono;
}

string cliente::getCorreo() const {
    return correo;
}

string cliente::getFechaNacimiento() const {
    return fechaNacimiento;
}

string cliente::getSexo() const {
    return sexo;
}

string cliente::getFechaInscripcion() const {
    return fechaInscripcion;
}

string cliente::getCedulaInstructor() const {
    return cedulaInstructor;
}

int cliente::getCanMediciones() const {
    return canMediciones;
}

Rutina* cliente::getRutinaActual() const {
    return rutinaActual;
}

// Setters
void cliente::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void cliente::setCedula(const string& cedula) {
    this->cedula = cedula;
}

void cliente::setTelefono(const string& telefono) {
    this->telefono = telefono;
}

void cliente::setCorreo(const string& correo) {
    this->correo = correo;
}

void cliente::setFechaNacimiento(const string& fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}

void cliente::setSexo(const string& sexo) {
    this->sexo = sexo;
}

void cliente::setFechaInscripcion(const string& fechaInscripcion) {
    this->fechaInscripcion = fechaInscripcion;
}

void cliente::setCedulaInstructor(const string& cedula) {
    this->cedulaInstructor = cedula;
}

// Métodos para mediciones
bool cliente::agregarMedicion(reporteM* medicion) {
    if (canMediciones < maxMediciones && medicion != nullptr) {
        mediciones[canMediciones] = medicion;
        canMediciones++;
        return true;
    }
    return false;
}

reporteM* cliente::getMedicion(int indice) const {
    if (indice >= 0 && indice < canMediciones) {
        return mediciones[indice];
    }
    return nullptr;
}

string cliente::historialMediciones() const {
    stringstream s;
    s << "HISTORIAL DE MEDICIONES" << endl;
    for (int i = 0; i < canMediciones; i++) {
        s << (i + 1) << "- ";
        if (mediciones[i]) {
            s << mediciones[i]->toStringResumido() << endl;
        }
    }
    return s.str();
}

void cliente::mostrarHistorialMediciones() const {
    cout << historialMediciones();
}

// Métodos para rutina
void cliente::asignarRutina(Rutina* rutina) {
    delete rutinaActual;
    rutinaActual = rutina;
}

void cliente::eliminarRutina() {
    delete rutinaActual;
    rutinaActual = nullptr;
}

// Métodos de utilidad
void cliente::mostrar() const {
    cout << "=== DETALLE DE CLIENTE ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
    cout << "Fecha de nacimiento: " << fechaNacimiento << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Fecha de inscripcion: " << fechaInscripcion << endl;
    cout << "Instructor asignado: " << (cedulaInstructor.empty() ? "Sin asignar" : cedulaInstructor) << endl;
    cout << "Mediciones registradas: " << canMediciones << "/" << maxMediciones << endl;
    cout << "Rutina actual: " << (rutinaActual ? "Asignada" : "No asignada") << endl;
}

string cliente::toString() const {
    return cedula + " " + nombre;
}

string cliente::toStringCompleto() const {
    stringstream s;
    s << "Nombre: " << nombre << endl;
    s << "Cedula: " << cedula << endl;
    s << "Telefono: " << telefono << endl;
    s << "Correo: " << correo << endl;
    s << "Fecha de nacimiento: " << fechaNacimiento << endl;
    s << "Sexo: " << sexo << endl;
    s << "Fecha de inscripcion: " << fechaInscripcion << endl;
    s << "Instructor: " << (cedulaInstructor.empty() ? "Sin asignar" : cedulaInstructor) << endl;
    return s.str();
}