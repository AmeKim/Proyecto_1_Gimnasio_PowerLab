#include "instructor.h"
#include "cliente.h"
#include "Rutina.h"
#include "reporteM.h"
#include "BateriaEjercicios.h"
#include "Ejercicio.h"

instructor::instructor(string nombre, string cedula, int telefono, string correo,
    int dia, int mes, int anio, vecEspecialidades* esp)
    : Persona(nombre, cedula, telefono, correo, fecha(dia, mes, anio)) {
    this->especialidades = esp;
}

instructor::instructor(string nombre, string cedula, int telefono, string correo,
    const fecha& fechaNac, vecEspecialidades* esp)
    : Persona(nombre, cedula, telefono, correo, fechaNac) {
    this->especialidades = esp;
}

instructor::instructor(string nombre, string cedula, int telefono, string correo,
    const string& fechaNacStr, vecEspecialidades* esp)
    : Persona(nombre, cedula, telefono, correo, fecha(fechaNacStr)) {
    this->especialidades = esp;
}

instructor::~instructor() {
    delete especialidades;
}

// Getters
vecEspecialidades* instructor::getEspecialidades() const {
    return especialidades;
}

int instructor::getCantidadEspecialidades() const {
    return especialidades ? especialidades->getCan() : 0;
}

// Setters
void instructor::setEspecialidades(vecEspecialidades* esp) {
    if (especialidades) {
        delete especialidades;
    }
    this->especialidades = esp;
}

// M�todos de especialidades
bool instructor::tieneEspecialidad(const string& nombreEsp) const {
    if (especialidades) {
        return especialidades->buscarPorNombre(nombreEsp) != nullptr;
    }
    return false;
}

// *** M�TODOS PRINCIPALES PARA CREAR RUTINAS ***

Rutina* instructor::crearRutinaCompleta(cliente* cli, BateriaEjercicios* bateria) {
    if (!cli) {
        return nullptr;
    }

    // El instructor crea una nueva rutina vac�a para el cliente
    Rutina* nuevaRutina = new Rutina(cli->getCedula());

    cout << "Instructor " << getNombre() << " creando rutina para " << cli->getNombre() << endl;

    return nuevaRutina;
}

bool instructor::generarRutinaParaCliente(cliente* cli, BateriaEjercicios* bateria) {
    if (!cli || !bateria) {
        return false;
    }

    // El instructor crea la rutina
    Rutina* nuevaRutina = crearRutinaCompleta(cli, bateria);
    if (!nuevaRutina) {
        return false;
    }

    cout << "=== INSTRUCTOR " << getNombre() << " GENERANDO RUTINA ===" << endl;
    cout << "Cliente: " << cli->getNombre() << " (" << cli->getCedula() << ")" << endl;

    // Aqu� se podr�a implementar la l�gica interactiva para agregar ejercicios
    // Por ahora, devolvemos la rutina vac�a para que se complete en el men�

    return true;
}

bool instructor::agregarEjercicioARutina(Rutina* rutina, BateriaEjercicios* bateria,
    int zona, int indiceEjercicio, int series, int repeticiones) {
    if (!rutina || !bateria) {
        return false;
    }

    // Buscar el ejercicio en la bater�a
    Ejercicio* ejercicioBase = bateria->obtenerEjercicioPorIndice(zona, indiceEjercicio);
    if (!ejercicioBase) {
        cout << "Ejercicio no encontrado en la bater�a" << endl;
        return false;
    }

    // El instructor crea una copia del ejercicio con las especificaciones
    Ejercicio* ejercicioPersonalizado = new Ejercicio(zona, ejercicioBase->getNombre(),
        ejercicioBase->getDescripcion(),
        series, repeticiones);

    // Agregar el ejercicio a la rutina
    bool agregado = rutina->agregarEjercicio(ejercicioPersonalizado);

    if (agregado) {
        cout << "Instructor " << getNombre() << " agreg�: " << ejercicioPersonalizado->getNombre()
            << " (" << series << " series x " << repeticiones << " reps)" << endl;
    }

    return agregado;
}

