#include "Rutina.h"
#include "utiles.h"

EjercicioRutina::EjercicioRutina(Ejercicio* ej, int ser, int rep) {
    ejercicio = ej;
    series = ser;
    repeticiones = rep;
}

EjercicioRutina::~EjercicioRutina() {
    // No eliminar el ejercicio ya que pertenece a la batería
}

Ejercicio* EjercicioRutina::getEjercicio() const {
    return ejercicio;
}

int EjercicioRutina::getSeries() const {
    return series;
}

int EjercicioRutina::getRepeticiones() const {
    return repeticiones;
}

string EjercicioRutina::toString() const {
    return ejercicio->getNombre() + ", series: " + to_string(series) +
        ", repeticiones: " + to_string(repeticiones);
}

Rutina::Rutina() {
    tam = 50;
    cant = 0;
    ejerciciosRutina = new EjercicioRutina * [tam];
    for (int i = 0; i < tam; i++) {
        ejerciciosRutina[i] = nullptr;
    }
}

Rutina::~Rutina() {
    for (int i = 0; i < cant; i++) {
        delete ejerciciosRutina[i];
    }
    delete[] ejerciciosRutina;
}

void Rutina::agregarEjercicio(Ejercicio* ejercicio, int series, int repeticiones) {
    if (cant < tam) {
        ejerciciosRutina[cant] = new EjercicioRutina(ejercicio, series, repeticiones);
        cant++;
    }
}

void Rutina::mostrarRutina(string nombreCliente) {
    print("==================================================================\n");
    print("RUTINA GENERADA PARA " + nombreCliente + "\n");
    print("==================================================================\n");

    // Mostrar por zonas
    string zonas[] = { "Pecho", "Tríceps", "Bíceps", "Piernas", "Espalda" };

    for (int zona = 1; zona <= 5; zona++) {
        print(zonas[zona - 1] + ":\n");
        bool tieneEjercicios = false;

        for (int i = 0; i < cant; i++) {
            if (ejerciciosRutina[i]->getEjercicio()->getZonaMuscular() == zona) {
                print(ejerciciosRutina[i]->toString() + "\n");
                tieneEjercicios = true;
            }
        }

        if (!tieneEjercicios) {
            print("Ninguno\n");
        }
        print("\n");
    }
}

void Rutina::limpiarRutina() {
    for (int i = 0; i < cant; i++) {
        delete ejerciciosRutina[i];
        ejerciciosRutina[i] = nullptr;
    }
    cant = 0;
}

int Rutina::getCantidad() const {
    return cant;
}