#include "cliente.h"
#include "Medicion.h"

cliente::cliente() : Persona() {
    fechaInscripcion = nullptr;
    sexo = 'm';
    instructorAsignado = nullptr;
    canMediciones = 0;
    tamMediciones = 10; // Máximo 10 mediciones según especificación del PDF
    mediciones = new void* [tamMediciones];
    for (int i = 0; i < tamMediciones; i++) {
        mediciones[i] = nullptr;
    }
    rutinaActual = nullptr;
}

cliente::cliente(const string& cedula, const string& nombre, const string& telefono,
    const string& correo, fecha* fechaNac, fecha* fechaInsc, char sexo)
    : Persona(cedula, nombre, telefono, correo, fechaNac) {
    this->fechaInscripcion = fechaInsc;
    this->sexo = sexo;
    this->instructorAsignado = nullptr;
    this->canMediciones = 0;
    this->tamMediciones = 10;
    this->mediciones = new void* [tamMediciones];
    for (int i = 0; i < tamMediciones; i++) {
        mediciones[i] = nullptr;
    }
    this->rutinaActual = nullptr;
}

cliente::~cliente() {
    if (fechaInscripcion) {
        delete fechaInscripcion;
    }

    // Eliminar mediciones
    for (int i = 0; i < canMediciones; i++) {
        if (mediciones[i]) {
            delete static_cast<Medicion*>(mediciones[i]);
        }
    }
    delete[] mediciones;

    // Eliminar rutina actual (si usas la clase Rutina)
    if (rutinaActual) {
        // delete static_cast<Rutina*>(rutinaActual);
        // Comentado por ahora hasta que definas si usar Rutina
    }

    // No eliminamos instructorAsignado porque es solo una referencia
}

// Getters
fecha* cliente::getFechaInscripcion() const {
    return fechaInscripcion;
}

char cliente::getSexo() const {
    return sexo;
}

void* cliente::getInstructorAsignado() const {
    return instructorAsignado;
}

int cliente::getCanMediciones() const {
    return canMediciones;
}

void* cliente::getRutinaActual() const {
    return rutinaActual;
}

void* cliente::getMedicion(int indice) const {
    if (indice >= 0 && indice < canMediciones) {
        return mediciones[indice];
    }
    return nullptr;
}

// Setters
void cliente::setFechaInscripcion(fecha* fechaInsc) {
    if (fechaInscripcion) {
        delete fechaInscripcion;
    }
    this->fechaInscripcion = fechaInsc;
}

void cliente::setSexo(char sexo) {
    this->sexo = sexo;
}

void cliente::setInstructorAsignado(void* inst) {
    this->instructorAsignado = inst;
}

void cliente::setRutinaActual(void* rutina) {
    if (rutinaActual) {
        // delete static_cast<Rutina*>(rutinaActual);
        // Comentado por ahora
    }
    this->rutinaActual = rutina;
}

// Métodos para mediciones
bool cliente::agregarMedicion(void* medicion) {
    if (canMediciones < tamMediciones && medicion != nullptr) {
        mediciones[canMediciones] = medicion;
        canMediciones++;
        return true;
    }
    return false; // No se puede agregar más mediciones (máximo 10)
}

void cliente::mostrarHistorialMediciones() const {
    cout << "HISTORIAL DE MEDICIONES" << endl;
    cout << getCedula() << " " << getNombre() << endl;
    cout << endl;

    if (canMediciones == 0) {
        cout << "No hay mediciones registradas." << endl;
        return;
    }

    for (int i = 0; i < canMediciones; i++) {
        if (mediciones[i]) {
            Medicion* med = static_cast<Medicion*>(mediciones[i]);
            cout << (i + 1) << "- Fecha: " << med->getFecha()->toString()
                << " | Peso: " << med->getPeso() << " kg"
                << " | IMC: " << med->getIMC() << endl;
        }
    }
}

void* cliente::getUltimaMedicion() const {
    if (canMediciones > 0) {
        return mediciones[canMediciones - 1];
    }
    return nullptr;
}

// Métodos heredados y propios
string cliente::toString() const {
    stringstream s;
    s << getCedula() << " " << getNombre();
    return s.str();
}

void cliente::mostrar() const {
    cout << toStringDetallado();
}

string cliente::toStringDetallado() const {
    stringstream s;
    s << "Detalle de cliente:" << endl;
    s << "Nombre: " << getNombre() << endl;
    s << "Cedula: " << getCedula() << endl;
    s << "Telefono: " << getTelefono() << endl;
    s << "Correo: " << getCorreo() << endl;

    if (getFechaNacimiento()) {
        s << "Fecha de nacimiento: " << getFechaNacimiento()->toString() << endl;
    }

    if (fechaInscripcion) {
        s << "Fecha de Inscripcion: " << fechaInscripcion->toString() << endl;
    }

    s << "Sexo: " << sexo << endl;

    if (instructorAsignado) {
        s << "Instructor: Asignado" << endl; // No podemos acceder al nombre sin incluir instructor.h
    }
    else {
        s << "Instructor: Sin asignar" << endl;
    }

    return s.str();
}