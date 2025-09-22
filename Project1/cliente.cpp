#include "cliente.h"

// Constructores
cliente::cliente() : Persona() {
    fechaInscripcion = "";
    sexo = "";
    cedulaInstructorAsignado = "";
    canMediciones = 0;
    tamMediciones = 10; // Máximo 10 mediciones según especificaciones
    mediciones = new reporteM * [tamMediciones];
    for (int i = 0; i < tamMediciones; i++) {
        mediciones[i] = nullptr;
    }
}

cliente::cliente(const string& nombre, const string& cedula, const string& telefono,
    const string& correo, const string& fechaNacimiento, const string& sexo,
    const string& fechaInscripcion)
    : Persona(nombre, cedula, telefono, correo, fechaNacimiento) {
    this->fechaInscripcion = fechaInscripcion;
    this->sexo = sexo;
    this->cedulaInstructorAsignado = "";
    this->canMediciones = 0;
    this->tamMediciones = 10; // Máximo 10 mediciones según especificaciones
    this->mediciones = new reporteM * [tamMediciones];
    for (int i = 0; i < tamMediciones; i++) {
        mediciones[i] = nullptr;
    }
}

cliente::~cliente() {
    for (int i = 0; i < canMediciones; i++) {
        delete mediciones[i];
    }
    delete[] mediciones;
}

// Getters
string cliente::getFechaInscripcion() const { return fechaInscripcion; }
string cliente::getSexo() const { return sexo; }

char cliente::getSexoChar() const {
    // Convertir string a char usando switch
    switch (sexo.length()) {
    case 0:
        return 'M'; // Default
    default:
        char primerChar = sexo[0];
        switch (primerChar) {
        case 'M':
        case 'm':
            return 'M';
        case 'F':
        case 'f':
            return 'F';
        default:
            return 'M'; // Default
        }
    }
}

string cliente::getCedulaInstructorAsignado() const { return cedulaInstructorAsignado; }
int cliente::getCanMediciones() const { return canMediciones; }
int cliente::getTamMediciones() const { return tamMediciones; }

reporteM* cliente::getMedicion(int indice) const {
    switch (indice >= 0 && indice < canMediciones) {
    case true:
        return mediciones[indice];
    case false:
        return nullptr;
    }
}

// Setters
void cliente::setFechaInscripcion(const string& fechaInscripcion) {
    this->fechaInscripcion = fechaInscripcion;
}

void cliente::setSexo(const string& sexo) {
    this->sexo = sexo;
}

void cliente::setCedulaInstructorAsignado(const string& cedulaInstructor) {
    this->cedulaInstructorAsignado = cedulaInstructor;
}

// Métodos para mediciones
bool cliente::agregarMedicion(reporteM* medicion) {
    switch (canMediciones < tamMediciones && medicion != nullptr) {
    case true:
        mediciones[canMediciones] = medicion;
        canMediciones++;
        return true;
    case false:
        return false;
    }
}

reporteM* cliente::getMedicionMasReciente() const {
    switch (canMediciones > 0) {
    case true:
        return mediciones[canMediciones - 1];
    case false:
        return nullptr;
    }
}

void cliente::mostrarHistorialMediciones() const {
    cout << "HISTORIAL DE MEDICIONES" << endl;
    switch (canMediciones) {
    case 0:
        cout << "No hay mediciones registradas." << endl;
        break;
    default:
        for (int i = 0; i < canMediciones; i++) {
            cout << (i + 1) << "- " << mediciones[i]->toString() << endl;
        }
        break;
    }
}

// Métodos de visualización
string cliente::toString() const {
    stringstream s;
    s << getCedula() << " " << getNombre();
    return s.str();
}

string cliente::toStringResumido() const {
    stringstream s;
    s << "Nombre: " << getNombre() << endl;
    s << "Cedula: " << getCedula() << endl;
    s << "Teléfono: " << getTelefono() << endl;
    s << "Correo: " << getCorreo() << endl;
    s << "Fecha de nacimiento: " << getFechaNacimiento() << endl;
    s << "Fecha de Inscripción: " << fechaInscripcion << endl;
    s << "Sexo: " << sexo << endl;
    return s.str();
}

string cliente::toStringDetallado() const {
    stringstream s;
    s << toStringResumido();
    switch (cedulaInstructorAsignado.empty()) {
    case true:
        s << "Instructor: Sin asignar" << endl;
        break;
    case false:
        s << "Instructor asignado: " << cedulaInstructorAsignado << endl;
        break;
    }
    s << "Mediciones registradas: " << canMediciones << endl;
    return s.str();
}

void cliente::mostrar() const {
    cout << toStringDetallado();
}