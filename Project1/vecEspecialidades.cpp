#include "vecEspecialidades.h"
#include "especialidad.h"

vecEspecialidades::vecEspecialidades(int capacidadInicial)
    : datos(nullptr), capacidad(0), cantidad(0) {
    if (capacidadInicial < 1) capacidadInicial = 8;
    datos = new Especialidad[capacidadInicial];
    capacidad = capacidadInicial;
    // No llamamos a cargarEspecialidadesPorDefecto aquí por si el programa necesita control sobre el momento de carga
}

vecEspecialidades::vecEspecialidades(const vecEspecialidades& otro)
    : datos(nullptr), capacidad(0), cantidad(0) {
    if (otro.cantidad > 0) {
        capacidad = otro.capacidad;
        cantidad = otro.cantidad;
        datos = new Especialidad[capacidad];
        for (int i = 0; i < cantidad; i++) {
            datos[i] = otro.datos[i];
        }
    }
}

vecEspecialidades::~vecEspecialidades() {
    delete[] datos;
    datos = nullptr;
    capacidad = 0;
    cantidad = 0;
}

vecEspecialidades& vecEspecialidades::operator=(const vecEspecialidades& otro) {
    if (this != &otro) {
        // Liberar memoria existente
        delete[] datos;
        datos = nullptr;
        capacidad = 0;
        cantidad = 0;

        // Copiar del otro
        if (otro.cantidad > 0) {
            capacidad = otro.capacidad;
            cantidad = otro.cantidad;
            datos = new Especialidad[capacidad];
            for (int i = 0; i < cantidad; i++) {
                datos[i] = otro.datos[i];
            }
        }
    }
    return *this;
}

void vecEspecialidades::asegurarCapacidad(int nuevaCapacidad) {
    if (nuevaCapacidad <= capacidad) return;
    Especialidad* nuevo = new Especialidad[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevo[i] = datos[i];
    }
    delete[] datos;
    datos = nuevo;
    capacidad = nuevaCapacidad;
}

void vecEspecialidades::agregar(const Especialidad& e) {
    if (cantidad >= capacidad) {
        asegurarCapacidad(capacidad * 2);
    }
    datos[cantidad++] = e;
}

void vecEspecialidades::limpiar() {
    // Resetea el conteo; mantiene el buffer para futuras inserciones
    cantidad = 0;
}

int vecEspecialidades::getCantidad() const {
    return cantidad;
}

const Especialidad& vecEspecialidades::obtener(int indice) const {
    if (indice < 0) indice = 0;
    if (indice >= cantidad) indice = cantidad - 1;
    return datos[indice];
}

Especialidad& vecEspecialidades::obtener(int indice) {
    // Si el índice es inválido, evitar acceso
    if (indice < 0) indice = 0;
    if (cantidad <= 0) indice = 0;  // proteger cuando está vacío
    if (indice >= cantidad) indice = cantidad - 1;

    // Última verificación de seguridad
    if (cantidad <= 0) {
        // Retornar una especialidad vacía estática
        static Especialidad especialidadVacia;
        return especialidadVacia;
    }

    return datos[indice];
}

int vecEspecialidades::indicePorNombre(const string& nombre) const {
    for (int i = 0; i < cantidad; ++i) {
        if (datos[i].getNombre() == nombre) return i;
    }
    return -1;
}

bool vecEspecialidades::existe(const string& nombre) const {
    return indicePorNombre(nombre) != -1;
}

void vecEspecialidades::cargarEspecialidadesPorDefecto() {
    limpiar();
    agregar(Especialidad(Especialidad::CROSSFIT));
    agregar(Especialidad(Especialidad::HIIT));
    agregar(Especialidad(Especialidad::TRX));
    agregar(Especialidad(Especialidad::PESAS));
    agregar(Especialidad(Especialidad::SPINNING));
    agregar(Especialidad(Especialidad::CARDIO));
    agregar(Especialidad(Especialidad::YOGA));
    agregar(Especialidad(Especialidad::ZUMBA));
}