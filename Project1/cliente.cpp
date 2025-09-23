#include "cliente.h"

cliente::cliente() : Persona() {
    sexo = 'M';
    fechaInscripcion = new fecha();
    cedulaInstructor = "";
    historialMediciones = new vecReportesM();
    rutinaActual = new Rutina();
}

cliente::cliente(string nombre, string cedula, string telefono, string correo,
    string fechaNac, char sexo, string fechaInsc, string cedulaInst)
    : Persona(nombre, cedula, telefono, correo, fechaNac) {
    this->sexo = sexo;
    fechaInscripcion = new fecha(fechaInsc);
    cedulaInstructor = cedulaInst;
    historialMediciones = new vecReportesM();
    rutinaActual = new Rutina();
}

cliente::~cliente() {
    delete fechaInscripcion;
    delete historialMediciones;
    delete rutinaActual;
}

char cliente::getSexo() const {
    return sexo;
}

fecha* cliente::getFechaInscripcion() const {
    return fechaInscripcion;
}

string cliente::getCedulaInstructor() const {
    return cedulaInstructor;
}

vecReportesM* cliente::getHistorialMediciones() {
    return historialMediciones;
}

Rutina* cliente::getRutinaActual() {
    return rutinaActual;
}

void cliente::setSexo(char sexo) {
    this->sexo = sexo;
}

void cliente::setFechaInscripcion(string fechaStr) {
    delete fechaInscripcion;
    fechaInscripcion = new fecha(fechaStr);
}

void cliente::setCedulaInstructor(string cedula) {
    cedulaInstructor = cedula;
}

void cliente::agregarMedicion(Medicion* medicion) {
    medicion->calcularTodo(sexo);
    historialMediciones->agregar(medicion);
}

string cliente::toString() {
    return getCedula() + " " + getNombre();
}

string cliente::toStringDetalle(string nombreInstructor, string nombreSucursal) const {
    string result = "Detalle de cliente:\n";
    result += "Nombre: " + getNombre() + "\n";
    result += "Cedula: " + getCedula() + "\n";
    result += "Teléfono: " + getTelefono() + "\n";
    result += "Correo: " + getCorreo() + "\n";
    result += "Fecha de nacimiento: " + getFechaNacimiento()->toString() + "\n";
    result += "Fecha de Inscripción: " + fechaInscripcion->toString() + "\n";
    result += "Sexo: " + string(1, sexo) + "\n";
    result += "Sucursal: " + nombreSucursal + "\n";
    result += "Instructor: " + nombreInstructor + "\n";
    return result;
}

double cliente::getUltimoIMC() const {
    int cant = historialMediciones->getCantidad();
    if (cant > 0) {
        Medicion* ultima = historialMediciones->obtener(cant - 1);
        return ultima->getImc();
    }
    return 0.0;
}