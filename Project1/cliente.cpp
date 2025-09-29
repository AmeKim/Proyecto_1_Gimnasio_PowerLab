#include "cliente.h"
#include "instructor.h"
#include "ClaseGrupal.h"
#include <sstream>

cliente::cliente() : Persona(), telefono(""), correo(""),fechaNacimiento(), fechaInscripcion(), sexo(""),instructorAsignado(nullptr), tamClases(3), cantClases(0) {mediciones = new vecReportesM();rutina = new Rutina();
    clasesMatriculadas = new ClaseGrupal * [tamClases];
    for (int i = 0; i < tamClases; i++) {
        clasesMatriculadas[i] = nullptr;
    }
}

cliente::cliente(const string& ced, const string& nom, const string& tel,const string& corr, const fecha& fechaNac, const fecha& fechaInsc,const string& sex): Persona(ced, nom), telefono(tel), correo(corr),fechaNacimiento(fechaNac), fechaInscripcion(fechaInsc), sexo(sex),instructorAsignado(nullptr), tamClases(3), cantClases(0) {
    mediciones = new vecReportesM();
    rutina = new Rutina();
    clasesMatriculadas = new ClaseGrupal * [tamClases];
    for (int i = 0; i < tamClases; i++) {
        clasesMatriculadas[i] = nullptr;
    }
}

cliente::cliente(const cliente& other): Persona(other), telefono(other.telefono), correo(other.correo),fechaNacimiento(other.fechaNacimiento), fechaInscripcion(other.fechaInscripcion),sexo(other.sexo), instructorAsignado(other.instructorAsignado),tamClases(other.tamClases), cantClases(other.cantClases) {
    mediciones = new vecReportesM();
    rutina = new Rutina();
    clasesMatriculadas = new ClaseGrupal * [tamClases];
    for (int i = 0; i < tamClases; i++) {
        clasesMatriculadas[i] = other.clasesMatriculadas[i];
    }
}

cliente& cliente:: operator=(const cliente& other) {
    if (this != &other) {
        Persona::operator=(other);
        telefono = other.telefono;
        correo = other.correo;
        fechaNacimiento = other.fechaNacimiento;
        fechaInscripcion = other.fechaInscripcion;
        sexo = other.sexo;
        instructorAsignado = other.instructorAsignado;
        cantClases = other.cantClases;

        for (int i = 0; i < tamClases; i++) {
            clasesMatriculadas[i] = other.clasesMatriculadas[i];
        }
    }
    return *this;
}

cliente::~cliente() {
    if (mediciones) {
        delete mediciones;
        mediciones = nullptr;
    }
    if (rutina) {
        delete rutina;
        rutina = nullptr;
    }
    if (clasesMatriculadas) {
        delete[] clasesMatriculadas;
        clasesMatriculadas = nullptr;
    }
}

// Getters
string cliente::getTelefono() const { return telefono; }
string cliente::getCorreo() const { return correo; }
string getNombreCompleto() { return getNombreCompleto(); }
fecha cliente::getFechaNacimiento() const { return fechaNacimiento; }
fecha cliente::getFechaInscripcion() const { return fechaInscripcion; }
string cliente::getSexo() const { return sexo; }
instructor* cliente::getInstructor() const { return instructorAsignado; }
vecReportesM* cliente::getMediciones() const { return mediciones; }
Rutina* cliente::getRutina() const { return rutina; }

// Setters
void cliente::setTelefono(const string& tel) { telefono = tel; }
void cliente::setCorreo(const string& corr) { correo = corr; }
void cliente::setFechaNacimiento(const fecha& f) { fechaNacimiento = f; }
void cliente::setFechaInscripcion(const fecha& f) { fechaInscripcion = f; }
void cliente::setSexo(const string& s) { sexo = s; }
void cliente::setInstructor(instructor* ins) { instructorAsignado = ins; }

void cliente::agregarMedicion(Medicion* med) {
    if (mediciones && med) {
        mediciones->agregar(med);
    }
}

bool cliente::matricularClase(ClaseGrupal* clase) {
    if (!clase || cantClases >= tamClases) return false;

    for (int i = 0; i < cantClases; i++) {
        if (clasesMatriculadas[i] == clase) return false;
    }

    clasesMatriculadas[cantClases++] = clase;
    return true;
}

int cliente::getCantidadClasesMatriculadas() const {
    return cantClases;
}

string cliente::mostrarClasesMatriculadas() const {
    if (cantClases == 0) {
        return "El cliente no tiene clases matriculadas.\n";
    }

    stringstream ss;
    for (int i = 0; i < cantClases; i++) {
        if (clasesMatriculadas[i]) {
            ss << (i + 1) << ") " << clasesMatriculadas[i]->getTipo() << "\n";
        }
    }
    return ss.str();
}

string cliente::toString() const {
    stringstream ss;
    ss << "Nombre: " << getNombre() << "\n";
    ss << "Cedula: " << getCedula() << "\n";
    ss << "Telefono: " << telefono << "\n";
    ss << "Correo: " << correo << "\n";
    ss << "Fecha de nacimiento: " << fechaNacimiento.toString() << "\n";
    ss << "Fecha de Inscripcion: " << fechaInscripcion.toString() << "\n";
    ss << "Sexo: " << sexo << "\n";
    return ss.str();
}