bool instructor::entregarRutinaACliente(cliente* cli, Rutina* rutina) {
    if (!cli || !rutina) {
        return false;
    }

    // Verificar que la rutina sea para este cliente
    if (rutina->getCedulaCliente() != cli->getCedula()) {
        cout << "Error: La rutina no corresponde al cliente especificado" << endl;
        return false;
    }

    cout << "=== INSTRUCTOR " << getNombre() << " ENTREGANDO RUTINA ===" << endl;
    cout << "Cliente: " << cli->getNombre() << endl;
    cout << "Rutina con " << rutina->getCan() << " ejercicios" << endl;

    // El cliente recibe la rutina del instructor
    cli->recibirRutinaDelInstructor(rutina);

    cout << "�Rutina entregada exitosamente!" << endl;
    return true;
}

void instructor::mostrarRutinaDeCliente(cliente* cli) const {
    if (!cli) {
        cout << "Cliente no v�lido" << endl;
        return;
    }

    cout << "=== INSTRUCTOR " << getNombre() << " MOSTRANDO RUTINA ===" << endl;
    cli->mostrarRutinaActual();
}

void instructor::mostrarBateriaEjerciciosPorZona(BateriaEjercicios* bateria, int zona) const {
    if (!bateria) {
        return;
    }

    cout << "=== INSTRUCTOR " << getNombre() << " - BATER�A DE EJERCICIOS ===" << endl;

    // Crear ejercicio temporal para obtener nombre de zona
    Ejercicio temp(zona, "", "");
    cout << "ZONA MUSCULAR: " << temp.getNombreZona() << endl;
    cout << "===========================================" << endl;

    bateria->mostrarEjerciciosPorZona(zona);
}

// *** M�TODOS PARA MEDICIONES ***

reporteM* instructor::crearMedicionParaCliente(cliente* cli, const fecha& fecha, double peso,
    double estatura, double pGrasa, double pMusculo) {
    if (!cli) {
        return nullptr;
    }

    cout << "=== INSTRUCTOR " << getNombre() << " CREANDO MEDICI�N ===" << endl;
    cout << "Cliente: " << cli->getNombre() << endl;

    // El instructor crea la medici�n
    reporteM* nuevaMedicion = (fecha, peso, estatura, pGrasa, pMusculo);

    // Calcular prote�na seg�n el sexo del cliente
    nuevaMedicion->calcularProteina(cli->getSexo());

    cout << "Medici�n creada - IMC: " << nuevaMedicion->getIMC()
        << " (" << nuevaMedicion->getClasificacion() << ")" << endl;

    return nuevaMedicion;
}

bool instructor::asignarMedicionACliente(cliente* cli, reporteM* medicion) {
    if (!cli || !medicion) {
        return false;
    }

    cout << "Instructor " << getNombre() << " asignando medici�n a " << cli->getNombre() << endl;

    return cli->agregarMedicion(medicion);
}

// M�todos de visualizaci�n
string instructor::toString() {
    stringstream s;
    s << getCedula() << " " << getNombre();
    return s.str();
}

string instructor::toStringDetallado() const {
    stringstream s;
    s << "=== DETALLE INSTRUCTOR ===" << endl;
    s << "Nombre: " << getNombre() << endl;
    s << "C�dula: " << getCedula() << endl;
    s << "Tel�fono: " << getTelefono() << endl;
    s << "Correo: " << getCorreo() << endl;
    s << "Fecha de nacimiento: " << getFechaNacimiento()->toString() << endl;

    if (especialidades && especialidades->getCan() > 0) {
        s << "Especialidades: " << especialidades->toString() << endl;
    }
    else {
        s << "Sin especialidades asignadas" << endl;
    }

    return s.str();
}

void instructor::mostrarEspecialidades() const {
    if (especialidades && especialidades->getCan() > 0) {
        cout << "=== ESPECIALIDADES DE " << getNombre() << " ===" << endl;
        especialidades->mostrarTodas();
    }
    else {
        cout << getNombre() << " no tiene especialidades asignadas." << endl;
    }
}