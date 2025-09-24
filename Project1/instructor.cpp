#include "instructor.h"

Instructor::Instructor() : Persona() {
    especialidades = new vecEspecialidades();
}
Instructor::Instructor(string nombre, string cedula, string telefono, string correo, const string& fechaNacimientoStr)
    : Persona(nombre, cedula, telefono, correo, fechaNacimientoStr) {
    especialidades = new vecEspecialidades();
}
Instructor::~Instructor() {
    delete especialidades;
}

bool Instructor::agregarEspecialidad(const string& esp) {
    if (esp.empty() || especialidades->buscar(esp)) return false;
    especialidad* nueva = new especialidad(esp);
    especialidades->agregar(nueva);
    return true;
}

bool Instructor::tieneEspecialidad(const string& esp) const {
    return especialidades->buscar(esp);
}

int Instructor::getCantEspecialidades() const {
    return especialidades->getCantidad();
}

string Instructor::getEspecialidad(int idx) const {
    if (idx < 0 || idx >= especialidades->getCantidad()) return "";
    especialidad* esp = especialidades->obtener(idx);
    return esp ? esp->getNombre() : "";
}

void Instructor::agregarRutinaCliente(Rutina* rutina, const string& nombreCliente){
    if(rutina == nullptr || nombreCliente.empty()) return;
    cout << "Rutina asignada al cliente " << nombreCliente << " por el instructor " << nombre << ":\n";
    rutina->mostrarRutina(nombreCliente);
}

void Instructor::realizarMedicionCliente(Medicion* medicion, const string& nombreCliente){
    if(medicion == nullptr || nombreCliente.empty()) return;
    cout << "Medici" << char(162) << "n realizada al cliente " << nombreCliente << " por el instructor " << nombre << ":\n";
    cout << medicion->toString() << "\n";
}

string Instructor::toString() {
    string info = "Instructor: " + nombre + "\nC" + char(130) + "dula: " + cedula + "\nTel" + char(130) + "fono: " + telefono +
        "\nCorreo: " + correo + "\nFecha de Nacimiento: " + fechaNacimiento->toString() +
        "\nEspecialidades: ";
    if (especialidades->getCantidad() == 0) {
        info += "Ninguna";
    } else {
        for (int i = 0; i < especialidades->getCantidad(); i++) {
            especialidad* esp = especialidades->obtener(i);
            if (esp != nullptr) {
                info += esp->getNombre();
                if (i < especialidades->getCantidad() - 1) {
                    info += ", ";
                }
            }
        }
    }
    return info;
}