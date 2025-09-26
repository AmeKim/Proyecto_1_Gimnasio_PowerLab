#include "ClaseGrupal.h"

// Constructor por defecto
ClaseGrupal::ClaseGrupal() {
    codigo = 0;
    tipo = "";
    capacidad = 0;
    salon = "";
    horario = "";
    cedulaInstructor = "";
    cantMatriculados = 0;
    tamMatriculados = 0;
    matriculados = nullptr;
}

// Constructor con parámetros
ClaseGrupal::ClaseGrupal(string tipo,int codigo, int capacidad, string salon, string horario, string cedulaInstructor) {
    this->codigoSucursal = codigoSucursal;
    this->codigo = codigo;
    this->tipo = tipo;
    this->capacidad = capacidad;
    this->salon = salon;
    this->horario = horario;
    this->cedulaInstructor = cedulaInstructor;
    this->cantMatriculados = 0;
    this->tamMatriculados = capacidad > 0 ? capacidad : 0;
    if (tamMatriculados > 0) {
        matriculados = new string[tamMatriculados];
        for (int i = 0; i < tamMatriculados; i++) matriculados[i] = "";
    }
    else {
        matriculados = nullptr;
    }
}

ClaseGrupal::~ClaseGrupal() {
    if (matriculados != nullptr) {
        delete[] matriculados;
        matriculados = nullptr;
    }
}

// Getters
string ClaseGrupal::getTipo() const { return tipo; }
int ClaseGrupal::getCodigo() const { return codigo; }
string ClaseGrupal::getCodigoSucursal(){

}
int ClaseGrupal::getCapacidad() const { return capacidad; }
int ClaseGrupal::getCantMatriculados() const { return cantMatriculados; }
string ClaseGrupal::getSalon() const { return salon; }
string ClaseGrupal::getHorario() const { return horario; }
string ClaseGrupal::getCedulaInstructor() const { return cedulaInstructor; }

// Comprueba si ya está matriculado
bool ClaseGrupal::estaMatriculado(string cedulaCliente) const {
    for (int i = 0; i < cantMatriculados; i++) {
        if (matriculados[i] == cedulaCliente) return true;
    }
    return false;
}

// Matricular cliente por cédula. Devuelve true si tuvo éxito.
bool ClaseGrupal::matricularCliente(string cedulaCliente) {
    if (cantMatriculados >= capacidad) return false; // sin cupo
    if (estaMatriculado(cedulaCliente)) return false; // ya matriculado
    // insertar en primera posición libre
    for (int i = 0; i < tamMatriculados; i++) {
        if (matriculados[i].empty()) {
            matriculados[i] = cedulaCliente;
            cantMatriculados++;
            return true;
        }
    }
    // si no encontramos posición (no debería ocurrir), intentar al final lógico
    if (cantMatriculados < tamMatriculados) {
        matriculados[cantMatriculados] = cedulaCliente;
        cantMatriculados++;
        return true;
    }
    return false;
}

// Remover matrícula (si existe)
bool ClaseGrupal::removerMatricula(string cedulaCliente) {
    for (int i = 0; i < tamMatriculados; i++) {
        if (matriculados[i] == cedulaCliente) {
            matriculados[i] = "";
            cantMatriculados--;
            return true;
        }
    }
    return false;
}

// Representación corta
string ClaseGrupal::toString() const {
    stringstream s;
    s << codigo << " - Tipo: " << tipo << " - Cap: " << capacidad << " - Mat: " << cantMatriculados;
    return s.str();
}

// Representación detallada
string ClaseGrupal::detalleClase() const {
    stringstream s;
    s << "Clase codigo: " << codigo << "\n";
    s << "Tipo (codigo): " << tipo << "\n";
    s << "Capacidad: " << capacidad << "\n";
    s << "Matriculados: " << cantMatriculados << "\n";
    s << "Cupos disponibles: " << (capacidad - cantMatriculados) << "\n";
    s << "Salon: " << salon << "\n";
    s << "Horario: " << horario << "\n";
    s << "Instructor: " << cedulaInstructor << "\n";
    if (cantMatriculados > 0 && matriculados != nullptr) {
        s << "Lista de matriculados:\n";
        int idx = 1;
        for (int i = 0; i < tamMatriculados; i++) {
            if (!matriculados[i].empty()) {
                s << idx << "- " << matriculados[i] << "\n";
                idx++;
            }
        }
    }
    return s.str();
}

string ClaseGrupal::mostrarTipos() const{
    stringstream s;
	s << "Tipos de clases grupales disponibles:\n";
	s << "1 - CrossFit\n";
	s << "2 - HIIT\n";
	s << "3 - TRX\n";
	s << "4 - Pesas\n";
	s << "5 - Spinning\n";
	s << "6 - Cardio\n";
	s << "7 - Yoga\n";
	s << "8 - Zumba\n";
	return s.str();
}
