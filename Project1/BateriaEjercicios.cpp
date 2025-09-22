#include "BateriaEjercicios.h"

BateriaEjercicios::BateriaEjercicios(int capacidad) {
    tam = capacidad;
    can = 0;
    ejercicios = new Ejercicio * [tam];
    for (int i = 0; i < tam; i++) {
        ejercicios[i] = nullptr;
    }
    inicializarEjerciciosBasicos();
}

BateriaEjercicios::~BateriaEjercicios() {
    for (int i = 0; i < can; i++) {
        delete ejercicios[i];
    }
    delete[] ejercicios;
}

bool BateriaEjercicios::agregarEjercicio(Ejercicio* ejercicio) {
    if (can < tam && ejercicio != nullptr) {
        ejercicios[can] = ejercicio;
        can++;
        return true;
    }
    return false;
}

void BateriaEjercicios::eliminarEjercicio(const string& nombre) {
    for (int i = 0; i < can; i++) {
        if (ejercicios[i] && ejercicios[i]->getNombre() == nombre) {
            delete ejercicios[i];
            for (int j = i; j < can - 1; j++) {
                ejercicios[j] = ejercicios[j + 1];
            }
            ejercicios[can - 1] = nullptr;
            can--;
            return;
        }
    }
}

Ejercicio* BateriaEjercicios::buscarEjercicio(const string& nombre) {
    for (int i = 0; i < can; i++) {
        if (ejercicios[i] && ejercicios[i]->getNombre() == nombre) {
            return ejercicios[i];
        }
    }
    return nullptr;
}

void BateriaEjercicios::mostrarEjerciciosPorZona(int zona) const {
    cout << "BATERIA DE EJERCICIOS DISPONIBLES PARA ZONA MUSCULAR ";

    // Crear ejercicio temporal para obtener el nombre de la zona
    Ejercicio temp(zona, "", "");
    cout << temp.getNombreZona() << endl;
    cout << "===========================================" << endl;

    int contador = 1;
    for (int i = 0; i < can; i++) {
        if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
            cout << contador << ". " << ejercicios[i]->getNombre() << endl;
            contador++;
        }
    }

    if (contador == 1) {
        cout << "No hay ejercicios disponibles para esta zona muscular." << endl;
    }
}

string BateriaEjercicios::getEjerciciosPorZona(int zona) const {
    stringstream s;
    s << "BATERIA DE EJERCICIOS DISPONIBLES PARA ZONA MUSCULAR ";

    // Crear ejercicio temporal para obtener el nombre de la zona
    Ejercicio temp(zona, "", "");
    s << temp.getNombreZona() << endl;
    s << "===========================================" << endl;

    int contador = 1;
    for (int i = 0; i < can; i++) {
        if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
            s << contador << ". " << ejercicios[i]->getNombre() << endl;
            contador++;
        }
    }

    if (contador == 1) {
        s << "No hay ejercicios disponibles para esta zona muscular." << endl;
    }

    return s.str();
}

Ejercicio* BateriaEjercicios::obtenerEjercicioPorIndice(int indice, int zona) const {
    int contador = 0;
    for (int i = 0; i < can; i++) {
        if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
            contador++;
            if (contador == indice) {
                return ejercicios[i];
            }
        }
    }
    return nullptr;
}

int BateriaEjercicios::getCan() const {
    return can;
}

int BateriaEjercicios::getTam() const {
    return tam;
}

void BateriaEjercicios::mostrarTodos() const {
    cout << "=== BATERIA COMPLETA DE EJERCICIOS ===" << endl;
    for (int zona = 1; zona <= 5; zona++) {
        Ejercicio temp(zona, "", "");
        cout << "\n" << temp.getNombreZona() << ":" << endl;
        cout << "-------------------" << endl;

        bool hayEjercicios = false;
        for (int i = 0; i < can; i++) {
            if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
                cout << "- " << ejercicios[i]->getNombre() << endl;
                hayEjercicios = true;
            }
        }
        if (!hayEjercicios) {
            cout << "No hay ejercicios para esta zona." << endl;
        }
    }
}

string BateriaEjercicios::toString() const {
    stringstream s;
    s << "=== BATERIA COMPLETA DE EJERCICIOS ===" << endl;
    for (int zona = 1; zona <= 5; zona++) {
        Ejercicio temp(zona, "", "");
        s << "\n" << temp.getNombreZona() << ":" << endl;
        s << "-------------------" << endl;

        bool hayEjercicios = false;
        for (int i = 0; i < can; i++) {
            if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
                s << "- " << ejercicios[i]->getNombre() << endl;
                hayEjercicios = true;
            }
        }
        if (!hayEjercicios) {
            s << "No hay ejercicios para esta zona." << endl;
        }
    }
    return s.str();
}

