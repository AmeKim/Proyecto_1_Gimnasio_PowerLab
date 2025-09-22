#include "cliente.h"
#include "instructor.h"

//cliente::cliente: persona() {}
cliente::~cliente() {
    delete fechaInscripcion;

    // Eliminar historial de mediciones
    for (int i = 0; i < cantMediciones; i++) {
        delete historialMediciones[i];
    }
    delete[] historialMediciones;

    // Eliminar rutina actual si existe
    if (rutinaActual) {
        delete rutinaActual;
    }
}

// Getters
char cliente::getSexo() const {
    return sexo;
}

fecha* cliente::getFechaInscripcion() const {
    return fechaInscripcion;
}

instructor* cliente::getInstructorAsignado() const {
    return instructorAsignado;
}

int cliente::getCantMediciones() const {
    return cantMediciones;
}

reporteM* cliente::getMedicion(int indice) const {
    if (indice >= 0 && indice < cantMediciones) {
        return historialMediciones[indice];
    }
    return nullptr;
}

Rutina* cliente::getRutinaActual() const {
    return rutinaActual;
}

// Setters
void cliente::setSexo(char sexo) {
    this->sexo = sexo;
}

void cliente::setfechaInscripcion(fecha* fecha) {
    if (fechaInscripcion) {
        delete fechaInscripcion;
    }
    fechaInscripcion = fecha;
}

void cliente::setInstructorAsignado(instructor* inst) {
    this->instructorAsignado = inst;
}

// M�todos para que el instructor gestione la rutina
void cliente::recibirRutinaDelInstructor(Rutina* rutina) {
    // Eliminar rutina anterior si existe (solo una rutina activa)
    if (rutinaActual) {
        delete rutinaActual;
        rutinaActual = nullptr;
    }
    // Almacenar la nueva rutina creada por el instructor
    this->rutinaActual = rutina;
}

void cliente::eliminarRutinaActual() {
    if (rutinaActual) {
        delete rutinaActual;
        rutinaActual = nullptr;
    }
}

// M�todos para mediciones
bool cliente::agregarMedicion(reporteM* medicion) {
    if (cantMediciones < maxMediciones && medicion) {
        // Calcular prote�na espec�fica seg�n el sexo del cliente
        medicion->calcularProteina(sexo);

        historialMediciones[cantMediciones] = medicion;
        cantMediciones++;
        return true;
    }
    return false;
}

reporteM* cliente::getUltimaMedicion() const {
    if (cantMediciones > 0) {
        return historialMediciones[cantMediciones - 1];
    }
    return nullptr;
}

// M�todos de visualizaci�n
string cliente::toString() const {
    stringstream s;
    s << getCedula() << " " << getNombre();
    return s.str();
}

string cliente::toStringDetallado() const {
    stringstream s;
    s << "Nombre: " << getNombre() << endl;
    s << "Cedula: " << getCedula() << endl;
    s << "Tel�fono: " << getTelefono() << endl;
    s << "Correo: " << getCorreo() << endl;
    s << "Fecha de nacimiento: " << getFechaNacimiento()->toString() << endl;
    s << "Fecha de Inscripci�n: " << fechaInscripcion->toString() << endl;
    s << "Sexo: " << sexo << endl;

    if (instructorAsignado) {
        s << "Instructor: " << instructorAsignado->getNombre() << endl;
    }
    else {
        s << "Instructor: Sin asignar" << endl;
    }

    if (tieneRutina()) {
        s << "Rutina: Asignada (" << rutinaActual->getCan() << " ejercicios)" << endl;
    }
    else {
        s << "Rutina: Sin asignar" << endl;
    }

    return s.str();
}

void cliente::mostrarHistorialMediciones() const {
    cout << "HISTORIAL DE MEDICIONES" << endl;
    cout << "Cliente: " << getNombre() << " (" << getCedula() << ")" << endl;

    if (cantMediciones == 0) {
        cout << "No hay mediciones registradas para este cliente." << endl;
        return;
    }

    for (int i = 0; i < cantMediciones; i++) {
        cout << (i + 1) << "- " << historialMediciones[i]->toString() << endl;
    }
}

void cliente::mostrarRutinaActual() const {
    if (tieneRutina()) {
        cout << "===================================================================" << endl;
        cout << "RUTINA ACTUAL DE " << getNombre() << endl;
        if (instructorAsignado) {
            cout << "Instructor: " << instructorAsignado->getNombre() << endl;
        }
        cout << "===================================================================" << endl;
        rutinaActual->mostrarRutina();
    }
    else {
        cout << "El cliente " << getNombre() << " no tiene rutina asignada." << endl;
    }
}

bool cliente::tieneRutina() const {
    return rutinaActual != nullptr;
}