#include "Rutina.h"

Rutina::Rutina(string cedulaCliente, int capacidad) {
    this->cedulaCliente = cedulaCliente;
    this->tam = capacidad;
    this->can = 0;
    this->ejercicios = new Ejercicio * [tam];
    for (int i = 0; i < tam; i++) {
        ejercicios[i] = nullptr;
    }
}

Rutina::~Rutina() {
    for (int i = 0; i < can; i++) {
        delete ejercicios[i];
    }
    delete[] ejercicios;
}

bool Rutina::agregarEjercicio(Ejercicio* ejercicio) {
    if (can < tam && ejercicio) {
        ejercicios[can] = ejercicio;
        can++;
        return true;
    }
    return false;
}

void Rutina::limpiarRutina() {
    for (int i = 0; i < can; i++) {
        delete ejercicios[i];
        ejercicios[i] = nullptr;
    }
    can = 0;
}

string Rutina::getCedulaCliente() const {
    return cedulaCliente;
}

int Rutina::getCan() const {
    return can;
}

string Rutina::toString() const {
    stringstream s;

    // Mostrar por zonas musculares
    for (int zona = 1; zona <= 5; zona++) {
        bool tieneEjercicios = false;

        // Verificar si hay ejercicios para esta zona
        for (int i = 0; i < can; i++) {
            if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
                tieneEjercicios = true;
                break;
            }
        }

        if (tieneEjercicios) {
            s << ejercicios[0]->getNombreZona() << ":" << endl;
            for (int i = 0; i < can; i++) {
                if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
                    s << ejercicios[i]->toString() << endl;
                }
            }
        }
        else {
            // Mostrar "Ninguno" para zonas sin ejercicios
            Ejercicio temp(zona, "", "");
            s << temp.getNombreZona() << ":" << endl;
            s << "Ninguno" << endl;
        }
    }

    return s.str();
}

void Rutina::mostrarRutina() const {
    cout << "===================================================================" << endl;
    cout << "RUTINA GENERADA" << endl;
    cout << "===================================================================" << endl;

    for (int zona = 1; zona <= 5; zona++) {
        bool tieneEjercicios = false;

        // Verificar si hay ejercicios para esta zona
        for (int i = 0; i < can; i++) {
            if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
                tieneEjercicios = true;
                break;
            }
        }

        // Crear un ejercicio temporal para obtener el nombre de la zona
        Ejercicio temp(zona, "", "");
        cout << temp.getNombreZona() << ":" << endl;

        if (tieneEjercicios) {
            for (int i = 0; i < can; i++) {
                if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
                    cout << ejercicios[i]->toString() << endl;
                }
            }
        }
        else {
            cout << "Ninguno" << endl;
        }
    }
}

void Rutina::mostrarPorZona(int zona) const {
    bool encontrado = false;
    for (int i = 0; i < can; i++) {
        if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
            ejercicios[i]->mostrar();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay ejercicios para esta zona muscular." << endl;
    }
}

int Rutina::contarEjerciciosPorZona(int zona) const {
    int contador = 0;
    for (int i = 0; i < can; i++) {
        if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
            contador++;
        }
    }
    return contador;
}