int BateriaEjercicios::contarEjerciciosPorZona(int zona) const {
    int contador = 0;
    for (int i = 0; i < can; i++) {
        if (ejercicios[i] && ejercicios[i]->getZonaMuscular() == zona) {
            contador++;
        }
    }
    return contador;
}

void BateriaEjercicios::inicializarEjerciciosBasicos() {
    // Ejercicios para Pecho (zona 1)
    agregarEjercicio(new Ejercicio(1, "Press de banca plano con barra", "Ejercicio fundamental de empuje horizontal para desarrollo del pecho"));
    agregarEjercicio(new Ejercicio(1, "Press inclinado con barra", "Press en banco inclinado para la parte superior del pecho"));
    agregarEjercicio(new Ejercicio(1, "Press declinado con barra", "Press en banco declinado para la parte inferior del pecho"));
    agregarEjercicio(new Ejercicio(1, "Flexiones de pecho", "Ejercicio de peso corporal para desarrollo del pecho"));
    agregarEjercicio(new Ejercicio(1, "Press con mancuernas", "Ejercicio con mancuernas para mayor rango de movimiento"));

    // Ejercicios para Tríceps (zona 2)
    agregarEjercicio(new Ejercicio(2, "Press cerrado con barra", "Press con agarre cerrado para tríceps"));
    agregarEjercicio(new Ejercicio(2, "Extensiones francesas", "Ejercicio de aislamiento para tríceps"));
    agregarEjercicio(new Ejercicio(2, "Fondos en paralelas", "Ejercicio de peso corporal para tríceps"));
    agregarEjercicio(new Ejercicio(2, "Patadas de tríceps", "Ejercicio de aislamiento con mancuerna"));

    // Ejercicios para Bíceps (zona 3)
    agregarEjercicio(new Ejercicio(3, "Curl con barra", "Ejercicio básico de flexión de codo"));
    agregarEjercicio(new Ejercicio(3, "Curl con mancuernas", "Curl alternado o simultáneo con mancuernas"));
    agregarEjercicio(new Ejercicio(3, "Curl martillo", "Curl con agarre neutro"));
    agregarEjercicio(new Ejercicio(3, "Curl en banco Scott", "Ejercicio en banco predicador"));

    // Ejercicios para Piernas (zona 4)
    agregarEjercicio(new Ejercicio(4, "Sentadillas", "Ejercicio fundamental para cuádriceps y glúteos"));
    agregarEjercicio(new Ejercicio(4, "Prensa de piernas", "Ejercicio en máquina para desarrollo de piernas"));
    agregarEjercicio(new Ejercicio(4, "Zancadas", "Ejercicio unilateral para piernas y glúteos"));
    agregarEjercicio(new Ejercicio(4, "Extensiones de pierna en máquina", "Ejercicio de aislamiento para cuádriceps"));
    agregarEjercicio(new Ejercicio(4, "Peso muerto rumano", "Ejercicio para femorales y glúteos"));
    agregarEjercicio(new Ejercicio(4, "Hip thrust", "Ejercicio específico para glúteos"));
    agregarEjercicio(new Ejercicio(4, "Curl de femorales en máquina", "Ejercicio de aislamiento para femorales"));
    agregarEjercicio(new Ejercicio(4, "Buenos días", "Ejercicio de bisagra de cadera"));
    agregarEjercicio(new Ejercicio(4, "Aductores", "Ejercicio para la parte interna del muslo"));
    agregarEjercicio(new Ejercicio(4, "Máquina de abductores", "Ejercicio para la parte externa del muslo"));

    // Ejercicios para Espalda (zona 5)
    agregarEjercicio(new Ejercicio(5, "Dominadas", "Ejercicio de tracción vertical"));
    agregarEjercicio(new Ejercicio(5, "Remo con barra", "Ejercicio de tracción horizontal"));
    agregarEjercicio(new Ejercicio(5, "Remo con mancuerna", "Remo unilateral con mancuerna"));
    agregarEjercicio(new Ejercicio(5, "Jalones al pecho", "Ejercicio en polea alta"));
    agregarEjercicio(new Ejercicio(5, "Peso muerto convencional", "Ejercicio fundamental de tracción"));
}